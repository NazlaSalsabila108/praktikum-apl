#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int max_coba = 3;
const int max_pasien = 100;
const int max_pengguna = 50;

struct RiwayatObat {
    string diagnosis;
    string riwayatObat;
};

struct Pasien {
    string nama;
    int umur;
    RiwayatObat riwayat;
};

struct Akun {
    string username;
    string password;
    string role;
};

void registrasi(Akun *pengguna, int &jumlahPengguna); 
bool login(Akun *pengguna, int jumlahPengguna, string &role); 
void tambahPasien(Pasien *dataPasien, int &hitungPasien); 
void tampilkanDataPasien(Pasien *dataPasien, int hitungPasien); 
void updatePasien(Pasien *pasien); 
void hapusPasien(Pasien *dataPasien, int &hitungPasien); 
void tampilkanDataPasienRekursif(Pasien *dataPasien, int index, int hitungPasien); 
void tampilkanDataPasienRekursif(Pasien *dataPasien, int hitungPasien); 
void sortPasien(Pasien *dataPasien, int hitungPasien, int metode);

int main() {
    Akun pengguna[max_pengguna];
    int jumlahPengguna = 0;

    Pasien dataPasien[max_pasien];
    int hitungPasien = 0;

    while (true) {
        int menuUtama;
        cout << "Menu Utama:\n";
        cout << "1. Registrasi\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> menuUtama;

        if (menuUtama == 3) {
            cout << "Program berhenti. Terimakasih sudah mengakses layanan kami\n";
            break;
        }

        if (menuUtama == 1) {
            registrasi(pengguna, jumlahPengguna);
        } else if (menuUtama == 2) {
            string role;
            bool loginBerhasil = login(pengguna, jumlahPengguna, role);

            if (!loginBerhasil) {
                cout << "Terlalu banyak percobaan login yang gagal. Keluar program.\n";
                break;
            }

            while (true) {
                int pilihan;
                cout << "\nSilahkan pilih menu yang anda butuhkan:\n";
                if (role == "admin") {
                    cout << "1. Tambah Pasien\n";
                    cout << "2. Tampilkan Data Pasien\n";
                    cout << "3. Update Pasien\n";
                    cout << "4. Hapus Pasien\n";
                    cout << "5. Keluar\n";
                } else if (role == "user") {
                    cout << "1. Tampilkan Data Pasien\n";
                    cout << "2. Keluar\n";
                }
                cout << "Masukkan pilihan Anda: ";
                cin >> pilihan;

                if (role == "admin") {
                    if (pilihan == 1) {
                        tambahPasien(dataPasien, hitungPasien);
                    } else if (pilihan == 2) {
                        int metodeSort;
                        cout << "Pilih metode pengurutan data pasien yang diinginkan:\n";
                        cout << "1. Pengurutan nama secara descending\n";
                        cout << "2. Pengurutan umur secara ascending\n";
                        cout << "Masukkan pilihan Anda: ";
                        cin >> metodeSort;

                        sortPasien(dataPasien, hitungPasien, metodeSort); 
                        tampilkanDataPasien(dataPasien, hitungPasien);
                    } else if (pilihan == 3) {
                        string nama;
                        cout << "Masukkan nama pasien yang akan diupdate: ";
                        cin.ignore();
                        getline(cin, nama);

                        bool ditemukan = false;
                        for (int i = 0; i < hitungPasien; ++i) {
                            if (dataPasien[i].nama == nama) {
                                updatePasien(&dataPasien[i]); 
                                ditemukan = true;
                                break;
                            }
                        }

                        if (!ditemukan) {
                            cout << "Pasien tidak ditemukan." << endl;
                        }
                    } else if (pilihan == 4) {
                        hapusPasien(dataPasien, hitungPasien);
                    } else if (pilihan == 5) {
                        cout << "Berhasil Logout." << endl;
                        break;
                    } else {
                        cout << "Pilihan tidak valid. Mohon coba lagi." << endl;
                    }
                } else if (role == "user") {
                    if (pilihan == 1) {
                        int metodeSort;
                        cout << "Pilih metode pengurutan:\n";
                        cout << "1. Nama secara descending\n";
                        cout << "2. Umur secara ascending\n";
                        cout << "Masukkan pilihan Anda: ";
                        cin >> metodeSort;

                        sortPasien(dataPasien, hitungPasien, metodeSort); 
                        tampilkanDataPasien(dataPasien, hitungPasien);
                    } else if (pilihan == 2) {
                        cout << "Berhasil Logout." << endl;
                        break;
                    } else {
                        cout << "Pilihan tidak valid. Mohon coba lagi." << endl;
                    }
                }
            }
        } else {
            cout << "Pilihan tidak valid. Mohon coba lagi." << endl;
        }
    }
    return 0;
}

