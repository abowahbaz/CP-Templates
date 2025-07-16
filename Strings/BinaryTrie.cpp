#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(st) (int)st.size()
#define all(st) st.begin(), st.end()

class BinaryTrie {
    const int LOG = 30;

    struct Node {
        int freq[2];
        Node *ch[2];

        Node() {
            freq[0] = freq[1] = 0;
            ch[0] = ch[1] = nullptr;
        }
    };

    static void deleter(Node *ptr) {
        if (ptr == nullptr)
            return;
        deleter(ptr->ch[0]), deleter(ptr->ch[1]);
        delete(ptr);
    }

    void erase(int x, int bit, Node *ptr) {
        if (bit == -1)
            return;
        bool idx = (x >> bit) & 1;
        erase(x, bit - 1, ptr->ch[idx]);
        ptr->freq[idx]--;
        if (ptr->freq[idx] == 0) {
            delete ptr->ch[idx];
            ptr->ch[idx] = nullptr;
        }
    }

    Node *root;

    public:
    BinaryTrie() {
        root = new Node();
    }

    ~BinaryTrie() {
        deleter(root);
    }

    void insert(int x) {
        Node *cur = root;
        for (int bit = LOG; bit >= 0; bit--) {
            int idx = (x >> bit) & 1;
            if (cur->ch[idx] == nullptr)
                cur->ch[idx] = new Node();
            cur->freq[idx]++;
            cur = cur->ch[idx];
        }
    }

    void erase(int x) {
        erase(x, LOG, root);
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