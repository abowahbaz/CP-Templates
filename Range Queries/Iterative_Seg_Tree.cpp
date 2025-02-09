#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

template < typename T > class Segment_Tree
{
	public:
	struct Node
	{
		T val;
		Node(T v = 0) : val(v) {}
	};
	Segment_Tree(int N) { init(N); }
	Segment_Tree(const vector < T > &a) { init(a.size()); Build(a); }
	void update(int idx, T val)
	{
		idx += n;
		tree[idx].val = val;
		for (idx /= 2; idx >= 1; idx /= 2)
		{
			tree[idx] = merge(tree[idx * 2], tree[(idx * 2) | 1]);
		}
	}
	T query(int l, int r)
	{
		Node res;
		while (l <= r)
		{
			if (l & 1) res = merge(res, tree[l++]);
			if (!(r & 1)) res = merge(res, tree[r--]);
			l >>= 1;
			r >>= 1;
		}
		return res.val;
	}
	private:
	int n;
	vector < Node > tree;
	void init(int N)
	{
		n = 1;
		while (n < N) n <<= 1;
		tree.resize((2 * n) + 1);
	}
	Node merge(const Node &a, const Node &b)
	{
		return Node(a.val + b.val);
	}

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
	}
	return 0;
}
