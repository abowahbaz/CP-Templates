#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

template < typename T > struct Mo
{
public:
	static constexpr int block_size = 450; // TODO
	struct Query
	{
		int l, r, idx;
		bool operator < (const Query& q) const
		{
			if (l / block_size != q.l / block_size)
				return l / block_size < q.l / block_size;
			return ((l / block_size & 1) ^ (r < q.r));
		}
		Query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
		Query() {};
	};
	void Set_Query(int l, int r, int idx)
	{
		queries[idx] = Query(l, r, idx);
	}

	Mo(int Q, const vector < T >& arr = {})
	{
		answers.resize(Q);
		queries.resize(Q);
		nums = arr;

	}
	void Process()
	{
		sort(queries.begin(), queries.end());
		for (Query& q : queries)
		{
			while (L > q.l)
				Add(--L);
			while (R < q.r)
				Add(++R);
			while (L < q.l)
				Remove(L++);
			while (R > q.r)
				Remove(R--);
			answers[q.idx] = Get_Answer();
		}

	}
	vector < T > answers;

private:
	int L = 1, R = 0;
	T answer = 0; // TODO
	vector < T > nums;
	void Add(int idx) // TODO
	{

	}

	void Remove(int idx) // TODO
	{

	}

	T Get_Answer() // TODO
	{
		return answer;
	}
	vector < Query > queries;

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
	cerr << clock() * 1.0 / CLOCKS_PER_SEC << "\n";
	return 0;
}
