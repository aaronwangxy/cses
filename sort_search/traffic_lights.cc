#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

/*
Idea: map from start to end for intervals
maintain heap containing largest distance
check if heap entry valid by seeing if start and end index line up
*/
void solve() {
    int x, n;
    cin >> x >> n;
    vt<int> arr(n);
    for (auto &v : arr) cin >> v;

    map<int, int> start_to_end;
    start_to_end[0] = x;
    priority_queue<vt<int>> q;
    q.push({x, 0});
    for (auto v : arr) {
        auto it = start_to_end.upper_bound(v);
        // should always be true
        if (it != start_to_end.begin()) {
            --it;
            int start = it->first;
            int end = it->second;
            start_to_end.erase(start);
            start_to_end[start] = v;
            q.push({v - start, start});
            start_to_end[v] = end;
            q.push({end - v, v});
            while (start_to_end[q.top()[1]] != q.top()[1] + q.top()[0]) {
                q.pop();
            }
            cout << q.top()[0] << " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}