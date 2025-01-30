#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()
const ll INF = (1LL << 60);

struct Floyd
{
    using edge = pair<int, ll>; // [to,cost]
    const vector<vector<edge>> adj;
    vector<vector<ll>> dist;
    vector<vector<bool>> reach;
    int n;
    Floyd(int n, const vector<vector<edge>> &adj) : n(n), adj(adj) {
        dist.assign(n + 1, vector<ll>(n + 1, INF));
        reach.assign(n + 1, vector<bool>(n + 1, false));
        for (int i = 1; i <= n; i++) {
            dist[i][i] = 0;
            reach[i][i] = true;
            for (auto [to, cost] : adj[i]) {
                dist[i][to] = cost;
                reach[i][to] = true;
            }
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        reach[i][j] = (reach[i][j] || (reach[i][k] && reach[k][j]));
                    }
    }

    vector<vector<ll>> minimax() // find path such that minimum cost is maximum
    {
        vector<vector<ll>> res(n, vector<ll>(n + 1, INF));
        for (int i = 1;i <= n;i++) res[i][i] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                    res[i][j] = min(res[i][j], max(dist[i][k], dist[k][j]));
        return res;
    }
    vector<vector<ll>>maximin() // find path such that maximum cost is minimum
    {
        vector<vector<ll>> res(n, vector<ll>(n + 1, INF));
        for (int i = 1;i <= n;i++) res[i][i] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                    res[i][j] = max(res[i][j], min(dist[i][k], dist[k][j]));
        return res;
    }
    ll get(int u, int v) { return dist[u][v]; }
    bool can(int u, int v) { return reach[u][v]; }

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
