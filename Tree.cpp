#include<iostream>
#include<queue>
using namespace std;
/*���Ľڵ㴴��*/
class Node{
    public:
    int val;
    Node *left,*right;
    Node(){
        right=NULL;
        left=NULL;
    } 
};
//���ĵݹ鴴��
Node* build(Node* root,int val){
    //��ʼ��һ���ڵ�
if(root==NULL){
    root=new Node();
    root->val=val;
    return root;
}
if(val<root->val) root->left=build(root->left,val);
else if(val>root->val) root->right=build(root->right,val);
return root;
}
//���Ĳ�α���
void levelOrder(Node* root){
 queue<Node*> q;
 //���ڵ������
 q.push(root);
 while(!q.empty()){
    Node *temp=q.front();
    //���ڵ�����в���ӡ���
    q.pop();
    cout<<temp->val<<" ";
    //����α��������������������
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
//�е���������ζ��
 }   
}
int main(){
    Node *root=NULL;
    int t[]={5,4,6,3,7};
    //�������Ĵ���
    for(int i=0;i<5;i++){
        root=build(root,t[i]);
    }
//pro1
int t1[]={2,3,4,1,5,6,7,8,9};
//���ֶ���������α���
Node *root1=NULL;
for(int i=0;i<9;i++){
        root1=build(root1,t1[i]);
    }

levelOrder(root1);
    levelOrder(root);
    cout<<"���Ĵ���"<<endl;
    return 0;
}