#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

struct Tarjan
{

    public:
    vector<vector<int>>scc;
    vector<int>low_link, id, in_stack, comp;
    int scc_count = 0;
    Tarjan(int n, const vector<vector<int>> &adj) :adj(adj)
    {
        this->n = n;
        low_link = id = in_stack = comp = vector<int>(n + 1, -1);
        for (int i = 1; i <= n; i++)
        {
            if (id[i] == -1)
                dfs(i);
        }
        reverse(all(scc));
    }
    private:
    const vector<vector<int>>adj;
    int n, idx = 0;
    stack<int>stk;
    void dfs(int node)
    {
        stk.push(node);
        in_stack[node] = true;
        id[node] = low_link[node] = idx++;
        for (int v : adj[node])
        {
            if (id[v] == -1)
                dfs(v);

            if (in_stack[v])
                low_link[node] = min(low_link[node], low_link[v]);
        }
        if (id[node] == low_link[node])
        {
            vector<int>cur_scc;
            while (!stk.empty())
            {
                int tp = stk.top();
                stk.pop();
                in_stack[tp] = false;
                low_link[tp] = id[node];
                cur_scc.push_back(tp);
                comp[tp] = scc_count;
                if (tp == node) break;
            }
            scc_count++;
            scc.push_back(cur_scc);
        }
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        solve(), cout << "\n";
    }
    return 0;
}
