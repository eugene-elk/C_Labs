#include"tree.h"

int max2(int a, int b)
{
	if (a > b) return a;
	else return b;
}

struct avltree *balance(struct avltree *tree)
{
	tree->height = max2(avltree_height(tree->left), avltree_height(tree->right)) + 1;
	if (avltree_height(tree->left) - avltree_height(tree->right) == 2)
	{
		if (avltree_height(tree->left->right) - avltree_height(tree->left->left) <= 0) 
			{
				tree = avltree_right_rotate(tree);
			} 
			else 
			{
				tree = avltree_leftright_rotate(tree);
			}
	}
	if (avltree_height(tree->left) - avltree_height(tree->right) == -2)
	{
		if (avltree_height(tree->right->right) - avltree_height(tree->right->left) >= 0) 
			{
				tree = avltree_right_rotate(tree);
			} 
			else 
			{
				tree = avltree_leftright_rotate(tree);
			}
	}
	return tree;
}

struct avltree* FindMin(struct avltree* rootnode)
{
	return (rootnode->left) ? FindMin(rootnode->left) : rootnode;
}

struct avltree* RemoveMin(struct avltree* minnode, struct avltree* rootnode)
{
	if (rootnode != minnode)
	{
		rootnode->left = RemoveMin(rootnode->left, minnode);
	}
	else
	{
		rootnode = rootnode->right;
	}
	return balance(rootnode);
}

struct avltree *avltree_del(struct avltree *tree, int key)
{
	if (tree)
	{
		if (key < tree->key)		//левое поддерево
		{
			tree->left = avltree_del(tree->left, key);
		}
		else if (key > tree->key)	//правое поддерево
		{
			tree->right = avltree_del(tree->right, key);
		}
		else
		{
			if (tree->left != NULL && tree->right != NULL)	//если искомое и имеет обоих потомков
			{
				struct avltree* tmpnode = FindMin(tree->right);
				tree->right = RemoveMin(tmpnode, tree->right);
				tree->key = tmpnode->key;					//вставка min на место...
			}
			else
			{
				tree = (!tree->right) ?  tree->left :  tree->right;
			}
		}
	}
	else
	{
		printf("Can't delete");
	}
	return balance(tree);
}

struct avltree *avltree_add(struct avltree *tree, int key)
{
	if (tree == NULL) {
		return avltree_create(key);
	}
	if (key < tree->key) 
	{
		tree->left = avltree_add(tree->left, key);
	}
	else if (key > tree->key) 
	{
		tree->right = avltree_add(tree->right, key);
	}
	
	return balance(tree);
}

/*
struct avltree *avltree_add2(struct avltree *tree, int key)
{
	if (tree == NULL) {
		return avltree_create(key);
	}
	if (key < tree->key) 
	{
		tree->left = avltree_add(tree->left, key);
		if (avltree_height(tree->left) - avltree_height(tree->right) == 2)
		{
			if (key < tree->left->key) 
			{
				tree = avltree_right_rotate(tree);
			} 
			else 
			{
				tree = avltree_leftright_rotate(tree);
			}
		}
	}
	else if (key > tree->key) 
	{
		tree->right = avltree_add(tree->right, key);
		if (avltree_height(tree->left) - avltree_height(tree->right) == (-2))
		{
			if (key > tree->right->key) 
			{
				tree = avltree_left_rotate(tree);
			} 
			else 
			{
				tree = avltree_rightleft_rotate(tree);
			}
		}
	}
	tree->height = max2(avltree_height(tree->left), avltree_height(tree->right)) + 1;
	return tree;
}
*/

int avltree_height(struct avltree *tree)
{
	return (tree != NULL) ? tree->height : -1;
}

struct avltree *avltree_create(int key)
{
	struct avltree* node = (struct avltree*)malloc(sizeof(struct avltree));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 0;
	return node;
}

void avltree_free(struct avltree *tree)
{
	if (tree == NULL)
		return;
	avltree_free(tree->left);
	avltree_free(tree->right);
	free(tree);
}

struct avltree *avltree_search(struct avltree *tree, int key)
{
	while (tree != NULL)
	{
		if (key == tree->key) 
		{
			return tree;
		} 
		else if (key < tree->key) 
		{
			tree = tree->left;
		} 
		else {
			tree = tree->right;
		}
	}
	return tree;
}

struct avltree *avltree_left_rotate(struct avltree *tree)
{
	struct avltree *right;
	right = tree->right;
	tree->right = right->left;
	right->left = tree;
	tree->height = max2(avltree_height(tree->left), avltree_height(tree->right)) + 1;
	right->height = max2(avltree_height(right->right), tree->height) + 1;
	return right;
}

struct avltree *avltree_right_rotate(struct avltree *tree)
{
	struct avltree *left;
	left = tree->left;
	tree->left = left->right;
	left->right = tree;
	tree->height = max2(avltree_height(tree->left), avltree_height(tree->right)) + 1;
	left->height = max2(avltree_height(left->left), tree->height) + 1;
	return left;
}

struct avltree *avltree_leftright_rotate(struct avltree *tree)
{
	tree->left = avltree_left_rotate(tree->left);
	return avltree_right_rotate(tree);
}

struct avltree *avltree_rightleft_rotate(struct avltree *tree)
{
	tree->right = avltree_right_rotate(tree->right);
	return avltree_left_rotate(tree);
}

void avltree_print(struct avltree *tree, int level)
{
	int i;
	if (tree == NULL)
		return;
	for (i = 0; i < level; i++)
		printf("  ");
	printf("%d\n", tree->key);
	avltree_print(tree->left, level + 1);
	avltree_print(tree->right, level + 1);
}