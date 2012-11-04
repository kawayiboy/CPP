//http://www.leetcode.com/2010/11/largest-binary-search-tree-bst-in_22.html

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct treenode
{
	treenode* left;
	treenode* right;
	int data;
};

void NewNode(treenode* t, int data)
{
	//t = new treenode();
	t->left=NULL;
	t->right=NULL;
	t->data=data;
}

bool covers(treenode* root, treenode* p) { /* is p a child of root? */ 
    if (root == NULL) return false;
    if (root->data == p->data) return true;
    return covers(root->left, p) || covers(root->right, p); 
}

treenode* commonAncestor(treenode* root, treenode* p, treenode* q) { 
   if (covers(root->left, p) && covers(root->left, q)) 
           return commonAncestor(root->left, p, q);
   if (covers(root->right, p) && covers(root->right, q)) 
           return commonAncestor(root->right, p, q);
   return root; 
} 
void main()
{
	treenode* root = new treenode();
	NewNode(root,15);
	treenode* tempnode= new treenode();
	NewNode(tempnode,10);
	treenode* tempnode2= new treenode();
	NewNode(tempnode2,20);
	root->left = tempnode;
	root->right = tempnode2;
	treenode* leftleft= new treenode();
	NewNode(leftleft,5);
	treenode* leftright= new treenode();
	NewNode(leftright,7);
	tempnode->left = leftleft;
	tempnode->right = leftright;

	treenode* leftrightleft= new treenode();
	NewNode(leftrightleft,2);
	treenode* leftrightright= new treenode();
	NewNode(leftrightright,6);
	leftright->left = leftrightleft;
	leftright->right = leftrightright;

	treenode* leftrightleftleft= new treenode();
	NewNode(leftrightleftleft,0);
	treenode* leftrightleftright= new treenode();
	NewNode(leftrightleftright,8);
	leftrightleft->left = leftrightleftleft;
	leftrightleft->right = leftrightleftright;

	treenode* ancestor = commonAncestor(root,leftleft,tempnode2);
	cout<<ancestor->data;

	getchar();
}

