#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(st) (int)st.size()
#define all(st) st.begin(), st.end()

struct CountLib
{
    private:
    const int MOD = 1e9 + 7;
    vector<ll> fact, inv_fact, inv;
    public:
    CountLib(int n, int mod = 1e9 + 7) :MOD(mod)
    {
        fact = inv_fact = inv = vector < ll >(n + 1);
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
};
const int N = 2e5 + 5, Mod = 1e9 + 7; // TODO
CountLib C(N, Mod);
ll mul_mod(ll a, ll b) { return ((a % Mod) * (b % Mod)) % Mod; }

// returns the number of solutions to the equation
// x_1 + x_2 + ... + x_n = s and 0 <= l <= x_i <= r
ll count_solutions(ll n, ll s, ll l, ll r)
{
    if (s < l * n) return 0;
    s -= l * n;
    r -= l;
    ll ans = 0;
    for (int k = 0; k <= n; k++) {
        ll cur = mul_mod(C.nCr(s - k - k * r + n - 1 + 1, n - 1 + 1), C.nCr(n, k));
        if (k & 1) ans -= cur;
        else ans += cur;
    }
    return ans;
}




void solve()
{

}

signed main()
{
#if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1; //cin>>t;
    while (t--)
        solve();
    return 0;
}