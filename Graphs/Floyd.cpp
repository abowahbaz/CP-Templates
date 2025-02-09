#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

struct Floyd
{
    vector<vector<ll>>dist;
    int n;
    Floyd(int n, vector < vector<ll>> &adj) :n(n)
    {
        dist.resize(n + 1, vector<ll>(n + 1, 1e18));
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                dist[i][j] = (i == j ? 0 : adj[i][j]);
    }
    void init()
    {
        for (int k = 1;k <= n;k++)
            for (int i = 1;i <= n;i++)
                for (int j = 1;j <= n;j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
    ll get(int u, int v) { return (dist[u][v] == 1e18 ? -1 : dist[u][v]); }
};

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
