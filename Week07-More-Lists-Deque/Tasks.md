# Задачи
**За задачите за двусвързан списък използвайте следната имплементация на node:**
```cpp
struct Node {
    int value;
    Node* prev;
    Node* next;

    Node() : value(0), prev(nullptr), next(nullptr) {}
    Node(int x) : value(x),  prev(nullptr), next(nullptr) {}
    Node(int x, Node* prev, Node* next) : value(x), prev(prev), next(next) {}
};
```

### Задача 1
Реализирайте функциите от интерфейса на двусвързания списък. Направете го като клас или подавайте `Node* head` като първи аргумент във всяка функция.
* **insertAfter/Before(pos, val), removeAfter/Before(pos) - О(1)**
* **insertFirst(val), removeFirst() - O(1)**
* **pushFront(val), popFront() - O(1)**
* **pushBack(val), popBack() - O(1)**

### Задача 
Да се дефинира функция `mirror`, която добавя към свързан списък неговото огледално копие.

```cpp
Вход:
1<->4<->5
Изход:
1<->4<->5<->5<->4<->1
```


### Задача 2
Да се дефинира функция, която да приема свързан списък и като резултат да връща дали в него има цикъл.


### Задача 1
Добавете следните карти към играта "Експлодиращи котета" от седмица 5:
- F - Виж бъдещето (See the Future) - Теглят се горните 3 карти, изписват се на екрана и се връщат в същия ред, в който са били.
- D - Тегли от дъното (Draw From the Bottom) - Тегли се най-долната карта

Променете използваната СД при нужда.

### Задача 
Реализирайте следните итератори:
* Forward iterator - за масив
* Forward iterator - за свързан списък
* Bidirectional iterator - за масив и двусвързан списък

*Bidirectional iterator включва всичко от forward и добавя `it--`*

---
[Задачи - leetcode](https://leetcode.com/problem-list/doubly-linked-list/)