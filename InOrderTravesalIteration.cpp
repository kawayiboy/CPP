#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>

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

void InOrderTraversal(treenode* root)
{
	if(root->left!=NULL)
		InOrderTraversal(root->left);

	cout<<root->data<<" ";

	if(root->right!=NULL)
		InOrderTraversal(root->right);
}

void InOrderTraversalInteration(treenode* root)
{
	stack<treenode*> s;
	//s.push(root);
	treenode* current = root;
	bool done = false;
	while (!done)
	{
		if(current)
		{
			s.push(current);
			current = current->left;
		}
		else
		{
			if(s.empty())
			{
				done = true;
			}
			else
			{
				current = s.top();
				s.pop();
				cout<<current->data<<" ";
				current = current->right;
			}
		}
	}
	
}

void BuildTree(treenode*& node,int num)
{
	if(node == NULL)
	{
		node = new treenode();
		NewNode(node,num);
		return;
	}

	if(node&&node->data>num)
		BuildTree(node->left,num);

	if(node&&node->data<=num)
		BuildTree(node->right,num);
}

void main()
{
	int arr[] ={1,2,3,4,5,6,7};
	int len = sizeof(arr)/sizeof(int);

	treenode* root = NULL;
	for (int i = 0;i<len;i++)
	{
		BuildTree(root,arr[i]);
	}

	InOrderTraversalInteration(root);
	
	getchar();
}