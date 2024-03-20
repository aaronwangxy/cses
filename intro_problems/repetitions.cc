#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    string s;
    cin >> s;
    int msf = 0;
    int l = 0;
    int r = 0;
    while (r < s.size()) {
        while (r < s.size() && s[l] == s[r]) {
            r++;
        }
        msf = max(msf,r-l);
        l=r;
    }
    cout << msf << "\n";
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