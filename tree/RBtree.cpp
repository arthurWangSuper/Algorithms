/*R-B Tree*/

#include<iostream>

using namespace std;



class RBtree{

	private:

		struct rbtree{

			int key;

			rbtree *leftchild;

			rbtree *rightchild；

			rbtree *parent;

			int color;

		};

	public:

		enum COLOR{

			BLACK;

			RED;

		}

	public:

		RBtree():root(NULL){};

		~RBtree(){};

		

		int insert_node(rbtree *node);

		int insert_fixup(rbtree *node);

		int delet_node(rbtree *node);

		int delete_fixup(rbtree *node);

		int transplant(rbtree *snode,rbtree *dnode);

		int rotate_left(rbtree *node);

		int rotate_right(rbtree *node);

		int printtree(rbtree *node);

		rbtree *getminnode();

	public:

		rbtree *root;

};

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

			node->leftchild = NULL;

			node->rightchild = NULL;

			pos_node->leftchild = node;

			

		}

		/*fixup*/

		

}
