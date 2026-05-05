#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void solve() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, vt<pair<int, ll>>> adjlist;
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adjlist[a].push_back({b, c});
    }

    unordered_map<int, ll> shortest_distances;
    priority_queue<pair<ll, int>, vt<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    while (shortest_distances.size() < n) {
        pair<ll, int> dist_node = pq.top(); pq.pop();
        ll dist = dist_node.first;
        int node = dist_node.second;

        if (shortest_distances.find(node) != shortest_distances.end()) {
            continue;
        }

        shortest_distances[node] = dist;
        for (auto nei : adjlist[node]) {
            int nei_node = nei.first;
            ll nei_dist = nei.second;
            if (shortest_distances.find(nei_node) == shortest_distances.end()) {
                pq.push({dist + nei_dist, nei_node});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << shortest_distances[i] << " ";
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