#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<vt<int>> intervals(n, vt<int>(2));
    for (auto &interval : intervals) {
        cin >> interval[0] >> interval[1];
    }
    sort(intervals.begin(), intervals.end());

    int ans = 0;
    priority_queue<int, vt<int>, greater<int>> q;
    for (auto interval : intervals) {
        int start = interval[0];
        int end = interval[1];
        q.push(end);
        while (!q.empty() && q.top() < start) {
            q.pop();
        }
        ans = max(ans, (int)q.size());
    }
    cout << ans;
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