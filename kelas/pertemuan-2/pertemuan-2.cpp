#include <iostream>

using namespace std;

// int main () {
    //int mahasiswa[2]
    //int mahasiswa[2]
    // string nama[4]= {"nazla", "desya", "ina"};
    
    // // int ukuran = sizeof(angka)/sizeof(angka[0]);
    // int angka[5];
    // angka[0] = 10;
    // angka[1] = 19;
    // angka[2] = 30;
    // angka[3] = 40;
    // angka[4] = 50;

//  int ukuran = sizeof(angka)/sizeof(angka[0]);

//  for(int i = 0; i < ukuran; i++ > ) {
//     cout << angka[i] << endl;
//  }
 
//  for(string y : nama) {
//     cout << y << endl;
//  }


    // cout << nama[0] << endl;
    // cout << angka[3] << endl;

    // cout << sizeof(nama) << endl;
    // cout << sizeof(nama[0]) << endl;
    // int ukuran = sizeof(angka)/sizeof(angka[0]);

    // cout << "Banyak elemen array angka adalah"<< ukuran << endl;
// }

// int matriks[2][2] = {
//     {1, 2},
//     {3, 4}
//     };

// cout << matriks[0][1] << endl;
// cout << matriks[1][1] << endl;
// cout << matriks[1][0] << endl;
// cout << matriks[0][0] << endl;


int panjang = 0; //menentukan panjang array 
string buah[100];

int total_array = sizeof(buah) / sizeof(string);
int pilihan, index; 

do {
    cout << "1. liat data"; << endl;
    cout << "2. tambah data"; << endl;
    cout << "3. edit data"; << endl;
    cout << "4. hapus data"; << endl;
    cin >> pilihan;

    switch (pilihan)
    {
        case 1: 
        if(panjang == 0) {
            cout << "Belom ada buah:" << endl;
            else {
                for (int 1 = 0; i < panjang; i++) {
                    cout << i + 1 << ". " << buah[i] << endl;
                }
            }
            break; 
            
        case 2: 
        if (panjang < total_array) {
            cout << "masukkan nama buah: ";
            cin.ignore();
            getline(cin, buah[panjang]);
            panjang++;
            cout << "Buah berhasil ditambah" << endl;
        }
        }
    }
}




