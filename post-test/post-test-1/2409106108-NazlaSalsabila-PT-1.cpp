#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool cekVerifikasi1(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool validasiKode(int code) {
    return (code > 100 && code < 99999);
}

bool cekVerifikasi2(int code) {
    return (code % 2 == 0 && code % 3 == 0 && code % 5 != 0);
}

bool cekVerifikasi3(int code) {
    string str = to_string(code);
    string reversedStr = string(str.rbegin(), str.rend());
    return str == reversedStr;
}

int main() {
    string username;
    string password;

    cout << "Masukkan Username: ";
    getline(cin, username);
    cout << "Masukkan Password: ";
    getline(cin, password);

    cout << "Login berhasil!" << endl;

    int code;
    while (true) {
        cout << "Masukkan kode sandi rahasia : ";
        cin >> code;

        if (!validasiKode(code)) {
            cout << "Kode sandi harus lebih dari 100 dan tidak lebih dari 99999." << endl;
            continue;
        }

        while (true) {
            cout << "\nMenu:" << endl;
            cout << "1. Cek verifikasi kode sandi bilangan prima" << endl;
            cout << "2. Cek verifikasi kode sandi habis dibagi 2 dan 3 tapi tidak habis dibagi 5" << endl;
            cout << "3. Cek verifikasi kode sandi adalah bilangan palindrome" << endl;
            cout << "4. Keluar program" << endl;

            int choice;
            cout << "Silahkan pilih menu : ";
            cin >> choice;

            switch (choice) {
                case 1:
                    if (cekVerifikasi1(code)) {
                        cout << code << " adalah bilangan prima." << endl;
                    } else {
                        cout << code << " bukan bilangan prima." << endl;
                    }
                    break;
                case 2:
                    if (cekVerifikasi2(code)) {
                        cout << code << " habis dibagi 2 dan 3 tetapi tidak habis dibagi 5." << endl;
                    } else {
                        cout << code << " bukan bilangan habis dibagi 2 dan 3 tetapi tidak habis dibagi 5." << endl;
                    }
                    break;
                case 3: 
                    if (cekVerifikasi3(code)) {
                        cout << code << " adalah bilangan Palindrome." << endl;
                    } else {
                        cout << code << " bukan termasuk bilangan Palindrome." << endl;
                    }
                    break;
                case 4:
                    cout << "Program berhenti." << endl;
                    return 0;
                default:
                    cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
            }

            char lanjutkanMemilihMenu;
            cout << "Apakah ingin melanjutkan ke menu? (y/n): ";
            cin >> lanjutkanMemilihMenu;
            if (lanjutkanMemilihMenu != 'y' && lanjutkanMemilihMenu != 'Y') {
               break ;
            }
        }
    }

    return 0;
}