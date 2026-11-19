#include <iostream>

struct Node {
    int value;
    Node* prev;
    Node* next;

    Node() : value(0), prev(nullptr), next(nullptr) {}
    Node(int x) : value(x),  prev(nullptr), next(nullptr) {}
    Node(int x, Node* prev, Node* next) : value(x), prev(prev), next(next) {}
};

Node* pop_back(Node* tail)
{
    if (!tail) return tail;
    Node* temp = tail->prev;
    if (temp) temp->next = nullptr;
    delete tail;
    tail = temp;
    return tail;
}

void printList(Node* list)
{
    if (!list) return;
    while (list)
    {
        std::cout << list->value << ' ';
        list = list->next;
    }
    std::cout << '\n';
}

void insertAfter(Node* pos, int val)
{
    if (!pos) return;
    Node* newEl = new Node(val, pos, pos->next);
    pos->next = newEl;
    if (newEl->next) newEl->next->prev = newEl;
}

void deleteAt(Node* pos)
{
    if (!pos) return;
    if (pos->prev) pos->prev->next = pos->next;
    if (pos->next) pos->next->prev = pos->prev;
    delete pos;
}

bool hasCycle(Node* head)
{
    if (!head) return false;
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main()
{
    //1 -> 2 -> 3
    Node* n1 = new Node(1);
    Node* n2 = new Node(2, n1, new Node(3));
    n1->next = n2;
    n2->next->prev = n2;


    //cyclic list
    // Node* head = new Node(10);
    // Node* n2   = new Node(20, head, nullptr);
    // head->next = n2;
    // Node* n3   = new Node(30, n2, nullptr);
    // n2->next   = n3;
    // Node* n4   = new Node(40, n3, nullptr);
    // n3->next   = n4;
    // Node* tail = new Node(50, n4, nullptr);
    // n4->next   = tail;

    // // Close the cycle
    // tail->next = head;
    // head->prev = tail;

 

    //deleteAt(n2->next);
    //printList(head);
    //std::cout << std::boolalpha << hasCycle(n1);
}