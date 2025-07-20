#include <bits/stdc++.h>
using namespace std;
#define ll long long

class HLD {
    private:
    bool VAL_ON_EDGE = false; // * if values are on edges, set it to true
    const vector<vector<int> > &adj;
    vector<int> dep, par, root, pos, SubtreeSz, heavy;
    int nxt_pos;

    void init(int u, int p = -1, int d = 0)
    {
        dep[u] = d, par[u] = p, SubtreeSz[u] = 1;
        for (auto &v : adj[u]) {
            if (v == p) continue;
            init(v, u, d + 1);
            SubtreeSz[u] += SubtreeSz[v];
            if (SubtreeSz[v] > SubtreeSz[heavy[u]])
                heavy[u] = v;
        }
    }

    void build(int u, bool newChain = true)
    {
        root[u] = newChain ? u : root[par[u]];
        pos[u] = nxt_pos++;
        if (heavy[u]) build(heavy[u], false);
        for (auto &v : adj[u]) {
            if (v == par[u] || v == heavy[u]) continue;
            build(v, true);
        }
    }

    void make_u_lower(int &u, int &v)
    {
        if (dep[root[u]] < dep[root[v]] || (root[u] == root[v] && dep[u] < dep[v]))
            swap(u, v);
    }

    pair<int,int> move_up(int &u)
    {
        pair<int, int> ret = { pos[root[u]], pos[u] };
        u = par[root[u]];
        return ret;
    }

    public:
    HLD(int n, const vector<vector<int>> &G, int treeRoot = 1) : adj(G)
    {
        dep = par = root = pos = SubtreeSz = heavy = vector<int>(n + 1);
        nxt_pos = 1;
        init(treeRoot);
        build(treeRoot);
    }

    vector<pair<int,int> > query_path(int u, int v)
    {
        vector<pair<int, int> > ret;
        while (root[u] != root[v]) {
            make_u_lower(u, v);
            ret.push_back(move_up(u));
        }
        make_u_lower(u, v);
        if (!VAL_ON_EDGE)
            ret.push_back({ pos[v], pos[u] });
        else if (u != v)
            ret.push_back({ pos[v] + 1, pos[u] });
        return ret;
    }

    int operator[](int u)
    {
        return pos[u];
    }

    int get_child(int u, int v)
    {
        return dep[u] > dep[v] ? u : v;
    }
};

// TODO : some data structure