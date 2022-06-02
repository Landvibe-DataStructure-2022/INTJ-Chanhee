#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> graph[101];
bool visited[101];
int composize = 0;

void dfs(int x) {
	visited[x] = true;
	composize++;
	for (int i : graph[x]) {
		if (!visited[i]) {
			dfs(i);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		while (m--) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		while (k--) {
			composize = 0;
			int c;
			cin >> c;
			dfs(c);
			cout << composize << endl;
			for (int i = 1; i <= n; i++) {
				visited[i] = false;
			}
		}
		for (int i = 1; i <= n; i++) {
			graph[i].clear();
		}
	}
}
