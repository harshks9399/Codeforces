

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> t(4 * N);
vector<int> v;

void build(int node, int llt, int rlt) {
    if (llt == rlt) {
        t[node] = v[llt];
        return;
    }

    int mlt = (llt + rlt) / 2;
    build(2 * node, llt, mlt);
    build(2 * node + 1, mlt + 1, rlt);
    t[node] = t[2 * node] + t[2 * node + 1];
}

int sum(int node, int l, int r, int llt, int rlt) {
    if (l > rlt || r < llt) return 0;  // No overlap
    if (l <= llt && r >= rlt) return t[node];  // Total overlap

    int mlt = (llt + rlt) / 2;
    return sum(2 * node, l, r, llt, mlt) + sum(2 * node + 1, l, r, mlt + 1, rlt);
}

void update(int node, int pos, int n_val, int lt, int rt) {
    if (lt == rt) {
        t[node] = n_val;
        return;
    }

    int mt = (lt + rt) / 2;
    if (pos <= mt) update(2 * node, pos, n_val, lt, mt);
    else update(2 * node + 1, pos, n_val, mt + 1, rt);

    t[node] = t[2 * node] + t[2 * node + 1];
}

int main() {
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    build(1, 0, n - 1);  // Start building from node 1

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << sum(1, a, b, 0, n - 1) << "\n";  // Start querying from node 1
    }

    return 0;
}
