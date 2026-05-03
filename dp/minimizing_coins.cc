#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n, target;
    cin >> n >> target;
    vt<int> coins(n);
    for (auto &c : coins) cin >> c;

    vt<ll> dp(target+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= target; ++i) {
        for (auto c : coins) {
            if (i - c >= 0 && dp[i-c] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i-c]);
        }
    }
    if (dp[target] == INT_MAX) {
        cout << -1;
    } else{
        cout << dp[target];
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