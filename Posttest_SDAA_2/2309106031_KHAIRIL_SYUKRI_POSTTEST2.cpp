#include <iostream>
#include <string>

using namespace std;

struct Peserta {
    string nama;
    string game;
    int id;
};

static int idCounter = 1;

void tambahPeserta(Peserta* peserta, int& jumlahPeserta) {
    cout << "Masukkan Nama Peserta: ";
    cin.ignore();
    getline(cin, peserta[jumlahPeserta].nama);
    cout << "Masukkan Game yang Diikuti: ";
    getline(cin, peserta[jumlahPeserta].game);
    
    peserta[jumlahPeserta].id = idCounter;
    idCounter++;
    
    jumlahPeserta++;
}

void tampilkanPeserta(Peserta* peserta, int jumlahPeserta) {
    if (jumlahPeserta == 0) {
        cout << "Belum ada peserta yang terdaftar" << endl;
        return;
    }
    
    cout << "\nDaftar Peserta:" << endl;
    for (int i = 0; i < jumlahPeserta; i++) {
        cout << "ID: " << peserta[i].id << endl;
        cout << "- Nama: " << peserta[i].nama << endl;
        cout << "- Game: " << peserta[i].game << endl;
    }
}

void updatePeserta(Peserta* peserta, int jumlahPeserta) {
    int id;
    cout << "Masukkan ID Peserta yang ingin diperbarui: ";
    cin >> id;

    for (int i = 0; i < jumlahPeserta; i++) {
        if (peserta[i].id == id) {
            cout << "Masukkan Nama Baru Peserta: ";
            cin.ignore();
            getline(cin, peserta[i].nama);
            cout << "Masukkan Game Baru yang Diikuti: ";
            getline(cin, peserta[i].game);
            cout << "Data peserta berhasil diperbarui" << endl;
            return;
        }
    }
    
    cout << "Peserta dengan ID tersebut tidak ditemukan" << endl;
}

void hapusPeserta(Peserta* peserta, int& jumlahPeserta) {
    int id;
    cout << "Masukkan ID Peserta yang ingin dihapus: ";
    cin >> id;

    for (int i = 0; i < jumlahPeserta; i++) {
        if (peserta[i].id == id) {
            for (int j = i; j < jumlahPeserta - 1; j++) {
                peserta[j] = peserta[j + 1];
            }
            jumlahPeserta--;
            cout << "Data peserta berhasil dihapus" << endl;
            return;
        }
    }

    cout << "Peserta dengan ID tersebut tidak ditemukan" << endl;
}

int main() {
    const int MAX_PESERTA = 100;
    Peserta* daftarPeserta = new Peserta[MAX_PESERTA];
    int jumlahPeserta = 0;

    int pilihan;

    do {
        cout << "\nMenu Pendaftaran Informatics Cup:" << endl;
        cout << "1. Tambah Peserta" << endl;
        cout << "2. Tampilkan Peserta" << endl;
        cout << "3. Update Peserta" << endl;
        cout << "4. Hapus Peserta" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (jumlahPeserta < MAX_PESERTA) {
                    tambahPeserta(daftarPeserta, jumlahPeserta);
                } else {
                    cout << "Kapasitas maksimum peserta telah tercapai" << endl;
                }
                break;
            case 2:
                tampilkanPeserta(daftarPeserta, jumlahPeserta);
                break;
            case 3:
                updatePeserta(daftarPeserta, jumlahPeserta);
                break;
            case 4:
                hapusPeserta(daftarPeserta, jumlahPeserta);
                break;
            case 5:
                cout << "Terima Kasih Sudah Mendaftar di Informatics Cup" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
        
    } while (pilihan != 5);

    delete[] daftarPeserta;
    return 0;
}