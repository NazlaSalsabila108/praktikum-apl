//penyelasaian studi kasus 1 modul kelima apl
#include <iostream>

using namespace std;

int main() {
    int x, y;

    cout << "Masukkan nilai pertama: ";
    cin >> x;
    cout << "Masukkan nilai kedua: ";
    cin >> y;

    cout << "\nSebelum penukaran:" << endl;
    cout << "Nilai pertama: " << x << endl;
    cout << "Nilai kedua: " << y << endl;

  
    int* ptrX = &x;
    int* ptrY = &y;

    int temp = *ptrX;
    *ptrX = *ptrY;
    *ptrY = temp;

    cout << "\nSetelah penukaran:" << endl;
    cout << "Nilai pertama: " << x << endl;
    cout << "Nilai kedua: " << y << endl;

    return 0;
}