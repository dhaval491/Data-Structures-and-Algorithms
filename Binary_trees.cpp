#include <iostream>
#include<queue>
#include<stack>
#include<vector>
#include<numeric>
using namespace std;
struct Tree_node
{
    int data;
    Tree_node *L_child;
    Tree_node *R_child;
};

class Tree
{
private:
    int Tree_size;
public:
    Tree_node *root;
    Tree(){root = new Tree_node;Tree_size = 0;root->L_child = nullptr;root->R_child = nullptr;}
    Tree(int x){root = new Tree_node;Tree_size = x;root->L_child = nullptr;root->R_child = nullptr;}
    Tree_node* Create_Tree();
    void Preorder(Tree_node *p);
    void Inorder(Tree_node *p);
    void Postorder(Tree_node *p);
    void Levelorder(Tree_node *p);
    int Height(Tree_node *root);
    int Degree_nodes(Tree_node *root);
    int Total_nodes(Tree_node *root);
    int Leaf_nodes(Tree_node *root);
    int Sum_of_elements(Tree_node *root);
    Tree_node* Insert_BST(Tree_node *root, int key);
    Tree_node* Create_BST(int A[]);
    Tree_node* Delete_BST(Tree_node *root,int key);
    Tree_node* InPre(Tree_node *p);
    Tree_node* InSuc(Tree_node *p);
    void Create_BST_Pre(int A[]);
    void Create_BST_Post(int A[]);

};



