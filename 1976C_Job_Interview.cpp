// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>prog(m+n+1), test(n+m+1);
    for(int i=0;i<=m+n;i++){
        cin>>prog[i];
    }
    for(int i=0;i<=m+n;i++){
        cin>>test[i];
    }

    

    for(int i=0;i<=n+m;i++){
        lli prog_score = 0, test_score = 0;
        int prog_count = 0, test_count = 0;
        for(int j=0;j<=n+m;j++){
            if(j==i) continue;
            if(prog[j] > test[j]){
                if(prog_count < n){
                    prog_count++;
                    prog_score+=prog[j];
                }else{
                    test_score+=test[j];
                    test_count++;
                }
            }else{
                if(test_count < m){
                    test_score+=test[j];
                    test_count++;
                }else{
                    prog_count++;
                    prog_score+=prog[j];
                }
            }
        }
        cout<<test_score + prog_score<<" ";
    }
    cout<<"\n";
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