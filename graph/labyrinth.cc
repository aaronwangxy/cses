#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void solve() {
    int n, m;
    cin >> n >> m;
    vt<vt<char>> grid(n, vt<char>(m));
    pair<int, int> start;
    pair<int, int> target;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                start = make_pair(i, j);
            }
            if (grid[i][j] == 'B') {
                target = make_pair(i, j);
            }
        }
    }

    bool found = false;
    vt<vt<pair<int, int>>> parent(n, vt<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> q;
    parent[start.first][start.second] = make_pair(-1, -1);
    q.push(start);
    while (!q.empty() && !found) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            pair<int, int> pair = q.front();
            if (pair == target) {
                found = true;
                break;
            }
            q.pop();
            int r = pair.first;
            int c = pair.second;
            for (int j = 0; j < 4; ++j) {
                int nr = r + dx[j];
                int nc = c + dy[j];
                if (0 <= nr && nr < n && 0 <= nc && nc < m && grid[nr][nc] != '#') {
                    auto child = make_pair(nr, nc);
                    if (parent[nr][nc] != make_pair(-1, -1)) {
                        continue;
                    }
                    parent[nr][nc] = pair;
                    q.push(child);
                }
            }
        }
    }
    
    if (!found) {
        cout << "NO";
        return;
    }

    map<pair<int, int>, char> change_direction = {
        {make_pair(1, 0), 'D'},
        {make_pair(-1, 0), 'U'},
        {make_pair(0, 1), 'R'},
        {make_pair(0, -1), 'L'},
    };

    vt<pair<int, int>> path_points;
    pair<int, int> current = target;
    while (current != start) {
        path_points.push_back(current);
        current = parent[current.first][current.second];
    }
    path_points.push_back(start);
    
    cout << "YES\n";
    reverse(path_points.begin(), path_points.end());
    string path;
    for (int i = 0; i < path_points.size() - 1; ++i) {
        int sr = path_points[i].first;
        int sc = path_points[i].second;
        int nr = path_points[i+1].first;
        int nc = path_points[i+1].second;
        pair<int, int> change = make_pair(nr - sr, nc - sc);
        path += change_direction[change];
    }
    cout << path.size() << "\n" << path;
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