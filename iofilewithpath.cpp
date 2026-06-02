#include<iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    //deklarasi variable baris dan namafile
    string bari, namafile;

    //membuat inpput untuk menangkap nama file
    cout << "masukkan nama file : ";
    cin >> namafile;

    //membuat file falam mode menulis
    ofstream outfile;
    //menunjuk ke sebuah nama file dengan ekstensi txt
    outfile.open(namafile + ".txt", ios::out);

    cout << ">= menulis file, \'q\' untuk keluar" << endl;

    //looping untuk menulis isi file
    while (true)
    {
        cout << "- ";
        //mendapatkan setiap karakter dlam satu baris
        getline(cin, baris);
        //kondisi jika baris hanya berisi huruf q
        if (baris == "q") break;
        //menulis dan memasukkan nilai dari baris ke dalam file
        outfile << baris << endl;
    }
    //menutup file apabila telah selesai di tulis
    outfile.close();

    //membuka file dalam mode membaca
    ifstream infile;

    //menunjuk ke sebuah file dengan eksistensi .txt
    infile.open(namafile + ".txt", ios::in);
}