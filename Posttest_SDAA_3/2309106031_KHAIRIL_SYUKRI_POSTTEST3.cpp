#include <iostream>
#include <string>

using namespace std;

// Struktur untuk node linked list
struct Node {
    string nama;
    string game;
    int id;
    Node* next;
};

// Struktur untuk daftar peserta
struct PesertaList {
    Node* head;
    int jumlahPeserta;

    PesertaList() {
        head = nullptr;
        jumlahPeserta = 0;
    }
};

static int idOtomatis = 1;

void tambahPeserta(PesertaList& pesertaList) {
    Node* newNode = new Node;
    
    cout << "Masukkan Nama Peserta: ";
    cin.ignore();
    getline(cin, newNode->nama);
    cout << "Masukkan Game yang Diikuti: ";
    getline(cin, newNode->game);

    newNode->id = idOtomatis++;
    newNode->next = nullptr;

    if (pesertaList.head == nullptr) {
        pesertaList.head = newNode;
    } else {
        Node* temp = pesertaList.head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    pesertaList.jumlahPeserta++;
}

void tampilkanPeserta(const PesertaList& pesertaList) {
    if (pesertaList.jumlahPeserta == 0) {
        cout << "Belum ada peserta yang terdaftar" << endl;
        return;
    }
    
    cout << "\nDaftar Peserta:" << endl;
    Node* temp = pesertaList.head;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << endl;
        cout << "- Nama: " << temp->nama << endl;
        cout << "- Game: " << temp->game << endl;
        temp = temp->next;
    }
}

void updatePeserta(PesertaList& pesertaList) {
    int id;
    cout << "Masukkan ID Peserta yang ingin diperbarui: ";
    cin >> id;

    Node* temp = pesertaList.head;
    while (temp != nullptr) {
        if (temp->id == id) {
            cout << "Masukkan Nama Baru Peserta: ";
            cin.ignore();
            getline(cin, temp->nama);
            cout << "Masukkan Game Baru yang Diikuti: ";
            getline(cin, temp->game);
            cout << "Data peserta berhasil diperbarui" << endl;
            return;
        }
        temp = temp->next;
    }
    
    cout << "Peserta dengan ID tersebut tidak ditemukan" << endl;
}

void hapusPeserta(PesertaList& pesertaList) {
    int id;
    cout << "Masukkan ID Peserta yang ingin dihapus: ";
    cin >> id;

    Node* temp = pesertaList.head;
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (temp->id == id) {
            if (prev == nullptr) { // Node yang dihapus adalah head
                pesertaList.head = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            pesertaList.jumlahPeserta--;
            cout << "Data peserta berhasil dihapus" << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Peserta dengan ID tersebut tidak ditemukan" << endl;
}

int main() {
    PesertaList daftarPeserta;

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
                tambahPeserta(daftarPeserta);
                break;
            case 2:
                tampilkanPeserta(daftarPeserta);
                break;
            case 3:
                updatePeserta(daftarPeserta);
                break;
            case 4:
                hapusPeserta(daftarPeserta);
                break;
            case 5:
                cout << "Terima Kasih Sudah Mendaftar di Informatics Cup" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
        
    } while (pilihan != 5);

    // Hapus semua node di akhir program
    while (daftarPeserta.head != nullptr) {
        Node* temp = daftarPeserta.head;
        daftarPeserta.head = daftarPeserta.head->next;
        delete temp;
    }

    return 0;
}