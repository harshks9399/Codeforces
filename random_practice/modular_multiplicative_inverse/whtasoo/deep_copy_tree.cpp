/*
 Author : Harsh Kumar Singh
 created at : 2024-10-04 19:10:00
*/
//TEMPLATES : ft, expo, gcd, seive, KMP(string), DSU, DSU_adv
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

struct Node{
    int val;
    Node*left=NULL;
    Node*right=NULL;

    Node() {}

    Node(int x){
        val = x;
    }

    Node(int x, Node * l,  Node * r){
        val = x;
        left = l;
        right = r;
    }
};


void helper(Node * curr, Node * head){
    if(head->right!=NULL) {
        curr->left = new Node(head->right->val);
        helper(curr->left, head->right);
    }
    if(head->left!=NULL) {
        curr->right = new Node(head->left->val);
        helper(curr->right, head->left);
    }
}

void print(Node * node){
    if(node==NULL) return ;
    cout<<node->val<<" ";
    print(node->left);
    print(node->right);
}


void solve(){
    Node * l = new Node(10, new Node(8), new Node(12));
    Node * r = new Node(30, new Node(25), new Node(40));
    Node * root  = new Node(20, l, r);

    /*LOGIC BELOW*/

    Node * ans = new Node(root->val);
    helper(ans, root);
    print(root);
    cout<<"\n";
    print(ans);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}