#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n, x;
    cin >> n >> x;
    vt<int> arr(n);
    for (auto &v : arr) cin >> v;

    int ans = 0;
    map<int, int> weights;
    for (auto v : arr) {
        ++weights[v];
    }

    while (!weights.empty()) {
        int smallest = weights.begin()->first;
        int target = x - smallest;

        --weights[smallest];
        if (weights[smallest] == 0) {
            weights.erase(smallest);
        }
        auto it = weights.upper_bound(target);
        if (it != weights.begin()) {
            --it;
            int other = it->first;
            --weights[other];
            if (weights[other] == 0) {
                weights.erase(other);
            }
        }
        ++ans;
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