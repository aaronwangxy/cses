#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vt<vt<ll>> dist(n+1, vt<ll>(n+1, LLONG_MAX));
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >>c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[a][b], c);
    }
    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] == LLONG_MAX || dist[k][j] == LLONG_MAX) continue;
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        ll d = dist[a][b] == LLONG_MAX ? -1 : dist[a][b];
        cout << d << " ";
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