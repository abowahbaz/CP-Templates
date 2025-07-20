#include<bits/stdc++.h>
using namespace std;
#define ll long long

// input should be a directed graph
vector<int>top_sort(int n, const vector<vector<int>> &adj)
{
    vector<int>indegree(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            indegree[j]++;
        }
    }
    queue<int>q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int>res;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    if ((int)res.size() != n) {
        return {};
        // cycle detected
    }
    return res;
}