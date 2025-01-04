#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()


template<typename T>class Monotonic_Queue
{
    private:
    vector<T>nums;
    deque<T>dq;
    void add(int idx)
    {
        while (!dq.empty() && dq.back() < nums[idx])
            dq.pop_back();
        dq.push_back(nums[idx]);
    }
    void remove(int idx)
    {
        if (!dq.empty() && dq.front() == nums[idx])
            dq.pop_front();
    }
    public:
    Monotonic_Queue(){}
    Monotonic_Queue(const vector<T> &arr) : nums(arr) {}
    vector<T> getAnswers(int K) // get max element of all subarrays of length K
    {
        vector<T>ret;
        for (int i = 0, j = 0; i < int(nums.size()); remove(i++))
        {
            while (j - i < K && j < int(nums.size()))
                add(j++);
            if (j - i == K)
                ret.push_back(dq.front());
        }
        return ret;
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
    for (int tc = 1; tc <= t; tc++)
        Solve();
    return 0;
};