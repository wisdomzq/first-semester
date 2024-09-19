#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
    int x;
    int z;
    Node* next;
    Node(int x, int z) : x(x), z(z), next(nullptr) {}
};

bool cmp(Node* a, Node* b) {
    return a->z < b->z;
}

void insert(Node*& head, int x, int z) {
    Node* newNode = new Node(x, z);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    Node* temp = head;
    bool first = true;
    while (temp) {
        if(temp->x == 0) {
            temp = temp->next;
            continue;
        }
        else{
             if (!first) cout << ",";
        cout << "<" << temp->x << "," << temp->z << ">";
        first = false;
        }
       
        temp = temp->next;
    }
    if (!first) cout << endl;
    else cout << "<0,0>" << endl;
   
}

Node* merge(Node* l1, Node* l2) {
    Node dummy(0, 0);
    Node* tail = &dummy;
    while (l1 && l2) {
        if (l1->z == l2->z) {
            tail->next = new Node(l1->x + l2->x, l1->z);
            l1 = l1->next;
            l2 = l2->next;
        } else if (l1->z < l2->z) {
            tail->next = new Node(l1->x, l1->z);
            l1 = l1->next;
        } else {
            tail->next = new Node(l2->x, l2->z);
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

int main() {
    int T, n, m, k;
    while (cin >> T) {
        if (T == 0) return 0;
        Node* x1 = nullptr;
        Node* x2 = nullptr;
        Node* x3 = nullptr;

        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x, z;
            cin >> x >> z;
            insert(x1, x, z);
        }
       
        printList(x1);

        cin >> m;
        for (int i = 0; i < m; ++i) {
            int x, z;
            cin >> x >> z;
            insert(x2, x, z);
        }
       
        printList(x2);

        cin >> k;
        for (int i = 0; i < k; ++i) {
            int x, z;
            cin >> x >> z;
            insert(x3, x, z);
        }
       
        printList(x3);

        Node* j1 = merge(x1, x2);
        printList(j1);

        Node* j2 = merge(j1, x3);
        printList(j2);
    }
}