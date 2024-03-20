#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    ll y,x;
    cin >> y >> x;
    y--,x--;

    // 0 1, 1 3, 2 7, 
    // 1 + n(n+1)
    ll val = 1+max(y,x)*(max(y,x)+1);

    if (max(y,x) % 2 == 1) {
        // increasing clockwise
        cout << val + y - x << "\n";
    } else {
        // increasing counter-clockwise
        cout << val - y + x << "\n";
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