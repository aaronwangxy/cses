#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vt<vt<char>> grid(n, vt<char>(n));
    for (auto &r : grid) {
        for (auto &c : r) {
            cin >> c;
        }
    }

    vt<vt<int>> dp(n, vt<int>(n));
    for (int i = 0; i < n; ++i) {
        if (grid[i][0] == '*') break;
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (grid[0][i] == '*') break;
        dp[0][i] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (grid[i][j] == '*') continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    cout << dp[n-1][n-1];
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