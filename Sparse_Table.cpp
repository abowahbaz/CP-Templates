#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

template < typename T > class Sparse_Table
{
private:
	int max_size = 32, k;
	typedef vector < T > vt;
	vector < vt > table;

	const T none = 0; 				// TODO
	T merge(T a, T b)
	{
		return (a + b); 			// TODO
	}

public:
	Sparse_Table(const vt values)
	{
		int n = values.size();
		k = max_size - __builtin_clz(n);
		table.resize(k, vt(n));
		for (int i = 0; i < n; i++)
			table[0][i] = values[i];

		for (int j = 1; j <= k; j++)
		{
			for (int i = 0; i + (1 << j) <= n; i++)
			{
				int z = j - 1;
				table[j][i] = merge(table[z][i], table[z][i + (1 << (z))]);
			}
		}
	}

	T query(int l, int r) // ! should be same base as the array
	{
		T ret = none;
		for (int i = k;i >= 0;i--)
			if ((1 << i) <= r - l + 1) {
				ret = merge(table[i][l], ret);
				l += 1 << i;
			}
		return ret;
	}
};


void Solve()
{
}

signed main()
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
