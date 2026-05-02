#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    int m;
    cin >> n >> m;

    map<int, int> prices;
    for (int i = 0; i < n; ++i) {
        int price;
        cin >> price;
        ++prices[price];
    }

    for (int i = 0; i < m; ++i) {
        int pay;
        cin >> pay;

        auto it = prices.upper_bound(pay);
        if (it != prices.begin()) {
            --it;
            int price = it->first;
            cout << price << "\n";
            --prices[price];
            if (prices[price] == 0) {
                prices.erase(price);
            }
        } else {
            cout << -1 << "\n";
        }
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