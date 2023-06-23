#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node* Next;
    //Constructor Create
    Node(int val){
        value = val;
        Next = NULL;
    }
};

void insertIntoTail(Node* &head, int val){
    Node *newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node *temp = head;

    while(temp->Next != NULL){
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void display(Node *n){
    while(n != NULL){
        cout<<n->value;
        if(n->Next != NULL)
            cout<<" -> ";
        n = n->Next;
    }

    cout<<endl<<endl;
}

int main(){

    Node* head = NULL;
    insertIntoTail(head,1);
    insertIntoTail(head,5);
    insertIntoTail(head,8);
    insertIntoTail(head,9);


    display(head);


    return 0;
}

