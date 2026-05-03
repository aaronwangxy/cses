#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;

vt<int> get_digits(int n) {
    vt<int> ans;
    while (n > 0) {
        ans.push_back(n % 10);
        n /= 10;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vt<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        vt<int> digits = get_digits(i);
        for (auto digit : digits) {
            if (dp[i-digit] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i-digit]);
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