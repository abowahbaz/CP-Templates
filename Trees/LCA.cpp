#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

struct LCA
{
    private:
    vector<vector<int>> adj, up;
    vector<int> depth;
    int n, LOG;
    void dfs(int u, int p)
    {
        up[u][0] = p;
        for (int i = 1; i <= LOG; i++) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for (int v : adj[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        }
    }
    public:
    LCA(vector<vector<int>> &adj, int root = 1) : adj(adj)
    {
        n = sz(adj);
        LOG = 31 - __builtin_clz(n);
        up.assign(n + 1, vector<int>(LOG + 1));
        depth.assign(n + 1, 0);
        dfs(root, root);
    }
    int kth_ancestor(int u, int k)
    {
        for (int i = 0; i <= LOG; i++) {
            if (k & (1 << i)) {
                u = up[u][i];
            }
        }
        return u;
    }
    int get_lca(int u, int v)
    {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        for (int i = LOG; i >= 0; i--) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        if (u == v) {
            return u;
        }
        for (int i = LOG; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
    int get_dist(int u, int v)
    {
        return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
    }

};


void Solve()
{

}

signed main()
{
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
