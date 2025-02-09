#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

class DSU
{
	private:
	vector < int > parent, gsize;
	int sets;
	public:
	DSU(int n) : sets(n)
	{
		parent = gsize = vector < int >(n + 1, 1);
		for (int i = 1; i <= n; i++)
			parent[i] = i;
	}
	int find(int u)
	{
		return parent[u] == u ? u : parent[u] = find(parent[u]);
	}
	void join(int u, int v)
	{
		u = find(u), v = find(v);
		if (u == v) return;
		if (gsize[u] < gsize[v]) swap(u, v);
		parent[v] = u;
		gsize[u] += gsize[v];
		sets--;
	}
	int get_sets() { return sets; }
	bool same(int u, int v) { return find(u) == find(v); }
};


void solve()
{
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	//cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		solve();
		cout << "\n";
	}
	return 0;
}
