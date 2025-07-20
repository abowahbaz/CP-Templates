#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll extended_euclid(ll a, ll b, ll &x, ll &y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
// solves the equation ax + by = c
ll LDE(ll a, ll b, ll c, ll &x, ll &y, ll &found)
{
    ll g = extended_euclid(a, b, x, y);
    if (found = c % g == 0)
        x *= c / g, y *= c / g;
    return g;
}