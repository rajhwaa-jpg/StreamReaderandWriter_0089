#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Struktur untuk menyimpan data barang
struct Barang {
    int id;
    string nama;
    int harga;
    int stok;
};

// Kelas TokoElektronik
class TokoElektronik {
private:
    string etalase[3]; // Array private berkapasitas 3 elemen untuk etalase
    
public:
    // Constructor untuk mengisi data awal etalase
    TokoElektronik() {
        etalase[0] = "TV 55 Inch - Rp 5.000.000";
        etalase[1] = "Laptop Core i5 - Rp 8.000.000";
        etalase[2] = "Smartphone Android - Rp 3.500.000";
    }
    
    // Method untuk mengambil produk dari etalase dengan exception handling
    string ambilProduk(size_t nomorRak) {
        try {
            // Menggunakan .at() untuk akses array dengan pengecekan batas
            return etalase[nomorRak];
        }
        catch (out_of_range &e) {
            // Lempar error kustom jika indeks melewati batas
            throw string("Gagal Mengambil Barang : Rak nomor " + to_string(nomorRak) + " kosong atau tidak tersedia!");
        }
    }
};

// Fungsi untuk menampilkan menu utama
void tampilMenu() {
    cout << "\n================================" << endl;
    cout << "  TOKO ELEKTRONIK GIBRAN JAYA  " << endl;
    cout << "================================" << endl;
    cout << "1. Lihat Data Gudang" << endl;
    cout << "2. Tambah Barang" << endl;
    cout << "3. Update Barang" << endl;
    cout << "4. Hapus Barang" << endl;
    cout << "5. Simulasi Etalase" << endl;
    cout << "6. Keluar" << endl;
    cout << "================================" << endl;
    cout << "Pilihan: ";
}

// Fungsi untuk membaca dan menampilkan data dari file
void bacaGudang() {
    ifstream file("gudang.txt");
    
    if (file.is_open()) {
        cout << "\n--- DATA GUDANG ---" << endl;
        string line;
        bool ada = false;
        
        while (getline(file, line)) {
            if (!line.empty()) {
                cout << line << endl;
                ada = true;
            }
        }
        
        if (!ada) {
            cout << "Gudang masih kosong." << endl;
        }
        file.close();
    } else {
        cout << "File gudang.txt tidak ditemukan. Membuat file baru..." << endl;
        ofstream newFile("gudang.txt");
        newFile.close();
    }
}

// Fungsi untuk menambah barang ke gudang
void tambahBarang() {
    ofstream file("gudang.txt", ios::app);
    
    if (file.is_open()) {
        int id, harga, stok;
        string nama;
        
        cout << "\n--- TAMBAH BARANG ---" << endl;
        cout << "ID Barang: ";
        cin >> id;
        cin.ignore();
        
        cout << "Nama Barang: ";
        getline(cin, nama);
        
        cout << "Harga: ";
        cin >> harga;
        
        cout << "Stok: ";
        cin >> stok;
        
        file << id << " | " << nama << " | " << harga << " | " << stok << endl;
        file.close();
        
        cout << "Barang berhasil ditambahkan!" << endl;
    }
}

// Fungsi untuk mengupdate barang
void updateBarang() {
    int idCari;
    
    cout << "\n--- UPDATE BARANG ---" << endl;
    cout << "Masukkan ID Barang yang ingin diupdate: ";
    cin >> idCari;
    cin.ignore();
    
    ifstream fileIn("gudang.txt");
    ofstream fileOut("gudang_temp.txt");
    
    string line;
    bool ditemukan = false;
    
    while (getline(fileIn, line)) {
        if (!line.empty()) {
            int id;
            sscanf(line.c_str(), "%d", &id);
            
            if (id == idCari) {
                string nama;
                int harga, stok;
                
                cout << "Nama Barang Baru: ";
                getline(cin, nama);
                
                cout << "Harga Baru: ";
                cin >> harga;
                
                cout << "Stok Baru: ";
                cin >> stok;
                
                fileOut << id << " | " << nama << " | " << harga << " | " << stok << endl;
                ditemukan = true;
            } else {
                fileOut << line << endl;
            }
        }
    }
    
    fileIn.close();
    fileOut.close();
    
    if (ditemukan) {
        remove("gudang.txt");
        rename("gudang_temp.txt", "gudang.txt");
        cout << "Barang berhasil diupdate!" << endl;
    } else {
        remove("gudang_temp.txt");
        cout << "ID Barang tidak ditemukan!" << endl;
    }
}

// Fungsi untuk menghapus barang
void hapusBarang() {
    int idCari;
    
    cout << "\n--- HAPUS BARANG ---" << endl;
    cout << "Masukkan ID Barang yang ingin dihapus: ";
    cin >> idCari;
    cin.ignore();
    
    ifstream fileIn("gudang.txt");
    ofstream fileOut("gudang_temp.txt");
    
    string line;
    bool ditemukan = false;
    
    while (getline(fileIn, line)) {
        if (!line.empty()) {
            int id;
            sscanf(line.c_str(), "%d", &id);
            
            if (id == idCari) {
                ditemukan = true;
            } else {
                fileOut << line << endl;
            }
        }
    }
    
    fileIn.close();
    fileOut.close();
    
    if (ditemukan) {
        remove("gudang.txt");
        rename("gudang_temp.txt", "gudang.txt");
        cout << "Barang berhasil dihapus!" << endl;
    } else {
        remove("gudang_temp.txt");
        cout << "ID Barang tidak ditemukan!" << endl;
    }
}

// Fungsi untuk simulasi etalase dengan exception handling
void simulasiEtalase() {
    TokoElektronik toko;
    
    cout << "\n--- SIMULASI ETALASE ---" << endl;
    
    // Skenario 1: Pengambilan barang di rak indeks 1 (harus sukses)
    cout << "\nSkenario 1: Mengambil barang dari Rak nomor 1" << endl;
    try {
        string produk = toko.ambilProduk(1);
        cout << "Berhasil mengambil: " << produk << endl;
    }
    catch (string error) {
        cout << error << endl;
    }
    
    // Skenario 2: Pengambilan barang di rak indeks 5 (harus gagal)
    cout << "\nSkenario 2: Mengambil barang dari Rak nomor 5" << endl;
    try {
        string produk = toko.ambilProduk(5);
        cout << "Berhasil mengambil: " << produk << endl;
    }
    catch (string error) {
        cout << error << endl;
    }
}

// Fungsi main
int main() {
    int pilihan;
    bool running = true;
    
    while (running) {
        tampilMenu();
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1:
                bacaGudang();
                break;
            case 2:
                tambahBarang();
                break;
            case 3:
                updateBarang();
                break;
            case 4:
                hapusBarang();
                break;
            case 5:
                simulasiEtalase();
                break;
            case 6:
                cout << "\nTerima kasih telah menggunakan sistem Gibran Jaya!" << endl;
                running = false;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
    
    return 0;
} 