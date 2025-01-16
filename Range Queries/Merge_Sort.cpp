/*
Merge Sort Tree with Point Update and Range Query using Sqrt Decomposition

*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()


template<typename T>
class Merge_Sort_Tree {
    // 1-Based
    private:
    int n;
    static const int MAX_N = 2e5 + 5; // TODO
    static const int len = 450; // TODO
    vector<T> a;
    vector<vector<T>> b;
    inline int blk_idx(int idx) { return idx / len; }
    inline int get(int idx, T val, bool is_block = 0) // TODO
    {
        if (is_block) {
            idx = blk_idx(idx);
            return sz(b[idx]) - (lower_bound(all(b[idx]), val) - b[idx].begin());
        }
        return a[idx] >= val;
    }

    public:
    Merge_Sort_Tree(int N, const vector<T> &vec)
    {
        n = N, a = vec;
        b = vector<vector<T>>(len + 5);

        for (int i = 1; i <= n; i++)
            b[blk_idx(i)].push_back(a[i]);
        for (int i = 0; i <= len; i++)
            sort(all(b[i]));
    }

    void update(int idx, T val)
    {
        int k = blk_idx(idx);
        int j = lower_bound(all(b[k]), a[idx]) - b[k].begin();
        b[k][j] = a[idx] = val;
        sort(all(b[k]));
    }

    int query(int L, int R, T x)
    {
        int res = 0;
        while (L <= R) {
            if (L % len == 0 && L + len - 1 <= R) {
                res += get(L, x, 1);
                L += len;
            }
            else {
                res += get(L++, x);
            }
        }
        return res;
    }
};

void Solve()
{
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        Solve();
        cout << "\n";
    }
    return 0;
}
