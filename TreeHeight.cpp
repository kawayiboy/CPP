#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int size = 0;

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

int GetHeight(treenode* t)
{
	if (t == NULL)
		return 0;
	else
		return 1+max(GetHeight(t->left),GetHeight(t->right));
	//int height = 1+max(GetHeight(t->left),GetHeight(t->right));
	//return height;
}

int TreeDiameter(treenode* t)
{
	if(t== NULL)
		return 0;
	int lheight = GetHeight(t->left);
	int rheight = GetHeight(t->right);
	int ldiameter = TreeDiameter(t->left);
	int rdiameter = TreeDiameter(t->right);
	return(max((lheight+rheight+1),max(ldiameter,rdiameter)));
}

bool IsBalanced(treenode* root)
{
	int lheight = GetHeight(root->left);
	int rheight = GetHeight(root->right);

	if(lheight-rheight>1||rheight-lheight>1)
		return false;
	else
		return true;
}

void TreeSize(treenode* t)
{
	if(t->left!=NULL)
		TreeSize(t->left);

	size++;
	if(t->right!=NULL)
		TreeSize(t->right);
}

void main()
{
	//1
	//2  3
	//4 5
	treenode* root = new treenode();
	NewNode(root,1);
	treenode* tempnode= new treenode();
	NewNode(tempnode,2);
	treenode* tempnode2= new treenode();
	NewNode(tempnode2,3);
	root->left = tempnode;
	root->right = tempnode2;
	treenode* leafleft= new treenode();
	NewNode(leafleft,4);
	treenode* leefright= new treenode();
	NewNode(leefright,5);
	tempnode->left = leafleft;
	tempnode->right = leefright;

	treenode* leafleft2= new treenode();
	NewNode(leafleft2,7);
	treenode* leefright2= new treenode();
	NewNode(leefright2,8);
	tempnode2->left = leafleft2;
	tempnode2->right = leefright2;

	int height = GetHeight(root);
	int diameter = TreeDiameter(root);
	TreeSize(root);
	cout<<height<<" "<<diameter<<" "<<size;
	bool bBalanced = IsBalanced(root);
	bBalanced?cout<<" Is Balanced":cout<<" Is not Balanced";
	getchar();
}

