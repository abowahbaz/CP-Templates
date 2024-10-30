#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()


template < typename T = int > class FenwickTree
{
    private:
    vector < T > BIT, values;
    int sz = 2E5 + 5;
    T def = 0;

    inline void init(int n, T def = 0) {
        sz = n + 1;
        this->def = def;
        values = BIT = vector < T >(sz + 1, def);
    }

    int lstOne(int x)
    {
        return (x & -x);
    }
   
     // TODO: change merge and unmerge functions according to the problem

    T merge(T a, T b) { return (a + b); }

    T unmerge(T a, T b) { return (a - b); }

    public:
    FenwickTree(int n, T def = 0) { init(n, def); }
    FenwickTree(const vector < T >& arr, T def = 0)
    {
        init(sz(arr), def);
        for (int i = 1; i < sz(arr); i++)
        {
            update(i, arr[i]);
        }
    }

    void update(int idx, T val)
    {
        // increase idx by value val
        values[idx] += val;
        while (idx < sz)
        {
            BIT[idx] += val;
            idx += lstOne(idx);
        }
    }

    T get(int idx)
    {
        T ret = def;
        while (idx > 0) {
            ret = merge(ret, BIT[idx]);
            idx -= lstOne(idx);
        }
        return ret;
    }

    T queryRange(int l, int r)
    {
        if (l > r)swap(l, r);
        return unmerge(get(r), get(l - 1));
    }
    T queryValue(int idx)
    {
        return queryRange(idx, idx);
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
        cout << "\n";
    }
    return 0;
}
