#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    for (int k=1; k <= n; ++k) {
        ll total_squares = k * k;
        ll ans = total_squares * (total_squares - 1) / 2;

        if (k > 2) {
            ans -= 4*(k-1)*(k-2);
        }

        cout << ans << "\n";
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