#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>bellman(int n, int src, const vector<vector<pair<int, ll>>> &adj) {
    vector<ll>dist(n + 1, 1e18);
    dist[src] = 0;
    for (int i = 1; i <= n; ++i) {
        int up = 0;
        for (int u = 1; u <= n; ++u) {
            for (auto &[v, w] : adj[u]) {
                if (dist[u] != 1e18 && dist[v] > dist[u] + w) {
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