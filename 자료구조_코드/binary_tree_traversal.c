// binary_tree_traversal
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct tree_node {
	int data;
	struct tree_node* left_child, * right_child;
} tnode_str;

tnode_str* root;

inorder(tnode_str* ptr) {
	if (ptr) {
		inorder(ptr->left_child);
		printf("%d ", ptr->data);
		inorder(ptr->right_child);
	}
}
preorder(tnode_str* ptr) {
	if (ptr) {
		printf("%d ", ptr->data);
		preorder(ptr->left_child);
		preorder(ptr->right_child);
	}
}
postorder(tnode_str* ptr) {
	if (ptr) {
		postorder(ptr->left_child);
		postorder(ptr->right_child);
		printf("%d ", ptr->data);
	}
}

//
//   		    n1
//		   / |
//		  n2  n3
//
void main()
{
	tnode_str* n1, * n2, * n3;

	n1 = (tnode_str*)malloc(sizeof(tnode_str));
	n2 = (tnode_str*)malloc(sizeof(tnode_str));
	n3 = (tnode_str*)malloc(sizeof(tnode_str));

	n1->data = 10;
	n1->left_child = n2;
	n1->right_child = n3;

	n2->data = 20;
	n2->left_child = NULL;
	n2->right_child = NULL;

	n3->data = 30;
	n3->left_child = NULL;
	n3->right_child = NULL;

	root = n1;
	printf("\ninorder\n");
	inorder(root);
	printf("\npreorder\n");
	preorder(root);
	printf("\npostorder\n");
	postorder(root);
}
