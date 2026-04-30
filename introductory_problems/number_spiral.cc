#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

ll llpow(ll base, ll exp) {
    ll res = 1;
    while (exp--) {
        res *= base;
    }
    return res;
}

/*
Idea: identify which "layer" we're on. We know 
that layer starts at (n-1)^2 + 1
*/
void solve() {
    ll r, c;
    cin >> r >> c;

    ll n = max(r, c);
    ll start = llpow(n-1, 2) + 1;

    // index from top
    ll index;
    if (r == c) {
        index = n - 1;
    } else if (c > r) {
        index = r - 1;
    } else {
        index = n + n - 1 - c;
    }

    // increasing
    if (n % 2 == 0) {
        cout << start + index << "\n";
    } else {
        cout << llpow(n, 2) - index << "\n";
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