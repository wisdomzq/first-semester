#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    int height;
    Node(char val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(Node* node) {
    return node ? node->height : 0;
}

void updateHeight(Node* node) {
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

int getBalanceFactor(Node* node) {
    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    updateHeight(y);
    updateHeight(x);
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    updateHeight(x);
    updateHeight(y);
    return y;
}

Node* insert(Node* node, char key) {
    if (!node)
        return new Node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;
    updateHeight(node);
    int balance = getBalanceFactor(node);
    // 进行相应的旋转操作
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preorder(Node* root, string& res) {
    if (root) {
        res += root->data;
        preorder(root->left, res);
        preorder(root->right, res);
    }
}

void inorder(Node* root, string& res) {
    if (root) {
        inorder(root->left, res);
        res += root->data;
        inorder(root->right, res);
    }
}

void postorder(Node* root, string& res) {
    if (root) {
        postorder(root->left, res);
        postorder(root->right, res);
        res += root->data;
    }
}

void printTree(Node* root, int space = 0) {
    if (!root)
        return;
    space += 4;
    printTree(root->right, space);
    for (int i = 4; i < space; i++)
        cout << " ";
    cout << root->data << endl;
    printTree(root->left, space);
}

int main() {
    string s;
    cin >> s;
    Node* root = nullptr;
    for (char c : s)
        root = insert(root, c);
    string pre, in, post;
    preorder(root, pre);
    inorder(root, in);
    postorder(root, post);
    cout << "Preorder: " << pre << endl;
    cout << "Inorder: " << in << endl;
    cout << "Postorder: " << post << endl;
    cout << "Tree:" << endl;
    printTree(root);
    return 0;
}
