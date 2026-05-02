#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

vt<string> solve_h(int cnt[], string curr, int n) {
    if (curr.size() == n) return {curr};
    vt<string> ans;
    for (int i = 0; i < 26; ++i) {
        // Use char at this index
        if (cnt[i] > 0) {
            --cnt[i];
            vt<string> incl = solve_h(cnt, curr + char('a' + i), n);
            ans.insert(ans.end(), incl.begin(), incl.end());
            ++cnt[i];
        }
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;
    int cnt[26] = {0};
    for (auto c : s) ++cnt[c - 'a'];
    vt<string> ans = solve_h(cnt, "", s.size());
    cout << ans.size() << "\n";
    for (auto a : ans) cout << a << "\n";
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