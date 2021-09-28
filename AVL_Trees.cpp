#include <iostream>

using namespace std;


struct AVLnode
{
    AVLnode *L_child;
    int data;
    int height;
    AVLnode *R_child;
};

int NodeHeight(AVLnode *p)
{
    int hl,hr;
    hl  = p && p->L_child? p->L_child->height:0;
    hr = p && p->R_child? p->R_child->height:0;
    return hl>hr?hl+1:hr+1;
}
int BalanceFactor(struct AVLnode *p)
{

     int hl  = p && p->L_child? p->L_child->height:0;
    int hr = p && p->R_child? p->R_child->height:0;
    return hl-hr;

}
AVLnode* LLRotations(AVLnode *root)
{
    AVLnode *PL = root->L_child, *PR = root->L_child->R_child;
    PL->R_child = root;root->L_child = PR;
    root->height = NodeHeight(root);
    PL->height = NodeHeight(PL);
    return PL;
}
AVLnode* LRRotations(AVLnode* root)
{
     AVLnode *PL = root->L_child, *PR = root->L_child->R_child;
     PL->R_child = PR->L_child; root->L_child = PR->R_child;
     PR->L_child = PL; PR->R_child = root;
     PL->height = NodeHeight(PL);
     PR->height = NodeHeight(PR);
     root->height = NodeHeight(root);
     return PR;

}
AVLnode* Insert(AVLnode *root,int key){

    AVLnode *r = nullptr;
    if(root == nullptr){
        r = new AVLnode; r->data = key; r->L_child = nullptr;r->R_child = nullptr;
        r->height = 1;
        return r;
    }
    if(key<root->data) root->L_child = Insert(root->L_child,key);
    else if(key>root->data) root->R_child = Insert(root->R_child,key);
    root->height = NodeHeight(root);

    if(BalanceFactor(root) == 2 && BalanceFactor(root->L_child) == 1)
        return LLRotations(root);
    else if(BalanceFactor(root) == 2 && BalanceFactor(root->L_child) == -1)
        return LRRotations(root);
//    else if(BalanceFactor(root) == -2 && BalanceFactor(root->R_child) == -1)
//        return RRRotations(root);
//    else if(BalanceFactor(root) == -2 && BalanceFactor(root->R_child) == 1)
//        return RLRotations(root);


    return root;
}

int main()
{
    AVLnode *root = nullptr;
    root = Insert(root,10);
    root = Insert(root,2);
    root = Insert(root,5);
    cout<<root->data<<endl;
}
