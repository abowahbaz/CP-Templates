#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(st) (int)st.size()
#define all(st) st.begin(), st.end()

class Trie
{
    private:
    char base;
    struct Node
    {
        Node *ch[26];
        int prefix, word;
        Node() {
            prefix = word = 0;
            memset(ch, 0, sizeof(ch));
        }
    };
    inline int get_idx(char c) { return (c - base); }
    Node *root;

    void release(Node *ptr)
    {
        if (ptr == nullptr) return;
        for (int i = 0; i < 26; i++)
            release(ptr->ch[i]);
        delete ptr;
    }
    public:
    Trie(char _base = 'a') :base(_base) { root = new Node; }
    ~Trie() { release(root); }
    void insert(const string s)
    {
        Node *cur = root;
        for (char c : s)
        {
            int idx = get_idx(c);
            if (cur->ch[idx] == nullptr)
                cur->ch[idx] = new Node;
            cur = cur->ch[idx];
            cur->prefix++;
        }
        cur->word++;
    }
    bool find(const string s)
    {
        Node *cur = root;
        for (char c : s)
        {
            int idx = get_idx(c);
            if (cur->ch[idx] == nullptr)
                return 0;
            cur = cur->ch[idx];
        }
        return (cur->word > 0);
    }
    void erase(const string s)
    {
        if (!find(s)) return;
        Node *cur = root;
        vector<Node *> path = { root };
        for (char c : s) {
            int idx = get_idx(c);
            cur = cur->ch[idx];
            cur->prefix--;
            path.push_back(cur);
        }
        cur->word--;
        for (int i = sz(s); i > 0; --i) {
            Node *node = path[i];
            if (node->prefix == 0 && node->word == 0) {
                int idx = get_idx(s[i - 1]);
                path[i - 1]->ch[idx] = nullptr;
                release(node);
                break;
            }
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
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1; //cin>>t;
    while (t--)
        solve();
    return 0;
}