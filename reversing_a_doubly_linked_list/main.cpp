//
//  main.cpp
//  reversing_a_doubly_linked_list
//
//  Created by Uby H on 26/07/23.
//

#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *prev,*next;
}*first=NULL;
void create(int A[],int n)
{
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->prev=NULL;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->prev=last;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display()
{
    struct Node *p=first;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void reverse()
{
    struct Node *p,*q=NULL;
    p=first;
    while(p!=NULL)
    {
        q=p->next;
        p->next=p->prev;
        p->prev=q;
        if(p->prev==NULL)first=p;
        p=p->prev;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements in the doubly linked list : "<<endl;
    cin>>n;
    int A[n];
    cout<<"Enter the elements in the doubly linked list : "<<endl;
    for(int i=0;i<n;i++)cin>>A[i];
    create(A,n);
    cout<<"The original linked list is given by : "<<endl;
    display();
    reverse();
    cout<<"The reversed linked list is given by : "<<endl;
    display();
    return 0;
}
