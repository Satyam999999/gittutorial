#include <iostream>
#include <vector>
#include <algorithm>
int treverse(tree* node,l,r,cnt){
    if(node==NULL) return;
if(node->val>=l && node->val<=r) cnt++;
traverse(node->left,l,r,cnt);
traverse(node->right,l,r,cnt);
return cnt;
}
using namespace std;
int solve(tree* root1,int u,int l,int r,int cnt){
if(u==1) tree* node=root1;
if(u==2) tree* node=root2;
if(u==3) tree* node=root3;
if(u==4) tree* node=root4;
if(u==5) tree* node=root5;
if(u==6) tree* node=root6;
if(node->val>=l && node->val<=r) cnt++;
traverse(node->left,l,r,cnt);
traverse(node->right,l,r,cnt);
return cnt;

}
struct tree{
    int val;
    tree* left;
    tree* right;
}
int main(){
    int n,q;
    cin>>n>>q;
tree* root1 = new tree;
tree* root2 = new tree;
tree* root3 = new tree;
tree* root4 = new tree;
tree* root5 = new tree;
tree* root6 = new tree;
root1->val=root3->val=root6->val=2;

root2->val=root5->val=root4->val=1;


root1->left=root2;
root->right=root3;
root->left->left= root4;
root->left->right= root5;
root->left->right->left=root6;


    while(q--){
int u,l,r;
cin>>u>>l>>r;
cout<<solve(root1,u,l,r,0)<<endl;

    }
}