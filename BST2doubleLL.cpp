#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;
//struct treenode
//{
//	treenode* left;
//	treenode* right;
//	int data;
//};

struct linklist{
	linklist* next;
	linklist* pre;
	int data;
};


//void NewNode(treenode* t,int data)
//{
//	//t = new treenode();
//	t->left=NULL;
//	t->right=NULL;
//	t->data=data;
//}

//linklist* listnode;
//void BST2DoubleLL(treenode* root)
//{
//	if (root==NULL)
//	{
//		listnode = NULL;
//		return NULL;
//	}
//
//	listnode = new linklist();
//	if(root->left!=NULL)
//	{
//		listnode->pre
//		listnode->pre = BST2DoubleLL(root->left,listnode->pre);
//	}
//	else
//		listnode->pre = NULL;
//
//	
//	listnode->data = root->data;
//
//	if(root->right!=NULL)
//	{
//		listnode->next = new linklist();
//		listnode->next = BST2DoubleLL(root->right,listnode->next);
//	}
//	else
//		listnode->next = NULL;
//
//	if(listnode->pre)
//	{
//		listnode->pre->next = listnode;
//		if(listnode->pre->pre==NULL)
//			listnode = listnode->pre;
//	}
//	if(listnode->next)
//	{
//		listnode->next->pre = listnode;
//		if(listnode->next->next==NULL)
//			listnode = listnode->next;
//	}
//
//
//	return listnode;
//}

struct treenode
{
	int data; // value of node
	treenode *left; // left child of node
	treenode *right; // right child of node
};

void NewNode(treenode* t,int data)
{
	//t = new treenode();
	t->left=NULL;
	t->right=NULL;
	t->data=data;
}

void helper(treenode *& head, treenode *& tail, treenode *root) {
	treenode *lt, *rh;
	if (root == NULL) {
		head = NULL, tail = NULL;
		return;
	}
	helper(head, lt, root->left);
	helper(rh, tail, root->right);
	if (lt!=NULL) {
		lt->right = root;
		root->left = lt;
	} else  {
		head = root;
	}
	if (rh!=NULL) {
		root->right=rh;
		rh->left = root;
	} else {
		tail = root;
	}
}

treenode * treeToLinkedList(treenode * root) {
	treenode * head, * tail;
	helper(head, tail, root);
	return head;
}

int arr[] = {4,6,8,10,12,14,16};

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

void main()
{	
	treenode* root = ArraytoBST(arr,0,6);

	//linklist* listnode = new linklist();
	//BST2DoubleLL(root,listnode);

	treenode* head = treeToLinkedList(root);

	while (head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->right;
	}

	//while (listnode->pre!=NULL)
	//{
	//	listnode = listnode->pre;
	//}

	//while (listnode->next!=NULL)
	//{
	//	cout<<listnode->data<<" ";
	//	listnode = listnode->next;
	//}
	getchar();
	
}