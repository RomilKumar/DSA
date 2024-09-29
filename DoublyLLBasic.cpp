#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int value)//parametrised constructor to initialise value
    {
       this->data=value;
this->next=NULL;
this->prev=NULL;
    }
};
 void insertAtHead(int value,Node*&head,Node* &tail){
    if(head==NULL&&tail==NULL){
        Node* newNode=new Node(value);
        tail=newNode;
        head=newNode;
    }
    else{
    //agr node present ho uske liye code h ye
    Node* newNode=new Node(value);
    newNode->next=head;
      head->prev=newNode;
      head=newNode;
    }

}
 void insertAtTail(int value,Node* head,Node* tail){
if(head==NULL&&tail==NULL){
    Node* newNode=new Node(value);
    tail=newNode;
    head=newNode;
}
else{
    //LL is not empty 
    Node* newNode=new Node(value);
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
}
}
int len( Node* &head){
  int  l=0;
    Node*temp=head;
    while(temp!=NULL){
l=l+1;
temp=temp->next;
    }
return l;
}
void insertAtPosition(int position,int value,Node*&head,Node*&tail){
 int length=len(head);
if(position==1){
    // Agr position start me hi ho insert At head
    insertAtHead(value,head,tail);
}
 else if(position==length+1){
    //insert at tail 
    insertAtTail(value,head,tail);
}
else{
    //Elements jb middle me ho
Node*newNode=new Node(value);
Node* temp=head;
for(int i=0;i<position-2;i++){
    temp=temp->next;
}
Node* forward=temp->next;
newNode->prev=temp->next;
temp->next=newNode;
forward->prev=newNode;
newNode->next=forward;


}
}
void print(Node* &head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"Null";
}
void printReverseLL(Node* &tail){

    Node*temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->prev;
    }
    cout<<"NULL";
}
bool search(int target,Node*head){
    Node*temp=head;
    while(temp!=NULL){
        if(temp->data==target){
            return true;
        }
        temp=temp->next;
    }
    //yaha aya mtlab element nhi mila
    return false;
}
  void deletefromll(int position,Node* &head,Node* &tail){
int length=len(head);
    if(head==NULL&&tail==NULL){
        cout<<"NO node to delete";
        return;
    }
else if(head==tail){
    //single node wala case
    Node *temp=head;
    head=NULL;
    tail=NULL;
    delete temp;
}
//first position deletion wala case
else if(position==1){
    Node* temp=head;
    head=temp->next;
    temp->next=NULL;
    head->prev=NULL;
    delete temp;
}

else if(position==length){
    Node*temp=tail;
    tail=temp->prev;
    tail->next=NULL;
    temp->prev=NULL;
    delete temp;

}
else{
    Node*temp=head;
    for(int i=0;i<position-2;i++){
        temp=temp->next;
    }
    Node* todelete=temp->next;
    Node*forward=todelete->next;
    temp->next=forward;
    forward->prev=temp;
    todelete->prev=NULL;
    todelete->next=NULL;
}
 }
int main(){
    Node* head=NULL;
    Node* tail=NULL;
insertAtHead(10,head,tail);
 //print(head);
insertAtHead(20,head,tail);
//print(head);
insertAtHead(30,head,tail);
print(head);
//print(head);
//printReverseLL(tail);
 //int truevalue=search(30,head);
//cout<<truevalue<<endl;
//insertAtPosition(3,40,head,tail);
//print(head);
deletefromll(3,head,tail);
print(head);
}