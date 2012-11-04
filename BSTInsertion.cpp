#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct treenode
{
	treenode* left;
	treenode* right;
	int data;
};

void NewNode(treenode* t,int data)
{
	//t = new treenode();
	t->left=NULL;
	t->right=NULL;
	t->data=data;
}

int arr[] = {-4,2,3,5,18};

treenode* ArraytoBST(int arr[],int start, int end)
{
	if (start > end) return NULL;

	int mid = start+(end - start)/2;
	treenode* root = new treenode();
	NewNode(root,arr[mid]);
	root->left = ArraytoBST(arr,start,mid-1);
	root->right = ArraytoBST(arr,mid+1,end);
	return root;
}

void Insert(treenode* root,int data)
{
	if(root->data==data);
	else if(root->data>data)
	{
		if(root->left!=NULL)
			Insert(root->left,data);
		else
		{
			treenode* t = new treenode();
			NewNode(t,data);
			root->left = t;
		}
		    
	}
	else if (root->data<data)
	{
		if(root->right!=NULL)
			Insert(root->right,data);
		else
		{
			treenode* t = new treenode();
			NewNode(t,data);
			root->right = t;
		}
	}
}

void InOrderTraversal(treenode* root)
{
	if(root->left!=NULL)
		InOrderTraversal(root->left);

	cout<<root->data<<" ";

	if(root->right!=NULL)
		InOrderTraversal(root->right);
}

void main()
{
	int len = sizeof(arr)/sizeof(int);
	treenode* root = ArraytoBST(arr,0,len-1);

	Insert(root,4);

	InOrderTraversal(root);

	getchar();
}