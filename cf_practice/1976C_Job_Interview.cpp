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

    int bad_candidate = -1, bad_type=-1;
    lli prog_count = 0, test_count = 0, tot_Score = 0;
    vector<lli> sol(n+m+1);
    for(int i=0;i<n+m;i++){
        if(prog[i] > test[i]){
            if(prog_count < n){
                tot_Score += prog[i];
                prog_count ++;
            }else{
                tot_Score += test[i];
                if(bad_candidate==-1){
                    bad_candidate = i;
                    bad_type = 0;
                }
                test_count ++;
            }
        }else{
            if(test_count < m){
                tot_Score += test[i];
                test_count++;
            }else{
                tot_Score += prog[i];
                if(bad_candidate==-1){
                    bad_candidate = i;
                    bad_type = 1;
                }
                prog_count++;
            }
        }
    }
    if(bad_candidate==-1){
        bad_candidate = m+n;
        bad_type = prog[m+n] > test[m+n] ? 0:1;
    }



    sol[m+n] = tot_Score;
    lli add;
    if(bad_type==0)
        add = test[n+m];
    else if(bad_type==1)
        add = prog[n+m];
    else if (prog_count == n)
        add = test[n+m];
    else
        add = prog[n+m];
    for(int candi = m+n-1;candi>=0;candi--){
        if(bad_candidate <= candi){
            lli rem ;
            if(bad_type==0) rem = test[candi];
            else rem = prog[candi];
            sol[candi] = tot_Score + add - rem;
        }else{
            lli rem,add2=0 ;
            rem = max(prog[candi], test[candi]);
            // add2 = max(prog[bad_candidate], test[bad_candidate]); ->wrong
            int candi_type = (prog[candi] > test[candi]) ? 1:0;
            if(candi_type != bad_type)
                add2 = max(prog[bad_candidate], test[bad_candidate]) - min(prog[bad_candidate], test[bad_candidate]);
            sol[candi] = tot_Score - rem + add + add2 ;
        }
    }
    for(auto it:sol)
        cout<<it<<" ";
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