#include <bits/stdc++.h>
using namespace std;
#define lli long long int

const int N = 1e5+1;
string s;
vector<vector<char>> t(4*N);

void build(int node, int L, int R) {
    if (L == R) {
        t[node].clear(); // Clear any existing data
        t[node].push_back(s[L]); // Store the character as an integer
        return;
    }

    int M = (L + R) / 2;
    build(2 * node, L, M);
    build(2 * node + 1, M + 1, R);

    // Merging two child nodes
    merge(t[2 * node].begin(), t[2 * node].end(), t[2 * node + 1].begin(), t[2 * node + 1].end(), back_inserter(t[node]));
    t[node].erase(unique(t[node].begin(), t[node].end()), t[node].end());
}

void find(int node, int L, int R, int l, int r, set<char>& ans) {
    if (l > R || r < L) return;
    if (l <= L && r >= R) {
        ans.insert(t[node].begin(), t[node].end());
        return;
    }
    int M = (L + R) / 2;
    find(2 * node, L, M, l, r, ans);
    find(2 * node + 1, M + 1, R, l, r, ans);
}

void merge(int node, int L, int R, int pos, char ch) {
    if (L == R) {
        t[node].clear(); // Clear the vector at this node
        t[node].push_back(ch); // Insert the updated character
        return;
    }

    int M = (L + R) / 2;
    if (pos <= M) merge(2 * node, L, M, pos, ch);
    else merge(2 * node + 1, M + 1, R, pos, ch);

    t[node].clear(); // Clear before merging
    merge(t[2 * node].begin(), t[2 * node].end(), t[2 * node + 1].begin(), t[2 * node + 1].end(), back_inserter(t[node]));
    t[node].erase(unique(t[node].begin(), t[node].end()), t[node].end());
}

void solve() {
    cin >> s;
    int n = s.size();
    build(1, 0, n - 1);

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            char nc;
            cin >> pos >> nc;
            merge(1, 0, n - 1, pos - 1, nc);
        } else {
            int l, r;
            cin >> l >> r;
            set<char> ans;
            find(1, 0, n - 1, l - 1, r - 1, ans);
            cout << ans.size() << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
