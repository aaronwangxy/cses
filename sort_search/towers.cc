#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> arr(n);
    for (auto &v : arr) cin >> v;

    map<int, int> tower_tops;
    for (auto v : arr) {
        auto it = tower_tops.upper_bound(v);
        if (it != tower_tops.end()) {
            int base = it->first;
            --tower_tops[base];
            if (tower_tops[base] == 0) {
                tower_tops.erase(base);
            }
        }
        ++tower_tops[v];
    }
    int ans = 0;
    for (auto [base, freq] : tower_tops) ans += freq;
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