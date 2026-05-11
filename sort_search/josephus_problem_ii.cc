#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

struct SegmentTree {
    int n;
    vt<int> t;

    SegmentTree(int num_children) {
        n = num_children;
        t = vt<int>(4*n);
        vt<int> arr(n);
        for (int i = 1; i <= n; ++i) {
            arr[i-1] = i;
        }
        build(1, 0, n-1, arr);
    }

    void build(int v, int tl, int tr, vt<int>& arr) {
        if (tl == tr) {
            t[v] = 1;
        } else {
            int tm = (tl + tr) / 2;
            build(v*2, tl, tm, arr);
            build(v*2+1, tm+1, tr, arr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }

    int query(int idx) {
        return query_h(1, 0, n-1, idx);
    }

    int query_h(int v, int tl, int tr, int idx) {
        t[v] -= 1;
        if (tl == tr) {
            return tl+1;
        }
        int tm = (tl + tr) / 2;
        int l = t[v*2];
        if (idx < l) {
            return query_h(v*2, tl, tm, idx);
        } 
        return query_h(v*2+1, tm+1, tr, idx - l);
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    
    SegmentTree st = SegmentTree(n);
    int idx = 0;
    for (int i = 0; i < n; ++i) {
        idx = (idx + k) % (n - i);
        cout << st.query(idx) << " ";
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