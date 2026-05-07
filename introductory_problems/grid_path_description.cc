#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

unordered_map<char, int> d = {
    {'R', 1},
    {'L', 3},
    {'U', 2},
    {'D', 0}
};

int dfs(int r, int c, int idx, string& s, bool visited[7][7]) {
    if (idx == 48 && r == 6 && c == 0) {
        return 1;
    }
    if (idx == 48 || r == 6 && c == 0) {
        return 0;
    }
    if ((r == 6 || visited[r+1][c]) && (r == 0 || visited[r-1][c])) {
        if (1 <= c && c <= 5 && !visited[r][c-1] && !visited[r][c+1]) {
            return 0;
        }
    }
    if ((c == 6 || visited[r][c+1]) && (c == 0 || visited[r][c-1])) {
        if (1 <= r && r <= 5 && !visited[r-1][c] && !visited[r+1][c]) {
            return 0;
        }
    }
    int ans = 0;
    visited[r][c] = true;
    if (s[idx] != '?') {
        int i = d[s[idx]];
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (0 <= nr && nr < 7 && 0 <= nc && nc < 7 && !visited[nr][nc]) {
            ans += dfs(nr, nc, idx+1, s, visited);
        }
    } else {
        for (int i = 0; i < 4; ++i) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (0 <= nr && nr < 7 && 0 <= nc && nc < 7 && !visited[nr][nc]) {
                ans += dfs(nr, nc, idx+1, s, visited);
            }
        }
    }
    visited[r][c] = false;
    return ans;
}

void solve() {
    string s;
    cin >> s;
    bool visited[7][7] = {};
    cout << dfs(0, 0, 0, s, visited);
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