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
            if (jumlahPengguna >= max_pengguna) {
                cout << "Mohon maaf jumlah pengguna sudah melewati maksimum." << endl;
                continue;
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
        } else if (menuUtama == 2) {
            string role;
            string username, password;
            bool loginBerhasil = false;

            for (int i = 0; i < max_coba; ++i) {
                cout << "Nama Pengguna: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

                for (int j = 0; j < jumlahPengguna; ++j) {
                    if (pengguna[j].username == username && pengguna[j].password == password) {
                        role = pengguna[j].role;
                        loginBerhasil = true;
                        break;
                    }
                }

                if (loginBerhasil) {
                    break;
                } else {
                    cout << "Nama pengguna atau password salah. Coba lagi." << endl;
                }
            }

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
                        if (hitungPasien >= max_pasien) {
                            cout << "Daftar pasien penuh." << endl;
                            continue;
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
                    } else if (pilihan == 2) {
                        cout << left << setw(20) << "Nama" << setw(5) << "Umur" << setw(20) << "Diagnosis" << setw(15) << "Riwayat obat" << endl;
                        cout << "-------------------------------------------------------------------" << endl;
                        for (int i = 0; i < hitungPasien; ++i) {
                            cout << left << setw(20) << dataPasien[i].nama 
                                 << setw(5) << dataPasien[i].umur 
                                 << setw(20) << dataPasien[i].riwayat.diagnosis 
                                 << setw(15) << dataPasien[i].riwayat.riwayatObat << endl;
                        }
                    } else if (pilihan == 3) {
                        string nama;
                        cout << "Masukkan nama yang akan diupdate: ";
                        cin.ignore();
                        getline(cin, nama);

                        int temukan = 0;
                        for (int i = 0; i < hitungPasien; ++i) {
                            if (dataPasien[i].nama == nama) {
                                cout << "Masukkan umur baru: ";
                                cin >> dataPasien[i].umur;
                                cin.ignore(); 
                                cout << "Masukkan diagnosis baru: ";
                                getline(cin, dataPasien[i].riwayat.diagnosis);
                                cout << "Masukkan riwayat obat baru: ";
                                getline(cin, dataPasien[i].riwayat.riwayatObat);
                                temukan = 1;
                                break;
                            }
                        }

                        if (!temukan) {
                            cout << "Pasien tidak ditemukan." << endl;
                        }
                    } else if (pilihan == 4) {
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
                    } else if (pilihan == 5) {
                        cout << "Berhasil Logout." << endl;
                        break;
                    } else {
                        cout << "Pilihan tidak valid. Mohon coba lagi." << endl;
                    }
                } else if (role == "user") {
                    if (pilihan == 1) {
                        cout << left << setw(20) << "Nama" << setw(5) << "Umur" << setw(20) << "Diagnosis" << setw(15) << "Riwayat obat" << endl;
                        cout << "-------------------------------------------------------------------" << endl;
                        for (int i = 0; i < hitungPasien; ++i) {
                            cout << left << setw(20) << dataPasien[i].nama 
                                 << setw(5) << dataPasien[i].umur 
                                 << setw(20) << dataPasien[i].riwayat.diagnosis 
                                 << setw(15) << dataPasien[i].riwayat.riwayatObat << endl;
                        }
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