#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

void solve() {
    string s;
    cin >> s;
    map<char, int> counter;
    for (auto c : s) {
        if (counter.find(c) == counter.end()) {
            counter[c] = 0;
        }
        counter[c] += 1;
    }
    int num_odd = 0;
    for (auto [c, freq] : counter) {
        if (freq % 2) {
            num_odd += 1;
        }
    }
    if (num_odd > 1) {
        cout << "NO SOLUTION";
    } else {
        vt<char> palindrome(s.size());
        int i = 0;
        for (auto [c, freq] : counter) {
            if (freq % 2 == 0) {
                for (int j = 0; j < freq / 2; ++j) {
                    palindrome[i] = c;
                    palindrome[s.size()-1-i] = c;
                    i += 1;
                }
            } else {
                int mid = s.size() / 2;
                for (int j = 1; j <= freq / 2; ++j) {
                    palindrome[mid -j] = c;
                    palindrome[mid + j] = c;
                }
                palindrome[mid] = c;
            }
        }
        for (auto c : palindrome) {
            cout << c;
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