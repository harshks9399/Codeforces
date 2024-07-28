// // THE BASIC SNIPPET
// #include <bits/stdc++.h>
// using namespace std;
// #define lli long long int

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     multiset<int>tic;
//     for(int i=0;i<n;i++) {
//         int x;
//         cin>>x;
//         tic.insert( -x);
//     }

//     // sort(tic.begin(), tic.end());

//     while(m--){
//         int maxi ; cin>>maxi;
//         if(tic.size()==0) {
//             cout<<-1<<"\n";
//             continue;
//         }

//         auto loc = lower_bound(tic.begin(), tic.end(), -1*maxi);
//         if(loc == tic.end()){
//             cout<<"-1\n";
//             continue;
//         }
//         cout<<-1 * (*loc)<<"\n";
//         tic.erase(loc);
//     }
//     return;
    
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//         solve();
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

int N, M, h, t;
multiset<int> prices;

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d", &h);
        prices.insert(-h);
    }
    for(int i = 0; i < M; i++){
        scanf("%d", &t);
        if(prices.lower_bound(-t) == prices.end())
            printf("-1\n");
        else {
            printf("%d\n", -(*prices.lower_bound(-t)));
            prices.erase(prices.lower_bound(-t));
        }
    }
}