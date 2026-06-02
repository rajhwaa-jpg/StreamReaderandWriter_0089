#include <iostream>
using namespace std;

int main()
{
    //membuat isi dari try untuk pengujian error
    try
    {
        cout << "selamat belajar di prodi ti umy" << endl;
        //throw 0.5 //melemparkan sebuah integer maka
        cout << "pernyataan tidak akan di tampilkan" << endl;
    }
    //kondisi jika throw yang bertipe data interger
    catch (int a)
    {
        cout << "pengecualian akan di eksekusi" << endl;
    }
    //kondisi jika throw bertipe data elain integer
    catch (...)
    {
        cout << "default pengecualian dieksekusi" << endl;
    }
    return 0;
}