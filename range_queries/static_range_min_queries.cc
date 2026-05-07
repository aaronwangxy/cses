#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

struct SegmentTree {
    int n;
    vt<int> t;

    SegmentTree(vt<int>& arr) {
        n = arr.size();
        t = vt<int>(4*n, INT_MAX);
        build(arr, 1, 0, n-1);
    }

    void build(vt<int>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(arr, v*2, tl, tm);
            build(arr, v*2+1, tm+1, tr);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }

    int query(int a, int b) {
        return query_h(1, 0, n-1, a, b);
    }

    int query_h(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return INT_MAX;
        }
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return min(query_h(v*2, tl, tm, l, min(r, tm)), query_h(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vt<int> arr(n);
    for (auto &a : arr) cin >> a;
    
    SegmentTree st = SegmentTree(arr);
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        cout << st.query(a, b) << "\n";
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