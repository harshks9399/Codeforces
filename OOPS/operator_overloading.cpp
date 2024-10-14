/*
 Author : Harsh Kumar Singh
 created at : 2024-10-11 17:17:46
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

class Complex{
    public : 
        int real;
        int img;
    
    public :
        Complex() : real(0), img(0) {}
        Complex(int x, int y) : real(x), img(y)  {}

        void disp() {
            if(img < 0) cout<<"the complex number is  "<<real<<img<<"i\n";
            else cout<<"the complex number is "<<real<<"+"<<img<<"i\n";
        }

        // friend Complex operator  + (Complex &a, Complex &b){
        //     Complex temp = Complex(0,0);
        //     temp.real = a.real + b.real;
        //     temp.img = a.img + b.img;
        //     return temp;
        // }

    Complex operator+(Complex const& obj)
        {
            cout << "operator called on the complex number : " << real << (img >= 0 ? "+" : "") << img << "i\n";
            Complex res;
            res.real = real + obj.real;
            res.img = img + obj.img;
            return res;
        }
    Complex operator-(Complex const& obj)
        {
            cout << "operator called on the complex number : " << real << (img >= 0 ? "+" : "") << img << "i\n";
            Complex res;
            res.real = real - obj.real;
            res.img = img - obj.img;
            return res;
        }


};


void solve(){
    Complex a(1,1), b(2,2);
    Complex c = a + b;
    c.disp();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}