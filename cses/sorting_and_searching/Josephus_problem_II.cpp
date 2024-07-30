#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
    
    int n,k;cin>>n>>k;
    unordered_map<int,int> start;
    
    for(int i=1;i<=n;i++) start[i] = i;
    
    
    int count2 = n-1;
    
    while(n!=1){
        int count = n;
        
        int out_idx = (k%n) + 1;
        int out = start[out_idx];
        
        unordered_map<int,int> curr;
        count--;
        int index = 1;
        while(count--){
            curr[index] = start[((index+k)%n) + 1];
            // cout<<curr[index]<<" ";
            index++;
        }
        // cout<<"\n";
        cout<<out<<" ";
        start = curr;
        n--;
        
    }
    cout<<start[1]<<" ";
    return 0;
}