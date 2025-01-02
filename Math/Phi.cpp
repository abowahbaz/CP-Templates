#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

ll phi(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

vector < ll > phi_sieve(int MAX)
{
    vector < ll > phi(MAX + 1);
    iota(all(phi), 0);
    for (int i = 2; i <= MAX; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= MAX; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    return phi;
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
