#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void dfs(int city, map<int, vt<int>>& adjlist, set<int>& visited) {
    visited.insert(city);
    for (auto nei : adjlist[city]) {
        if (visited.find(nei) == visited.end()) {
            dfs(nei, adjlist, visited);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, vt<int>> adjlist;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    vt<int> to_connect;
    set<int> visited;
    for (int i = 1; i <= n; ++i) {
        if (visited.find(i) == visited.end()) {
            to_connect.push_back(i);
            dfs(i, adjlist, visited);
        }
    }
    cout << to_connect.size()-1 << "\n";
    for (int i = 0; i < to_connect.size()-1; ++i) {
        cout << to_connect[i] << " " << to_connect[i+1] << "\n";
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