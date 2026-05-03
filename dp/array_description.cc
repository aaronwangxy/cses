#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vt<int> arr(n);
    for (auto &a : arr) {
        cin >> a;
        --a;
    }

    // Store number of arrays that can be made up to and including each candidate value
    vt<vt<int>> dp(n, vt<int>(m));
    if (arr[0] == -1) {
        for (int i = 0; i < m; ++i) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][arr[0]] = 1;
    }

    int steps[3] = {-1, 0, 1};
    for (int i = 1; i < n; ++i) {
        if (arr[i] == -1) {
            for (int j = 0; j < m; ++j) {
                for (auto dx : steps) {
                    int prev_val = j + dx;
                    if (0 <= prev_val && prev_val < m) {
                        dp[i][j] = (dp[i][j] + dp[i-1][prev_val]) % MOD;
                    }
                }
            }
        } else {
            for (auto dx : steps) {
                int prev_val = arr[i] + dx;
                if (0 <= prev_val && prev_val < m) {
                    dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][prev_val]) % MOD;
                }
            }
        }
    }

    ll ans = 0;
    for (auto v : dp[n-1]) {
        ans = (ans + v) % MOD;
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