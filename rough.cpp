#include<bits/stdc++.h>
using namespace std;


int main(){
    unordered_map<int,int>check;
    check[1] = 1;
    check[2] = 2;
    check[3] = 3;
    check[4] = 4;
    check[5] = 5;
    for(auto it:check)  
        cout<<it.first<<" "<<it.second<<endl;
    return 0;
}