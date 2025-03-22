#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int max_coba = 3;
const int max_pasien = 100;

struct Akun {
    string username;
    string password;
    string role;
};

int main() {
    Akun pengguna[] = {
        {"Admin", "12345", "admin"},
        {"Nazla_Salsabila", "2409106108", "user"},
        {"Najla", "1701", "admin"}
    };

    string dataPasien[max_pasien][4];  
    int hitungPasien = 0;

    string username, password, role;
    int masuk = 0;

    while (true) {
        int menuUtama;
        cout << "Menu Utama:\n";
        cout << "1. Login Sebagai Admin\n";
        cout << "2. Login Sebagai User\n";
        cout << "3. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> menuUtama;

        if (menuUtama == 3) {
            cout << "Program berhenti.\n";
            break; 
        }

        if (menuUtama == 1 || menuUtama == 2) {
            for (int i = 0; i < max_coba; ++i) {
                cout << "Nama Pengguna: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

                for (const auto &user : pengguna) {
                    if (user.username == username && user.password == password) {
                        masuk = 1;
                        role = user.role;
                        break;
                    }
                }

                if (masuk) {
                    break;
                } else {
                    cout << "Nama pengguna atau password salah. Coba lagi." << endl;
                }
            }

            if (!masuk) {
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
                            cout << "Daftar penuh." << endl;
                            continue;
                        }

                        cout << "Masukkan nama: ";
                        cin.ignore();
                        getline(cin, dataPasien[hitungPasien][0]);
                        cout << "Masukkan umur: ";
                        getline(cin, dataPasien[hitungPasien][1]);
                        cout << "Masukkan diagnosis: ";
                        getline(cin, dataPasien[hitungPasien][2]);
                        cout << "Masukkan riwayat obat sebelumnya: ";
                        getline(cin, dataPasien[hitungPasien][3]);
                        hitungPasien++;
                    } else if (pilihan == 2) {
                        cout << left << setw(20) << "Nama" << setw(5) << "Umur" << setw(20) << "Diagnosis" << setw(15) << "Riwayat obat" << endl;
                        cout << "-------------------------------------------------------------------" << endl;
                        for (int i = 0; i < hitungPasien; ++i) {
                            cout << left << setw(20) << dataPasien[i][0] << setw(5) << dataPasien[i][1] << setw(20) << dataPasien[i][2] << setw(15) << dataPasien[i][3] << endl;
                        }
                    } else if (pilihan == 3) {
                        string nama;
                        cout << "Masukkan nama yang akan diupdate: ";
                        cin.ignore();
                        getline(cin, nama);

                        int temukan = 0;
                        for (int i = 0; i < hitungPasien; ++i) {
                            if (dataPasien[i][0] == nama) {
                                cout << "Masukkan umur baru: ";
                                getline(cin, dataPasien[i][1]);
                                cout << "Masukkan diagnosis baru: ";
                                getline(cin, dataPasien[i][2]);
                                cout << "Masukkan riwayat obat baru: ";
                                getline(cin, dataPasien[i][3]);
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
                            if (dataPasien[i][0] == nama) {
                                for (int j = i; j < hitungPasien - 1; ++j) {
                                    for (int k = 0; k < 4; ++k) {
                                        dataPasien[j][k] = dataPasien[j + 1][k];
                                    }
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
                        cout << "Program berhenti." << endl;
                        break;
                    } else {
                        cout << "Pilihan tidak valid. Mohon coba lagi." << endl;
                    }
                } else if (role == "user") {
                    if (pilihan == 1) {
                        cout << left << setw(20) << "Nama" << setw(5) << "Umur" << setw(20) << "Diagnosis" << setw(15) << "Riwayat obat" << endl;
                        cout << "-------------------------------------------------------------------" << endl;
                        for (int i = 0; i < hitungPasien; ++i) {
                            cout << left << setw(20) << dataPasien[i][0] << setw(5) << dataPasien[i][1] << setw(20) << dataPasien[i][2] << setw(15) << dataPasien[i][3] << endl;
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
