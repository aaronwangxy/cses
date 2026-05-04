#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void sink(vt<vt<char>>& grid, int row, int col) {
    int n = grid.size();
    int m = grid[0].size();
    grid[row][col] = '#';
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int nr = row + dx[i];
            int nc = col + dy[i];
            if (0 <= nr && nr < n && 0 <= nc && nc < m && grid[nr][nc] == '.') {
                sink(grid, nr, nc);
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vt<vt<char>> grid(n, vt<char>(m));
    for (auto &r : grid) {
        for (auto &c : r) {
            cin >> c;
        }
    }

    int ans = 0;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (grid[r][c] == '.') {
                ++ans;
                sink(grid, r, c);
            }
        }
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