#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    ll a, b;
    cin >> a >> b;
    if (b > a) {
        swap(a, b);
    }

    ll diff = a - b;
    a -= 2 * diff;
    b -= diff;
    if (a == b && a % 3 == 0 && a >= 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}