#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

struct Node
{
	ll val;
	Node(ll v = 0) : val(v) {}
};

template <typename T>
class SegTree // 1-based
{
	private:
	int tree_size;
	vector<Node> seg; // 1-based
	Node merge(const Node &a, const Node &b)
	{
		return a.val + b.val; // TODO
	}
	void init(int n)
	{
		tree_size = 1;
		while (tree_size < n) tree_size <<= 1;
		seg.resize(tree_size << 1);
	}
	void build(const vector<T> &a) // 1-based array
	{
		int n = sz(a) - 1;
		for (int i = 1;i <= n;i++)
			seg[tree_size + i].val = a[i];
		for (int i = tree_size - 1;i >= 1;i--)
			seg[i] = merge(seg[2 * i], seg[2 * i + 1]);
	}

	public:
	SegTree(int n) { init(n); }
	SegTree(const vector<T> &a) { // 1-based array
		int n = sz(a) - 1;
		init(n), build(a);
	}
	void update(int idx, T val) {
		idx += tree_size;
		seg[idx].val = val;
		for (idx >>= 1;idx >= 1;idx >>= 1)
			seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);

	}
	T query(int l, int r) {
		Node res;
		l += tree_size, r += tree_size;
		while (l <= r)
		{
			if (l & 1) res = merge(res, seg[l++]);
			if (!(r & 1)) res = merge(res, seg[r--]);
			l >>= 1, r >>= 1;
		}
		return res.val;
	}
};

void solve()
{
}

signed main()
{
#if LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t = 1; // cin>>t;
	while (t--)
		solve();
	return 0;
}
