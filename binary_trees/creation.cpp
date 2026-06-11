#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root){

    cout << "Enter the data : " << endl;

    int data;
    cin>> data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data inserting in left of " << data << endl;

    root -> left = buildTree(root -> left);

    cout << "Enter data inserting in right of " << data <<endl;

    root -> right = buildTree(root -> right);

    return root;


}

void inorder(node* root){

    if(root == NULL){
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";

    inorder(root -> right);

}

void preorder(node* root){
    if(root == NULL){
        return;
    }

    cout<< root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(node* root){
    if(root == NULL){
        return;
    }

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}


void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else {
            cout << temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }

        }

    }
}

int main(){
    node* root = NULL;

    //creating a tree
    root = buildTree(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // level order traversal
    cout << "Printing level order traversal " << endl;
    levelOrderTraversal(root);

    cout<< "Printing Inorder traversal " << endl;
    inorder(root) ;
    cout << endl;

    cout << "Printing Preorder Traversal: " << endl;
    preorder(root);
    cout << endl;

    cout << "Printing Postorder Traversal: " << endl; 
    postorder(root);
    cout << endl;

    return 0;
}
