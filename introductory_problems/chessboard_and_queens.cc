#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

// number of valid boards with a queen placed on (r, c)
int count_ways(int r, int c, vt<vt<char>>& board, vt<vt<int>>& attacked) {
    int n = 8;
    if (attacked[r][c] > 0 || board[r][c] == '*') {
        return 0;
    }
    if (r == n - 1) {
        return 1;
    }
    int num_ways = 0;
    for (int i = 0; i < 8; ++i) {
        int nr = r;
        int nc = c;
        for (int j = 1; j < n; ++j) {
            nr += dx[i];
            nc += dy[i];
            if (0 <= nr && nr < n && 0 <= nc && nc < n) {
                attacked[nr][nc] += 1;
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        num_ways += count_ways(r+1, i, board, attacked);
    }
    for (int i = 0; i < 8; ++i) {
        int nr = r;
        int nc = c;
        for (int j = 1; j < n; ++j) {
            nr += dx[i];
            nc += dy[i];
            if (0 <= nr && nr < n && 0 <= nc && nc < n) {
                attacked[nr][nc] -= 1;
            } else {
                break;
            }
        }
    }
    return num_ways;
}

void solve() {
    int n = 8;
    vt<vt<char>> board(n, vt<char>(n));
    for (auto &r : board) {
        for (auto &c : r) {
            cin >> c;
        }
    }

    vt<vt<int>> attacked(n, vt<int>(n));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += count_ways(0, i, board, attacked);
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