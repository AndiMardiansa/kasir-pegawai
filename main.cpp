#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Barang {
    string nama;
    int harga;
    int stok;
};

// =========================
void tampilStok() {
    ifstream file("stok.txt");
    if (!file.is_open()) {
        cout << "Data stok belum tersedia!" << endl;
        return;
    }

    string baris;
    cout << "\n=== DAFTAR STOK BARANG ===\n";
    while (getline(file, baris)) {
        cout << baris << endl;
    }

    file.close();
}

// =========================
void tambahStok() {
    int jumlah;
    cout << "Masukkan jumlah barang: ";
    cin >> jumlah;
    cin.ignore();

    ofstream file("stok.txt", ios::app);
    Barang brg;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nBarang ke-" << i + 1 << endl;
        cout << "Nama Barang : ";
        getline(cin, brg.nama);
        cout << "Harga       : ";
        cin >> brg.harga;
        cout << "Stok        : ";
        cin >> brg.stok;
        cin.ignore();

        file << brg.nama << "|" << brg.harga << "|" << brg.stok << endl;
    }

    file.close();
    cout << "\nStok berhasil ditambahkan!" << endl;
}

// =========================
void transaksiKasir() {
    ifstream fileStok("stok.txt");
    if (!fileStok.is_open()) {
        cout << "Stok kosong! Tambahkan stok dulu." << endl;
        return;
    }

    Barang daftar[100];
    int totalBarang = 0;

    while (fileStok >> daftar[totalBarang].nama) {
        fileStok.ignore();
        fileStok >> daftar[totalBarang].harga;
        fileStok.ignore();
        fileStok >> daftar[totalBarang].stok;
        totalBarang++;
    }
    fileStok.close();

    ofstream struk("struk.txt");
    int totalBayar = 0;

    struk << "========= STRUK PEMBELIAN =========\n";

    int beli;
    cout << "Jumlah jenis barang dibeli: ";
    cin >> beli;

    for (int i = 0; i < beli; i++) {
        string cari;
        int qty;
        cout << "\nNama barang: ";
        cin >> cari;
        cout << "Jumlah beli: ";
        cin >> qty;

        for (int j = 0; j < totalBarang; j++) {
            if (daftar[j].nama == cari && daftar[j].stok >= qty) {
                int subtotal = daftar[j].harga * qty;
                daftar[j].stok -= qty;
                totalBayar += subtotal;

                struk << "Barang  : " << cari << endl;
                struk << "Harga   : " << daftar[j].harga << endl;
                struk << "Jumlah  : " << qty << endl;
                struk << "Subtotal: " << subtotal << endl;
                struk << "----------------------------\n";
            }
        }
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

    ofstream update("stok.txt");
    for (int i = 0; i < totalBarang; i++) {
        update << daftar[i].nama << "|" << daftar[i].harga << "|" << daftar[i].stok << endl;
    }
    update.close();

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
void menuKasir() {
    int pilih;
    char ulang;

    do {
        cout << "\n====================\n";
        cout << "MENU KASIR\n";
        cout << "====================\n";
        cout << "1. Tambah Stok Barang\n";
        cout << "2. Lihat Stok Barang\n";
        cout << "3. Transaksi\n";
        cout << "4. Lihat Struk\n";
        cout << "5. Keluar\n";
        cout << "Pilih Menu: ";
        cin >> pilih;

        switch (pilih) {
        case 1: tambahStok(); break;
        case 2: tampilStok(); break;
        case 3: transaksiKasir(); break;
        case 4: tampilStruk(); break;
        case 5: return;
        default: cout << "Pilihan salah!" << endl;
        }

        cout << "\nUlangi menu? (y/n): ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');
}

// =========================
int main() {
    menuKasir();
    return 0;
}