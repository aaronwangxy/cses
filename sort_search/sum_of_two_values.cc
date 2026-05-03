#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n, target;
    cin >> n >> target;
    vt<int> arr(n);
    for (auto &v : arr) cin >> v;

    map<int, int> int_to_idx;
    for (int i = 0; i < n; ++i) {
        int value = arr[i];
        int_to_idx[value] = i;
    }

    bool found = false;
    for (int i = 0; i < n; ++i) {
        int value = arr[i];
        int complement = target - value;
        if (int_to_idx.find(complement) != int_to_idx.end() && int_to_idx[complement] != i && !found) {
            cout << to_string(i+1) + " " + to_string(int_to_idx[complement]+1);
            found = true;
        }
    }
    if (!found) cout << "IMPOSSIBLE";
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