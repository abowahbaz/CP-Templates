#include <bits/stdc++.h>
using namespace std;
#define ll long long

template < typename T > struct Mo
{
	public:
	static const int MAX_N = 2e5 + 5; // TODO
	static const int block_size = 450; // TODO 
	struct Query
	{
		int l, r, idx;
		bool operator < (const Query &q) const
		{
			if (l / block_size != q.l / block_size)
				return l / block_size < q.l / block_size;
			return ((l / block_size & 1) ^ (r < q.r));
		}
		Query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
		Query() {};
	};
	void set_query(int l, int r, int idx)
	{
		queries[idx] = Query(l, r, idx);
	}

	Mo(int Q, const vector < T > &arr = {})
	{
		answers.resize(Q);
		queries.resize(Q);
		nums = arr;

	}
	void process()
	{
		sort(queries.begin(), queries.end());
		for (Query &q : queries)
		{
			while (L > q.l)
				add(--L);
			while (R < q.r)
				add(++R);
			while (L < q.l)
				remove(L++);
			while (R > q.r)
				remove(R--);
			answers[q.idx] = calc_answer();
		}

	}
	vector < T > answers;

	private:
	int L = 1, R = 0;
	T answer = 0;					 // TODO
	vector < T > nums;
	void add(int idx)				 // TODO
	{

	}

	void remove(int idx) 			// TODO
	{

	}

	T calc_answer() // TODO
	{
		return answer;
	}
	vector < Query > queries;

};
