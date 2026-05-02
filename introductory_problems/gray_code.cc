#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

vt<string> solve_h(int n) {
    if (n == 1) {
        return {"0", "1"};
    }
    vt<string> a = solve_h(n-1);
    vt<string> b = a;
    reverse(b.begin(), b.end());
    for(auto &s : a) {
        s += "0";
    }
    for (auto &s : b) {
        s += "1";
    }
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

void solve() {
    int n;
    cin >> n;
    for (auto s : solve_h(n)) {
        cout << s << "\n";
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