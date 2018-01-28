/*R-B Tree*/

#include<iostream>

using namespace std;


template<typename T>
class RBtree{
	private:
		struct rbtree{
			T key;
			rbtree *leftchild;
			rbtree *rightchild；
			rbtree *parent;
			int color;
		};

	public:
		enum COLOR{
			BLACK;
			RED;
		};
	public:
		RBtree():root(NULL){};
		~RBtree(){};
		int insert_node(rbtree *node);
		int insert_fixup(rbtree *node);
		int delet_node(rbtree *node);
		int delete_fixup(rbtree *node);
		int RB_ transplant(rbtree *snode,rbtree *dnode);
		int left_rotate(rbtree *node);
		int right_rotate(rbtree *node);
		int printtree(rbtree *node);
		rbtree *getminnode();
	public:
		rbtree *root;
};
/*left rotate*/
int RBtree::left_rotate(rbtree *node)
{
/*R->P*/
/*R.l->P.r*/
	node->rightchild->parent = node->parent;
	node->parent = node->rightchild;
	node->rightchild = node->rightchild->leftchild;
	node->rightchild->parent = node;
	
	return 0;
}
/*right rotate*/
int RBtree::right_rotate(rbtree *node)
{
	node->leftchild->parent = node->parent;
	node->parent = node->leftchild;
	node->leftchild = node->leftchild->rightchild;
	node->leftchild->parent = node;
	
	return 0;
}
int RB_transplant(rbtree *snode,rbtree *dnode)
{
	/*modify to T.nil later*/
	if(snode->parent == NULL)
	{
		dnode = root;
	}	
	if(snode == snode->parent->leftchild)
	{
		snode->parent->leftchild = dnode;
	}
	if(snode == snode->parent->rightchild)
	{
		snode->parent->rightchild = dnode;
	}
	dnode->parent = snode->parent;
	return 0;
}
/*insert new node*/
int RBtree::insert_node(rbtree *node)

{
		if(root == NULL)
		{
			node->color = BLACK;
			node->leftchild = NULL;
			node->rightchild = NULL;
			node->parent = NULL;
			root = node;

		}
		rbtree *cur_node = root;
		rbtree *pos_node = NULL;
		/*find pos to insert*/
		while(cur_node != NULL)
		{
			pos_node = cur_node;
			if(node->key >= cur_node->key)
			{
				cur_node = cur_node->rightchild;
			}
			else
			{
				cur_node = cur_node->leftchild;
			}
		}
		if(node->key >= pos_node->key)
		{
			/*rihgtchild*/
			node->color = RED;
			node->parent = pos_node;
			node->leftchild = NULL;
			node->rightchild = NULL;
			pos_node->rightchild = node;

		}
		else
		{
			/*leftchild*/
			node->color = RED;
			node->parent = pos_node;
			node->rightchild = NULL;
			node->leftchild = NULL;
			pos_node->leftchild = node;

		}
		/*fixup*/
		insert_fixup(node);
				
	return 0;
}