void registrasi(Akun *pengguna, int &jumlahPengguna) {
    if (jumlahPengguna >= max_pengguna) {
        cout << "Mohon maaf jumlah pengguna sudah melewati maksimum." << endl;
        return;
    }

    Akun akunBaru;
    cout << "Masukkan username: ";
    cin >> akunBaru.username;
    cout << "Masukkan password: ";
    cin >> akunBaru.password;
    cout << "Masukkan role (admin/user): ";
    cin >> akunBaru.role;

    pengguna[jumlahPengguna] = akunBaru;
    jumlahPengguna++;
    cout << "Registrasi berhasil! Silahkan login" << endl;
}

bool login(Akun *pengguna, int jumlahPengguna, string &role) {
    string username, password;
    for (int i = 0; i < max_coba; ++i) {
        cout << "Nama Pengguna: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        for (int j = 0; j < jumlahPengguna; ++j) {
            if (pengguna[j].username == username && pengguna[j].password == password) {
                role = pengguna[j].role;
                return true;
            }
        }

        cout << "Nama pengguna dan password tidak ditemukan. Silahkan Registrasi terlebih dahulu" << endl;
    }
    return false;
}

void tambahPasien(Pasien *dataPasien, int &hitungPasien) {
    if (hitungPasien >= max_pasien) {
        cout << "Daftar pasien penuh." << endl;
        return;
    }

    cout << "Masukkan nama: ";
    cin.ignore();
    getline(cin, dataPasien[hitungPasien].nama);
    cout << "Masukkan umur: ";
    cin >> dataPasien[hitungPasien].umur;
    cin.ignore();
    cout << "Masukkan diagnosis: ";
    getline(cin, dataPasien[hitungPasien].riwayat.diagnosis);
    cout << "Masukkan riwayat obat sebelumnya: ";
    getline(cin, dataPasien[hitungPasien].riwayat.riwayatObat);
    hitungPasien++;
}

void tampilkanDataPasien(Pasien *dataPasien, int hitungPasien) {
    cout << left << setw(20) << "Nama" << setw(5) << "Umur" << setw(20) << "Diagnosis" << setw(15) << "Riwayat obat" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    tampilkanDataPasienRekursif(dataPasien, 0, hitungPasien);
}

void tampilkanDataPasienRekursif(Pasien *dataPasien, int index, int hitungPasien) {
    if (index >= hitungPasien) return;
    cout << left << setw(20) << dataPasien[index].nama
         << setw(5) << dataPasien[index].umur
         << setw(20) << dataPasien[index].riwayat.diagnosis
         << setw(15) << dataPasien[index].riwayat.riwayatObat << endl;
    tampilkanDataPasienRekursif(dataPasien, index + 1, hitungPasien);
}

void tampilkanDataPasienRekursif(Pasien *dataPasien, int hitungPasien) {
    tampilkanDataPasienRekursif(dataPasien, 0, hitungPasien);
}

void updatePasien(Pasien *pasien) {
    cout << "Masukkan umur baru: ";
    cin >> pasien->umur;
    cin.ignore();
    cout << "Masukkan diagnosis baru: ";
    getline(cin, pasien->riwayat.diagnosis);
    cout << "Masukkan riwayat obat baru: ";
    getline(cin, pasien->riwayat.riwayatObat);
}

void hapusPasien(Pasien *dataPasien, int &hitungPasien) {
    string nama;
    cout << "Masukkan nama yang akan dihapus: ";
    cin.ignore();
    getline(cin, nama);

    int temukan = 0;
    for (int i = 0; i < hitungPasien; ++i) {
        if (dataPasien[i].nama == nama) {
            for (int j = i; j < hitungPasien - 1; ++j) {
                dataPasien[j] = dataPasien[j + 1];
            }
            hitungPasien--;
            cout << "Nama Pasien berhasil dihapus." << endl;
            temukan = 1;
            break;
        }
    }

    if (!temukan) {
        cout << "Nama Pasien tidak ditemukan." << endl;
    }
}

void sortPasien(Pasien *dataPasien, int hitungPasien, int metode) {
    for (int i = 1; i < hitungPasien; i++) {
        Pasien key = dataPasien[i];
        int j = i - 1;

        if (metode == 1) { 
            while (j >= 0 && dataPasien[j].nama < key.nama) {
                dataPasien[j + 1] = dataPasien[j];
                j--;
            }
        } else if (metode == 2) { 
            while (j >= 0 && dataPasien[j].umur > key.umur) {
                dataPasien[j + 1] = dataPasien[j];
                j--;
            }
        }
        dataPasien[j + 1] = key;
    }
}