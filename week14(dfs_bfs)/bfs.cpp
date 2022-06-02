#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> graph[101];
bool visited[101];

void bfs(int x) {
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		if (visited[front]) continue;
		cout << front << " ";
		visited[front] = true;
		for (int i : graph[front]) {
			if (!visited[i]){
				q.push(i);
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		while (m--) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		bfs(1);
		cout << endl;
		for (int i = 1; i <= n; i++) {
			graph[i].clear();
			visited[i] = false;
		}
	}
}