#include <iostream>

typedef struct mGraph {
	bool** a;
	int n;
	int e;
}MGraph;

void Init(MGraph* mg) {
	
	std::cin >> mg->n >> mg->e;

	mg->a = new bool*[mg->n];
	for (int i = 0; i < mg->n; i++) {
		mg->a[i] = new bool[mg->n];
		for (int j = 0; j < mg->n; j++)
			mg->a[i][j] = 0;
	}

	int m, n;

	for (int i = 0; i < mg->e; i++) {
		std::cin >> m >> n;
		mg->a[m][n] = 1;
		mg->a[n][m] = 1;
	}

	for (int i = 0; i < mg->n; i++) {
		for (int j = 0; j < mg->n; j++)
			std::cout << mg->a[i][j] << " ";
		std::cout << std::endl;
	}
}

void DFS(int v, bool visited[], const MGraph* mg) {
	visited[v] = 1;
	std::cout << v<<" ";
	for (int j = 0;j <= mg->n; j++) {
		if (!visited[j]&&mg->a[v][j]) {
			DFS(j, visited, mg);
		}
	}
}

void DFS(const MGraph *mg) {
	bool* visited = new bool[mg->n];
	for (int i = 0; i < mg->n; i++)
		visited[i] = 0;
	for(int i=0;i<mg->n;i++)
		if (!visited[i])
			DFS(i, visited, mg);
}

int main() {
	MGraph mg;
	Init(&mg);
	DFS(&mg);
	return 0;
}