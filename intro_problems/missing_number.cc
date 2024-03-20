#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    ll n;
    cin >> n;

    unordered_set<int> s;

    for (int i=1;i<=n;++i) {
        s.insert(i);
    }

    for (int i = 0; i < n-1; ++i) {
        int val;
        cin >> val;
        s.erase(val);
    }

    cout << *s.begin() << "\n";
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