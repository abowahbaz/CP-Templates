#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

template < typename T > class SegmentTree
{
public:
	struct Node
	{
		T val;
		Node(T v = 0) : val(v) {}
	};
	SegmentTree(int N) { Init(N); }
	SegmentTree(const vector < T >& a) { Init(a.size()); Build(a); }
	void Update(int idx, T val)
	{
		idx += n;
		tree[idx].val = val;
		for (idx /= 2; idx >= 1; idx /= 2)
		{
			tree[idx] = Merge(tree[idx * 2], tree[(idx * 2) | 1]);
		}
	}
	Node Query(int l, int r)
	{
		Node res;
		for (l += n, r += n; l <= r; l /= 2, r /= 2)
		{
			if (l & 1) res = Merge(res, tree[l++]);
			if (!(r & 1)) res = Merge(res, tree[r--]);
		}
		return res;
	}
private:
	int n;
	vector < Node > tree;
	void Init(int N)
	{
		n = 1;
		while (n < N) n <<= 1;
		tree.resize((2 * n) + 1);
	}
	Node Merge(const Node& a, const Node& b)
	{
		return Node(a.val + b.val);
	}
	void Build(const vector < T >& a)
	{
		for (int i = 1; i < sz(a); i++)
		{
			tree[i + n] = Node(a[i]);
		}
		for (int i = n - 1; i >= 1; i--)
		{
			tree[i] = Merge(tree[i * 2], tree[(i * 2) | 1]);
		}
	}
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
	}
	return 0;
}
