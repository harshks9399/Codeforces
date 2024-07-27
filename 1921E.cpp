// THE BASIC SNIPPET
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m, x1,y1,x2,y2;
    cin>>n>>m>>x1>>y1>>x2>>y2;
    if(x1 >= x2) {cout<<"Draw\n";return;}
    int hd = abs(y2-y1);
    int vd = abs(x2-x1);

    if(hd>vd) {cout<<"Draw\n";return;}

    if(vd%2==1){ // Alice can win
        if(hd<=1) {cout<<"Alice\n";return;}
        // int lbd = y2-1;
        // int rbd = m-y2;
        // int bd;
        // if(y1 > y2) bd = lbd;
        // else if(y2 > y1) bd = rbd;
        // int b_move = (vd-1)/2;
        // if(b_move <= bd) cout<<"DRaw\n";
        // else cout<<"ALice\n";
        int a1 = max(1, y1-(vd/2)-1), a2= min(m, y1+(vd/2)+1);
        int b1 = max(1, y2-(vd/2)), b2 = min(m, y2+(vd/2));
        bool f1 = (a1<=b1) && (b1<=a2);
        bool f2 = (a1<=b2) && (b2<=a2);
        if(f1 && f2) cout<<"ALice\n";
        else cout<< "Draw\n";
        return;
    }else{
        // if(hd<=1) {cout<<"Bob\n";return;}
        // int lbd = y1-1;
        // int rbd = m-y1;
        // int bd;
        // if(y1 > y2) bd = rbd;
        // else if(y2 > y1) bd = lbd;
        // int b_move = (vd)/2;
        // if(b_move <= bd) cout<<"DRaw\n";
        // else cout<<"Bob\n";
        int b1 = max(1, y2-(vd/2)), b2= min(m, y2+(vd/2));
        int a1 = max(1, y1-(vd/2)), a2 = min(m, y1+(vd/2));
        bool f1 = (b1<=a1) && (a1<=b2);
        bool f2 = (b1<=a2) && (a2<=b2);
        if(f1 && f2) cout<<"Bob\n";
        else cout<< "Draw\n";
        return;
    }
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