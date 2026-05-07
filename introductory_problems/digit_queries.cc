#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

/*
1-9 9 * 10^0 * 1
10-99 90 * 2 = 9 * 10^1 * 2
100-999 900 * 3
*/

ll llpow(int e) {
    ll ans = 1;
    while (e--) {
        ans *= 10;
    }
    return ans;
}

void solve() {
    ll k;
    cin >> k;

    // Find how many digits are in the number
    ll cum_digits = 0;
    int i = 1;
    for (; cum_digits + i * 9 * llpow(i-1) < k; ++i) {
        cum_digits += i * 9 * llpow(i-1);
    }
    k -= cum_digits;
    ll nums_to_skip = (k-1)/i;
    ll num = llpow(i-1) + nums_to_skip;
    int digit = k - i*nums_to_skip;
    string snum = to_string(num);
    cout << snum[digit-1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}