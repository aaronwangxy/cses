#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    ll n;
    cin >> n;

    ll sum = n*(n+1)/2;
    if (sum % 2) {
        cout << "NO";
        return;
    }
    ll target = sum / 2;

    cout << "YES\n";
    set<ll> split;
    for (ll i = n; i > 0; --i) {
        if (target >= i) {
            target -= i;
            split.insert(i);
        }
    }
    cout << split.size() << "\n";
    for (auto val : split) {
        cout << val << " ";
    }
    cout << "\n" << n - split.size() << "\n";
    for (int i = 1; i <= n; ++i) {
        if (split.find(i) == split.end()) {
            cout << i << " ";
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