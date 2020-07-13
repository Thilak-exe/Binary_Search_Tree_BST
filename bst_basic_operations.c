#include<stdio.h>
#include<stdlib.h>

typedef struct bstnode
{
	int data;
	struct bstnode* left;
	struct bstnode* right;
}node;

node* root=NULL; //global variable of Structure bstnode

node* allocate_node(int x)
{
	node *n=(node*)malloc(sizeof(node));
	n->data=x;
	n->left=n->right=NULL;
	
	return n;
}

node* insert_node(node* par,int x)
{
	if(par==NULL)
	{
		par=allocate_node(x);
		return par;
	}
	
	if(x < par->data)
	{
		par->left=insert_node(par->left,x);
		return;
	}
	else
	{
		if(x > par->data)
		{
			par->right=insert_node(par->right,x);
			return;
		}
		else
		{
			printf("Error in Creating BST ! The number already exists in the BST !"); exit(1);
			return;
		}
	}
}

void inorder_traversal(node* root)
{
	if(root==NULL)
	{
		return;
	}
	
	inorder_traversal(root->left);
	printf("%d ",root->data);
	inorder_traversal(root->right);
	return;
	
}

void postorder_traversal(node* root)
{
	if(root==NULL)
	{
		return;
	}
	
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	printf("%d ",root->data);
	return;
}

void preorder_traversal(node* root)
{
	if(root==NULL)
	{
		return;
	}
	
	printf("%d ",root->data);
	preorder_traversal(root->left);
	preorder_traversal(root->right);
	return;
	
}

void main()
{
	int ch,x;
	
	

	
	do
	{
		printf("\n\n1. Insert \n2. Inorder Traversal \n3. Post_Order Traversal \n4. Pre_Order Traversal\n\n>> CHOICE : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: fflush(stdin); printf("Data : "); scanf("%d",&x); root=insert_node(root,x); break;
			case 2: inorder_traversal(root);break;
			case 3: postorder_traversal(root);break;
			case 4: preorder_traversal(root);break;
			default: printf("Invalid Menu Choice ! ");
		}
		
	}while(ch<=4);
}
