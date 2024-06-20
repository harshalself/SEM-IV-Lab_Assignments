/*Expression tree: Write a menu driven C++ program to construct an
expression tree from the given prefix expression eg. +--a*bc/def and
perform following operations:
1. Traverse it using post order traversal (non recursive)
2. Delete the entire tree
3. Change a tree so that the roles of the left and right pointers are
swapped at every node*/

#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

class Node{
    public:
        char data;
        Node* left;
        Node* right;

};

Node* create_node(char val){
        Node* new_node = new Node();
        new_node->data = val;
        new_node->left = nullptr;
        new_node->right = nullptr;
        return new_node;
    }
    
    Node* Expression_tree(char prefix[]){
        stack<Node*> s;
        int i = strlen(prefix)-1;
        while(i>=0){
            char ch = prefix[i];
            if(ch>='a' && ch<='z'){
            Node* new_node = create_node(ch);
            s.push(new_node);
            }
            else{
            Node* new_node = create_node(ch);
            new_node->left = s.top();
            s.pop();
            new_node->right = s.top();
            s.pop();
            s.push(new_node);
            }
            i--;
        }
        return s.top();
    }
    
    void postOrderTraversal(Node* root)
    {
	    if (root == NULL)
		    return;

	    // define two stacks - stack1 and stack2
	    stack<Node *> stack1, stack2;

	    // start from root node and push to first stack
	    stack1.push(root);
	    Node* node;

	    // Repeat untill first stack is not empty
	    while (!stack1.empty()) {
		    // pop node from stack1 and push to stack2
		    node = stack1.top();
		    stack1.pop();
		    stack2.push(node);

		    // push left and right node of popped stack
		    if (node->left)
			    stack1.push(node->left);
		    if (node->right)
			    stack1.push(node->right);
	    }

	    // if stack is empty print the nodes in stack2
	    while (!stack2.empty()) {
		    node = stack2.top();
		    stack2.pop();
		    cout << node->data << " ";
	    }
    }

int main(){

int ch;
char exp[] = "+--a*bc/def";
Node* root = Expression_tree(exp);

    do{
    cout<<"Enter Your Choice: "<<endl;
    cin>>ch;
        switch(ch){
            case 1:
            Expression_tree(exp);
            cout<<"Expression Tree created!"<<endl;
            break;
            
            case 2:
            cout<<"Post Order Traversal: "<<endl;
            postOrderTraversal(root);
            cout<<endl;
            break;
            
            default:
            cout<<"Invalid Choice"<<endl;
            break;
        }
    }while(true);

}
