#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
    } else if (n < 4) {
        cout << "NO SOLUTION";
    } else if (n == 4) {
        cout << "2 4 1 3";
    } else {
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
        for (int i = 2; i <= n; i += 2) {
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