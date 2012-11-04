//http://crackinterviewtoday.wordpress.com/2010/03/15/rebuild-a-binary-tree-from-inorder-and-preorder-traversals/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> preordervec,inordervec;

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

treenode* BuildTree(vector<int> preorderindex,vector<int> inorder,int len)
{
    if(len <1)
    {
        return NULL;
    }
    
    treenode* root = new treenode();
    NewNode(root, preordervec[preorderindex[0]]);
    
    if(len ==1)
    {
        return root;
    }
    
    vector<int> newpreordervecid,newinordervec,newpreordervecid2,newinordervec2;
    
    vector<int>::iterator pos = find(inorder.begin(),inorder.end(),preordervec[preorderindex[0]]);
    
    int i = 0;
    for(;inorder[i]!=preordervec[preorderindex[0]];i++)
    {
        newinordervec.push_back(inorder[i]);
        vector<int>::iterator It = find(preordervec.begin(),preordervec.end(),inorder[i]);
        newpreordervecid.push_back(It-preordervec.begin());
    }
    sort(newpreordervecid.begin(),newpreordervecid.end());
    root->left = BuildTree(newpreordervecid,newinordervec,newpreordervecid.size());
    
    int postlen =len-i;
    for (i++;i<len; i++) 
    {
        newinordervec2.push_back(inorder[i]);
        vector<int>::iterator It = find(preordervec.begin(),preordervec.end(),inorder[i]);
        newpreordervecid2.push_back(It-preordervec.begin());
    }
    sort(newpreordervecid2.begin(),newpreordervecid2.end());
    root->right = BuildTree(newpreordervecid2,newinordervec2,newpreordervecid2.size());

    
    return root;
}

int main()
{
    int preorder[] = {1,2,4,8,9,10,11,5,3,6,7};
    int inorder[] = {8,4,10,9,11,2,5,1,6,3,7};
	int len = sizeof(preorder)/sizeof(int);
    
    vector<int> index;
    for(int i = 0;i<len;i++)
    {
        preordervec.push_back(preorder[i]);
        inordervec.push_back(inorder[i]);
        index.push_back(i);
    }
    
	treenode* root = BuildTree(index,inordervec,len);
	InOrderTraversal(root);
    
	getchar();
    return 1;
}