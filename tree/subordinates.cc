#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int get_num_subordinates(int boss, unordered_map<int, vt<int>>& adjlist, unordered_map<int, int>& num_subordinates) {
    if (num_subordinates.find(boss) != num_subordinates.end()) {
        return num_subordinates[boss];
    }
    int subs = 0;
    for (auto sub : adjlist[boss]) {
        subs += 1 + get_num_subordinates(sub, adjlist, num_subordinates);
    }
    num_subordinates[boss] = subs;
    return subs;
}

void solve() {
    int n;
    cin >> n;
    unordered_map<int, vt<int>> adjlist;
    for (int i = 2; i <= n; ++i) {
        int boss;
        cin >> boss;
        adjlist[boss].push_back(i);
    }
    unordered_map<int, int> num_subordinates;
    for (int i = 1; i <= n; ++i) {
        cout << get_num_subordinates(i, adjlist, num_subordinates) << " ";
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