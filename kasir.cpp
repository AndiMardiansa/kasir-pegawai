#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* ================================================================
   PROJECT: APLIKASI KASIR PEGAWAI
   Berisi 10 Materi Praktikum Pemrograman:
   1. Sekuen
   2. Kondisional
   3. Perulangan
   4. Perulangan (Iteratif - Rekursif)
   5. Rekursi
   6. Array Satu Dimensi
   7. Sorting dan Searching
   8. Array Dua Dimensi
   9. Array 1-2 Dimensi
   10. Pointer
   ================================================================ */

// ---------- KONSTANTA & STRUCT (dipakai berbagai praktikum) ----------
const int MAX_BARANG = 5;
const int JUMLAH_CABANG = 3;
const int JUMLAH_HARI = 7;
const int JUMLAH_KATEGORI = 3;

struct Barang {
    string nama;
    int harga;
    int stok;
};

// PRAKTIKUM 6: ARRAY SATU DIMENSI
// Array of struct berisi data barang yang dijual di kasir
Barang dataBarang[MAX_BARANG] = {
    {"Indomie Goreng", 3500, 100},
    {"Aqua 600ml", 4000, 80},
    {"Beras 5kg", 65000, 30},
    {"Gula Pasir 1kg", 15000, 50},
    {"Minyak Goreng 1L", 18000, 40}
};

string namaCabang[JUMLAH_CABANG] = {"Cabang A", "Cabang B", "Cabang C"};
string namaHari[JUMLAH_HARI] = {"Senin","Selasa","Rabu","Kamis","Jumat","Sabtu","Minggu"};
string namaKategori[JUMLAH_KATEGORI] = {"Makanan","Minuman","Lainnya"};

// PRAKTIKUM 8: ARRAY DUA DIMENSI
int rekapPenjualan[JUMLAH_HARI][JUMLAH_KATEGORI];

// PRAKTIKUM 9: ARRAY 1-2 DIMENSI
// (menggabungkan array 1D dataBarang dengan array 2D stokPerCabang)
int stokPerCabang[MAX_BARANG][JUMLAH_CABANG];

// ---------- PROTOTYPE FUNGSI ----------
void inputDataKasir(string &namaKasir, string &tanggal);
bool cekMember();
int hitungDiskon(int total, bool member);
void tampilkanDaftarBarang();
int totalIteratif(int harga[], int qty[], int n);
int totalRekursif(int harga[], int qty[], int n);
void tampilkanBarangRekursif(int index);
void bubbleSortHarga(Barang arr[], int n);
int linearSearchNama(Barang arr[], int n, string nama);
void inputRekapPenjualan();
void tampilkanRekapPenjualan();
void isiStokPerCabang();
void tampilkanStokPerCabang();
void tampilkanBarangPointer(Barang *ptr, int n);
void updateStokPointer(int *stokPtr, int tambah);
void transaksiKasir();
void tampilStruk();
void menuUtama();

// ================================================================
// PRAKTIKUM 1: SEKUEN
// Sekumpulan instruksi yang dijalankan berurutan dari atas ke bawah,
// tanpa ada percabangan (if) maupun perulangan (loop).
// ================================================================
void inputDataKasir(string &namaKasir, string &tanggal) {
    cout << "\n=== DATA KASIR (Praktikum 1: Sekuen) ===\n";
    cout << "Nama Kasir : ";
    getline(cin, namaKasir);
    cout << "Tanggal    : ";
    getline(cin, tanggal);
    cout << "Data kasir berhasil disimpan.\n";
    // Perhatikan: baris-baris di atas dijalankan berurutan (sekuensial),
    // tidak ada pengecekan kondisi (if) maupun pengulangan (loop).
}

// ================================================================
// PRAKTIKUM 2: KONDISIONAL
// Menggunakan if-else untuk menentukan apakah pelanggan member
// (mendapat diskon) atau bukan.
// ================================================================
bool cekMember() {
    char jawaban;
    cout << "\n=== Praktikum 2: Kondisional ===\n";
    cout << "Apakah pelanggan member? (y/n): ";
    cin >> jawaban;
    cin.ignore();

    if (jawaban == 'y' || jawaban == 'Y') {
        cout << "Pelanggan adalah MEMBER, mendapat diskon 10%.\n";
        return true;
    } else {
        cout << "Pelanggan BUKAN member.\n";
        return false;
    }
}

