#include <iostream>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

struct treenode
{
	treenode* left;
	treenode* right;
	int data;
};

int distance(treenode* t)
{
	int d;
	if (t->left==NULL&&t->right==NULL)
		return 0;
	else if(t->left==NULL)
		d = distance(t->right)+1;
	else if(t->right==NULL)
		d = distance(t->left)+1;
	else
	{
		d = min(distance(t->left),distance(t->right))+1;
	}

}

void NewNode(treenode* t)
{
	//t = new treenode();
	t->left=NULL;
	t->right=NULL;
	t->data=1;
}

void main()
{
	treenode* root = new treenode();
	NewNode(root);
	treenode* tempnode= new treenode();
	NewNode(tempnode);
	treenode* tempnode2= new treenode();
	NewNode(tempnode2);
	root->left = tempnode;
	root->right = tempnode2;
	treenode* leafleft= new treenode();
	NewNode(leafleft);
	treenode* leefright= new treenode();
	NewNode(leefright);
	tempnode->left = leafleft;
	tempnode2->right = leefright;
	//treenode* leafleftleft= new treenode();
	//NewNode(leafleftleft);
	//leafleft->left = leafleftleft;

	int minidis = distance(root);
	cout<<minidis;

	getchar();
}