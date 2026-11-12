#include <iostream>
#include <string>
using namespace std;
struct Node {
    string namaBarang;
    int harga;
    Node* next;
};
Node* head = nullptr;
Node* tail = nullptr;

void insertTail(string nama, int harga) {
    Node* newNode = new Node();
    newNode->namaBarang = nama;
    newNode->harga = harga;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteHead() {
    if (head == nullptr) return;

    Node* temp = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
    }
    delete temp;
}

void deleteTail() {
    if (head == nullptr) return;

    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
}

void tampilkanBarangMewah() {
    cout << "\nList Barang mewah:" << endl;
    Node* temp = head;
    int nomor = 1;

    while (temp != nullptr) {
        if (temp->harga > 100000) {
            cout << nomor << " | " << temp->namaBarang << " (Rp" << temp->harga << ")" << endl;
            nomor++;
        }
        temp = temp -> next;
    }
}

int main() {
    int pilihan;
    string nama;
    int harga;

    cout << "Pilih menu (1 - 4)" << endl;
    cout << "1. Insert tail" << endl;
    cout << "2. Delete head" << endl;
    cout << "3. Delete tail" << endl;
    cout << "4. Tampilkan barang mewah" << endl;

    while (true) {
        if (!(cin >> pilihan)) break;

        if (pilihan == 1) {
            cout << "Nama barang : ";
            cin.ignore(); 
            getline(cin, nama);
            cout << "Harga : ";
            cin >> harga;
            insertTail(nama, harga);
        } 
        else if (pilihan == 2) {
            deleteHead();
        } 
        else if (pilihan == 3) {
            deleteTail();
        } 
        else if (pilihan == 4) {
            tampilkanBarangMewah();
         break;   
        }
    }

    return 0;
}