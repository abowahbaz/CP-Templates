#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(st) (int)st.size()
#define all(st) st.begin(), st.end()

vector<ll>bellman(int n, int src, const vector<vector<pair<int, ll>>> &adj) {
    vector<ll>dist(n + 1, LLONG_MAX);
    dist[src] = 0;
    for (int i = 1; i <= n; ++i) {
        int up = 0;
        for (int u = 1; u <= n; ++u) {
            for (auto &[v, w] : adj[u]) {
                if (dist[u] != LLONG_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    up = 1;
                }
            }
        }
        if (i == n && up) // negative cycle
            return { LLONG_MIN };

        if (!up) break;
    }
    return dist;

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
    int t = 1; //cin>>t;
    while (t--)
        solve();
    return 0;
}