#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vt<int> apps(n);
    for (auto &v : apps) cin >> v;
    vt<int> apts(m);
    for (auto &v : apts) cin >> v;

    sort(apps.begin(), apps.end());
    sort(apts.begin(), apts.end());
    int i = 0, j = 0;
    int ans = 0;
    while (i < n && j < m) {
        int app = apps[i], apt = apts[j];
        if (abs(app - apt) <= k) {
            ans++;
            i++;
            j++;
        } else if (app < apt) {
            i++;
        } else {
            j++;
        }
    }
    cout << ans;
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