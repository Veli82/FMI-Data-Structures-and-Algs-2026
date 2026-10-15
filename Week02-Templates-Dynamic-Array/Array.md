# Какво представлява:
Както вече знаем, масивът представлява последователни клетки в паметта с фиксиран брой. Динамичният масив се уголемява динамично (по време на изпълнение на програмата), когато искаме да добавим елемент и мястото в него не е достатъчно. Този процес на *преоразмеряване* (resize), включва заделяне на нова памет (по голяма), прехвърляне на елементите и освобождаване на старата. Това причинява амортизираната сложност при добавяне на елемент в края на динамичния масив.  
Важно е да отбележим, че масивът се възползва от **locality**.

![array](https://deen3evddmddt.cloudfront.net/uploads/content-images/array-data-structure.webp)

# Интерфейс:
* достъп (четене или промяна) до елемент по индекс - **О(1)**
* търсене на елемент (по стойност) - **О(n)**
* добавяне на елемент в края - **О(1)** - амортизирано за динамичен масив! (иначе е О(n))
* добавяне на елемнет в началото/средата - **О(n)**
* премахване на елемент по индекс: със запазване на реда - **О(n)**, без запазване - **О(1)**
* премахване на последен елемент - **О(1)**
* size() - връща броя на елементите - **О(1)**
* isEmpty() - проверява дали е празен - **О(1)** //не съм сиг

При *сортиран* масив имаме следните разлики:
* търсене на елемент - **О(logN)** (binary search)
* добавяне, премахване, промяна на елемент - **O(n)**

# Имплементация:
```cpp
template <class T>
class vector
{
    T* array;   //pointer to dynamically allocated memory
    int size;   //curr number of elements
    int cap;    //max number of elements for the currently allocated memory

    //if (size == cap) resize();
}
```

# Клас в STL:
[Vector - cppreference](https://www.cppreference.com/cpp/container/vector) - Динамичен масив\
[Array - cppreference](https://www.cppreference.com/cpp/container/array) - Масив с фиксирана дължина
```cpp
#include <vector>   //needed for vector!
#include <array>    //needed for array!

int main(){
    std::vector<int> vector;    //dynamic array of type int
    std::array<int,10> array;   //array of type int with fixed length (10 in this example)
}
```

# Задачи
### Задача 1
Да се реализира шаблонен клас на динамичен масив, който да има коректна голяма четворка и метод `push_back(const T& elem)`, който да добавя елемент на края на масива.

### Задача 2
Към горната реализация на динамичен масив добавете функциите:
- clear, insert, erase, pop_back
- at, op[], data, empty, size, 
- оператори за равенство и сравнение

---
[Задачи - leetcode](https://leetcode.com/problem-list/array/)