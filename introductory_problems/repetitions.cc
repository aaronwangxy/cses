#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    string s;
    cin >> s;

    int ans = 0;
    int i = 0;
    while (i < s.size()) {
        char curr_char = s[i];
        int curr_length = 1;
        while (i+1 < s.size() && s[i+1] == curr_char) {
            i += 1;
            curr_length += 1;
        }
        ans = max(ans, curr_length);
        i += 1;
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