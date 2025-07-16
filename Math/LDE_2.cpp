#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(st) (int)st.size()
#define all(st) st.begin(), st.end()

ll extended_euclid(ll a, ll b, ll &x, ll &y) {
    ll xx = y = 0;
    ll yy = x = 1;
    while (b) {
        ll q = a / b;
        ll t = b; b = a % b; a = t;
        t = xx; xx = x - q * xx; x = t;
        t = yy; yy = y - q * yy; y = t;
    }
    return a;
}
// a*x+b*y=c. returns valid x and y if possible.
// all solutions are of the form (x0 + k * b / g, y0 - k * b / g)
bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    if (a == 0 and b == 0) {
        if (c) return false;
        x0 = y0 = g = 0;
        return true;
    }
    g = extended_euclid(abs(a), abs(b), x0, y0);
    if (c % g != 0) return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 *= -1;
    if (b < 0) y0 *= -1;
    return true;
}
void shift(ll &x, ll &y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}
// returns the number of solutions where x is in the range[minx, maxx] and y is in the range[miny, maxy]
ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    ll x, y, g;
    if (find_any_solution(a, b, c, x, y, g) == 0) return 0;
    if (a == 0 and b == 0) {
        assert(c == 0);
        return 1LL * (maxx - minx + 1) * (maxy - miny + 1);
    }
    if (a == 0) {
        return (maxx - minx + 1) * (miny <= c / b && c / b <= maxy);
    }
    if (b == 0) {
        return (maxy - miny + 1) * (minx <= c / a && c / a <= maxx);
    }
    a /= g, b /= g;
    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;
    shift(x, y, a, b, (minx - x) / b);
    if (x < minx) shift(x, y, a, b, sign_b);
    if (x > maxx) return 0;
    ll lx1 = x;
    shift(x, y, a, b, (maxx - x) / b);
    if (x > maxx) shift(x, y, a, b, -sign_b);
    ll rx1 = x;
    shift(x, y, a, b, -(miny - y) / a);
    if (y < miny) shift(x, y, a, b, -sign_a);
    if (y > maxy) return 0;
    ll lx2 = x;
    shift(x, y, a, b, -(maxy - y) / a);
    if (y > maxy) shift(x, y, a, b, sign_a);
    ll rx2 = x;
    if (lx2 > rx2) swap(lx2, rx2);
    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);
    if (lx > rx) return 0;
    return (rx - lx) / abs(b) + 1;
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