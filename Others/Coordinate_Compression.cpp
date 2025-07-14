#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(st) int(st.size())
#define all(st) st.begin(), st.end()

template<class T>
vector <int> compress(const vector<T> arr) // compress [int,long long,string] to [1,n] values
{
    vector<T> temp = arr;
    sort(temp.begin(), temp.end());
    temp.erase(unique(all(temp)), temp.end());
    vector<int> ret;
    for (int i = 0; i < arr.size(); i++) {
        int new_val = upper_bound(all(temp), arr[i]) - temp.begin();
        ret.emplace_back(new_val);
    }
    return ret;
}

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
