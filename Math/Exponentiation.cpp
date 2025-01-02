#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

ll bin_pow(ll x, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = res * x;
        x = x * x;
        n >>= 1;
    }
    return res;
}

ll bin_pow_mod(ll x, ll n, ll mod)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x, ll mod)
{
    return bin_pow_mod(x, mod - 2, mod);
}

vector<int>apply_permutation(vector<int> &a, vector<int> &p)
{
    int n = sz(a);
    vector<int>res(n);
    for (int i = 0; i < n; i++)
    {
        res[i] = a[p[i]];
    }
    return res;
}

vector<int>permute_k_times(vector<int> &a, vector<int> &p, int k)
{
    while (k > 0)
    {
        if (k & 1)
            a = apply_permutation(a, p);
        p = apply_permutation(p, p);
        k >>= 1;
    }
    return a;
}


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
