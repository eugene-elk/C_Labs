#ifndef TREE
#define TREE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct avltree {
	int key;
	int height;
	struct avltree *left;
	struct avltree *right;
};

int avltree_height(struct avltree *tree);
struct avltree *avltree_create(int key);
void avltree_free(struct avltree *tree);
int max2(int a, int b);
struct avltree *avltree_add(struct avltree *tree, int key);
struct avltree *avltree_search(struct avltree *tree, int key);
struct avltree *avltree_left_rotate(struct avltree *tree);
struct avltree *avltree_right_rotate(struct avltree *tree);
struct avltree *avltree_leftright_rotate(struct avltree *tree);
struct avltree *avltree_rightleft_rotate(struct avltree *tree);
void avltree_print(struct avltree *tree, int level);
struct avltree *avltree_del(struct avltree *tree, int key);

#endif