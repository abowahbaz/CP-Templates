#include<bits/stdc++.h>
using namespace std;
#define ll long long

template<typename T> class BIT {
    vector<T>tree;
    int n;
    public:
    BIT(int N) : n(N) {
        tree.resize(n + 1, 0);
    }
    BIT(const vector<T> &a) : n(a.size()) {
        tree.resize(n + 1, 0);
        for (int i = 0; i < n; i++)
            update(i + 1, a[i]);
    }
    void update(int idx, T delta) {
        for (; idx <= n; idx += idx & -idx)
            tree[idx] += delta;
    }
    T query(int idx) {
        T res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += tree[idx];
        return res;
    }
    T query(int l, int r) { return query(r) - query(l - 1); }

};