#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<vector<lli>> d1(n, vector<lli>(n, 0)), d2(n, vector<lli>(n, 0));

    // Base cases
    for (int i = 0; i < n; i++) {
        d1[i][i] = s[i];
        d2[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            lli pick_left = s[i] + d2[i + 1][j];
            lli pick_right = s[j] + d2[i][j - 1];

            if (pick_left > pick_right) {
                d1[i][j] = pick_left;
                d2[i][j] = d1[i + 1][j];
            } else {
                d1[i][j] = pick_right;
                d2[i][j] = d1[i][j - 1];
            }
        }
    }

    cout << d1[0][n - 1];
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
