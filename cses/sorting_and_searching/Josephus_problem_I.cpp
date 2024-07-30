// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve(){
    int n;
    cin>>n;

    queue<int>q;

    for(int i=1;i<=n;i++) q.push(i);

    int flag = 0;
    while(q.size()>0){
        int top = q.front();
        q.pop();
        if(!flag) q.push(top);
        else cout<<top<<" ";
        flag = (flag==0);
    }
    return;
}


// void solve(){
//     int n;
//     cin>>n;
//     if(n==1) {
//         cout<<"1\n";
//         return;
//     }
//     unordered_map<int,int>start;
//     for(int i=1;i<=n;i++) start[i] = i;

//     while(n!=1){
//         int out  = start[2];
//         unordered_map<int,int>curr;
//         int num = n-1;
//         int index = 1;
//         while(num--){
//             curr[index] = start[((index+1)%n) + 1];
//             index++;
//         }
//         n--;
//         cout<<out<<" ";
//         start = curr;
//     }
//     cout<<start[1]<<" ";
//     return;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}