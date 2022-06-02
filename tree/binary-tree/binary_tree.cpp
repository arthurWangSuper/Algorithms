#include "binary_tree.h"
// 先序遍历
template <typename T>
void BinaryTree<T>::PreOrderTravase() const
{
    std::function<void(TreeNode*)> PreOrder = [&](TreeNode* root){
        if(!root) return ;
        std::cout<<root->val<<" ";
        PreOrder(root->left);
        PreOrder(root->right);
    };
    PreOrder(root);
}

int main(){
    std::vector<int> ivec{1,2,3,4,5,6,7,8,9};

    BinaryTree<int> *pB =new BinaryTree<int>(ivec);

    pB->PreOrderTravase();
    std::cout<<std::endl;

    pB->SymmetricTree();
    pB->PreOrderTravase();
    std::cout<<std::endl;

    return 0;

}
