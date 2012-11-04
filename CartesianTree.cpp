//http://www.careercup.com/question?id=12715683

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Node
{
	int value;
	Node* left;
	Node* right;
};

Node* build(int data[], int start, int end)
{
	if(end<start)
		return NULL;

	int minval = INT_MAX;
	int minIndex = -1;

	for (int i=start;i<=end;i++)
	{
		if(data[i]<minval)
		{
			minval = data[i];
			minIndex = i;
		}
	}
	Node* node = new Node();
	node->value = minval;
	node->left = build(data, start,minIndex-1);
	node->right = build(data, minIndex+1,end );

	return node;
}

void InOrderTraversal(Node* root)
{
	if(root->left!=NULL)
		InOrderTraversal(root->left);

	cout<<root->value<<" ";

	if(root->right!=NULL)
		InOrderTraversal(root->right);

}

int main()
{
	int data[] = {9,3,7,1,8,12,10,20,15,18,5};
	int len = sizeof(data)/sizeof(int);

	Node* root = build(data,0,len-1);
	InOrderTraversal(root);

	getchar();
    return 1;
}