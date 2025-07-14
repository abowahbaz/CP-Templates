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
    void update(int t, int tl, int tr, int idx, T val)
    {
        if (tl == tr)
        {
            seg[t] = val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (idx <= tm)
            update(2 * t, tl, tm, idx, val);
        else
            update(2 * t + 1, tm + 1, tr, idx, val);
        seg[t] = merge(seg[2 * t], seg[2 * t + 1]);
    }
    Node query(int t, int tl, int tr, int l, int r)
    {
        if (r < tl || l > tr)
            return Node();
        if (tl >= l && tr <= r)
            return seg[t];
        int tm = (tl + tr) / 2;
        return merge(query(2 * t, tl, tm, l, r), query(2 * t + 1, tm + 1, tr, l, r));
    }
    void init(int n)
    {
        tree_size = 1;
        while (tree_size < n)
            tree_size <<= 1;
        seg.resize(tree_size << 1);
    }
    void build(int t, int tl, int tr, const vector<T> &a)
    {
        if (tl == tr)
        {
            seg[t] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * t, tl, tm, a);
        build(2 * t + 1, tm + 1, tr, a);
        seg[t] = merge(seg[2 * t], seg[2 * t + 1]);
    }

    public:
    SegTree(int n) { init(n); }
    SegTree(const vector<T> &a) { // 1-based array
        int n = sz(a) - 1;
        init(n);
        build(1, 1, tree_size, a);

    }
    void update(int idx, T val) {
        update(1, 1, tree_size, idx, val);
    }
    T query(int l, int r) {
        return query(1, 1, tree_size, l, r).val;
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
