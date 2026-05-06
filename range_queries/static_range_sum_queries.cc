#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void solve() {
    int n, q;
    cin >> n >> q;
    vt<ll> arr(n);
    for (auto &a : arr) cin >> a;

    for (int i = 1; i < n; ++i) {
        arr[i] += arr[i-1];
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        if (a == 0) {
            cout << arr[b] << "\n";
        } else {
            cout << arr[b] - arr[a-1] << "\n";
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