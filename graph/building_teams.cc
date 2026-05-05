#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void assign(int pupil, unordered_set<int>& t1, unordered_set<int>& t2, bool& impossible, unordered_map<int, vt<int>>& adjlist) {
    queue<int> q;
    q.push(pupil);
    bool t1_turn = true;
    while (!q.empty()) {
        unordered_set<int>& team = t1_turn ? t1 : t2;
        unordered_set<int>& other_team = t1_turn ? t2 : t1;
        int sz = q.size();
        for (int _ = 0; _ < sz; ++_) {
            int curr = q.front(); q.pop();
            team.insert(curr);
            for (auto nei : adjlist[curr]) {
                if (team.find(nei) != team.end()) {
                    impossible = true;
                    break;
                }
                if (other_team.find(nei) != other_team.end()) continue;
                q.push(nei);
            }
        }
        t1_turn = !t1_turn;
    }
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

    unordered_set<int> t1;
    unordered_set<int> t2;
    bool impossible = false;
    for (int i = 1; i <= n; ++i) {
        if (t1.find(i) == t1.end() && t2.find(i) == t2.end()) {
            assign(i, t1, t2, impossible, adjlist);
        }
    }

    if (impossible) {
        cout << "IMPOSSIBLE";
    } else {
        for (int i = 1; i <= n; ++i) {
            if (t1.find(i) != t1.end()) {
                cout << "1 ";
            } else {
                cout << "2 ";
            }
        }
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