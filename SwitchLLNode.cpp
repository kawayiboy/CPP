//http://www.careercup.com/question?id=13575664
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct LinkedList
{
	LinkedList* next;
	int data;
};

LinkedList* NewNode(int arr[],int len)
{
	LinkedList* head = new LinkedList();
	head->data = arr[0];

	LinkedList* pre = head;
	for (int i = 1;i<len;i++)
	{
		LinkedList* node = new LinkedList();
		node->data = arr[i];
		pre->next = node;
		pre = node;
	}

	return head;
}

void PrintLL(LinkedList* head)
{
	LinkedList* cursor = head;
	while (cursor)
	{
		cout<<cursor->data<<" ";
		cursor = cursor->next;
	}
}

LinkedList* GetKthNode(LinkedList* head,int n,LinkedList*& pre)
{
	LinkedList* node = head;
	int count = 1;
	while(count<n)
	{
		pre = node;
		node = node->next;
		count++;
	}
	return node;
}

LinkedList* GetLastKthNode(LinkedList* head,int n,LinkedList*& pre)
{
	LinkedList* node = head;
	LinkedList* pre2;
	node = GetKthNode(node,n,pre2);
	LinkedList* node2 = head;
	while (node->next)
	{
		node = node->next;
		pre = node2;
		node2 = node2->next;
	}
	return node2;
}

void Switch(LinkedList*& head,int k)
{
	LinkedList* pre = NULL,*pre2= NULL;
	LinkedList* node = GetKthNode(head,k,pre);
	LinkedList* node2 = GetLastKthNode(head,k,pre2);


	if(pre!=NULL&&pre2!=NULL)
	{
		if(pre2 == node)
		{
			//LinkedList* temp = node->next;
			pre->next = node2;
			node->next = node2->next;
			node2->next = node;
		}
		else if(pre == node2)
		{
			pre2->next = node;
			node2->next = node->next;
			node->next = node2;
		}
		else
		{
			LinkedList* temp = node->next;
			pre->next = node2;
			pre2->next = node;
			node->next = node2->next;
			node2->next = temp;
		}

	}
	else if(pre==NULL)
	{
		LinkedList* temp = node->next;
		pre2->next = node;
		node->next = NULL;
		node2->next = temp;
		head = node2;
	}
	else if(pre2==NULL)
	{
		LinkedList* temp = node2->next;
		pre->next = node2;
		node2->next = NULL;
		node->next = temp;
		head = node;
	}
}

//1->2->3->4->5->6->7->8 
void main()
{
	int arr[] = {1,2,3,4,5,6,7,8};
	int len = sizeof(arr)/sizeof(int);

	LinkedList* head = NewNode(arr,len);
	Switch(head,8);
	PrintLL(head);

	getchar();
}