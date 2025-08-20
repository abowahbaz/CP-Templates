#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct FFT
{
    const double PI = acos(-1);
    using cd = complex<double>;

    private:
    void compute(vector<cd> &f, bool inverse = 0)
    {
        int n = f.size();
        // bit-reversal sort
        for (int i = 0, j = 0;i < n;++i)
        {
            if (i < j)
                swap(f[i], f[j]);

            int bit = n >> 1;
            for (;j & bit;bit >>= 1) j ^= bit;
            j ^= bit;
        }

        for (int lv = 2;lv <= n;lv <<= 1)
        {
            double angle = 2 * PI / lv;
            cd wlv(cos(angle), sin(angle) * (inverse ? -1 : 1));

            for (int i = 0;i < n;i += lv)
            {
                cd w(1);
                for (int j = 0;j < lv / 2;j++)
                {
                    cd tmp = f[i + j];

                    f[i + j] = f[i + j] + w * f[i + j + lv / 2];
                    f[i + j + lv / 2] = tmp - w * f[i + j + lv / 2];

                    w *= wlv;
                }
            }
        }

        if (inverse)
            for (auto &x : f) x /= n;
    }

    public:
    FFT() {}

    vector<ll>multiply(const vector<ll> &a, const vector<ll> &b, int limit = 4e5 + 5)
    {
        vector<cd>fa(a.begin(), a.end()), fb(b.begin(), b.end());
        int n = 1;
        while (n < int(a.size() + b.size()))
            n <<= 1;
        fa.resize(n), fb.resize(n);

        compute(fa), compute(fb);

        for (int i = 0;i < n;i++)
            fa[i] *= fb[i];

        compute(fa, true);
        n = min(n, limit);
        vector<ll>ans(n);
        for (int i = 0;i < n;i++)
        {
            ans[i] = round(fa[i].real());
        }
        return ans;
    }
    vector<ll>poly_pow(vector<ll>p, ll e) // raise the polynomial to the power of e
    {
        vector<ll>ans = { 1 };
        while (e)
        {
            if (e & 1) ans = multiply(ans, p);
            p = multiply(p, p);
            e >>= 1;
        }
        return ans;
    }
};