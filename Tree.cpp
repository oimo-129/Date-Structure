#include<iostream>
#include<queue>
using namespace std;
/*树的节点创建*/
class Node{
    public:
    int val;
    Node *left,*right;
    Node(){
        right=NULL;
        left=NULL;
    } 
};
//树的递归创建
Node* build(Node* root,int val){
    //初始化一个节点
if(root==NULL){
    root=new Node();
    root->val=val;
    return root;
}
if(val<root->val) root->left=build(root->left,val);
else if(val>root->val) root->right=build(root->right,val);
return root;
}
//树的层次遍历
void levelOrder(Node* root){
 queue<Node*> q;
 //根节点入队列
 q.push(root);
 while(!q.empty()){
    Node *temp=q.front();
    //根节点出队列并打印输出
    q.pop();
    cout<<temp->val<<" ";
    //按层次遍历左子树与右子树入队
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
//有点广度搜索的味道
 }   
}
int main(){
    Node *root=NULL;
    int t[]={5,4,6,3,7};
    //二叉树的创建
    for(int i=0;i<5;i++){
        root=build(root,t[i]);
    }
//pro1
int t1[]={2,3,4,1,5,6,7,8,9};
//提现二叉树按层次遍历
Node *root1=NULL;
for(int i=0;i<9;i++){
        root1=build(root1,t1[i]);
    }

levelOrder(root1);
    levelOrder(root);
    cout<<"树的创建"<<endl;
    return 0;
}