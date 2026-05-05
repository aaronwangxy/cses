#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

bool dfs(int city, unordered_map<int, vt<int>>& adjlist, unordered_map<int, int>& parent, unordered_set<int>& visited_all, int& start) {
    visited_all.insert(city);

    for (auto nei : adjlist[city]) {
        if (parent[city] == nei) continue;
        if (parent.find(nei) != parent.end()) {
            parent[nei] = city;
            start = nei;
            return true;
        } else {
            parent[nei] = city;
            if (dfs(nei, adjlist, parent, visited_all, start)) {
                return true;
            }
            parent.erase(nei);
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, vt<int>> adjlist;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    unordered_map<int, int> parent;
    unordered_set<int> visited_all;
    int start = -1;
    for (int i = 1; i <= n; ++i) {
        if (visited_all.find(i) == visited_all.end()) {
            parent[i] = -1;
            if (dfs(i, adjlist, parent, visited_all, start)) {
                vt<int> cycle;
                int curr = start;
                do {
                    cycle.push_back(curr);
                    curr = parent[curr];
                } while (curr != start);
                cycle.push_back(start);
                cout << cycle.size() << "\n";
                for (auto c : cycle) cout << c << " ";
                return;
            }
            parent.erase(i);
        }
    }
    cout << "IMPOSSIBLE";
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