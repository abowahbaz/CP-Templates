#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

template<typename T> class Fenwick_Tree
{
    private:
    vector<T> BIT;
    int n;
    public:
    Fenwick_Tree(int n, const vector<T> &arr) : n(n)
    {
        BIT.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            BIT[i] = arr[i];
        }
    }
    void assign(int idx, T val)
    {
        T prev_val = query(idx, idx);
        T diff = val - prev_val;
        add(idx, diff);
    }
    void add(int idx, T val)
    {
        for (; idx <= n; idx += idx & -idx) {
            BIT[idx] += val;
        }
    }
    T query(int idx)
    {
        T ans = 0;
        for (; idx > 0; idx -= idx & -idx) {
            ans += BIT[idx];
        }
        return ans;
    }
    T query(int L, int R)
    {
        return query(R) - query(L - 1);
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
