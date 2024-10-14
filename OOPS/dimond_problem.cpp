/*
 Author : Harsh Kumar Singh
 created at : 2024-10-11 13:26:19
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int


class vehicle{
    public:
        vehicle(){
            cout<<"vehicle constructor called\n";
        }
};

class fourwheeler{
    public:
        fourwheeler(){
            cout<<"4 wheeler constructor called\n";
        }
};

class car: public vehicle, public fourwheeler{
    public : 
        car() {
            cout<<"car constructor as well\n";
        }
};





class person{
    public: 
        string name;
        int age;
    person(){
        cout<<"person constructor\n";
    }
};

class student: public person{
    public : 
        student(){
            cout<<"student constructor called\n";
        }
};

class faculty: public person{
    public : 
        faculty(){ cout<<"faculty constructor called\n"; }
};

class TA: public student, public faculty{
    public  : 
        TA() { cout<<"TA constructor called \n" ;}
};



void solve(){
    // car obj;
    TA obj2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin >> t;
    t = 1;

    while(t--)
        solve();
    return 0;
}