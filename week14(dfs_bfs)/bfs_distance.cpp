#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> graph[101];
bool visited[101];

int bfs(int start, int end) {
	queue<pair<int, int>> q;
	q.push({ start,0 });
	while (!q.empty()) {
		int front = q.front().first;
		int count = q.front().second;
		q.pop();
		if (front == end) return count;
		if (visited[front]) continue;
		visited[front] = true;
		for (int i : graph[front]) {
			if (!visited[i]) {
				q.push({ i,count + 1 });
			}
		}
	}
	return 0;
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
			int c, d;
			cin >> c >> d;
			cout << bfs(c, d) << endl;
			for (int i = 1; i <= n; i++) {
				visited[i] = false;
			}
		}
		for (int i = 1; i <= n; i++) {
			graph[i].clear();
		}
	}
}