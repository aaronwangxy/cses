#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<vt<int>> movies(n, vt<int>(2));
    for (auto &movie : movies) {
        cin >> movie[0] >> movie[1];
    }
    sort(movies.begin(), movies.end(), [](auto &a, auto &b) {
        return a[1] < b[1];
    });

    int ans = 0;
    int prev_end = 0;
    for (auto movie : movies) {
        int start = movie[0];
        int end = movie[1];
        if (start >= prev_end) {
            ++ans;
            prev_end = end;
        }
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