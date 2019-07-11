/*输入某二叉树的前序遍历和中序遍历结果，请重建出该二叉树。*/

#include <stdexcept>
#include <stdio.h>

struct TreeNode{
	TreeNode *left;
	TreeNode *right;
	int val;

	TreeNode():left(NULL),right(NULL),val(0){};
};

/* preorder_start: pointer to start of preorder array
 * preorder_end:
 * inorder_start:
 * inorder_end:
 * */

TreeNode *doConstruct(int *preorder_start,int *preorder_end,int *inorder_start,int *inorder_end){
	TreeNode *root = new TreeNode;
	root->val = preorder_start[0];
	
	//find the single 
	if(preorder_start == preorder_end){
		if(inorder_start == inorder_end){
			return root;
		}else{
			throw std::logic_error("-Invalid Input!");
		}
	}

	//find the pos int inorder array
	int *inorder_pos = inorder_start;
	while(inorder_pos<=inorder_end){
		if(*inorder_pos == root->val){
			break;
		}
		++inorder_pos;
	}
	//no find
	if((inorder_pos == inorder_end) && (*inorder_pos!=root->val)){
		throw std::logic_error("Invalid Input!!");
	}

	int left_length = inorder_pos-inorder_start;
	int *left_preorder_end = preorder_start+left_length;
	
	//left length is 0		
	if(left_length >0){
		root->left = doConstruct(preorder_start+1,left_preorder_end,inorder_start,inorder_pos-1);
	}
	//right length is 0
	if(left_length <preorder_end-preorder_start)
	{
		root->right = doConstruct(left_preorder_end+1,preorder_end,inorder_pos+1,inorder_end);
	}
	return root;


}


TreeNode *construct(int *preorder,int size_pre,int *inorder,int size_in){
	if(preorder == NULL || inorder == NULL || size_pre <=0 ||size_in <= 0){
		return NULL;
	}
	return doConstruct(preorder,preorder+size_pre-1,inorder,inorder+size_in-1);
}

void printBinaryTreePreorder(TreeNode *root){
	if(root == NULL){
		return;
	}

	printf("%d\n",root->val);
	printBinaryTreePreorder(root->left);
	printBinaryTreePreorder(root->right);

}

int main(){
	int preorder[]={1,2,4,7,3,5,6,8};
	int inorder[] ={4,2,7,1,5,3,8,6};

	TreeNode *root = construct(preorder,sizeof(preorder)/sizeof(int),inorder,sizeof(inorder)/sizeof(int));
	
	printBinaryTreePreorder(root);
	return 0;

}
