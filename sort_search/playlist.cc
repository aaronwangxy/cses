#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    int n;
    cin >> n;
    vt<int> arr(n);
    for (auto& v : arr) cin >> v;

    int ans = 1;
    map<int, int> song_to_index;
    int l = 0;
    for (int r = 0; r < n; ++r) {
        int song = arr[r];
        if (song_to_index.find(song) != song_to_index.end() && song_to_index[song] >= l) {
            l = song_to_index[song] + 1;
        }
        song_to_index[song] = r;
        ans = max(ans, r - l + 1);
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