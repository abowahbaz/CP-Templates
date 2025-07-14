#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(st) (int)st.size()
#define all(st) st.begin(), st.end()

struct DC
{
    private:
    vector<array<int, 2>> edges;
    vector<vector<int>>seg, add, cut;
    const vector<vector<int>> &query;
    vector<int>parent, rank, answer, indx;
    stack<pair<int, int>>stk;
    int tree_size, comp;

    // DSU with rollback
    void dsu_init(int n)
    {
        parent.resize(n + 1), rank.resize(n + 1, 1);
        iota(all(parent), 0);
        comp = n;
    }
    int find(int u) {
        while (parent[u] != u) u = parent[u];
        return u;
    }
    void merge(int u, int v)
    {
        u = find(u), v = find(v);
        if (u == v) {
            stk.push({ -1,-1 });
            return;
        }
        if (rank[u] < rank[v]) swap(u, v);
        stk.push({ u,v });
        rank[u] += rank[v];
        parent[v] = u;
        comp--;
    }
    void rollback(int k = 1) // rollback k times
    {
        while (k-- && !stk.empty())
        {
            auto [u, v] = stk.top(); stk.pop();
            if (u == -1) continue;
            rank[u] -= rank[v];
            parent[v] = v;
            comp++;
        }
    }
    // Segment Tree
    void tree_init(int q)
    {
        tree_size = 1;
        while (tree_size <= q) tree_size <<= 1;
        seg = vector<vector<int>>(tree_size * 4);
        answer = vector<int>(tree_size * 4);
    }
    void update(int l, int r, int node, int lx, int rx, int idx)
    {
        if (r<lx || l>rx) return;
        if (l >= lx && r <= rx)
        {
            seg[node].push_back(idx);
            return;
        }
        int mid = (l + r) >> 1;
        update(l, mid, 2 * node + 1, lx, rx, idx);
        update(mid + 1, r, 2 * node + 2, lx, rx, idx);
    }
    void dfs(int l, int r, int node)
    {
        for (auto it : seg[node])
        {
            int u = edges[it][0], v = edges[it][1];
            merge(u, v);
        }

        if (l == r)
        {
            answer[l] = comp;
            rollback(sz(seg[node]));
            return;
        }

        int mid = (l + r) >> 1;
        dfs(l, mid, 2 * node + 1);
        dfs(mid + 1, r, 2 * node + 2);
        rollback(sz(seg[node]));
    }
    // helping funcions
    void build_query(int q)
    {
        map<array<int, 2>, int>mp;
        edges.push_back({ 0,0 });
        for (int i = 0;i < q;i++)
        {
            int op = query[i][0];
            if (op == '?')
            {
                indx.push_back(i);
            }
            else
            {
                int u = query[i][1], v = query[i][2];
                if (u > v) swap(u, v);
                if (mp.find({ u,v }) == mp.end())
                {
                    mp[{u, v}] = sz(edges);
                    edges.push_back({ u,v });
                }
                int edge_idx = mp[{u, v}];
                if (op == '+')
                {
                    add[edge_idx].push_back(i);
                }
                else cut[edge_idx].push_back(i);
            }
        }
        for (int i = 1;i < sz(edges);i++)
        {
            cut[i].push_back(q + 1);
        }
    }
    void build_tree()
    {
        for (int i = 1;i < sz(edges);i++)
        {
            for (int l : add[i])
            {
                int r = *lower_bound(all(cut[i]), l) - 1;
                update(0, tree_size - 1, 0, l, r, i);
            }
        }
    }
    public:
    DC(int n, int q, const vector<vector<int>> &_query) :query(_query)
    {
        add = cut = vector<vector<int>>(q + 1);
        dsu_init(n), tree_init(q);
        build_query(q);
        build_tree();
        dfs(0, tree_size - 1, 0);
    }
    void print_answers()
    {
        for (int j : indx) cout << answer[j] << "\n";
    }
};




void solve()
{
	// Standard Problem Section
    int n, q; cin >> n >> q;
    vector<vector<int>>query;
    for (int i = 0;i < q;i++)
    {
        char op; cin >> op;
        if (op != '?')
        {
            int u, v; cin >> u >> v;
            query.push_back({ op,u,v });
        }
        else query.push_back({ op });
    }
    DC dc(n, q, query);
    dc.print_answers();


}

signed main()
{
#if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}