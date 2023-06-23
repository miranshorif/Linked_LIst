#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *Next;
    //Constructor Creation
    Node(int val){
        value = val;
        Next = NULL;
    }
};

struct Test{
    int positionArray[1000];
};

void insertAtTail(Node* &head,int val){
    Node *newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node * temp = head;
    while(temp->Next != NULL){
        temp = temp->Next;
    }
    temp->Next = newNode;

}

void insertAtHead(Node* &head,int val){
    Node *newNode = new Node(val);
    newNode->Next = head;
    head = newNode;
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

int countLength(Node *&head){
    int cnt = 0;
    Node *temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->Next;
    }

    return cnt;
}

 void insertAtSpecificPosition(Node *&head,int position, int val){
    int i=0;
    Node* temp = head;
    while(i<position-2){
        temp = temp->Next;
        i++;
    }
    Node *newNode = new Node(val);
    newNode->Next = temp->Next;
    temp->Next = newNode;
 }

 int searchByValueUnique(Node *&head, int key){
    Node *temp = head;
    int cnt = 1;

    if(temp == NULL){
        return -1;
    }

    while(temp->value != key){

        if(temp->Next == NULL){
            return -1;
        }
        temp = temp->Next;
        cnt++;
    }
    return cnt;
 }

 void searchByValueDublication(Node *&head,int key){
    int size;
    size = countLength(head);
    int positionArray[size],k=1;
    int cnt = 1;
    int flag = 0;

    Node *temp = head;

    while(temp != NULL){
        if(temp->value == key){
            positionArray[k] = cnt;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        cnt++;
    }

    if(flag == 0) cout<<"The searched value is not in the List"<<endl;
    else{
        positionArray[0] = k;
        cout<<"The value is found at Position: ";
        for(int i=1;i<positionArray[0];i++){
            cout<<positionArray[i];
            if(i<positionArray[0]-1) cout<<",";
        }
        cout<<endl;
    }
 }

 Test searchByValueDublicationReturn(Node *&head,int key){

    int k=1;
    Test T;
    int cnt = 1;

    Node *temp = head;

    while(temp != NULL){
        if(temp->value == key){
            T.positionArray[k] = cnt;
            k++;

        }
        temp = temp->Next;
        cnt++;
    }
    T.positionArray[0] = k;
    return T;
 }

int main(){

    Node *head = NULL;
    int value,position;
    cout<<"choice 1: insert at head"<<endl
        <<"choice 2: insert at tail"<<endl
        <<"choice 3: insertAtSpecificPosition"<<endl
        <<"choice 4: searchByValueUnique"<<endl
        <<"choice 5: searchByValueDublication"<<endl
        <<"choice 0: Exit"<<endl;

    cout<<"Next Choice: ";
    int choice;
    cin>>choice;
    while(choice != 0){

        switch(choice)
        {
        case 1:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtHead(head,value);
            break;
        case 2:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtTail(head,value);
            break;
        case 3:
            cout<<"Enter the desired position: ";
            cin>>position;
            cout<<"Enter the value: ";
            cin>>value;
            insertAtSpecificPosition(head,position,value);
            break;
        case 4:
            cout<<"Enter the value to search: ";
            cin>>value;
            position = searchByValueUnique(head, value);
            if(position != -1){
                cout<<"The value position is: "<<position<<endl;
            }
            else{
                cout<<"The Value is not in the Linked List"<<endl;
            }
            break;
        case 5:
            cout<<"Enter the dublication value to search: ";
            cin>>value;
            //searchByValueDublication(head,value);
            Test T;
            T = searchByValueDublicationReturn(head,value);
            if(T.positionArray[0] == 1){
                cout<<"The searched value is not in the List"<<endl;
            }
            else{
                int size = T.positionArray[0];
                cout<<"The value is found at Position: ";
                for(int i=1;i<size;i++){
                    cout<<T.positionArray[i];
                    if(i<size-1) cout<<", ";
                }
                cout<<endl;
            }
            break;
        default:
            break;
        }

        cout<<"Enter Choice: ";
        cin>>choice;
    }
    cout<<endl<<"Linked List: ";
    display(head);
    cout<<"Length of Linked List: "<<countLength(head)<<endl;

return 0;
}
