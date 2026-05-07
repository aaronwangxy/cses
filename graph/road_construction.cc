#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

struct UnionFind {
    vt<int> parents;
    vt<int> sizes;
    int num_components;
    int largest_component;

    UnionFind(int n) {
        parents = vt<int>(n);
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
        sizes = vt<int>(n, 1);
        num_components = n;
        largest_component = 1;
    }

    int find(int a) {
        while (a != parents[a]) {
            a = parents[a];
        }
        return a;
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) {
            return;
        }
        if (sizes[pa] > sizes[pb]) {
            swap(pa, pb);
        }
        sizes[pb] += sizes[pa];
        parents[pa] = pb;
        --num_components;
        largest_component = max(largest_component, sizes[pb]);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    UnionFind uf = UnionFind(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        uf.unite(a, b);
        cout << uf.num_components << " " << uf.largest_component << "\n";
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