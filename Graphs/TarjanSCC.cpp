#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Tarjan
{
public:
    vector<vector<int>> scc;
    vector<int> low_link, id, in_stack, comp;
    vector<pair<int, int>> bridges;
    vector<int> articulation_points;
    int scc_count = 0;
    Tarjan(int n, const vector<vector<int>> &adj) : adj(adj)
    {
        this->n = n;
        low_link = id = in_stack = comp = vector<int>(n + 1, -1);
        is_art = vector<bool>(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            if (id[i] == -1)
                dfs(i, -1);
        }
        reverse(scc.begin(), scc.end());
        for (int i = 1; i <= n; i++)
            if (is_art[i]) articulation_points.push_back(i);
    }
private:
    const vector<vector<int>> adj;
    int n, idx = 0;
    stack<int> stk;
    vector<bool> is_art;
    void dfs(int node, int parent)
    {
        stk.push(node);
        in_stack[node] = true;
        id[node] = low_link[node] = idx++;
        int children = 0;
        for (int v : adj[node])
        {
            if (v == parent) continue;
            if (id[v] == -1)
            {
                children++;
                dfs(v, node);
                low_link[node] = min(low_link[node], low_link[v]);
                // Bridge
                if (low_link[v] > id[node])
                    bridges.emplace_back(node, v);
                // Articulation point
                if (parent != -1 && low_link[v] >= id[node])
                    is_art[node] = true;
            }
            else if (in_stack[v])
            {
                low_link[node] = min(low_link[node], id[v]);
            }
        }
        if (parent == -1 && children > 1)
            is_art[node] = true;
        if (id[node] == low_link[node])
        {
            vector<int> cur_scc;
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