Tree_node* Tree::Create_Tree()
{
    Tree_node *p,*t;
    int x,node_counter;
    node_counter = this->Tree_size;
    std::queue<Tree_node*> Q;
    cout<<"Enter The root value "<<endl;
    cin>>x;
    this->root  = new Tree_node; node_counter--; // whenever you make a node in heap you decrease the node counter
    root->L_child = nullptr;
    root->R_child =  nullptr;
    root->data = x;
    p = root;
    Q.push(root);

    while(node_counter)
    {
     p = Q.front();
     Q.pop();
     // Left Child
     cout<<"Enter the Left child: "<<endl;
     cin>>x;
     if(x != -1)
     {
         t = new Tree_node;node_counter--;
         t->data = x; t->L_child = t->R_child = nullptr;
         p->L_child = t;
         Q.push(p->L_child);

     }
     // Right child
     cout<<"Enter the Right child: "<<endl;
     cin>>x;
     if(x != -1)
     {
         t = new Tree_node;node_counter--;
         t->data = x; t->L_child = t->R_child = nullptr;
         p->R_child = t;
         Q.push(p->R_child);

     }

    }
    return root;
}
void Tree::Preorder(Tree_node *p){
//    if(p != nullptr)  // Recursive
//    {
//        cout<<p->data<<endl;
//        Preorder(p->L_child);
//        Preorder(p->R_child);
//    }
 // Iterative
 Tree_node *t = p; // Initial step for root node and make stack non-empty
 stack <Tree_node*> Stk;
 cout<<t->data<<endl;
 Stk.push(t);
 t = t->L_child;
 while (!Stk.empty() || t!= nullptr)
 {
     if(t != nullptr)
     {
         cout<<t->data<<endl;
         Stk.push(t);
         t = t->L_child;
     }
     else
     {
         t = Stk.top();
         Stk.pop();
         t=  t->R_child;
     }
 }
}
void Tree::Postorder(Tree_node *p){
    if(p != nullptr)
    {
        Postorder(p->L_child);
        Postorder(p->R_child);
        cout<<p->data<<endl;
    }
}
void Tree::Inorder(Tree_node *p){
    if(p != nullptr)
    {
        Inorder(p->L_child);
        cout<<p->data<<endl;
        Inorder(p->R_child);
    }
//    cout<<"Iterative inorder"<<endl;
//Tree_node *t = p; // Initial step for root node and make stack non-empty
// stack <Tree_node*,std::vector<Tree_node*>> Stk;
// Stk.push(t);
// t = t->L_child;
// while (!Stk.empty() || t!= nullptr)
// {
//     if(t != nullptr)
//     {
//         Stk.push(t);
//         t = t->L_child;
//     }
//     else
//     {
//         t = Stk.top();
//         Stk.pop();
//         cout<<t->data<<endl;
//         t=  t->R_child;
//     }
// }
}
void Tree::Levelorder(Tree_node *p)
{
    cout<<"Level Order"<<endl;
    queue<Tree_node*> Q;
    cout<<p->data<<endl;
    Q.push(p);
    while(!Q.empty())
    {
        p = Q.front();
        Q.pop();
        if(p->L_child != nullptr)
        {
            cout<<p->L_child->data<<endl;
            Q.push(p->L_child);
        }
        if(p->R_child != nullptr)
        {
            cout<<p->R_child->data<<endl;
            Q.push(p->R_child);
        }
    }
}
int Tree::Degree_nodes(Tree_node *root)
{
    int x,y;
    if(root != nullptr)
    {
        x = Degree_nodes(root->L_child);
        y = Degree_nodes(root->R_child);
        if(root->L_child && root->R_child) return x+y+1;
        else return x+y;

    }
    return 0;
}
int Tree::Total_nodes(Tree_node *root)
{
    int x,y;
    if(root != nullptr)
    {

        x = Total_nodes(root->L_child);
        y = Total_nodes(root->R_child);
        return x+y+1;
    }
    else{
            return 0;
        }

}
int Tree::Leaf_nodes(Tree_node *root)
{
    int x,y;
    if(root != nullptr)
    {
        if(root->L_child == nullptr && root->R_child ==nullptr)
        {
            return 1;
        }
        else{
        x = Leaf_nodes(root->L_child);
        y = Leaf_nodes(root->R_child);
        return x+y;
        }

    }
        return 0;
}
int Tree::Sum_of_elements(Tree_node *root)
{
    int x,y;
    if(root != nullptr)
    {

        x = Sum_of_elements(root->L_child);
        y = Sum_of_elements(root->R_child);
        return x+y+root->data;
    }
        return 0;
}
Tree_node* Tree::Insert_BST(Tree_node *root, int key)
{
    Tree_node *r, *p = root, *q; r = p;
    while(p!=nullptr)
    {
        r = p;
        if(key  == p->data) return root;
        else if(key < p->data) p = p->L_child;
        else p = p->R_child;
    }
    q = new Tree_node; q->data = key; q->L_child = q->R_child = nullptr;
    if(key<r->data) r->L_child = q; else r->R_child = q;
    return root;

}
Tree_node* Tree::Create_BST(int A[])
{
    Tree_node* root; root  = new Tree_node;
    root->data = A[0];root->L_child = root->R_child = nullptr;
    for(int i = 1;i<this->Tree_size;i++)
    {
        this->Insert_BST(root,A[i]);
    }
    return root;
}

Tree_node* Tree::InPre(Tree_node *p)
{
    while(p != nullptr && p->R_child) p = p->R_child;
    if(p) cout<< "Inorder Predecessor = "<<p->data<<endl;
    return p;
}
Tree_node* Tree::InSuc(Tree_node *p)
{
    while(p != nullptr && p->L_child) p = p->L_child;
    if(p) cout<< "Inorder Predecessor = "<<p->data<<endl;
    return p;

}

Tree_node* Tree::Delete_BST(Tree_node* root,int key)
{
    Tree_node* q;
    if(root == nullptr) return nullptr;
    if(root->L_child == nullptr && root->R_child == nullptr)
    {
        delete root;
        return nullptr;
    }
    if(key < root->data) root->L_child = Delete_BST(root->L_child,key);
    else if(key > root->data) root->R_child = Delete_BST(root->R_child,key);
    else{
            if(this->Height(root->L_child)>this->Height(root->R_child))
            {
            q = this->InPre(root->L_child);
            root->data = q->data;
            root->L_child = Delete_BST(root->L_child,q->data);
            }
            else{
            q = this->InSuc(root->R_child);
            root->data = q->data;
            root->R_child = Delete_BST(root->R_child,q->data);
            }
    }
    return root ;
}

