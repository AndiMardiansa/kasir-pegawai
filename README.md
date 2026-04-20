# Sistem Kasir Digital - App Kasir

Aplikasi POS (Point of Sale) berbasis terminal yang dibangun dengan C++ untuk memudahkan transaksi penjualan.

## Fitur Utama

✓ **Manajemen Produk** - Menampilkan daftar produk dengan harga dan stok  
✓ **Keranjang Belanja** - Tambah/hapus item ke keranjang belanja  
✓ **Proses Checkout** - Transaksi pembayaran dengan perhitungan kembalian otomatis  
✓ **Struk Pembelian** - Cetak struk dengan detail transaksi lengkap  
✓ **Manajemen Stok** - Tracking stok produk secara real-time

## File Struktur

```
app-kasir/
├── main.cpp           # File utama dengan logic aplikasi POS
├── Product.h          # Class untuk data produk
├── Cart.h             # Class untuk keranjang belanja
├── Transaction.h      # Class untuk pemrosesan transaksi
├── Makefile           # Build configuration
├── kasir              # Executable (hasil kompilasi)
└── README.md          # File ini
```

## Persyaratan

- C++11 atau lebih tinggi
- g++ compiler
- Linux/Unix terminal

## Cara Menggunakan

### 1. Kompilasi Program

Gunakan salah satu metode berikut:

**Dengan g++ langsung:**

```bash
g++ -std=c++11 -o kasir main.cpp
```

**Dengan Make (jika tersedia):**

```bash
make
```

### 2. Menjalankan Program

```bash
./kasir
```

### 3. Menu Operasional

Setelah program berjalan, Anda akan melihat menu utama dengan pilihan:

1. **Lihat Menu Produk** - Menampilkan daftar semua produk tersedia
2. **Tambah ke Keranjang** - Memilih produk dan jumlah yang ingin dibeli
3. **Lihat Keranjang** - Menampilkan item yang ada di keranjang belanja
4. **Hapus Item dari Keranjang** - Menghapus produk dari keranjang
5. **Checkout** - Melakukan pembayaran dan mencetak struk
6. **Keluar** - Keluar dari program

## Daftar Produk Default

| ID  | Produk        | Harga     | Stok |
| --- | ------------- | --------- | ---- |
| 1   | Kopi Hitam    | Rp 15.000 | 50   |
| 2   | Teh Manis     | Rp 10.000 | 60   |
| 3   | Jus Jeruk     | Rp 18.000 | 40   |
| 4   | Nasi Goreng   | Rp 35.000 | 30   |
| 5   | Mie Goreng    | Rp 30.000 | 35   |
| 6   | Bakso         | Rp 28.000 | 25   |
| 7   | Soto Ayam     | Rp 32.000 | 20   |
| 8   | Lumpia Goreng | Rp 12.000 | 45   |
| 9   | Perkedel      | Rp 8.000  | 70   |
| 10  | Tahu Goreng   | Rp 9.000  | 60   |

## Contoh Penggunaan

### Skenario 1: Membeli 2 Produk

1. Pilih menu **1** untuk lihat produk
2. Pilih menu **2** untuk tambah ke keranjang
3. Masukkan ID produk: `1` (Kopi Hitam)
4. Masukkan jumlah: `2`
5. Ulangi langkah 2-4 untuk produk kedua (ID `4` - Nasi Goreng, qty `1`)
6. Pilih menu **3** untuk lihat keranjang
7. Pilih menu **5** untuk checkout
8. Masukkan jumlah pembayaran: `60000`
9. Struk otomatis dicetak

## Class Hierarchy

```
Product                    <- Menyimpan data produk
  ↓
CartItem (struct)          <- Item di dalam cart
  ↓
Cart                       <- Keranjang belanja
  ↓
Transaction                <- Proses transaksi
  ↓
POS                        <- Main controller aplikasi
```

## Fitur Teknis

- **Object-Oriented Design** - Menggunakan class dan inheritance
- **STL Containers** - Vector untuk menyimpan data produk dan item
- **Date & Time** - Timestamp otomatis pada setiap transaksi
- **Formatted Output** - Tampilan interface yang rapi dengan ASCII art
- **Input Validation** - Validasi stok dan jumlah pembayaran

## Pengembangan Lebih Lanjut

Ide-ide untuk enhancement:

- Simpan data produk ke file (database)
- Laporan penjualan harian/bulanan
- Diskon dan promo otomatis
- Authentication/Login kasir
- Multi-currency support
- Barcode scanner integration

## Lisensi

Free to use for educational purposes

---

**Dibuat dengan C++** | **2024**
