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

// QuickSort (Ascending)
Node* getTail(Node* cur) {
    while (cur != nullptr && cur->next != nullptr) {
        cur = cur->next;
    }
    return cur;
}

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->id < pivot->id) {
            if ((*newHead) == nullptr) {
                (*newHead) = cur;
            }
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) {
                prev->next = cur->next;
            }
            Node* tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == nullptr) {
        (*newHead) = pivot;
    }

    (*newEnd) = tail;

    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end) {
        return head;
    }

    Node* newHead = nullptr, *newEnd = nullptr;
    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot) {
            tmp = tmp->next;
        }
        tmp->next = nullptr;

        newHead = quickSortRecur(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(PesertaList& pesertaList) {
    pesertaList.head = quickSortRecur(pesertaList.head, getTail(pesertaList.head));
}

// MergeSort (Descending)
Node* SortedMerge(Node* a, Node* b) {
    Node* result = NULL;
    
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    
    if (a->id >= b->id) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return result;
}

void FrontBackSplit(Node* source, Node** frontRef, Node** backRef) {
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
    
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void MergeSort(Node** headRef) {
    Node* head = *headRef;
    Node* a;
    Node* b;
    
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    
    FrontBackSplit(head, &a, &b);
    
    MergeSort(&a);
    MergeSort(&b);
    
    *headRef = SortedMerge(a, b);
}

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
        cout << "11. Urutkan Peserta (QuickSort Ascending)" << endl;
        cout << "12. Urutkan Peserta (MergeSort Descending)" << endl;
        cout << "13. Keluar" << endl;
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
                quickSort(daftarPeserta);
                cout << "Daftar peserta telah diurutkan secara ascending menggunakan QuickSort." << endl;
                break;
            case 12:
                MergeSort(&daftarPeserta.head);
                cout << "Daftar peserta telah diurutkan secara descending menggunakan MergeSort." << endl;
                break;
            case 13:
                cout << "Terima Kasih Sudah Mendaftar di Informatics Cup" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
        
    } while (pilihan != 13);

    while (daftarPeserta.head != nullptr) {
        Node* temp = daftarPeserta.head;
        daftarPeserta.head = daftarPeserta.head->next;
        delete temp;
    }

    return 0;
}