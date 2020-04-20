#pragma once

#include <iostream>
// 标志是否需要调整，若底层进行了调整，则上层不用进行调整
// LL-LR-RL-RR

template<typename T>
class AVLTree{
private:
    struct Base_Node
    {
        Base_Node *left;
        Base_Node *right;
        T val;
        int bf; //标示上一次插入是左右节点 若为 左 则为-1 右为 1 处于平衡状态则为 0（如左右都插入了）
    };
public: 
    AVLTree(){};

private:
    // root:
    // dest:找到插入点，若没找到对应点则为nullptr
    // taller: 标志是否需要调整，每次进行插入前都是不需要调整的
    void search_to_insert(Base_Node* &root,Base_Node* &dest,T& key,bool taller);
    void left_balance(Base_Node* &p);
    void right_balance(Base_Node* &p);
    void left_rotate(Base_Node* &p);
    void right_rotate(Base_Node* &p);
private:
    Base_Node *root;
};

template<typename T>
void AVLTree<T>::search_to_insert(Base_Node* &root,Base_Node* &dest,T& key,bool taller){
   if(root == std::nullptr){
       root = new Base_Node;
       root->left = std::nullptr;
       root->right = std::nullptr;
       root->val = key;
       root->bf = 0;
       taller = true;
       dest = root;
       return ;
   }
   if(root->val == key){
        return ;
   }
   else if(root->val > key){
       search_to_insert(root->left,dest,key,taller);
       if(taller){
           switch (root->bf)
           {
           case 1:
                  left_balance(root);
                  taller = false;
               break;
           case 0:
                root->bf = 1;
                taller =true;
           case -1:
                root->bf = 0;
                taller = false;
           default:
               break;
           }(root->bf)
       }
   }else if(root->val < key){
       search_to_insert(root->right,dest,key,taller);
       if(taller){
           switch (root->bf)
           {
           case 1:
                  root->bf =0;
                  taller = false;
               break;
           case 0:
                root->bf = -1;
                taller =true;
           case -1:
                right_balance(root);
                taller = false;
           default:
               break;
           }(root->bf)
       }
   }
}
template<typename T>
void AVLTree<T>::left_balance(Base_Node* &p){
    //两种情况，1 LL,2 LR
    Base_Node *tmp = p->left;
    if(p->left->bf == 1){
        //LL
         p->bf = 0;
        tmp->bf = 0;
        left_rotate(p);
    } else if(root->left->bf == -1){
        //LR 
        Base_Node * tmp_right = tmp->right;
        // 在之后进行的左旋中，
        switch (tmp_right->bf)
        {
        case 1:
            tmp->bf=0;
            p->bf = -1;
            break;
        case 0:
            tmp->bf = 0;
            p->bf = 0;
            break;
        case -1:
            tmp->bf =1;
            p->bf =0;
            break;
        default:
            break;
        }
        tmp_right->bf = 0;
        left_rotate(tmp);
        right_rotate(p);
    }
}
template<typename T>
void AVLTree<T>::right_balance(Base_Node* &p){

}
template<typename T>
void AVLTree<T>::left_rotate(Base_Node* &p){
     Base_Node *tmp = p->right;
    p->right = tmp->left;
    tmp->left = p;
    p = tmp;
}
template<typename T>
void AVLTree<T>::right_rotate(Base_Node* &p){
    Base_Node *tmp = p->left;
    p->left = tmp->right;
    tmp->right = p;
    p = tmp;
}