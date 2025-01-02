#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

ll extended_gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
ll linear_diophantine(ll a, ll b, ll c, ll &x, ll &y)
{
    ll x0, y0;
    ll d = extended_gcd(a, b, x0, y0);
    if (c % d != 0) {
        return -1;
    }
    x = x0 * (c / d);
    y = y0 * (c / d);
    return d;
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