int hitungDiskon(int total, bool member) {
    // if-else sederhana: kondisi (member atau tidak) menentukan besar diskon
    if (member) {
        return total * 10 / 100;
    } else {
        return 0;
    }
}

// ================================================================
// PRAKTIKUM 3: PERULANGAN
// Menggunakan for-loop untuk menampilkan seluruh isi array dataBarang.
// (Contoh while-loop untuk perulangan lain ada di transaksiKasir())
// ================================================================
void tampilkanDaftarBarang() {
    cout << "\n=== Praktikum 3 & 6: Perulangan + Array 1 Dimensi ===\n";
    cout << "Daftar Barang yang Dijual:\n";
    cout << "Kode | Nama                | Harga   | Stok\n";
    // for-loop mengulang sebanyak elemen array (MAX_BARANG)
    for (int i = 0; i < MAX_BARANG; i++) {
        cout << i + 1 << "    | " << dataBarang[i].nama
             << " | Rp" << dataBarang[i].harga
             << " | " << dataBarang[i].stok << endl;
    }
}

// ================================================================
// PRAKTIKUM 4: PERULANGAN (ITERATIF - REKURSIF)
// Menghitung total belanja dengan DUA cara berbeda untuk kasus yang
// SAMA, supaya terlihat perbandingan pendekatan iteratif (loop)
// dengan pendekatan rekursif (memanggil dirinya sendiri).
// ================================================================

// Versi ITERATIF: menggunakan for-loop
int totalIteratif(int harga[], int qty[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += harga[i] * qty[i];
    }
    return total;
}

// Versi REKURSIF: fungsi memanggil dirinya sendiri
// Basis   : jika n == 0, total = 0 (berhenti)
// Rekurens: total = (harga[n-1]*qty[n-1]) + totalRekursif(..., n-1)
int totalRekursif(int harga[], int qty[], int n) {
    if (n == 0) {
        return 0; // basis rekursi
    }
    return (harga[n - 1] * qty[n - 1]) + totalRekursif(harga, qty, n - 1);
}

// ================================================================
// PRAKTIKUM 5: REKURSI
// Contoh rekursi murni: menampilkan daftar barang secara TERBALIK
// (dari index terakhir ke index pertama) menggunakan rekursi.
// ================================================================
void tampilkanBarangRekursif(int index) {
    // Basis rekursi: berhenti saat index kurang dari 0
    if (index < 0) {
        return;
    }
    cout << index + 1 << ". " << dataBarang[index].nama
         << " - Rp" << dataBarang[index].harga << endl;
    // Panggil dirinya sendiri dengan index-1 (mundur satu langkah)
    tampilkanBarangRekursif(index - 1);
}

