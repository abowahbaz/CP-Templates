#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

template <typename T> class SegTree // 1-based
{
    public:
    struct Node
    {
        T val;
        Node(T v = 0) : val(v) {}
        Node operator=(const T val)
        {
            this->val = val;
            return *this;
        }
    };
    SegTree(int n) { init(n); }
    SegTree(const vector<T> &a) { // 1-based array
        int sz = sz(a) - 1;
        init(sz);
        build(1, 1, tree_size, a);

    }
    void update(int idx, T val) {
        update(1, 1, tree_size, idx, val);
    }
    T query(int l, int r) {
        return query(1, 1, tree_size, l, r).val;
    }

    private:
    int tree_size;
    vector<Node> tree; // 1-based
    Node none = 0LL; // TODO
    Node merge(const Node &a, const Node &b)
    {
        return a.val + b.val; // TODO
    }
    void update(int t, int tl, int tr, int idx, T val)
    {
        if (tl == tr)
        {
            tree[t] = val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (idx <= tm)
            update(2 * t, tl, tm, idx, val);
        else
            update(2 * t + 1, tm + 1, tr, idx, val);
        tree[t] = merge(tree[2 * t], tree[2 * t + 1]);
    }
    Node query(int t, int tl, int tr, int l, int r)
    {
        if (r < tl || l > tr)
            return none;
        if (tl >= l && tr <= r)
            return tree[t];
        int tm = (tl + tr) / 2;
        return merge(query(2 * t, tl, tm, l, r), query(2 * t + 1, tm + 1, tr, l, r));
    }
    void init(int n)
    {
        tree_size = 1;
        while (tree_size < n)
            tree_size *= 2;
        tree.assign(2 * tree_size, none);
    }
    void build(int t, int tl, int tr, const vector<T> &a)
    {
        if (tl == tr)
        {
            tree[t] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * t, tl, tm, a);
        build(2 * t + 1, tm + 1, tr, a);
        tree[t] = merge(tree[2 * t], tree[2 * t + 1]);
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
