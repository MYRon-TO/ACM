#include <iostream>

typedef struct mGraph {
	bool** a;
	int n;
	int e;
	int start;
	int* d;
}MGraph;

void Init(MGraph* mg) {

	std::cin >> mg->n >> mg->e >> mg->start;

	mg->d = new int[mg->n];
	mg->a = new bool* [mg->n];
	for (int i = 0; i < mg->n; i++) {
		mg->d[i] = -1;
		mg->a[i] = new bool[mg->n];
		for (int j = 0; j < mg->n; j++)
			mg->a[i][j] = 0;
	}

	int m, n;

	for (int i = 0; i < mg->e; i++) {
		std::cin >> m >> n;
		mg->a[m][n] = 1;
	}
	/*
	for (int i = 0; i < mg->n; i++) {
		for (int j = 0; j < mg->n; j++)
			std::cout << mg->a[i][j] << " ";
		std::cout << std::endl;
	}
	*/
}

class Queue {
public:
	void Push(int i) {
		a[num] = i;
		num++;
	}
	int OutQueue() {
		first++;
		return a[first - 1];
	}

	bool IsEmpty() {
		return first == num;
	}
protected:
	int a[255] = { 0 };
	int num = 0;
	int first = 0;
private:

};


void BFS(int v, bool visited[], MGraph* mg) {
	Queue q;
	visited[v] = 1;
	//std::cout << v << " ";
	q.Push(v);
	int k = 0;
	while (!q.IsEmpty()) {
		v = q.OutQueue();
		k++;
		for (int j = 0; j < mg->n; j++) {
			if (!visited[j] && mg->a[v][j]) {
				visited[j] = 1;
				mg->d[j] = k;
				//std::cout <<k<<std::endl;
				q.Push(j);

			}
		}
	}

}

void BFS(MGraph* mg) {
	bool* visited = new bool[mg->n];
	for (int i = 0; i < mg->n; i++)
		visited[i] = 0;

	BFS(mg->start, visited, mg);
}

int main() {
	MGraph mg;
	Init(&mg);
	BFS(&mg);
	for (int i = 0; i < mg.n; i++) {
		if (i != mg.start) {
			std::cout << mg.d[i] << std::endl;
		}
	}

	return 0;
}