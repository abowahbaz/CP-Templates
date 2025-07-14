#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(st) (int)st.size()
#define all(st) st.begin(), st.end()

// solve system of N linear equations,aug -> Augmented Matrix : NxN+1 matrix with last column for coeffecient
vector<double> gauss_solve(int n, vector<vector<double>>aug)
{
    for (int i = 0; i < n - 1; i++) {
        int l = i;
        for (int j = i + 1; j < n;j++)
            if (fabs(aug[j][i]) > fabs(aug[l][i]))
                l = j;

        for (int k = i; k <= n;k++)
            swap(aug[i][k], aug[l][k]);

        for (int j = i + 1; j < n; j++)
            for (int k = n; k >= i; k--)
                aug[j][k] -= aug[i][k] * aug[j][i] / aug[i][i];
    }
    vector<double>ans(n);
    for (int j = n - 1;j >= 0;j--)
    {
        double t = 0;
        for (int k = j + 1;k < n;k++)
        {
            t += aug[j][k] * ans[k];
        }
        ans[j] = (aug[j][n] - t) / (aug[j][j]);
    }
    return ans;
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
    int t = 1; //cin >> t;
    while (t--)
        solve();
    return 0;
}