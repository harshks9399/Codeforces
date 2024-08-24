/*
 Author : Harsh Kumar Singh
 created at : 2024-08-24 20:34:49
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin >> n;
    vector<vector<lli>> dist(n + 1, vector<lli>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dist[i][j];
        }
    }

    vector<int> lines(n);
    for (int i = 0; i < n; i++) cin >> lines[i];
    reverse(lines.begin(), lines.end());

    vector<lli> ans;
    lli curr = 0;
    vector<bool> included(n + 1, false);  // Track included nodes

    for (int k = 0; k < n; k++) {
        int nk = lines[k];
        included[nk] = true;

        // Floyd-Warshall update
        for (int i = 1; i <= n; i++) {
            if (!included[i]) continue;
            for (int j = 1; j <= n; j++) {
                if (!included[j]) continue;
                dist[i][j] = min(dist[i][j], dist[i][nk] + dist[nk][j]);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!included[i]) continue;
            for (int j = 1; j <= n; j++) {
                if (!included[j]) continue;
                dist[i][nk] = min(dist[i][nk], dist[i][j] + dist[j][nk]);
                dist[nk][j] = min(dist[nk][j], dist[nk][i] + dist[i][j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!included[i]) continue;
            for (int j = 1; j <= n; j++) {
                if (!included[j]) continue;
                dist[i][j] = min(dist[i][j], dist[i][nk] + dist[nk][j]);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!included[i]) continue;
            for (int j = 1; j <= n; j++) {
                if (!included[j]) continue;
                dist[i][nk] = min(dist[i][nk], dist[i][j] + dist[j][nk]);
                dist[nk][j] = min(dist[nk][j], dist[nk][i] + dist[i][j]);
            }
        }

        // Sum up the distances for included nodes
        curr = 0;
        for (int i = 1; i <= n; i++) {
            if (!included[i]) continue;
            for (int j = 1; j <= n; j++) {
                if (!included[j]) continue;
                curr += dist[i][j];
            }
        }

        ans.push_back(curr);
    }

    reverse(ans.begin(), ans.end());
    for (auto it : ans) cout << it << " ";
    cout << "\n";
    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}