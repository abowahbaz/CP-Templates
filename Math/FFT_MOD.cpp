#include<bits/stdc++.h>
using namespace std;
#define ll long long

template<int Mod = 998244353>
struct FFT_MOD {
    private:
    using cd = complex<double>;
    const int cut;

    void compute(vector<cd> &a) {
        int n = sz(a), L = 31 - __builtin_clz(n);
        vector<complex<long double>> R(2, 1);
        vector<cd> rt(2, 1); // (^ 10% faster if double)

        for (int k = 2; k < n; k <<= 1) {
            R.resize(n);
            rt.resize(n);
            auto x = polar(1.0L, acos(-1.0L) / k);
            for (int i = k; i < 2 * k; i++)
                rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
        }

        vector<ll> rev(n);
        for (int i = 0; i < n; i++)
            rev[i] = (rev[i / 2] | (i & 1) << L) / 2;

        for (int i = 0; i < n; i++)
            if (i < rev[i])
                swap(a[i], a[rev[i]]);

        for (int k = 1; k < n; k <<= 1) {
            for (int i = 0; i < n; i += (k << 1)) {
                for (int j = 0; j < k; j++) {
                    auto x = (double *)&rt[j + k], y = (double *)&a[i + j + k];
                    cd z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);
                    a[i + j + k] = a[i + j] - z;
                    a[i + j] += z;
                }
            }
        }
    }

    public:
    FFT_MOD() : cut(int(sqrt(Mod))) {}

    vector<ll> multiply(const vector<ll> &a, const vector<ll> &b) {
        vector<ll> res(sz(a) + sz(b) - 1);
        int B = 32 - __builtin_clz(sz(res)), n = 1 << B;
        vector<cd> L(n), R(n), outs(n), outl(n);

        for (int i = 0; i < sz(a); i++)
            L[i] = cd((int)a[i] / cut, (int)a[i] % cut);

        for (int i = 0; i < sz(b); i++)
            R[i] = cd((int)b[i] / cut, (int)b[i] % cut);

        compute(L);
        compute(R);

        for (int i = 0; i < n; i++) {
            int j = -i & (n - 1);
            outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
            outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
        }

        compute(outl);
        compute(outs);

        for (int i = 0; i < sz(res); i++) {
            ll av = ll(real(outl[i]) + .5), cv = ll(imag(outs[i]) + .5);
            ll bv = ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5);
            res[i] = ((av % Mod * cut + bv) % Mod * cut + cv) % Mod;
        }

        return res;
    }
};
