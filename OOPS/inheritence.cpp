/*
 Author : Harsh Kumar Singh
 created at : 2024-10-11 12:36:57
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

class derived;

class par{
    private : 
        int b;
    public:
        int a;
        par(int x, int y){
            a = x;
            b = y;
        }
        friend class derived;
};

class derived{
    public : 
        void set_val(int x, int y, par& obj){
            obj.a = x;
            obj.b = y;
        }

        void disp(par&obj){
            cout<<obj.a<<" "<<obj.b<<"\n";
        }
};


class mobile{
    public : 
        mobile() {
            cout<<"mobile constructor called\n";
        }
};

class car{
    public : 
        car(){
            cout<<"car constructor called\n";
        }
};

class toyota: public car, public mobile{
    public:
        toyota(){
            cout<<"toyota constructor called\n";
        }
};


void solve(){
    toyota obj = toyota();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}