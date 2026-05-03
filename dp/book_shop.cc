#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;
    vt<int> prices(n);
    vt<int> pages(n);
    for (auto &p : prices) cin >> p;
    for (auto &p : pages) cin >> p;

    vt<int> dp(x+1);
    for (int i = 0; i < n; ++i) {
        for (int j = x; j > 0; --j) {
            int price = prices[i];
            int page = pages[i];
            if (j-price >= 0)
                dp[j] = max(dp[j], page + dp[j-price]);
        }
    }
    cout << dp[x];
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