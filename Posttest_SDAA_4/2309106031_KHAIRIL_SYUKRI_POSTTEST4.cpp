#include <iostream>
#include <string>

using namespace std;

struct Node {
    string nama;
    string game;
    int id;
    Node* next;
};

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
            if (prev == nullptr) {
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

struct Stack {
    Node* top;

    Stack() {
        top = nullptr;
    }

    void push(PesertaList& pesertaList) {
        if (pesertaList.head == nullptr) {
            cout << "Tidak ada peserta untuk dimasukkan ke stack." << endl;
            return;
        }
        
        Node* newNode = pesertaList.head;
        pesertaList.head = pesertaList.head->next;

        newNode->next = top;
        top = newNode;

        cout << "Peserta berhasil dimasukkan ke stack." << endl;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack kosong." << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;

        cout << "Peserta berhasil dihapus dari stack." << endl;
    }

    void tampilkanStack() {
        if (top == nullptr) {
            cout << "Stack kosong." << endl;
            return;
        }

        Node* temp = top;
        cout << "\nPeserta di dalam stack:" << endl;
        while (temp != nullptr) {
            cout << "ID: " << temp->id << endl;
            cout << "- Nama: " << temp->nama << endl;
            cout << "- Game: " << temp->game << endl;
            temp = temp->next;
        }
    }
};

struct Queue {
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(PesertaList& pesertaList) {
        if (pesertaList.head == nullptr) {
            cout << "Tidak ada peserta untuk dimasukkan ke queue." << endl;
            return;
        }

        Node* newNode = pesertaList.head;
        pesertaList.head = pesertaList.head->next;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Peserta berhasil dimasukkan ke queue." << endl;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue kosong." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        cout << "Peserta berhasil dihapus dari queue." << endl;
    }

    void tampilkanQueue() {
        if (front == nullptr) {
            cout << "Queue kosong." << endl;
            return;
        }

        Node* temp = front;
        cout << "\nPeserta di dalam queue:" << endl;
        while (temp != nullptr) {
            cout << "ID: " << temp->id << endl;
            cout << "- Nama: " << temp->nama << endl;
            cout << "- Game: " << temp->game << endl;
            temp = temp->next;
        }
    }
};

int main() {
    PesertaList daftarPeserta;
    Stack stackPeserta;
    Queue queuePeserta;
    
    int pilihan;

    do {
        cout << "\nMenu Pendaftaran Informatics Cup:" << endl;
        cout << "1. Tambah Peserta" << endl;
        cout << "2. Tampilkan Peserta" << endl;
        cout << "3. Update Peserta" << endl;
        cout << "4. Hapus Peserta" << endl;
        cout << "5. Push ke Stack" << endl;
        cout << "6. Pop dari Stack" << endl;
        cout << "7. Enqueue ke Queue" << endl;
        cout << "8. Dequeue dari Queue" << endl;
        cout << "9. Tampilkan Stack" << endl;
        cout << "10. Tampilkan Queue" << endl;
        cout << "11. Keluar" << endl;
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
                stackPeserta.push(daftarPeserta);
                break;
            case 6:
                stackPeserta.pop();
                break;
            case 7:
                queuePeserta.enqueue(daftarPeserta);
                break;
            case 8:
                queuePeserta.dequeue();
                break;
            case 9:
                stackPeserta.tampilkanStack();
                break;
            case 10:
                queuePeserta.tampilkanQueue();
                break;
            case 11:
                cout << "Terima Kasih Sudah Mendaftar di Informatics Cup" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
        
    } while (pilihan != 11);

    while (daftarPeserta.head != nullptr) {
        Node* temp = daftarPeserta.head;
        daftarPeserta.head = daftarPeserta.head->next;
        delete temp;
    }

    return 0;
}