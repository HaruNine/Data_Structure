//binary_tree_array
#include <stdio.h>

#define MAX_SIZE 1000
char tree_array[MAX_SIZE];

void make_tree()
{
	tree_array[1] = 'A';
	tree_array[2] = 'B';
	tree_array[3] = 'C';
	tree_array[4] = 'D';
	tree_array[5] = 'E';
	tree_array[6] = 'F';
}

void inorder(int index)
{
	printf("inorder(%d)\n", index);
	if (tree_array[index] == 0) {
		return;
	}
	inorder(2 * index);
	printf("<%c>", tree_array[index]);
	inorder(2 * index + 1);
}

void main()
{
	make_tree();
	inorder(1);
}