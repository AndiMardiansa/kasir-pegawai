#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include "Product.h"
#include "Cart.h"
#include "Transaction.h"

using namespace std;

class POS {
private:
    vector<Product> products;
    Cart cart;
    int transactionCounter;

public:
    POS() : transactionCounter(1000) {
        initializeProducts();
    }

    void initializeProducts() {
        products.push_back(Product(1, "Kopi Hitam", 15000, 50));
        products.push_back(Product(2, "Teh Manis", 10000, 60));
        products.push_back(Product(3, "Jus Jeruk", 18000, 40));
        products.push_back(Product(4, "Nasi Goreng", 35000, 30));
        products.push_back(Product(5, "Mie Goreng", 30000, 35));
        products.push_back(Product(6, "Bakso", 28000, 25));
        products.push_back(Product(7, "Soto Ayam", 32000, 20));
        products.push_back(Product(8, "Lumpia Goreng", 12000, 45));
        products.push_back(Product(9, "Perkedel", 8000, 70));
        products.push_back(Product(10, "Tahu Goreng", 9000, 60));
    }

    void displayMainMenu() {
        system("clear");
        cout << "\n";
        cout << "╔══════════════════════════════════════╗" << endl;
        cout << "║       SISTEM KASIR DIGITAL v1.0      ║" << endl;
        cout << "╚══════════════════════════════════════╝" << endl;
        cout << "\n1. Lihat Menu Produk" << endl;
        cout << "2. Tambah ke Keranjang" << endl;
        cout << "3. Lihat Keranjang" << endl;
        cout << "4. Hapus Item dari Keranjang" << endl;
        cout << "5. Checkout" << endl;
        cout << "6. Keluar" << endl;
        cout << "\nPilih menu (1-6): ";
    }

    void viewProducts() {
        system("clear");
        cout << "\n========== DAFTAR PRODUK ==========\n";
        cout << left << setw(5) << "ID" 
             << setw(20) << "Nama Produk"
             << setw(15) << "Harga"
             << setw(10) << "Stok" << endl;
        cout << string(50, '-') << endl;

        for (const auto& product : products) {
            cout << left << setw(5) << product.getId()
                 << setw(20) << product.getName()
                 << setw(15) << "Rp " + to_string((int)product.getPrice())
                 << setw(10) << product.getStock() << endl;
        }
        cout << string(50, '=') << endl;
    }

    void addToCart() {
        viewProducts();
        
        int productId, quantity;
        cout << "\nMasukkan ID Produk: ";
        cin >> productId;

        auto it = find_if(products.begin(), products.end(),
                         [productId](const Product& p) { return p.getId() == productId; });

        if (it == products.end()) {
            cout << "Produk tidak ditemukan!" << endl;
            cin.ignore();
            cin.get();
            return;
        }

        if (it->getStock() <= 0) {
            cout << "Stok produk habis!" << endl;
            cin.ignore();
            cin.get();
            return;
        }

        cout << "Masukkan Jumlah: ";
        cin >> quantity;

        if (quantity > it->getStock()) {
            cout << "Stok tidak cukup! Stok tersedia: " << it->getStock() << endl;
            cin.ignore();
            cin.get();
            return;
        }

        cart.addItem(*it, quantity);
        it->decreaseStock(quantity);

        cout << "\n✓ " << it->getName() << " ditambahkan ke keranjang!" << endl;
        cin.ignore();
        cin.get();
    }

    void removeFromCart() {
        if (cart.getItemCount() == 0) {
            cout << "Keranjang kosong!" << endl;
            cin.ignore();
            cin.get();
            return;
        }

        cart.display();

        int productId;
        cout << "Masukkan ID Produk yang ingin dihapus: ";
        cin >> productId;

        auto& items = cart.getItems();
        auto it = find_if(products.begin(), products.end(),
                         [productId](const Product& p) { return p.getId() == productId; });

        for (auto& item : items) {
            if (item.product.getId() == productId) {
                it->increaseStock(item.quantity);
                break;
            }
        }

        cart.removeItem(productId);
        cout << "✓ Produk berhasil dihapus dari keranjang!" << endl;
        cin.ignore();
        cin.get();
    }

    void checkout() {
        if (cart.getItemCount() == 0) {
            cout << "Keranjang masih kosong!" << endl;
            cin.ignore();
            cin.get();
            return;
        }

        cart.display();

        double totalAmount = cart.getTotalAmount();
        double paymentAmount;

        cout << "\nMasukkan Jumlah Pembayaran (Rp): ";
        cin >> paymentAmount;

        if (paymentAmount < totalAmount) {
            cout << "Uang pembayaran kurang!" << endl;
            cin.ignore();
            cin.get();
            return;
        }

        transactionCounter++;
        Transaction transaction(transactionCounter, totalAmount, paymentAmount, cart.getItems());
        transaction.printReceipt();

        cout << "Terima kasih telah berbelanja!" << endl;
        cart.clear();

        cin.ignore();
        cin.get();
    }

    void run() {
        int choice;
        while (true) {
            displayMainMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    viewProducts();
                    cin.ignore();
                    cin.get();
                    break;
                case 2:
                    addToCart();
                    break;
                case 3:
                    cart.display();
                    cin.ignore();
                    cin.get();
                    break;
                case 4:
                    removeFromCart();
                    break;
                case 5:
                    checkout();
                    break;
                case 6:
                    system("clear");
                    cout << "\n╔══════════════════════════════════════╗" << endl;
                    cout << "║  Terima kasih! Sampai jumpa lagi!    ║" << endl;
                    cout << "╚══════════════════════════════════════╝\n" << endl;
                    return;
                default:
                    cout << "Pilihan tidak valid!" << endl;
                    cin.ignore();
                    cin.get();
            }
        }
    }
};

int main() {
    POS pos;
    pos.run();
    return 0;
}
