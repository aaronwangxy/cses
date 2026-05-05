#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

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

    map<int, int> parent;
    parent[1] = -1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto nei : adjlist[curr]) {
            if (parent.find(nei) != parent.end()) continue;
            parent[nei] = curr;
            q.push(nei);
        }
    }

    vt<int> path;
    int curr = n;
    while (parent.find(curr) != parent.end()) {
        path.push_back(curr);
        curr = parent[curr];
    }

    if (curr == -1) {
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for (auto p : path) cout << p << " ";
    } else {
        cout << "IMPOSSIBLE";
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