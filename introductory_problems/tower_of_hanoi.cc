#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

/*
Idea: we need to get the largest disk 
to the right tower. This necessarily means 
we reach a state where 
1. The leftmost tower only has the largest disk
2. The rightmost tower is empty (in order to place largest disk)
1 and 2 => the n-1 tower must be built in the middle
So, 
1. Build n-1 tower in the middle (recursive)
2. Move from 1 to 3 (largest disk from left tower to right tower)
3. Move n-1 tower to the right tower (recursive)
*/
vt<string> solve_h(int n, int src, int dst){
    if (n == 1) {
        return {to_string(src) + " " +  to_string(dst)};
    }
    int tmp = 1 ^ 2 ^ 3 ^ src ^ dst;
    vt<string> a = solve_h(n-1, src, tmp);
    vt<string> b = solve_h(n-1, tmp, dst);
    a.insert(a.end(), to_string(src) + " " + to_string(dst));
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

void solve() {
    int n;
    cin >> n;
    vt<string> ans = solve_h(n, 1, 3);
    cout << ans.size() << "\n";
    for (auto s : ans) {
        cout << s << "\n";
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