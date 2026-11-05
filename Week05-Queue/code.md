
Това е задача 3 - решението което направихме в час (изнесено във функция).
За улеснение може да направим 2 неща (за които не се сетих навреме 🥲):
1. Добавяме променлива levelSize и още един цикъл (между двата сегашни) който да върти до levelSize. Така знаем, кога е моментът, в който едното ниво свършва и почва другото (т.е. възможните ходове с n стъпки са изчерпани и започваме тези с n+1). Не е нужно всеки елемент да влачи дълбочината си, променливата moves отговаря на търсеното от задачата. Кодът, който трябва да добавим изглежда като нещо такова:
``` cpp
//...
int moves = 0;
while (!q.empty())
{
        int levelSize = q.size();  // process the queue level by level
        ++moves;
 
        for (int i = 0; i < levelSize; ++i) {
            std::pair<int, int> curr = q.front();
            q.pop();
 
            for (int d = 0; d < 8; ++d) {
                //...
```
2. Може директно да проверяваме дали позициите са visited преди да ги добавяме в опашката, не след като ги извадим.

```cpp
#include<stack>
#include<string>
#include<vector>
#include <iostream>
#include <utility>
#include <queue>


struct Pos
{
	int x;
	int y;
	int depth = 0;
};

const Pos arr[8]
{
	{1, 2}, {2, 1}, {-1, -2}, {-2,-1},
	{1, -2}, {-1, 2}, {2, -1}, {-2, 1}
};

Pos operator+(const Pos& rhs, const Pos& lhs)
{
	return { rhs.x + lhs.x, rhs.y + lhs.y , rhs.depth + lhs.depth};
}

bool operator==(const Pos& rhs, const Pos& lhs)
{
	return rhs.x == lhs.x && rhs.y == lhs.y;
}


const int BOARD_SIZE = 8;

bool isValid(Pos p)
{
	return p.x < BOARD_SIZE && p.x >= 0 && p.y < BOARD_SIZE && p.y >= 0;
}

int getMinStepsToPos(const Pos& knight,const Pos& dest)
{
	if (!isValid(knight) || !isValid(dest)) throw std::runtime_error("invalid input");
	bool visited[BOARD_SIZE][BOARD_SIZE]{};
	std::queue<Pos> q;
	q.push(knight);

	while (!q.empty())
	{
		Pos curr = q.front();
		q.pop();
		if (visited[curr.x][curr.y]) continue;
		if (curr == dest) return curr.depth;

		for (int i = 0; i < 8; i++)
		{
			Pos next = curr + arr[i];
			next.depth++;
			if (isValid(next))
				q.push(next);

		}
		visited[curr.x][curr.y] = true;
	}
	return -1;
}


int main()
{
	Pos knight = { 2,1 };
	Pos dest = { 0,1 };
	
	std::cout << getMinStepsToPos(knight, dest);
	
}

```