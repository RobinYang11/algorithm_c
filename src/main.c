#include <stdio.h>
#include "tree.c"

int main(int argc, char const *argv[])
{

	Tree tree;
	initTree(&tree);
	char letters[] = {'Z', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
	insertTreeNode(-1, letters[0], &tree);
	insertTreeNode(0, letters[1], &tree);
	insertTreeNode(0, letters[2], &tree);
	insertTreeNode(0, letters[3], &tree);
	insertTreeNode(1, letters[4], &tree);
	insertTreeNode(1, letters[5], &tree);
	insertTreeNode(1, letters[6], &tree);
	insertTreeNode(2, letters[7], &tree);
	insertTreeNode(2, letters[8], &tree);
	insertTreeNode(2, letters[9], &tree);

	getTreeRoot(&tree);
	printf("%c \r\n",getTreeRoot(&tree).value);

	// for (int i = 0; i < MAX; i++)
	// {
	// 	printf("%c", tree.nodes[i].value);
	// 	printf("\r\n");
	// }
	return 0;
}