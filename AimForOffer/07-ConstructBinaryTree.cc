#include <iostream>

struct BinaryTreeNode{
	BinaryTreeNode *m_left;
	BinaryTreeNode *m_right;
	int m_nval;
};

BinaryTreeNode* construct(int *preorder, int *inorder, int length){
	if(preorder == nullptr || inorder == nullptr || length < 0)
		return nullptr;
	return constructCore(preorder, preorder+length-1, inorder,inorder+length-1);
}

BinaryTreeNode* constructCore(int *startPreOrder, int *endPreOrder, int *startPreOrder, int *endPreOrder){
	
	int rootValue = *startPreOrder;
	BinaryTreeNode *root = new BinaryTreeNode();
	root->m_left = nullptr;
	root->m_right = nullptr;
	root->m_nval = *startPreOrder;
	
	if(startPreOrder == endPreOrder){
		if(startInOrder == endInOrder && *startInorder == *StartPreOrder)
			return root;
		else 
			throw std::exception("Invalid input");	
	}
	
	int *rootInorder = startInorder;
	// 在中序遍历中查找
	while(rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;
	if(rootInorder == endInorder && *rootInorder != rootValue)
		std::throw std::exception("Invalid Input");

	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if(leftLength > 0){
		root->m_pLeft = constructCore(startPreOrder+1, leftPreorderEnd, startInorder, rootInorder-1);
	}
	if(leftLength < endPreorder - startPreorder){
		root->m_pLeft = constructCore(leftPreorderEnd,endPreOrder, rootInorder+1, endInorder);
	}
	return root;
	
	


}
