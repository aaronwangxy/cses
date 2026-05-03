#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

/*
Assume we can make amounts 1..k
if we include coin c, we can make 
amounts c, c+1...c+k i.e. we can make 
1...c+k iff c <= k+1
*/
void solve() {
    int n;
    cin >> n;
    vt<int> coins(n);
    for (auto &c : coins) cin >> c;
    sort(coins.begin(), coins.end());

    bool found = false;
    ll end = 0;
    for (auto c : coins) {
        if (c > end + 1) {
            cout << end + 1;
            found = true;
            break;
        }
        end += c;
    }
    if (!found) {
        cout << end + 1;
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