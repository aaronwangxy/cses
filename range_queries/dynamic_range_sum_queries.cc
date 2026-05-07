#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

struct SegmentTree {
    int n;
    vt<ll> t;

    SegmentTree(vt<int>& arr) {
        n = arr.size();
        t = vt<ll>(4*n, 0);
        build(1, 0, n-1, arr);
    }

    void build(int v, int tl, int tr, vt<int>& a) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(v*2, tl, tm, a);
            build(v*2+1, tm+1, tr, a);
            t[v] = t[v*2] + t[v*2+1];
        }
    }

    ll query(int a, int b) {
        return query_h(1, 0, n-1, a, b);
    }

    ll query_h(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return query_h(v*2, tl, tm, l, min(tm, r)) + query_h(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

    void update(int pos, int val) {
        update_h(1, 0, n-1, pos, val);
    }

    void update_h(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            t[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update_h(v*2, tl, tm, pos, val);
            } else {
                update_h(v*2+1, tm+1, tr, pos, val);
            }
            t[v] = t[v*2] + t[v*2+1];
        }
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vt<int> arr(n);
    for (auto &a : arr) cin >> a;

    SegmentTree st = SegmentTree(arr);
    for (int i = 0; i < q; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            --a;
            st.update(a, b);
        }  else {
            --a; --b;
            cout << st.query(a, b) << "\n";
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