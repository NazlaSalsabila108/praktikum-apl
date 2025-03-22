#include <iostream> 

using namespace std;


    // //cara 1 buat struct 
    // struct mahasiswa
    // {
    //     /*data*/
    //     string nama; 
    //     int nim;
    // };

    // //cara 2 buat struct
    // typedef struct 
    // {
    //     /*data*/
    //     string nama;
    //     int nim;
    // };



int main() {
    // struct Mahasiswa
    // {
    //     /*data*/
    //     string nama;
    //     int nim;
    // };

    struct Nilai
    {
        int uts;
        int uas;

    };

    struct Data
    {
        string nama;
        int nim; 
    };

    struct Mahasiswa
    {   
        Data data;       
        Nilai nilai;
    };

    Mahasiswa mahasiswa[10];
    //cara memberikan nilai ke struct array
    mahasiswa[0].data.nama = "shandy";
    mahasiswa[1].data.nama = "ade";

    //cara menampilkan data dari struct array
    cout << mahasiswa[0].data.nama << endl;
    cout << mahasiswa[1].data.nama << endl;


    // Mahasiswa mahasiswa;
    // //struct utama      struct kedua        nama variabel
    // mahasiswa.          data.               nama                = "shandy";
    // mahasiswa.nilai.uts = 123;
    // cout << mahasiswa.nilai.uts;
    // // cout << mahasiswa.data.nim;




    //struct mahasiswa mhs;
    //nama struk        //nama deklarasi
    // Mahasiswa           mahasiswa;

    // // menambahkan data du strcut Mahasiswa
    // mahasiswa.nama = "shandy";
    // mahasiswa.nim = 1234;

    // //menampilkan elemen di dalam struct
    // cout << mahasiswa.nama << endl;
    // cout << mahasiswa.nim;

    return 0;
    }
