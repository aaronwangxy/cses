#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "1\n";
    } else if (n < 4) {
        cout << "NO SOLUTION\n";
    } else if (n == 4) {
        cout << "3 1 4 2\n";
    } else {
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
        for (int i = 2; i <= n; i += 2) {
            cout << i << " ";
        }
    }
    cout << "\n";
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