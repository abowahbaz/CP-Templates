#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
 Sqrt Decomposition is more like an adhoc algorithm,
 the below implementation is just an example of point update range sum
 https://cses.fi/problemset/task/1648
 */

struct Sqrt_Decomposition {
    private:
    static const int MAX_N = 2e5 + 5; // TODO
    static const int len = 450; // TODO
    vector<ll> blk, arr;
    int blk_idx(int idx) { return idx / len; }

    public:
    Sqrt_Decomposition(const vector<ll> &nums)
    {
        int n = (int)nums.size();
        arr.resize(n);
        blk.resize(len);
        // one-based
        for (int i = 1; i < n; i++) {
            update(i, nums[i]);
        }
    }

    void update(int idx, ll val)
    {
        blk[blk_idx(idx)] -= arr[idx];
        blk[blk_idx(idx)] += val;
        arr[idx] = val;
    }

    ll query(int L, int R) // one-based
    {
        ll ans = 0;
        while (L <= R) {
            if (L % len == 0 && L + len <= R) {
                ans += blk[blk_idx(L)];
                L += len;
            }
            else {
                ans += arr[L];
                L++;
            }
        }
        return ans;
    }
};
