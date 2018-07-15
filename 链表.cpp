#include<iostream>
#include<cstdlib> 
using namespace std;
typedef struct node{
	int data;
	node *next;
}Node;
Node *head=NULL;
Node *wei=NULL;
void create(int data){
	head=(Node*)malloc(sizeof(node));
	head->data=data;
	head->next=NULL;
	wei=head;
}
void pushlist(int data)
{
	if(head==NULL)
	{
		create(data);
	}
	else
	{
		Node *tou=NULL;
		tou=(Node*)malloc(sizeof(node));
		tou->data=data;
		tou->next=head;
		head=tou;
	}	
}
void pushbacklist(int data)
{
	if(head==NULL)
	{
		create(data);
	}
	else
	{
	Node *pigu=(Node*)malloc(sizeof(node));
	pigu->data=data;	
	pigu->next=NULL;
	wei->next=pigu;
	wei=pigu;		
	}
}
void charu(int where,int data)
{
	
	Node *p=head;
	for(int j=1;j<where&&p!=NULL;j++)	
	{
		p=p->next;
	}
	Node *cha=(Node*)malloc(sizeof(node));
	cha->data=data;
	cha->next=NULL;
	Node *s=p->next;
	p->next=cha;
	cha->next=s;
}
void print()
{
	int i=0;
	Node *p=head;
	do{
		cout<<p->data<<" "; 
		p=p->next; 
		i++;
	}
	while(p!=NULL);
	cout<<endl;
	cout<<i<<endl;
}
int  main()  
{  
    pushlist(3);
    pushlist(2);
    pushlist(1);
    pushbacklist(4);
    pushbacklist(5);
    pushbacklist(6);
   	print();
	return 0; 
}
