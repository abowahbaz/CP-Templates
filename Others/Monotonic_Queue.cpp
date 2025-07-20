#include <bits/stdc++.h>
using namespace std;
#define ll long long

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