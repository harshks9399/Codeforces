#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n, m, k, g;
    cin >> n >> m >> k >> g;
    vector<int> v(g);
    for (int &it: v) cin >> it;
    sort(v.begin(), v.end());

    multiset<lli> multisetO;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int l = i, r = n - i - 1;
            int u = j, d = m - j - 1;

            lli o1 = min(l + 1, r + 1);
            o1 = o1 < k ? o1 : k;

            lli o2 = min(u + 1, d + 1);
            o2 = o2 < k ? o2 : k;

            lli o = -1 * o1 * o2;
            multisetO.insert(o);
            cout<<o<<" ";
        }
        cout<<"\n";
    }

    lli ans = 0;
    for (int i = g - 1; i >= 0; i--) {
        lli top = *multisetO.begin();
        top *= -1;
        multisetO.erase(multisetO.begin());
        ans += v[i] * top;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
