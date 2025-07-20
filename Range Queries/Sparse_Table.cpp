#include <bits/stdc++.h>
using namespace std;
#define ll long long

template < typename T > class Sparse_Table
{
	private:
	const int LOG = 32;
	int k;
	vector < vector < T > > table;

	const T none = 0; 				// TODO
	T merge(T a, T b)
	{
		return (a + b); 			// TODO
	}

	public:
	Sparse_Table(const vector < T > values)
	{
		int n = values.size();
		k = LOG - __builtin_clz(n);
		table.resize(k, vector < T >(n));
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

	T query(int L, int R) // ! should be same base as the array
	{
		T ret = none;
		for (int i = k;i >= 0;i--)
			if ((1 << i) <= R - L + 1) {
				ret = merge(table[i][L], ret);
				L += 1 << i;
			}
		return ret;
	}
};