#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    ll n;
    cin >> n;
    while (n!=1) {
        cout << n << " ";
        if (n%2==0) {
            n /= 2;
        } else {
            n = 3*n+1;
        }
    }
    cout << "1\n";
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