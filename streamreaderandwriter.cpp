#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    //deklarasi cariable baris untuk menyimpan data string
    string baris;

    //membuka file dalam mode menulis
    ofstream outfile;
    //menunjukan ke sebuah nama file
    outfile.open("contohfile.txt");

    cout << ">= menulis file, \'q\' untuk keluar" << endl;

    //unlimited loop untuk meulis file
    while (true)
    {
        cout << "- ";
        //,endapat setiap karakter dalam satu baris
        getline(cin, baris);
        //kondisi false jika baris hanya berisi karakter q
        if (baris == "q") break;
        //menulis dan memasukkan nilai dari variable baris ke dalamfile
        outfile << baris << endl;
    }
    //menutup file apabila telah selesai di tulis
    outfile.close();

    //membuka file dalam mode membaca
    ifstream infile;
    //menunjuk file dalam mode membaca
    infile.open("contohfile.txt");

    cout << endl << ">= membuka dan membaca file" << endl;
    //kondisi jika file ada
    if (infile.is_open())
    {
        //perulangan untuk memunculkan setiap baris
        while (getline(infile, baris))
        {
            cout << baris << endl;
        }
        //menutup file jika telah selesai di loop
        infile.close(); 
    }
    //kondisi jika file tidak ada
    else cout << "unable to open file";
    return 0;
}