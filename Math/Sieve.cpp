#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector <bool> sieve(int MAXN)
{
    vector <bool> is_prime(MAXN + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAXN; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

vector <int> spf(int MAXN) // smallest prime factor
{
    vector <int> spf(MAXN + 1);
    for (int i = 1; i <= MAXN; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}

vector <ll> prime_factors(ll n)
{
    vector <ll> factors;
    for (ll i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        if (cnt)  factors.push_back(i);
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

vector <ll> factorize(ll n)
{
    vector <ll> factors;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i * i != n) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}