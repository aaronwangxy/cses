#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void solve() {
    int n, m;
    cin >> n >> m;
    vt<int> arr(n);
    for (auto &a : arr) cin >> a;

    map<int, int> num_to_idx;
    for (int i = 0; i < n; ++i) {
        num_to_idx[arr[i]] = i;
    }
    num_to_idx[0] = n;
    num_to_idx[n+1] = n;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int num = arr[i];
        int prev = num - 1;
        if (num_to_idx[prev] > num_to_idx[num]) {
            ++ans;
        }
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        int n1 = arr[a];
        int n2 = arr[b];
        int n1prev = n1-1;
        int n1next = n1+1;
        int n2prev = n2-1;
        int n2next = n2+1;
        int old_idx_n1prev = num_to_idx[n1prev];
        int old_idx_n1next = num_to_idx[n1next];
        int old_idx_n2prev = num_to_idx[n2prev];
        int old_idx_n2next = num_to_idx[n2next];

        if (old_idx_n1prev < a && num_to_idx[n1prev] > b) ++ans;
        if (old_idx_n1prev > a && num_to_idx[n1prev] < b) --ans;
        if (old_idx_n1next < a && num_to_idx[n1next] > b) --ans;
        if (old_idx_n1next > a && num_to_idx[n1next] < b) ++ans;
        num_to_idx[arr[a]] = b;

        if (old_idx_n2prev < b && num_to_idx[n2prev] > a) ++ans;
        if (old_idx_n2prev > b && num_to_idx[n2prev] < a) --ans;
        if (old_idx_n2next < b && num_to_idx[n2next] > a) --ans;
        if (old_idx_n2next > b && num_to_idx[n2next] < a) ++ans;
        num_to_idx[arr[b]] = a;

        swap(arr[a], arr[b]);
        cout << ans << "\n";
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