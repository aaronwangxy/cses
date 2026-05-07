#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int dfs(int node, unordered_map<int, vt<int>>& adjlist, int& ans, vt<int>& visited) {
    visited[node] = true;
    int h1 = 0;
    int h2 = 0;
    for (auto nei : adjlist[node]) {
        if (!visited[nei]) {
            int h = dfs(nei, adjlist, ans, visited);
            if (h > h2) {
                swap(h, h2);
            }
            if (h2 > h1) {
                swap(h2, h1);
            }
        }
    }
    ans = max(ans, h1 + h2);
    return 1 + max(h1, h2);
}

void solve() {
    int n;
    cin >> n;
    unordered_map<int, vt<int>> adjlist;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    int ans = 0;
    vt<int> visited(n+1);
    dfs(1, adjlist, ans, visited);
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