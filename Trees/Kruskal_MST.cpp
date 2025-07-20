#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Edge
{
    int id, u, v; ll w; // [edge_index,to,from,cost]
    Edge() {}
    Edge(int Id, int U, int V, ll W) {
        this->id = Id, this->u = U, this->v = V, this->w = W;
    }
    bool operator < (const Edge &e) const
    {
        return w < e.w;
    }
};

struct MST
{
    private:
    vector<Edge> edges;
    vector<int> parent, rank, mst_edges;
    int n;
    int get_parent(int u)
    {
        return parent[u] == u ? u : parent[u] = get_parent(parent[u]);
    }
    void join(int u, int v)
    {
        u = get_parent(u);
        v = get_parent(v);
        if (u != v) {
            if (rank[u] < rank[v]) {
                swap(u, v);
            }
            parent[v] = u;
            if (rank[u] == rank[v]) {
                rank[u]++;
            }
        }
    }
    public:
    MST(int n, const vector<Edge> &edges) : n(n), edges(edges)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        sort(edges.begin(), edges.end());
    }
    // returns the cost of the MST and the edges used
    pair<ll, vector<int>> process()
    {
        ll cost = 0;
        for (Edge &e : edges) {
            if (get_parent(e.u) != get_parent(e.v)) {
                cost += e.w;
                join(e.u, e.v);
                mst_edges.push_back(e.id);
            }
        }
        return { cost, mst_edges };
    }
};
