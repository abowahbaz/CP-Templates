//Yet another messy code by Abo_WahbaZ
#include <bits/stdc++.h>
#define nl "\n"
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()
using namespace std;
using ll = long long;

class MonotonicQueue
{
    private:
    using T = int;
    vector<T>nums;
    deque<T>dq;
    void add(int idx)
    {
        while (!dq.empty() && dq.back() > nums[idx]) // Monotonic Decreasing
            dq.pop_back();
        dq.push_back(nums[idx]);
    }
    void remove(int idx)
    {
        if (!dq.empty() && dq.front() == nums[idx])
            dq.pop_front();
    }
    public:
    MonotonicQueue() {}
    MonotonicQueue(const vector<T> &arr) : nums(arr) {}
    vector<T> getAnswers(int len)
    {
        vector<T>ret;
        for (int i = 0, j = 0; i < int(nums.size()); remove(i++))
        {
            while (j - i < len && j < int(nums.size()))
                add(j++);
            if (j - i == len)
                ret.push_back(dq.front());
        }
        return ret;
    }
};

void Solve(int tc)
{
    vector<int> arr = { 2 ,1 ,4 ,5 ,3 ,4 ,1 ,2 };
    MonotonicQueue mq(arr);
    vector<int>answers = mq.getAnswers(4);
    for (int &i : answers)
        cout << i << " ";
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