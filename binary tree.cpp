#include <iostream>
using namespace std;

class node{
public:
int data;
node *parent;
node *left;
node *right;
node(){
 data=-1;
 parent=NULL;
 left=NULL;
 right=NULL;
 }
};

class bTree{
public:
node *root;

public:
bTree(){
root=NULL;
}
/*
void insert(node *v,int x)
 {
  node *temp=new node;
  temp->data=x;
  if(root==NULL)
  {
   root=temp;
  }
  else
  {
   if(x < v->data)
   {
    if(v->left != NULL)
    {
     insert(v->left,x);
    }
    else
    {
     v->left=temp;
    }
   }
   else
   {
    if(v->right != NULL)
    {
     insert(v->right,x);
    }
    else
    {
     v->right=temp;
    }
   }
 }
}
void insertLeft(node *temp,int x){
 node *tmp=new node;
 tmp->data=x;
 temp->left=tmp;
 tmp->parent=temp;
}
void insertRight(node *temp,int x){
 node *tmp=new node;
 tmp->data=x;
 temp->right=tmp;
 tmp->parent=temp;
} */

void insert(node *t,int val){
node *temp=new node;
temp->data=val;


if(root==NULL){
 root=temp;
}                                  

else
{
  if(val < t->data){
    if(t->left==NULL){
      t->left=temp;
      temp->parent=t;      
     }
    else
    {
     insert(t->left,val);
     }
  }
  else{
    if(t->right==NULL){
      t->right=temp;
      temp->parent=t;
    }
  else{
    insert(t->right,val);
    }
  }
 }
}  



void display(node *temp){
  if(temp==NULL){
    return;
  }
  display(temp->left);
  cout<<temp->data<<" ";
  display(temp->right);
}

/*void search(int k){
node *temp=root;
if(k<temp->left){
if(temp->data==k){
cout<<"FOUND!";
break;
}
else
{
temp=temp->next;
*/


node *search(node *v,int data)
{
 node *temp=v,*p;
 if(v==NULL)
 {
  cout<<"Not Found\n";
  return NULL;
  }
  else
  {
   if(data < temp->data)
   p=search(temp->left,data);
   else if(data > temp->data)
   p=search(temp->right,data);
   else
   {
    cout<<"Found\n";
    return temp;
   }
   return p;
  }
 }

void deleteNode(int key)
 {
  node *p=search(root,key);
  if(p->left == NULL && p->right == NULL)
  {
   if(p->parent->left == p)
   p->parent->left=NULL;
   else
   p->parent->right=NULL;
  }
  else if(p->left==NULL)
  {
  if(p->parent->left==p)
   p->parent->left=p->right;
  else
   p->parent->right=p->right;
  }
  else if(p->right == NULL)
  {
   if(p->parent->left == p)
   p->parent->left=p->left;
   else
   p->parent->right=p->left;
  }
  else
  {
    node *temp=p->left;
   while(temp->right != NULL)
   {
    temp=temp->right;
   }
   if(temp->left != NULL)
   {
    temp->parent->right=temp->left;
    p->data=temp->data;
   }
   else
   {
    temp->parent->right=NULL;
    p->data=temp->data;
   }
  }
}

};

int main(){
bTree b;
b.insert(b.root,2);
b.insert(b.root,7);
b.insert(b.root,4);
b.insert(b.root,11);
b.insert(b.root,3);
b.display(b.root);
b.search(b.root,7);
b.deleteNode(4);
b.display(b.root);
return 0;

}
