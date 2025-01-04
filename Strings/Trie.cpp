#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

class Trie
{
    private:
    constexpr static int S = 26, base = 'a'; // TODO
    struct Node
    {
        Node *child[S];
        bool isEnd;
        Node()
        {
            for (int i = 0; i < S; i++)
                child[i] = nullptr;
            isEnd = false;
        }
    };
    // Some helper functions
    int get(char c) { return c - base; }
    bool check(Node *cur, int idx) { return !cur->child[idx]; }

    Node *root;
    public:
    Trie()
    {
        root = new Node();
    }
    void insert(string s)
    {
        Node *cur = root;
        for (char c : s)
        {
            int idx = get(c);
            if (check(cur, idx))
                cur->child[idx] = new Node();
            cur = cur->child[idx];
        }
        cur->isEnd = true;
    }
    bool search(string s)
    {
        Node *cur = root;
        for (char c : s)
        {
            int idx = get(c);
            if (check(cur, idx))
                return false;
            cur = cur->child[idx];
        }
        return cur->isEnd;
    }
    bool isPrefix(string s)
    {
        Node *cur = root;
        for (char c : s)
        {
            int idx = get(c);
            if (check(cur, idx))
                return false;
            cur = cur->child[idx];
        }
        return true;
    }
    void erase(string s)
    {
        if (!search(s))
            return;
        Node *cur = root;
        for (char c : s)
        {
            int idx = get(c);
            if (check(cur, idx))
                return;
            cur = cur->child[idx];
        }
        cur->isEnd = false;
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
