#include "tree.h"

// Course: Programming (C)
// AVL tree
// Student: Lositsky E.I. Group: M3105
// Teacher: Povyshev V.V.
// Created 07.12.2016
// Description: AVL-tree with functions: add, delete, search

int main()
{
	struct avltree *tree = NULL; //корень
	char* command = (char*)calloc(10, sizeof(char));
	int scan;
	while(stricmp(command, "close"))
	{
		scanf("%s", command);
		if(!stricmp(command, "add"))
		{
			scanf("%d", &scan);
			tree = avltree_add(tree, scan);
		}	
		else if(!stricmp(command, "delete"))
		{
			scanf("%d", &scan);
			tree = avltree_del(tree, scan);
		}
		else if(!stricmp(command, "search"))
		{
			scanf("%d", &scan);
			avltree_print(avltree_search(tree, scan), 0);
		}
		else if(!stricmp(command, "print"))
		{
			avltree_print(tree, 0);
		}
	}
	return 0;
}