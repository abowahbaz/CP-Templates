#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

// Eulerain Path Method Of LCA

struct Euler_LCA // 1 based indexing
{
    private:
    int LOG;
    vector < int > euler, first, depth, bin_log;
    const vector < vector < int > > adj;
    vector < vector < int > > dp;

    inline int get_min(int u, int v)
    {
        return depth[u] < depth[v] ? u : v;
    }

    public:
    void dfs(int u, int p, int h)
    {
        depth[u] = h;
        first[u] = int(euler.size());
        euler.emplace_back(u);
        for (int v : adj[u])
        {
            if (v == p) continue;
            dfs(v, u, h + 1);
            euler.emplace_back(u);
        }
    }
    Euler_LCA(int n, vector < vector < int > > &g) : adj(g)
    {
        first = depth = vector < int >(n + 1, -1);
        dfs(1, 0, 0);
        LOG = sz(euler) + 1;
        dp.resize(LOG, vector < int >(int(log2(LOG)) + 1));

        // Precompute Sparse Table
        for (int i = 0;i < LOG;i++)
            dp[i][0] = euler[i];

        for (int j = 1;(1 << j) <= LOG;j++)
        {
            for (int i = 0;i + (1 << j) - 1 < LOG;i++)
            {
                int u = dp[i][j - 1];
                int v = dp[i + (1 << (j - 1))][j - 1];
                dp[i][j] = get_min(u, v);
            }
        }

        // Precompute bin_log
        bin_log.resize(LOG + 1);
        for (int i = 2;i <= LOG;i++)
            bin_log[i] = bin_log[i >> 1] + 1;
    }
    // LCA of u and v in O(1)
    int get_lca(int u, int v)
    {
        int l = first[u], r = first[v];
        if (l > r) swap(l, r);

        int j = bin_log[r - l + 1];

        u = dp[l][j], v = dp[r - (1 << j) + 1][j];

        return get_min(u, v);
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
