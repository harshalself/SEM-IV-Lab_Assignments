/*
Tree using traversal sequence: Write a C++ program to construct the
binary tree with a given preorder and inorder sequence and Test your tree
with all traversals
*/

#include <iostream>
using namespace std;

class Node{

   public:
       int data;
       Node *left;
       Node *right;
       
       Node(int value){ 
        data = value; 
        left = nullptr;
        right = nullptr;
       }

};


class BST{

   public:
    int findIndex(int inorder[], int val, int size){
        int index = -1;
        for(int i =0; i<size; ++i){
            if(inorder[i]==val){
                return index = i;
            }
        }
        
            return index;
    }
    
    
    Node *buildTree(int inorder[], int preorder[], int startIndex, int endIndex, int *preIndex, int size){
    
    if(startIndex>endIndex || (*preIndex) >=size){
        return nullptr;
    }
    
    int rootIndex = findIndex(inorder, preorder[*preIndex],size);
    Node *root = new Node(inorder[rootIndex]);
    
    *preIndex = *preIndex + 1;
    
    root->left = buildTree(inorder,preorder,startIndex,rootIndex-1,preIndex,size);
    root->right = buildTree(inorder,preorder,rootIndex+1,endIndex,preIndex,size);
    
    return root;
    
    }
    
    void inorderTraversal(Node *root){
        if(root == nullptr){
           return;
           }
        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);
    
    }
    
    void preorderTraversal(Node *root){
        if(root == nullptr){
           return;
           }
        cout<<root->data<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    
    }
    
    void postorderTraversal(Node *root){
        if(root == nullptr){
           return;
           }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root->data<<" ";
    
    }
    
    

};

int main(){

  BST b1;
  int size = 6;
  int inorder[] = {4, 2, 5, 1, 6, 3};
  int preorder[] = {1, 2, 4, 5, 3, 6};
  int preindex = 0;
  int ch;
  Node *root = b1.buildTree(inorder,preorder,0, size-1,&preindex,size);
  
  do{
  cout<<endl<<endl<<"Menu..."<<endl;
  cout<<"1. Inorder Traversal"<<endl;
  cout<<"2. Preorder Traversal"<<endl;
  cout<<"3. Postorder Traversal"<<endl<<endl;
  cout<<"Enter Your Choice:"<<endl;
  cin>>ch;
      switch(ch){
        case 1:
            cout<<"Inorder Traversal: "<<endl;
            b1.inorderTraversal(root);
            break;
        
        case 2:
            cout<<"Preorder Traversal: "<<endl;
            b1.preorderTraversal(root);
            break;
        
        case 3:
            cout<<"Postorder Traversal: "<<endl;
            b1.postorderTraversal(root);
            break;
        
        default: 
            cout<<"Invalid Choice!"<<endl;
      }
  }while(ch<=3);

}
