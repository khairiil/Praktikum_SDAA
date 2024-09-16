#include <iostream>
using namespace std;

void menaraHanoi(int n, char asal, char tujuan, char sementara, int& langkah) {
    if (n == 1) {
        langkah++;
        cout << "Langkah: "<< langkah <<" Pindahkan Piringan 1 dari menara "<< asal << " ke menara " << tujuan << endl;
    } else {
        menaraHanoi(n - 1, asal, sementara, tujuan, langkah);
        langkah++;
        cout << "Langkah: " << langkah << " Pindahkan Piringan " << n << " dari menara " << asal << " ke menara " << tujuan << endl;
        menaraHanoi(n - 1, sementara, tujuan, asal, langkah);
    }
}

int main() {
    int jumlah;
    cout << "Masukkan Jumlah Piringan: ";
    cin >> jumlah;
    int langkah = 0;
    char asal = 'A', sementara = 'B', tujuan = 'C';
    menaraHanoi(jumlah, asal, tujuan, sementara, langkah);
    return 0;
}