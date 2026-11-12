#include <iostream>


struct node {
    int value;
    node* next;

    node() : value(0), next(nullptr) {}
    node(int x) : value(x), next(nullptr) {}
    node(int x, node *next) : value(x), next(next) {}
};

int countOf(const node* head, int val)
{
    if (!head) return 0;
    const node* curr = head;
    int counter = 0;
    while (curr->next)
    {
        if (curr->value == val)
        {
            counter++;
        }
        curr = curr->next;
    }
    return counter;
}


void insertAfter(node* pos, int val)
{
    if (!pos) return;
    node* newEl = new node(val, pos->next);
    pos->next = newEl;
}

void removeAfter(node* pos)
{
    if (!pos || !pos->next) return;
    node* temp = pos->next;
    pos->next = temp->next;
    delete temp;
}

void printList(node* head)
{
    while(head)
    {
        std::cout << head->value << ' ';
        head = head->next;
    }
}

node* insertFront(node* head, int val)
{
    if (!head) return head;
    node* newEl = new node(val, head);
    head = newEl;
    return head;
}

node* popFront(node* head)
{
    if (!head) return head;
    node* temp = head->next;
    delete head;
    head = temp;
    return head;
}

node* removeAll(node* list, int value)
{
    if (!list) return list;
    while (list->value == value)
    {
        list = popFront(list);
    }
    node* curr = list;
    while (curr->next)
    {
        if (curr->next->value == value)
            removeAfter(curr);
        else curr = curr->next;
    }

    return list;
}

node* reverse(node* list)
{
    if (!list || !list->next) return list;
    node* prev = nullptr;
    node* curr = list;
    node* next = list->next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


int main()
{
    node* n1 = new node(2,new node(3) );
    node* head = new node(1, n1);
    node* list = new node(1, new node(2, new node(3, new node(4, new node(5)))));
    //insertAfter(n1, 8);
    //insertFront(head, 0);
    removeAfter(n1);
    printList(reverse(list));

    
}