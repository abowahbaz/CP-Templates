#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
#define nl "\n"
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()
#define add_mod(a,b,m) ((a%m) + (b%m) + m)%m
#define sub_mod(a,b,m) ((a%m) - (b%m) + m)%m
#define mul_mod(a,b,m) ((a%m) * (b%m) + m)%m
#define Sekiro cin.tie(0)->sync_with_stdio(0)
#define bits(x) __builtin_popcountll(x)
#define exec_time high_resolution_clock::now()
#define getunique(v) {sort(all(v));v.erase(unique(all(v)),v.end());}

typedef long long ll;
const int MOD = 1E9 + 7;

// less_equal<T> for multiset
template<typename T> using ordered_set = tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;

/*
    What a fine specimen you have become , Wolf
    - The Great Shinobi Owl.
*/

class SegmentTree
{
    private:
    // problem specific
    using T = ll;
    int n = 1;
    vector<T>seg;
    // problem specific
    const T none = 0;
    T merge(const T& a, const T& b)
    {
        // problem specific
        return (a + b);
    }
    void init(int N)
    {
        while (n < N) n <<= 1;
        seg.resize(n * 2, none);
    }
    void build(const vector<T>& arr) // assuming array is one based
    {
        for (int i = 1;i < arr.size();i++)
            update(i, arr[i]);
    }
    public:
    SegmentTree() {};
    SegmentTree(const vector<T>& arr)
    {
        init(arr.size()), build(arr);
    }
    // Optional Constructor
    SegmentTree(const int n) { init(n); }

    void update(int idx, T val)
    {
        idx += n;
        seg[idx] = val;
        for (idx >>= 1;idx >= 1;idx >>= 1)
            seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }

    T query(int l, int r)
    {
        if (l > r) swap(l, r);
        l += n, r += n;
        T result = none;
        while (l <= r)
        {
            if ((l & 1)) result = merge(result, seg[l++]);
            if (!(r & 1)) result = merge(result, seg[r--]);
            l >>= 1, r >>= 1;
        }
        return result;
    }

    // Optional Operator Overloading
    SegmentTree operator =(const SegmentTree other)
    {
        this->n = other.n;
        this->seg = other.seg;
        return *this;
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
    Sekiro;
    int t = 1;
    //cin >> t;
    cout << fixed << setprecision(12);
    auto t1 = exec_time;
    for (int tc = 1; tc <= t; tc++)
    {
        Solve();
    }
    auto t2 = exec_time;
    cerr << "Time : " << duration_cast<milliseconds>(t2 - t1).count() << " ms\n";
    return 0;
}
