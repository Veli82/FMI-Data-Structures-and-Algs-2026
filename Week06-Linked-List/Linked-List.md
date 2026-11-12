# Какво представлява:
Свързаният списък представлява линейна структура от данни, в която елементите НЕ СА последователни в паметта. Те се заделят динамично и се намират разпръснати в heap-a. Идеята е, че всеки елемент, освен стойността си, **пази и адреса на елемента след него в списъка**. Това се реализира с простата структура `node`.  
За да имаме свързан списък е достатъчно да пазим указател само към първия елемент. За да стигнем до даден елемент трябва да минем през всеки елемент, който е преди него в списъка. От тук идва линейната сложност за достъп до елемент.  
Понеже елементите не са последователни в паметта, не можем да се възползваме от locality.

![linked-list](https://media.geeksforgeeks.org/wp-content/uploads/20250619155958124670/Linked-list.webp)

# Интерфейс:
* търсене на елемент (по стойност) - **О(n)**
* добавяне или премахване на елемент на което и да е място (при условие, че имаме итератор сочещ към това място) - **О(1)**:  
**insertAfter(pos, val), removeAfter(pos)**
* **insertFirst(val), removeFirst() - O(1)**
* **pushBack(val), popBack() - O(n)**
* **isEmpty()** - проверява дали е празен - **О(1)**

# Реализация:
```cpp
struct node
{
    int data;
    node* next;
}

class Linked_list
{
    node* first;
    //node* last;   //optional --> push_back(el) - О(1)
    //size_t size;  //optional --> getSize() - О(1)
}
//the optional parts are not implemented in std::forward_list
```

# Клас в STL:
[forward_list-cppreference](https://en.cppreference.com/cpp/container/forward_list)
```cpp
#include <forward_list>   //include needed!

int main(){
    std::forward_list<int> linked_list;    //declaration
}
```

# Задачи
**За задачите използвайте следната имплементация на node:**
```cpp
 * struct Node {
 *     int value;
 *     Node* next;

 *     Node() : value(0), next(nullptr) {}
 *     Node(int x) : value(x), next(nullptr) {}
 *     Node(int x, Node *next) : value(x), next(next) {}
 * };
```
За упражнение може да направите и шаблон на Node (вместо да е само с int)

### Задача 0
Реализирайте функциите от интерфейса на свързания списък. Направете го като клас или подавайте `Node* head` като първи аргумент във всяка функция.
* **insertAfter(pos, val), removeAfter(pos) - О(1)**
* **insertFirst(val), removeFirst() - O(1)**
* **pushFront(val), popFront() - O(1)**
* **pushBack(val), popBack() - O(n)**
* **isEmpty()** - **О(1)**
* **find(val)** - **О(n)**


### Задача 1

Дефинирайте функция `unsigned int countOf(const Node* list, int value)`, която връща броя на
срещанията на `value` в списъка с начало `list`.

### Задача 2

Дефинирайте функция `Node* removeAll(Node* list, int value)`, която премахва всички
срещания на `value` от списъка с начало `list` и връща началото на така получения списък.

### Задача 3

Дефинирайте функция `Node* removeKth(Node* list, size_t k)`, която премахва всеки k-ти елемент
от списъка с начало `list` и връща началото на така получения списък.

```cpp
Вход:
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
k = 3
Изход:
1 -> 2 -> 4 -> 5 -> 7
```

### Задача 4

Да се напише функция `Node* reverse(Node* list)`, която обръща списъка с начало `list` и връща
новото му начало.

### Задача 5

Реализирайте функция `Node* cloneReversed(const Node* first)`, която:

1. Получава указател към първия елемент на свързан списък. Този списък не бива да бъде променян.
2. Създава нов списък, който съхранява същите стойности, но наредени в обратен ред. Например, ако
първоначалният списък има вида

1 -> 2 -> 3 -> 4 -> 5

, функцията създава копие, което има вида

5 -> 4 -> 3 -> 2 -> 1

Паметта за кутиите на новия списък да се заделя с `new`. Ако по време на копирането някое от
заделянията на памет не успее, функцията трябва да почисти паметта, преди да прекрати своята работа;
не бива да се допуска изтичане на памет. В този случай функкцията трябва да хвърли изключение от тип
`std::bad_alloc`.

3. Връща началото на новия списък. Ако `first` е `nullptr`, функцията да връща `nullptr`.


- [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/) - Easy
- [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/) - Easy
- [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) - Medium
- [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) - Medium
- [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/) - Medium

---
[Задачи - leetcode](https://leetcode.com/problem-list/linked-list/)