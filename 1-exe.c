#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
}

struct Node* newNode(int data);
{
	struct Node* Newnode = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct Node* insert(struct Node* root, int data)
{
	if (root == NULL) return newNode(data);
	if (data < root->data)
	{
		root->left = insert(root->left, data);
	}
	else
	{
		root->right = insert(root->right, data);
	}
	return root;	
}

void inorder(struct Node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d", root->data);
		inorder(root->right);
	}
}

int main()
{
	struct Node* root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	printf("In-order traversal: ");
	inorder(root);
	printf("\n");
}
