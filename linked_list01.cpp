#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};
void printList(Node *n)
{
    while(n != NULL)
    {
        cout<<n->val;
        if(n->next != NULL)
            cout<<" -> ";
        n=n->next;
    }
    cout<<endl<<endl;
}

void listInsert(Node* &head,int pos,int value)
{
    int i=0;
    if(pos==0){
        Node *save_next = head;
        head = new Node(value);
        head->next = save_next;
        return;
    }
    Node *temp = head;
    while(i<pos-2){
        temp = temp->next;
        i++;
    }
    Node *newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

int main(){

    Node *head = new Node(5);
    Node *a = new Node(10);
    Node *c = new Node(15);
    Node *b = new Node(20);

    head->next = a;
    a->next = c;
    c->next = b;

    listInsert(head,0,100);
    printList(head);

return 0;
}
