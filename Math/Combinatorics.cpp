#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

struct Combinatorics
{
    private:
    const int MOD = 1e9 + 7;
    vector<ll> fact, inv_fact, inv;
    public:
    Combinatorics(int n, int mod = 1e9 + 7) :MOD(mod)
    {
        fact.resize(n + 1);
        inv_fact.resize(n + 1);
        inv.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        inv[1] = 1;
        for (int i = 2; i <= n; i++) {
            inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
        }
        inv_fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            inv_fact[i] = (inv_fact[i - 1] * inv[i]) % MOD;
        }
    }
    ll nCr(int n, int r)
    {
        if (r < 0 || r > n) {
            return 0;
        }
        return (fact[n] * inv_fact[r] % MOD) * inv_fact[n - r] % MOD;
    }
    ll nPr(int n, int r)
    {
        if (r < 0 || r > n) {
            return 0;
        }
        return (fact[n] * inv_fact[n - r]) % MOD;
    }
    ll catalan(int n)
    {
        return nCr(2 * n, n) * inv[n + 1] % MOD;
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
