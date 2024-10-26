#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

class Mo
{
    public:
    using T = int;
    static constexpr int block_size = 350; // TODO
    struct Query
    {
        int l, r, idx;
        bool operator < (const Query& q) const
        {
            if (l / block_size != q.l / block_size)
                return l / block_size < q.l / block_size;
            return r < q.r;
        }
        Query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
    };
    void push_query(int l, int r, int idx)
    {
        queries[idx] = Query(l, r, idx);
    }
    Mo(int Q, const vector < T >& nums = {})
    {
        queries.resize(Q);
        ans.resize(Q);
    }

    void process()
    {
        sort(all(queries));
        for (Query& q : queries)
        {
            while (L > q.l)
                add(--L);
            while (R < q.r)
                add(++R);
            while (L < q.l)
                remove(L++);
            while (R > q.r)
                remove(R--);
            ans[q.idx] = get_answer();
        }

    }
    private:
    int L = 1, R = 0;
    void add(T x) // TODO
    {
    }
    void remove(T x) // TODO
    {
    }

    T get_answer() // TODO
    {
        return 0;
    }
    vector < Query > queries;
    vector < T > ans;

};



void Solve()
{

}

int main()
{
#if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        Solve();
        cout << "\n";
    }
    return 0;
}
