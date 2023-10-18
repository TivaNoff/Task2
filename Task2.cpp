#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
};

Node* swapPairs(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
}

int main() {
    Node* head = new Node{ 1, new Node{2, new Node{3, new Node{4, nullptr}}} };
    Node* newHead = swapPairs(head);
    while (newHead != nullptr) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;
    return 0;
}
