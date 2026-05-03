#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;

void solve() {
    int n, target;
    cin >> n >> target;
    vt<int> coins(n);
    for (auto &c : coins) cin >> c;

    vt<int> dp(target+1);
    dp[0] = 1;
    for (auto c : coins) {
        for (int i = 1; i <= target; ++i) {
            if (i - c >= 0) {
                dp[i] = (dp[i] + dp[i-c]) % MOD;
            }
        }
    }
    cout << dp[target];
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