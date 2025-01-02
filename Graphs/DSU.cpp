#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

class DSU
{
	public:
	DSU(int n) : sets(n)
	{
		parent = gsize = vector < int >(n + 1, 0);
		for (int i = 1; i <= n; i++)
			parent[i] = i;
	}
	int get_parent(int u)
	{
		return parent[u] == u ? u : parent[u] = get_parent(parent[u]);
	}
	void join(int u, int v)
	{
		u = get_parent(u), v = get_parent(v);
		if (u == v) return;
		if (gsize[u] < gsize[v]) swap(u, v);
		parent[v] = u;
		gsize[u] += gsize[v];
		sets--;
	}
	int getSets()
	{
		return sets;
	}
	private:
	vector < int > parent, gsize;
	int sets;

};


void Solve()
{
}

int main()
{
#if LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	//cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		Solve();
		cout << "\n";
	}
	return 0;
}
