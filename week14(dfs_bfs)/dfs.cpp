
#include<iostream>
#include<vector>
using namespace std;

vector<int> graph[101];
int visited[101];

void dfs(int x) {
	cout << x << " ";
	visited[x] = true;
	for (int i : graph[x]) {
		if (!visited[i]) {
			dfs(i);
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		dfs(1);
		cout << 
		for (int j = 1; j <= n; j++) {
			graph[j].clear();
			visited[j] = false;
		}
	}
}