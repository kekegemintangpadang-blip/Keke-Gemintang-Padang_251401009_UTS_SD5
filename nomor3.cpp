#include <iostream>
#include <string>
using namespace std;

const int MAKSIMAL = 100;
struct Stack {
    char data[MAKSIMAL];
    int top = -1;

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAKSIMAL - 1;
    }

    void push(char huruf) {
        if (!isFull()) {
            top++;
            data[top] = huruf;
        }
    }

    char pop() {
        if (!isEmpty()) {
            char temp = data[top];
            top--;
            return temp;
        }
        return '\0';
    }
};

int main() {
    Stack stack;
    string kataAsli;
    string kataDibalik = "";

    cout << "Masukkan kata : ";
    cin >> kataAsli;

    for (int i = 0; i < kataAsli.length(); i++) {
        stack.push(kataAsli[i]);
    }
    while (!stack.isEmpty()) {
        kataDibalik += stack.pop();
    }
    cout << "Kata dibalik : " << kataDibalik << endl;

    if (kataAsli == kataDibalik) {
        cout << "Kesimpulan : Kata ini adalah palindrom" << endl;
    } else {
        cout << "Kesimpulan : Bukan palindrom" << endl;
    }

    return 0;
}

