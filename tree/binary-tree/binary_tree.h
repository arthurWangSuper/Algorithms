#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <deque>

template <typename T>
class BinaryTree {

public:
    typedef typename std::vector<T>::iterator T_it;  //加一个typename关键字，告诉编译器其为类型，因为模板类中不确定std::vector<T>::iterator的具体的类型

    struct TreeNode{
        TreeNode *left;
        TreeNode *right;
        T val;
        TreeNode(T val):left(nullptr),right(nullptr),val(val){}
    };

    typedef TreeNode* pTreeNode;
    BinaryTree(){ };
    BinaryTree(const std::vector<T>& vec);
    BinaryTree(std::istream& os);
    ~BinaryTree(){/*do something delete */};
    void SymmetricTree();
    void PreOrderTravase() const;

private:
    TreeNode* Vec2BinaryTree(T_it it_s,T_it it_e);

    TreeNode *root;
};

template <typename T>
BinaryTree<T>::BinaryTree(const std::vector<T>& vec){

    std::vector<T> Valvec(vec.begin(),vec.end());
    std::sort(Valvec.begin(),Valvec.end());

    T_it mid = Valvec.begin()+Valvec.size()/2;

    root = new TreeNode(*mid);
    root->left = Vec2BinaryTree(Valvec.begin(),mid-1);
    root->right = Vec2BinaryTree(mid+1,Valvec.end());
}

template <typename T>
BinaryTree<T>::BinaryTree(std::istream &os) {
    T val;
    TreeNode *cur = root;
    while(os>>val){
    }
}

template <typename T>
typename BinaryTree<T>::TreeNode*                   //这里需要注意一下，加一个typename 关键字，告诉编译器这是一个类型
BinaryTree<T>::Vec2BinaryTree(T_it it_s,T_it it_e){
    if(it_s == it_e)
        return nullptr;

    T_it mid = it_s+(it_e-it_s)/2;

    TreeNode* Node = new TreeNode(*mid);
    Node->left = Vec2BinaryTree(it_s,mid);
    Node->right = Vec2BinaryTree(mid+1,it_e);
    return  Node;
}
template <typename T>
void BinaryTree<T>::SymmetricTree(){

    std::function<void(TreeNode*)> Symmetric_Recursive = [&](TreeNode* root){
        if(root == nullptr)
            return;

        // 高德面试的时候 这么写，问题在于 第一条执行完毕之后，左子节点已经改变了
        // root->left = symmetric(root->right);
        // root->right = symmetric(root->left);

        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        Symmetric_Recursive(root->left);
        Symmetric_Recursive(root->right);

    };

    std::function<void(TreeNode*)> Symmetric_NonRecursive = [&](TreeNode* root){
        std::deque<TreeNode*> buf;
        buf.push_back(root);
        while(!buf.empty()){
            auto TNode = buf.front();
            buf.pop_front();

            TreeNode *tmp = TNode->left;
            TNode->left = TNode->right;
            TNode->right = tmp;

            if(TNode->left != nullptr)
                buf.push_back(TNode->left);

            if(TNode->right != nullptr)
                buf.push_back(TNode->right);
        }
    };
    Symmetric_NonRecursive(root);
}
