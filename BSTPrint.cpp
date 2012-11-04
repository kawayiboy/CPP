//http://www.careercup.com/question?id=13561671

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

//void InOrderTraversal(treenode* root1,treenode* root2)
//{
//	if(root1->left!=NULL)
//		if(root1->left<1)
//		InOrderTraversal(root1->left);
//
//	cout<<root->value<<" ";
//
//	if(root->right!=NULL)
//		InOrderTraversal(root->right);
//}

void InOrderCompare(treenode* p1,treenode* p2)
{
	if((p1 != NULL)||(p2 !=NULL))
	{
		if(p1->data > p2->data)
		{
			if(p1->left) InOrderCompare(p1->left,p2);
			cout<<" "<<p1->data<<" ";
			if(p1->right) InOrderCompare(p1->right,p2);
		}
		else
		{
			if(p2->left) InOrderCompare(p1,p2->left);
			cout<<" "<<p2->data<<" ";
			if(p2->right) InOrderCompare(p1,p2->right);
		}
	}
	else return;
}

void traverse(treenode *t1, treenode *t2) {
	//
	if(t2 == 0) {
		if(t1 == 0)
			return;
		traverse(t1->left, 0);
		printf("%d ", t1->data);
		traverse(t1->right, 0);
		return;
	}
	//
	if(t1 == 0) {
		traverse(0, t2->left);
		printf("%d ", t2->data);
		traverse(0, t2->right);
		return;
	}
	//
	traverse(t1->left, t2->left);
	if(t1->data >= t2->data) {
		printf("%d ", t2->data);
		treenode *s = t1->left;
		t1->left = 0;
		traverse(t1, t2->right);
		t1->left = s;
	} else {
		printf("%d ", t1->data);
		treenode *s = t2->left;
		t2->left = 0;
		traverse(t1->right, t2);
		t2->left = s;
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

int arr[] = {1,2,3,4,5,6,7};

int arr1[] = {1,3,5};
int arr2[] = {2,4,6};

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
	int len = sizeof(arr)/sizeof(int);
	//treenode* root = ArraytoBST(0,len-1);
	treenode* root1 = ArraytoBST(arr1,0,2);
	treenode* root2 = ArraytoBST(arr2,0,2);

	//treenode* root1 = new treenode();
	//NewNode(root1,3);
	//treenode* left1= new treenode();
	//NewNode(left1,1);
	//treenode* right1= new treenode();
	//NewNode(right1,5);
	//root1->left = left1;
	//root1->right = right1;

	//treenode* root2 = new treenode();
	//NewNode(root2,4);
	//treenode* left2= new treenode();
	//NewNode(left2,2);
	//treenode* right2= new treenode();
	//NewNode(right2,6);
	//root2->left = left2;
	//root2->right = right2;
	
	//InOrderTraversal(root);
	traverse(root1,root2);

	getchar();
}