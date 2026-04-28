#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// =========================
void transaksiKasir() {
    ofstream struk("struk.txt");
    int totalBayar = 0;

    struk << "========= STRUK PEMBELIAN =========\n";

    int jumlahBarang;
    cout << "Jumlah jenis barang: ";
    cin >> jumlahBarang;
    cin.ignore();

    for (int i = 0; i < jumlahBarang; i++) {
        string nama;
        int harga, qty;

        cout << "\nBarang ke-" << i + 1 << endl;
        cout << "Nama Barang : ";
        getline(cin, nama);
        cout << "Harga       : ";
        cin >> harga;
        cout << "Jumlah      : ";
        cin >> qty;
        cin.ignore();

        int subtotal = harga * qty;
        totalBayar += subtotal;

        struk << "Barang  : " << nama << endl;
        struk << "Harga   : " << harga << endl;
        struk << "Jumlah  : " << qty << endl;
        struk << "Subtotal: " << subtotal << endl;
        struk << "----------------------------\n";
    }

    int bayar;
    cout << "\nTotal Bayar : " << totalBayar << endl;
    cout << "Uang Bayar  : ";
    cin >> bayar;

    struk << "TOTAL     : " << totalBayar << endl;
    struk << "BAYAR     : " << bayar << endl;
    struk << "KEMBALIAN : " << bayar - totalBayar << endl;
    struk << "=================================\n";
    struk.close();

    cout << "\nTransaksi berhasil!" << endl;
}

// =========================
void tampilStruk() {
    ifstream file("struk.txt");
    if (!file.is_open()) {
        cout << "Struk belum ada!" << endl;
        return;
    }

    string baris;
    cout << "\n=== STRUK PEMBELIAN ===\n";
    while (getline(file, baris)) {
        cout << baris << endl;
    }
    file.close();
}

// =========================
void menuTransaksi() {
    int pilih;

    do {
        cout << "\n====================\n";
        cout << "MENU KASIR\n";
        cout << "====================\n";
        cout << "1. Transaksi\n";
        cout << "2. Lihat Struk\n";
        cout << "3. Keluar\n";
        cout << "Pilih Menu: ";
        cin >> pilih;

        switch (pilih) {
        case 1: transaksiKasir(); break;
        case 2: tampilStruk(); break;
        case 3: cout << "Terima kasih!\n"; break;
        default: cout << "Pilihan salah!" << endl;
        }

    } while (pilih != 3);
}

// =========================
int main() {
    menuTransaksi();
    return 0;
}
