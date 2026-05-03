#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vt<ll> dp(n+1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int roll = 1; roll <= 6; ++roll) {
            if (i - roll >= 0) {
                dp[i] = (dp[i] + dp[i - roll]) % MOD;
            }
        }
    }
    cout << dp[n];
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