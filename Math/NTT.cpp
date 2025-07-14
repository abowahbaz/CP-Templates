#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

struct NTT
{
    private:
    const int Mod = (119 << 23) + 1, root = 62;
    ll mod_pow(ll x, ll e)
    {
        ll res = 1;
        while (e) {
            if (e & 1) res = ((res % Mod) * (res % Mod)) % Mod;
            e >>= 1;
            x = ((x % Mod) * (x % Mod)) % Mod;
        }
        return res;
    }
    int primitive_root() {
        vector<ll>fact;
        ll phi = Mod - 1, n = phi;
        for (ll i = 2;i * i <= n;i++)
            if (n % i == 0) {
                fact.push_back(i);
                while (n % i == 0) n /= i;
            }
        if (n > 1) fact.push_back(n);

        for (int res = 2;res <= Mod;res++)
        {
            bool ok = true;
            for (int i = 0; i < (int)fact.size() && ok; i++)
                ok &= mod_pow(res, phi / fact[i]) != 1;

            if (ok) return res;
        }
        return -1; // should not be reached
    }

    void compute(vector<ll> &a) {
        int n = a.size(), L = 31 - __builtin_clz(n);
        vector<ll> rt(2, 1);
        for (int k = 2, s = 2; k < n; k *= 2, s++) {
            rt.resize(n);
            ll z[] = { 1, mod_pow(root, Mod >> s) };
            for (int i = k; i < 2 * k; ++i)
                rt[i] = (ll)rt[i / 2] * z[i & 1] % Mod;
        }
        vector<ll> rev(n);
        for (int i = 0; i < n; ++i) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;

        for (int i = 0; i < n; ++i) if (i < rev[i]) swap(a[i], a[rev[i]]);
        
        for (int k = 1; k < n; k *= 2) {
            for (int i = 0; i < n; i += 2 * k) {
                for (int j = 0; j < k; ++j) {
                    ll z = (ll)rt[j + k] * a[i + j + k] % Mod, &ai = a[i + j];
                    a[i + j + k] = ai - z + (z > ai ? Mod : 0);
                    ai += (ai + z >= Mod ? z - Mod : z);
                }
            }
        }
    }
    public:
    NTT(const int M) :Mod(M), root(primitive_root()) {};

    vector<ll> multiply(const vector<ll> &a, const vector<ll> &b) {
        if (a.empty() || b.empty()) return {};
        int s = a.size() + b.size() - 1, B = 32 - __builtin_clz(s), n = 1 << B;
        ll inv = mod_pow(n, Mod - 2);
        vector<ll> L(a), R(b), out(n);
        L.resize(n), R.resize(n);
        compute(L), compute(R);
        for (int i = 0; i < n; ++i)
            out[-i & (n - 1)] = (ll)L[i] * R[i] % Mod * inv % Mod;

        compute(out);
        return { out.begin(), out.begin() + s };
    }
};




void solve()
{

}

signed main()
{
#if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}