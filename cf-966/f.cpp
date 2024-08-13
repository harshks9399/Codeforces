// Author : Harsh Kumar Singh
//TEMPLATES : ft, expo, gcd
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> v(n);
    lli tot_score = 0;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if(a < b) v[i] = {a, b};
        else v[i] = {b, a};
        tot_score += a + b;
    }

    if(tot_score < k) {
        cout<<"TOT "<<tot_score<<"\n";
        cout << "-1\n";
        return;
    }

    map<int,int> m1, m2;
    m1[0] = 0;

    for(int i = 0; i < n; i++) {
        int a = min(v[i].first, v[i].second);
        int b = max(v[i].first, v[i].second);
        map<int,int> m_temp;
        m_temp[0] = 0;
        int score = 1;
        while(score <= b) {
            m_temp[score] = a + m_temp[score-1];
            b--;
            score++;
            if(b == 0) break;
            int temp = min(a, b);
            b = max(a, b);
            a = temp;
        }
        

        m2 = m1;
        if(i==0) continue; 
        for(auto it : m1) {
            for(int j = 1; j < score; j++) {
                int ns = it.first + j;
                int nst = it.second + m_temp[j];
                if(m2.find(ns) == m2.end()) m2[ns] = nst;
                else m2[ns] = min(m2[ns], nst);
            }
            cout<<it.first + score - 1 <<" ";
        }
        cout<<"\n";
        m1 = m2;
    }

    cout<<m1[k]<<"\n";
    return;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}