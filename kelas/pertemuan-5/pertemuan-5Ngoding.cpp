#include <iostream>
using namespace std;


void cekNilai (int *arr) {
    cout << "elemen pertama adalah : " << arr[0] << endl;
}

// int ubahNilai(int &a, int b){
//     return a = b;
//     }
//     int a,b;
//     a = 5;
//     b = 20;

//     ubahNilai(a, b);
//     cout << a << endl;

int main() {
  
    //* untuk ngambil value dari variabel
    //& untuk mengambil address dari variabel
    // int array [100] = {1, 2, 3};

    // cekNilai(array);

    int a = 10;
    int *b = &a;
    
    cout << "Nilai a adalah : " << a << endl;
    cout << "alamat a adalah : " << &a << endl; 
    cout << "nilai b adalah : " << *b << endl;
    cout << "alamat b adalah : " << &b << endl; 

    // cout << a;

    // struct Address{
    //     string kota;
    //     string provinsi;
    //     string negara;
    //     };
    //     // deklarasi variabel dengan struct
    //     Address address1;

    //     // mengisi value address1  (dokumen aslinya)
    //     address1.kota = "Samarinda";
    //     address1.provinsi = "Kalimantan Timur";
    //     address1.negara = "Indonesia";

    //     // mengcopy value address1 ke address2
    //     address2 = address1;

    //     // mengganti property kota dari samarinda ke ikn
    //     address2.kota = "ikn";

    //     // value address1
    //     cout<< address1.kota <<endl;
    //     // value address2
    //     cout<< address2.kota <<endl;
}