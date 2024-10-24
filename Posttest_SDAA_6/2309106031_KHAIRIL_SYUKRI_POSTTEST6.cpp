#include <iostream>
#include <string>
#include <vector>
#include <cmath>

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

vector<Node*> linkedListToArray(const PesertaList& pesertaList) {
    vector<Node*> arr;
    Node* temp = pesertaList.head;
    while (temp != nullptr) {
        arr.push_back(temp);
        temp = temp->next;
    }
    return arr;
}

int fibonacciSearch(const vector<Node*>& arr, const string& x) {
    int n = arr.size();
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);

        if (arr[i]->nama < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            offset = i;
        } else if (arr[i]->nama > x) {
            fibM = fibMMm2;
            fibMMm2 = fibMMm1 - fibMMm2;
        } else
            return arr[i]->id;
    }

    if (fibMMm1 && arr[offset + 1]->nama == x)
        return arr[offset + 1]->id;

    return -1;
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

int jumpSearch(const vector<Node*>& arr, const string& x) {
    int n = arr.size();
    if (n == 0) return -1;
    
    int step = sqrt(n);
    int prev = 0;

    while (prev < n && arr[min(step, n) - 1]->nama < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    while (prev < min(step, n) && arr[prev]->nama < x) {
        prev++;
        if (prev == min(step, n)) return -1;
    }

    if (prev < n && arr[prev]->nama == x) {
        return arr[prev]->id;
    }

    return -1;
}

void badCharHeuristic(const string& str, int size, int badchar[256]) {
    for (int i = 0; i < 256; i++)
        badchar[i] = -1;
    for (int i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

void boyerMooreSearch(const vector<Node*>& arr, const string& pattern) {
    string text = "";
    vector<int> positions;
    
    for (const auto& node : arr) {
        positions.push_back(text.length());
        text += node->nama + " ";
    }

    int m = pattern.length();
    int n = text.length();
    int badchar[256];

    badCharHeuristic(pattern, m, badchar);

    int s = 0;
    bool found = false;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0) {
            for (size_t i = 0; i < positions.size(); i++) {
                if (s >= positions[i] && (i == positions.size() - 1 || s < positions[i + 1])) {
                    cout << "Peserta ditemukan dengan ID: " << arr[i]->id << endl;
                    found = true;
                    break;
                }
            }
            s += (s + m < n) ? m - badchar[text[s + m]] : 1;
        } else {
            s += max(1, j - badchar[text[s + j]]);
        }
    }
    
    if (!found) {
        cout << "Peserta tidak ditemukan." << endl;
    }
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
        cout << "13. Fibonacci Search" << endl;
        cout << "14. Jump Search" << endl;
        cout << "15. Boyer-Moore Search" << endl;
        cout << "16. Keluar" << endl;
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
                cout << "Peserta berhasil diurutkan dengan QuickSort Ascending." << endl;
                break;
            case 12:
                MergeSort(&daftarPeserta.head);
                cout << "Peserta berhasil diurutkan dengan MergeSort Descending." << endl;
                break;
            case 13: {
                vector<Node*> arr = linkedListToArray(daftarPeserta);
                string namaCari;
                cout << "Masukkan nama peserta yang ingin dicari: ";
                cin.ignore();
                getline(cin, namaCari);
                int idDitemukan = fibonacciSearch(arr, namaCari);
                if (idDitemukan != -1) {
                    cout << "Peserta ditemukan dengan ID: " << idDitemukan << endl;
                } else {
                    cout << "Peserta tidak ditemukan." << endl;
                }
                break;
            }
            case 14: {
                vector<Node*> arr = linkedListToArray(daftarPeserta);
                string namaCari;
                cout << "Masukkan nama peserta yang ingin dicari: ";
                cin.ignore();
                getline(cin, namaCari);
                int idDitemukan = jumpSearch(arr, namaCari);
                if (idDitemukan != -1) {
                    cout << "Peserta ditemukan dengan ID: " << idDitemukan << endl;
                } else {
                    cout << "Peserta tidak ditemukan." << endl;
                }
                break;
            }
            case 15: {
                vector<Node*> arr = linkedListToArray(daftarPeserta);
                string namaCari;
                cout << "Masukkan nama peserta yang ingin dicari: ";
                cin.ignore();
                getline(cin, namaCari);
                boyerMooreSearch(arr, namaCari);
                break;
            }
            case 16:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 16);

    return 0;
}
