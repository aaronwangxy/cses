#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> arr(n);
    for (auto &v : arr) cin >> v;

    int ans = 0;
    set<int> seen;
    for (auto v : arr) {
        int prev = v - 1;
        if (seen.find(prev) == seen.end()) {
            ++ans;
        }
        seen.insert(v);
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