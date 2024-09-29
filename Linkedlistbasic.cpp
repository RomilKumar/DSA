#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    //parametrised constructor
Node(int value){
    this->data=value;
    this->next=NULL;
}
};
void insertAthead(int value,Node* &head,Node* &tail){

    if(head==NULL&&tail==NULL){
        //create a new node 
        Node* newNode=new Node(value);
        //iske baad parametrised constructor call hojaye
        //head ko newnode pe lagao and tail ko v
        head=newNode;
        tail=newNode;

    }
    else{
        //agr node pehle se exist krta ho
        //is case me bhi ek node bnana hoga
        Node* newNode=new Node(value);
        newNode->next=head;
        head=newNode;


    }
}
void insertAttail(int value,Node*&head,Node*&tail){
    //empty wale case me same kaam karenge jo pehle kiya tha
    if(head==NULL&&tail==NULL){
        //create a new node 
        Node* newNode=new Node(value);
        //iske baad parametrised constructor call hojaye
        //head ko newnode pe lagao and tail ko v
        head=newNode;
        tail=newNode;
    }
    else{
        //pehle ek node banaunga
        Node* newNode=new Node(value);
        tail->next=newNode;
        tail=newNode;
    }

}
int getlength(Node* head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len=len+1;
    }
    return len;
}
void insertInBetw(int value,int position,Node* head,Node* tail){
int length=getlength(head);
if (position==1){
    
insertAthead(value,head,tail);

    
}
else if(position=length+1){
insertAttail(value,head,tail);
}
else{
    //pehle temp ko wha lejao jha insert krna h use ek pehle
    Node *temp=head;
    for(int i=0;i<position-2;i++){
        temp=temp->next;
    }
    //ab ek node create krenge
    Node*newNode=new Node(value);
    newNode->next=temp->next;
    temp->next=newNode;
}
}
bool search(int target,Node* head){
    Node* temp=head;
    while(temp!=NULL){
        if( temp->data==target){
        return true;
        }
        temp=temp->next;
    }
return false;
}
void deletefromLL(int position,Node* head,Node* tail){
    //koi node present n ho
    if(head==NULL && tail==NULL){
        cout<<"No Node Present So Nothing To Delete";
        return;
    }
    //ek hi node present ho
    if(head==tail){
Node* temp=head;
head=NULL;
tail=NULL;
    }
    else{
        //todelete element which is present at position 1
        if(position==1){
        Node* temp=head;
        //temp->next means  agle wale node ko point krna  
        head=temp->next;
        //temp->next jo agle wale ko point kr rha use null krna h
        //that means wo kisi ko point n kre
        temp->next=NULL;
        delete temp;
        }
        else{
            //inbetween deleteion
            Node* temp=head;
            for(int i=0;i<position-2;i++){
                temp=temp->next;
            }
            Node* curr=temp->next;
            Node* forward=curr->next;
            head->next=forward;
        curr->next=NULL;
            delete curr;
        }

    }
}

void print( Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";

}
int main(){
     Node* head=NULL;
     Node* tail=NULL;
     insertAthead(10,head,tail);
     
     insertAthead(20,head,tail);
    // print(head);
insertAttail(30,head,tail);
//print(head);
insertInBetw(40,4,head,tail);
//print (head);
 //int ans=search(30,head);
 //cout<<ans;
// deletefromLL(2,head,tail);
//  print(head);
 cout<<endl;
 deletefromLL(1,head,tail);
print(head);

}