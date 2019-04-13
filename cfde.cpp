#include <bits/stdc++.h>

using namespace std;

int n, m, D;
vector<vector<int>> g;

int cnt;
vector<int> p, color;
vector<pair<int, int>> ans;

mt19937 rnd(time(NULL));

void bfs(int s, int bad) {
	queue<int> q;
	q.push(s);
	color[s] = cnt;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (p[v] != -1) {
			if (rnd() & 1) ans.push_back(make_pair(p[v], v));
			else ans.push_back(make_pair(v, p[v]));
		}
		for (auto to : g[v]) {
			if (to == bad || color[to] != -1) continue;
			p[to] = v;
			color[to] = cnt;
			q.push(to);
		}
	}
	++cnt;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m >> D;
	g = vector<vector<int>>(n);
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	p = color = vector<int>(n, -1);
	cnt = 0;
	for (int i = 1; i < n; ++i) {
		if (color[i] == -1) {
			bfs(i, 0);
		}
	}
	
	if (cnt > D || D > int(g[0].size())) {
		cout << "NO" << endl;
		return 0;
	}
	
	sort(g[0].begin(), g[0].end(), [](int a, int b) {
		return color[a] < color[b];
	});
	
	for (int i = 0; i < int(g[0].size()); ++i) {
		if (i == 0 || color[g[0][i]] != color[g[0][i - 1]]) {
			ans.push_back(make_pair(0, g[0][i]));
		}
	}
	D -= cnt;
	for (int i = 1; i < int(g[0].size()); ++i) {
		if (D == 0) break;
		if (color[g[0][i]] == color[g[0][i - 1]]) {
			ans.push_back(make_pair(0, g[0][i]));
			--D;
		}
	}
	
	g = vector<vector<int>>(n);
	for (auto it : ans) {
		g[it.first].push_back(it.second);
		g[it.second].push_back(it.first);
	}
	ans.clear();
	p = color = vector<int>(n, -1);
	cnt = 0;
	bfs(0, -1);
	
	shuffle(ans.begin(), ans.end(), rnd);
	cout << "YES" << endl;
	for (auto it : ans) {
		cout << it.first + 1 << " " << it.second + 1 << endl;
	}
	
	return 0;
}

