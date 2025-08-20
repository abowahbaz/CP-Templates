#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll pow_mod(ll x, ll n, ll mod) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res = ((res % mod) * (x % mod)) % mod;
        x = ((x % mod) * (x % mod)) % mod;
        n >>= 1;
    }
    return res;
}

// finds smallest x > 0 , such that a^x mod M = b mod M
// set zero according to the problem
ll discrete_log(ll a, ll b, ll m, bool zero = false) {

    if (zero && pow_mod(a, 0, m) == b % m)
        return 0;

    ll n = (ll)sqrt(m) + 1, e = 1, f = 1, j = 1;
    unordered_map<ll, ll> mp;
    while (j <= n && (e = f = e * a % m) != b % m)
        mp[e * b % m] = j++;
    if (e == b % m) return j;
    if (gcd(m, e) == gcd(m, b))
        for (int i = 2;i < n + 2;i++)
            if (mp.count(e = e * f % m))
                return n * i - mp[e];
    return -1;
}

// x1 the smallest value that satisfy the equation
// x2 the second smallest value that satisfy the equation
// discrete_log(a,1,m) returns difference x2 - x1
// useful for calculating kth x that satisfiy the equation
ll get_common_difference(ll a, ll b, ll m) {
    if (discrete_log(a, b, m) == -1) return -1; // not solvable
    return discrete_log(a, 1, m);
}

// set zero according to the problem
ll get_kth_solution(ll a, ll b, ll m, ll k, bool zero = false) {
    ll first = discrete_log(a, b, m, zero);
    if (first == -1) return -1;
    return (first + (k - 1) * get_common_difference(a, b, m));
}