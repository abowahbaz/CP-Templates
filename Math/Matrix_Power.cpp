#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = (3e18L) + 5;
template<typename T>
struct Matrix {
    // const static int Mod = 1e9 + 7;
    const static int Mod = 998244353;
    int n, m;
    vector<vector<T>> a;
    Matrix() {}
    Matrix(int _n, int _m) : n(_n), m(_m) {
        a = vector<vector<T>>(n, vector<T>(m));
    }
    Matrix(const vector<vector<T>> &v) {
        n = (int)v.size(), m = (int)v[0].size();
        a = v;
    }
    void make_unit() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) a[i][j] = (i == j);
    }
    void fill(T val) {
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++) a[i][j] = val;
    }

    vector<T> &operator[](int idx) { return a[idx]; }

    const vector<T> &operator[](int idx) const { return a[idx]; }

    Matrix operator*(const Matrix &other) {
        assert(m == other.n);
        Matrix ans = Matrix(n, other.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < other.m; j++) {
                for (int k = 0; k < m; k++) {
                    ans[i][j] = (ans[i][j] + 1LL * a[i][k] * other[k][j] % Mod) % Mod;
                }
            }
        }
        return ans;
    }

    Matrix min_path_product(const Matrix &other)
    {
        assert(m == other.n);
        Matrix ans(n, other.m);
        ans.fill(INF);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < other.m; j++) {
                for (int k = 0; k < m; k++) {
                    ans[i][k] = min(ans[i][k], a[i][j] + other.a[j][k]);
                }
            }
        }
        return ans;
    }
    static Matrix pow(Matrix<T> mt, ll k)
    {
        assert(mt.n == mt.m);
        int n = mt.n;
        Matrix ans(n, n);   ans.make_unit();
        while (k > 0) {
            if (k & 1) {
                ans = ans * mt;
            }
            mt = mt * mt;
            k >>= 1;
        }
        return ans;
    }
    // initial matrix should be INF everywhere except for given edges
    // invalid path if cost[i][j] >= INF / 2 (INF = 3e18 + 5)
    static Matrix min_path_k_steps(Matrix<T> mt, ll k)
    {
        int n = mt.n;
        Matrix ans(n, n); ans.fill(INF);
        for (int i = 0;i < n;i++) ans[i][i] = 0;
        while (k > 0) {
            if (k & 1) {
                ans = ans.min_path_product(mt);
            }
            mt = mt.min_path_product(mt);
            k >>= 1;
        }
        return ans;
    }
};