// ================================================================
// PRAKTIKUM 7: SORTING DAN SEARCHING
// Sorting  : Bubble Sort berdasarkan harga (ascending)
// Searching: Linear Search berdasarkan nama barang
// ================================================================
void bubbleSortHarga(Barang arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].harga > arr[j + 1].harga) {
                // tukar (swap) posisi dua elemen
                Barang temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int linearSearchNama(Barang arr[], int n, string nama) {
    for (int i = 0; i < n; i++) {
        if (arr[i].nama == nama) {
            return i; // ditemukan, kembalikan index
        }
    }
    return -1; // tidak ditemukan
}

// ================================================================
// PRAKTIKUM 8: ARRAY DUA DIMENSI
// rekapPenjualan[hari][kategori] menyimpan jumlah barang terjual
// ================================================================
void inputRekapPenjualan() {
    cout << "\n=== Praktikum 8: Array Dua Dimensi ===\n";
    for (int h = 0; h < JUMLAH_HARI; h++) {
        for (int k = 0; k < JUMLAH_KATEGORI; k++) {
            cout << "Jumlah terjual [" << namaHari[h] << "][" << namaKategori[k] << "]: ";
            cin >> rekapPenjualan[h][k];
        }
    }
}

void tampilkanRekapPenjualan() {
    cout << "\n=== Rekap Penjualan Mingguan (Array 2 Dimensi) ===\n";
    cout << "Hari      ";
    for (int k = 0; k < JUMLAH_KATEGORI; k++) cout << " | " << namaKategori[k];
    cout << " | Total\n";

    for (int h = 0; h < JUMLAH_HARI; h++) {
        int totalHari = 0;
        cout << namaHari[h] << "   ";
        for (int k = 0; k < JUMLAH_KATEGORI; k++) {
            cout << " | " << rekapPenjualan[h][k];
            totalHari += rekapPenjualan[h][k];
        }
        cout << " | " << totalHari << endl;
    }
}

// ================================================================
// PRAKTIKUM 9: ARRAY 1-2 DIMENSI
// Menggabungkan array 1D (dataBarang) dengan array 2D (stokPerCabang).
// Setiap BARIS pada array 2D mewakili satu barang dari array 1D,
// setiap KOLOM mewakili stok barang tersebut di suatu cabang.
// ================================================================
void isiStokPerCabang() {
    cout << "\n=== Praktikum 9: Array 1-2 Dimensi ===\n";
    for (int i = 0; i < MAX_BARANG; i++) {          // baris = index array 1D dataBarang
        cout << "\nBarang: " << dataBarang[i].nama << endl;
        for (int c = 0; c < JUMLAH_CABANG; c++) {   // kolom = cabang (array 2D)
            cout << "  Stok di " << namaCabang[c] << ": ";
            cin >> stokPerCabang[i][c];
        }
    }
}

void tampilkanStokPerCabang() {
    cout << "\n=== Laporan Stok per Cabang (Gabungan Array 1D & 2D) ===\n";
    cout << "Nama Barang          ";
    for (int c = 0; c < JUMLAH_CABANG; c++) cout << " | " << namaCabang[c];
    cout << " | Total Stok\n";

    for (int i = 0; i < MAX_BARANG; i++) {
        int totalStokBarang = 0;
        cout << dataBarang[i].nama;
        for (int c = 0; c < JUMLAH_CABANG; c++) {
            cout << " | " << stokPerCabang[i][c];
            totalStokBarang += stokPerCabang[i][c];
        }
        cout << " | " << totalStokBarang << endl;
    }
}

// ================================================================
// PRAKTIKUM 10: POINTER
// Menggunakan pointer untuk mengakses array of struct (pointer
// arithmetic), dan pointer untuk mengubah nilai variabel lewat
// alamat memorinya secara langsung.
// ================================================================
void tampilkanBarangPointer(Barang *ptr, int n) {
    cout << "\n=== Praktikum 10: Pointer ===\n";
    for (int i = 0; i < n; i++) {
        // (ptr + i) menunjuk ke elemen ke-i, ->nama mengakses anggota struct
        cout << (ptr + i)->nama << " - Rp" << (ptr + i)->harga << endl;
    }
}

void updateStokPointer(int *stokPtr, int tambah) {
    // *stokPtr mengambil NILAI yang ditunjuk oleh pointer, lalu diubah
    // langsung di alamat memori aslinya (bukan salinan/copy)
    *stokPtr = *stokPtr + tambah;
}

// ================================================================
// FITUR UTAMA: TRANSAKSI KASIR
// Menggabungkan Praktikum 1 (sekuen), 2 (kondisional), 3 (perulangan),
// dan 4 (iteratif-rekursif) dalam satu alur transaksi nyata.
// ================================================================
void transaksiKasir() {
    ofstream struk("struk.txt");

    string namaKasir, tanggal;
    inputDataKasir(namaKasir, tanggal);          // PRAKTIKUM 1

    bool member = cekMember();                    // PRAKTIKUM 2

    tampilkanDaftarBarang();

    int jumlahBarang;
    cout << "\nJumlah jenis barang yang dibeli: ";
    cin >> jumlahBarang;
    cin.ignore();

    int harga[20], qty[20];
    string nama[20];

    // PRAKTIKUM 3: PERULANGAN (for-loop untuk input tiap barang)
    for (int i = 0; i < jumlahBarang; i++) {
        int kode;
        cout << "\nBarang ke-" << i + 1 << endl;
        cout << "Pilih kode barang (1-" << MAX_BARANG << "): ";
        cin >> kode;
        cout << "Jumlah beli: ";
        cin >> qty[i];
        cin.ignore();

        kode = kode - 1; // index array dimulai dari 0
        nama[i] = dataBarang[kode].nama;
        harga[i] = dataBarang[kode].harga;
    }

    // PRAKTIKUM 4: bandingkan hasil hitung iteratif dan rekursif (hasilnya harus sama)
    int totalIter = totalIteratif(harga, qty, jumlahBarang);
    int totalRek = totalRekursif(harga, qty, jumlahBarang);

    cout << "\nTotal (hitung iteratif) : " << totalIter << endl;
    cout << "Total (hitung rekursif) : " << totalRek << endl;

    int diskon = hitungDiskon(totalIter, member);   // PRAKTIKUM 2
    int totalBayar = totalIter - diskon;

    int bayar;
    cout << "Total Setelah Diskon : " << totalBayar << endl;
    cout << "Uang Bayar : ";
    cin >> bayar;

    // PRAKTIKUM 3: while-loop untuk validasi input (contoh perulangan lain selain for)
    while (bayar < totalBayar) {
        cout << "Uang tidak cukup! Masukkan lagi: ";
        cin >> bayar;
    }

    struk << "========= STRUK PEMBELIAN =========\n";
    struk << "Kasir   : " << namaKasir << endl;
    struk << "Tanggal : " << tanggal << endl;
    struk << "Member  : " << (member ? "Ya (Diskon 10%)" : "Tidak") << endl;
    struk << "----------------------------\n";
    for (int i = 0; i < jumlahBarang; i++) {
        struk << nama[i] << " x" << qty[i] << " = Rp" << harga[i] * qty[i] << endl;
    }
    struk << "----------------------------\n";
    struk << "Subtotal  : " << totalIter << endl;
    struk << "Diskon    : " << diskon << endl;
    struk << "TOTAL     : " << totalBayar << endl;
    struk << "BAYAR     : " << bayar << endl;
    struk << "KEMBALIAN : " << bayar - totalBayar << endl;
    struk << "=================================\n";
    struk.close();

    cout << "\nTransaksi berhasil! Struk disimpan ke struk.txt\n";
}

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

// ================================================================
// MENU UTAMA
// Menggabungkan seluruh 10 praktikum ke dalam satu aplikasi kasir
// ================================================================
void menuUtama() {
    int pilih;
    do {
        cout << "\n=====================================\n";
        cout << "     APLIKASI KASIR PEGAWAI\n";
        cout << "=====================================\n";
        cout << "1. Transaksi Kasir\n";
        cout << "2. Lihat Struk Terakhir\n";
        cout << "3. Daftar Barang (Array 1D)\n";
        cout << "4. Tampilkan Barang Mundur (Rekursi)\n";
        cout << "5. Sorting & Searching Barang\n";
        cout << "6. Rekap Penjualan Mingguan (Array 2D)\n";
        cout << "7. Laporan Stok per Cabang (Array 1D & 2D)\n";
        cout << "8. Demo Pointer\n";
        cout << "9. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
        case 1:
            transaksiKasir();
            break;
        case 2:
            tampilStruk();
            break;
        case 3:
            tampilkanDaftarBarang();
            break;
        case 4:
            tampilkanBarangRekursif(MAX_BARANG - 1);
            break;
        case 5: {
            Barang temp[MAX_BARANG];
            for (int i = 0; i < MAX_BARANG; i++) temp[i] = dataBarang[i];

            bubbleSortHarga(temp, MAX_BARANG);
            cout << "\nBarang terurut berdasarkan harga:\n";
            for (int i = 0; i < MAX_BARANG; i++) {
                cout << temp[i].nama << " - Rp" << temp[i].harga << endl;
            }

            string cari;
            cout << "\nCari barang berdasarkan nama: ";
            getline(cin, cari);
            int idx = linearSearchNama(dataBarang, MAX_BARANG, cari);
            if (idx != -1) {
                cout << "Ditemukan! Harga: Rp" << dataBarang[idx].harga
                     << ", Stok: " << dataBarang[idx].stok << endl;
            } else {
                cout << "Barang tidak ditemukan.\n";
            }
            break;
        }
        case 6:
            inputRekapPenjualan();
            tampilkanRekapPenjualan();
            break;
        case 7:
            isiStokPerCabang();
            tampilkanStokPerCabang();
            break;
        case 8: {
            tampilkanBarangPointer(dataBarang, MAX_BARANG);
            cout << "\nTambah stok barang pertama (contoh pointer):\n";
            int tambah;
            cout << "Tambah stok sebanyak: ";
            cin >> tambah;
            updateStokPointer(&dataBarang[0].stok, tambah);
            cout << "Stok baru " << dataBarang[0].nama << ": " << dataBarang[0].stok << endl;
            break;
        }
        case 9:
            cout << "Terima kasih!\n";
            break;
        default:
            cout << "Pilihan salah!\n";
        }
    } while (pilih != 9);
}

int main() {
    menuUtama();
    return 0;
}
