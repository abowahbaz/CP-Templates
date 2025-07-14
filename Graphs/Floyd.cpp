#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

struct Floyd
{
    vector<vector<ll>>dist;
    int n;
    Floyd(int _n, const vector<vector<ll>> &adj) :n(_n)
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
    // minimax / maximin can be precomputed for all pairs in O(n^3)
    ll minimax(int u, int v)
    {
        ll ans = 1e18;
        for (int k = 1;k <= n;k++)
            if (dist[u][k] != 1e18 && dist[k][v] != 1e18)
                ans = min(ans, max(dist[u][k], dist[k][v]));
        return (ans == 1e18 ? -1 : ans);
    }
    ll maximin(int u, int v)
    {
        ll ans = -1;
        for (int k = 1;k <= n;k++)
            if (dist[u][k] != 1e18 && dist[k][v] != 1e18)
                ans = max(ans, min(dist[u][k], dist[k][v]));
        return ans;
    }
};

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
    int t = 1;  //cin >> t;
    while(t--)
        solve();
    return 0;
}
