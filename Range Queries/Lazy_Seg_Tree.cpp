#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    ll val, lazy;    bool is_lazy;
    Node(ll x = 0) { val = x, lazy = 0, is_lazy = 0; }
    void change(ll x, int tl, int tr)
    {
        val += x * (tr - tl);
        lazy += x;
        is_lazy = 1;
    }
};

template<typename T>
class LazySegTree {
    private:
    int tree_size;
    vector<Node>seg;

    Node merge(const Node &a, const Node &b) {
        return Node(a.val + b.val);
    }
    void propagate(int t, int tl, int tr) {
        if (!seg[t].is_lazy || tl - tr == 1) return;
        int tm = (tl + tr) / 2;
        seg[2 * t].change(seg[t].lazy, tl, tm);
        seg[2 * t + 1].change(seg[t].lazy, tm, tr);
        seg[t].lazy = 0, seg[t].is_lazy = 0;
    }

    void build(int t, int tl, int tr, const vector<T> &arr)
    {
        if (tl >= arr.size()) return;
        if (tl == tr)
        {
            seg[t] = Node(arr[tl]);
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * t, tl, tm, arr);
        build(2 * t + 1, tm + 1, tr, arr);
        seg[t] = merge(seg[2 * t], seg[2 * t + 1]);
    }
    void update(int t, int tl, int tr, int l, int r, ll val)
    {
        propagate(t, tl, tr);
        if (r < tl || l > tr)
            return;
        if (tl >= l && tr <= r)
        {
            seg[t].change(val, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        update(2 * t, tl, tm, l, r, val);
        update(2 * t + 1, tm + 1, tr, l, r, val);
        seg[t] = merge(seg[2 * t], seg[2 * t + 1]);
    }
    Node query(int t, int tl, int tr, int l, int r)
    {
        propagate(t, tl, tr);
        if (r < tl || l > tr)
            return Node();
        if (tl >= l && tr <= r)
            return seg[t];
        int tm = (tl + tr) / 2;
        return merge(query(2 * t, tl, tm, l, r), query(2 * t + 1, tm + 1, tr, l, r));
    }
    void init(int n) {
        tree_size = 1;
        while (tree_size < n) tree_size <<= 1;
        seg.resize(tree_size << 1);
    }

    public:
    LazySegTree(int n) { init(n); }
    // one-based array
    LazySegTree(const vector<T> &arr) {
        int n = arr.size() - 1;
        init(n);
        build(1, 1, tree_size, arr);
    }
    void update(int l, int r, ll val)
    {
        update(1, 1, tree_size, l, r, val);
    }
    Node query(int l, int r)
    {
        return query(1, 1, tree_size, l, r);
    }
};