#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insertNode(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insertNode(root->left, val);
    } else if (val > root->data) {
        root->right = insertNode(root->right, val);
    }
    return root;
}

void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int carinilai(Node* root) {
    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->data;
}

int main() {
    Node* root = nullptr;
    int angka;

    while (cin >> angka && angka != 0) {
        root = insertNode(root, angka);
    }

    if (root != nullptr) {
        cout << "Post-Order     : ";
        postOrder(root);
        cout << endl;
        cout << "Nilai terbesar : " << carinilai(root) << endl;
        cout << "Root           : " << root->data << endl;
    }

}