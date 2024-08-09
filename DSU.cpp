//Yet another messy code by Abo_WahbaZ
#include <bits/stdc++.h>
#define nl "\n"
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()
using namespace std;
using ll = long long;

class DisjointSetUnion
{
    private:
    static constexpr int MAXN = 2e5 + 10;
    int parent[MAXN], Ssize[MAXN];
    int n = 1, sets = 1;
    int findSet(int node)
    {
        if (parent[node] == node) return node;
        return parent[node] = findSet(parent[node]);
    }
    public:
    DisjointSetUnion() {}
    DisjointSetUnion(int N)
    {
        n = sets = N;
        for (int i = 1;i <= n;i++)
            parent[i] = i, Ssize[i] = 1;
    }
    void joinSets(int u, int v)
    {
        u = findSet(u), v = findSet(v);
        if (u == v) return;
        if (Ssize[u] < Ssize[v])
            swap(u, v);
        Ssize[u] += Ssize[v];
        parent[v] = u;
        sets--;
    }
    bool isSameSet(int u, int v)
    {
        return findSet(u) == findSet(v);
    }
    int numberOfSets()
    {
        return sets;
    }
    int getSize(int node)
    {
        return Ssize[findSet(node)];
    }

};


void Solve(int tc)
{
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    cout << fixed << setprecision(12);
    for (int tc = 1; tc <= t; tc++)
        Solve(tc);
    return 0;
};