int Tree::Height(Tree_node* root)
{
    int x,y;
    if(root == nullptr) return 0;
    x = Height(root->L_child);
    y = Height(root->R_child);
    return x>y? x+1:y+1;
}
void Tree::Create_BST_Pre(int A[])
{
    int i = 0;
    this->root->data = A[i++]; int x;
    Tree_node* p = this->root;
    Tree_node*t;
    stack<Tree_node*> Stk;

    while(i<Tree_size)
    {
        if(A[i]<p->data)
        {
            cout<<"1st"<<endl;
            t = new Tree_node; t->data = A[i++];t->L_child = nullptr;t->R_child = nullptr;
            p->L_child =t;
            Stk.push(p);
            p = t;
        }
        else{
        if(Stk.empty())x = 0x7f800000;
        else x = Stk.top()->data;
        if((A[i]>p->data && A[i]<x))
        {
            cout<<"2st"<<endl;
            t = new Tree_node; t->data = A[i++];t->L_child = nullptr;t->R_child = nullptr;
            p->R_child = t;
            p = t;
        }
        else
        {
            cout<<"3st"<<endl;
            p = Stk.top();Stk.pop();
        }
        }
    }
}


void Tree::Create_BST_Post(int A[])
{
    int i = Tree_size-1;
    this->root->data = A[i--]; int x;
    Tree_node* p = this->root;
    Tree_node*t;
    stack<Tree_node*> Stk;

    while(i>=0)
    {
        if(A[i]>p->data)
        {
            cout<<"1st"<<endl;
            t = new Tree_node; t->data = A[i--];t->L_child = nullptr;t->R_child = nullptr;
            p->R_child =t;Stk.push(p);
            p = t;
        }
        else{
        if(Stk.empty())x = -1000;
        else x = Stk.top()->data;
        if((A[i]<p->data && A[i]>x))
        {
            cout<<"2st"<<endl;
            t = new Tree_node; t->data = A[i--];t->R_child = nullptr;t->L_child = nullptr;
            p->L_child = t;
            //Stk.push(p);
            p = t;
        }
        else
        {
            cout<<"3st"<<endl;
            p = Stk.top();Stk.pop();
        }
        }
    }
}


int main()
{
    int Tree_size;
    cout<<"Enter the value of Tree Size: ";
    cin>>Tree_size;
 Tree MyTree(Tree_size);
 Tree_node *B_tree, *InPre;
 int A[] = {15,10,25,20,45,50,40,30};
 MyTree.Create_BST_Post(A);
//B_tree = MyTree.Create_Tree();
// cout<<"Value of B tree  = "<<B_tree<<endl;
 cout<<"Preorder Traversal: "<<endl;
 MyTree.Preorder(MyTree.root);
 cout<<"Inorder Traversal: "<<endl;
 MyTree.Inorder(MyTree.root);
 cout<<"Postorder Traversal: "<<endl;
 MyTree.Levelorder(MyTree.root);


// cout<<"Preorder Traversal: "<<endl;
// MyTree.Preorder(B_tree);
// cout<<"Inorder Traversal: "<<endl;
// MyTree.Inorder(B_tree);
// cout<<"Postorder Traversal: "<<endl;
// MyTree.Postorder(B_tree);
//B_tree = MyTree.Insert_BST(B_tree,)
// MyTree.Levelorder(B_tree);
// B_tree = MyTree.Delete_BST(B_tree, 5);
//  cout<< "After Deleting"<<endl;
//  MyTree.Levelorder(B_tree);
//  cout<<"Postorder Traversal: "<<endl;
//  MyTree.Postorder(B_tree);


//
// cout<<"No of 2 degree nodes  "<<MyTree.Degree_nodes(B_tree)<<endl;
//cout<<"No of  nodes  "<<MyTree.Total_nodes(B_tree)<<endl;
//cout<<"No of  Leaf nodes  "<<MyTree.Leaf_nodes(B_tree)<<endl;
//cout<<"Sum of All elements  "<<MyTree.Sum_of_elements(B_tree)<<endl;

}
