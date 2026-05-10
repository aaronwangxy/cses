#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return;
    }

    set<int> children;
    for (int i = 1; i <= n; ++i) {
        children.insert(i);
    }
    auto to_remove = ++children.begin();
    vt<int> removed;
    while (n > 1) {
        removed.push_back(*to_remove);
        auto tmp = to_remove;
        to_remove = next(to_remove);
        if (to_remove == children.end()) {
            to_remove = children.begin();
        }
        to_remove = next(to_remove);
        if (to_remove == children.end()) {
            to_remove = children.begin();
        }
        children.erase(tmp);
        --n;
    }
    for (auto r : removed) cout << r << " ";
    cout << *children.begin();
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