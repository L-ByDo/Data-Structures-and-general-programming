/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
class Node{  //create a class of node with instance being key, data and next pointer. In this way every node will be an object of this Node class
    public:
    int key;  //key will act like an index of nodes. Every node needs to have unique key
    int data;  //this is the actual data of node
    Node* next;
    Node(){
        this->next=NULL;  //initially keep Null in every node's pointer. We will link them later
    }
    Node(int d,int k){
        this->key=k;  //parameterized constructor will be called only if we pass data and key to the object
        this->data=d;
    }
};
class SingleLinkedList{  //create a class of linked list that will perform operations on our linked list
    public:
    Node *head;  //declare a head pointer that always points to first node
    SingleLinkedList(){
        head=NULL;  //initially head is null
    }
    SingleLinkedList(Node *n){
        head=n;   //if first address of first node is passed in this constructor, head starts pointing to that node
    }
    Node* nodeExists(int k){  //method to check if node exists
        Node *temp=NULL;  //create temporary variable as temp
        Node *ptr=head;  //create another temporary variable ptr and make it to point to head
        while(ptr!=NULL){
            if(ptr->key==k){  //if key of any node matches to passed key, assign that node's pointer to temp
                temp=ptr;
            }
            ptr=ptr->next;  //keep incrementing the pointer ptr to next node unless last node occurs that is NULL
        }
        return temp; //return temp or in other words, key of that node that matches
    }
    void appendNode(Node *n){
        if(nodeExists(n->key)!=NULL){  //if node exists returns some value, means a node with same key exists
            cout<<"Node already exists";
        }
        else{
            if(head==NULL){ //if no element in linked list,head would be pointing to null,
                head=n; //just keep address of node to head
                cout<<"Node appended"<<"\n";
            }
            else{ //else create temporary variable and start from head until next of node points to null that is last node appears
                Node *ptr=head;
                while(ptr->next!=NULL){
                    ptr=ptr->next;
                }
                ptr->next=n;  //when loop exists, means ptr must be having the address NULL and ptr is representing last node, just keep value of new node pointer in next of ptr
                cout<<"Node appended"<<"\n";
            }
        }
    }
    void prependNode(Node *n){
        if(nodeExists(n->key)!=NULL){
            cout<<"Node already exists";
        }
        else{
            n->next=head;   //address of next node after head must be assigned to this new node
            head=n; //head should now point to new node
            cout<<"Node prepended"<<"\n";
        }
    }
    void inserAfter(int k,Node *n){
        Node *ptr=nodeExists(k);  //the loop of node exists method would have already taken us to the key of that node we require
        if(ptr==NULL){
         cout<<"No node exists with this key";
        }
        else{
        if(nodeExists(n->key)!=NULL){
            cout<<"Node already exists";if(nodeExists(n->key)!=NULL){
            cout<<"Node already exists";
        }if(nodeExists(n->key)!=NULL){
            cout<<"Node already exists";
        }
        }
        else{
    n->next=ptr->next; //the next pointer of current node should be stored in next pointer of new node;
    ptr->next=n; //then store address of new node to that particular node
    }
    }
    }
    void deleteNode(int k){
        if(head==NULL){
            cout<<"No node present";
        }
        else if(head!=NULL){
            if(head->key==k){
                head=head->next;
                cout<<"Node unlinked";
            }
            else{
                Node *temp=NULL;
                Node *prev=head;
                Node *current=head->next; //since we already deleted the head start from next
                while(current!=NULL){  //iterate over entire list
                    if(current->key==k){   //if key of any node matches with passed key
                        temp=current;  //assign address of that node to temp
                        current=NULL;
                    }
                    else{
                        prev=prev->next;   //else keep incrementing pointers to next nodes
                        current=current->next;
                    }
                }
                if(temp!=NULL){   //if we found node and it's value was assigned to temp
                    prev->next=temp->next;  //pointer of previous node should now contain address of node that comes after deleted nodev
                    cout<<"Node unlinked"<<"\n";
                }
                else{
                    cout<<"Node does not exists";
                }
            }
        }
    }
void updateNode(int k,int d){
        Node *ptr=nodeExists(k);  //ptr now has same key
        if(ptr!=NULL){
            ptr->data=d;  //node data is mutable;
            cout<<"Node updated"<<"\n";
        }
        else{
            cout<<"Node does not exists";
        }
}
void print(){
if(head==NULL){
    cout<<"List is empty";
}
else{
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
}
}
void reverseList(){
    Node* ptr=head;
    Node* nextnode=NULL;
    Node* previous=NULL;
    while(ptr!=NULL){
        nextnode=ptr->next;
        ptr->next=previous;
        previous=ptr;
        ptr=nextnode;
    }
    head=previous;
    cout<<"Linked list reversed"<<"\n";
}
void removeDuplicates(){
    Node* ptr=head;
    while(ptr->next->next!=NULL){
        if(ptr->next->data==ptr->data){
            ptr->next=ptr->next->next;
            cout<<"Duplicate removed"<<"\n";
        }
        ptr=ptr->next;
        if(ptr->next->next==NULL){
            ptr->next=NULL;
        }
    }
}

};
int main()
{
    Node* n1=new Node();
    n1->key=1;
    n1->data=10;
    SingleLinkedList s;
    s.appendNode(n1);
    Node* n2=new Node();
    n2->key=2;
    n2->data=120;
    s.prependNode(n2);
    s.print();
    s.updateNode(1,100);
    s.print();
    s.deleteNode(1);
    s.print();
    return 0;
}
/*// Online C++ compiler to run C++ online.
// Write C++ code in this online editor and run it.

#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    int key;
    Node* next;
    Node(){
        next=NULL;
    }
};
class CircularList{
    public:
    Node* head;
    CircularList(){
        head=NULL;
    }
    void insertNode(Node* n){
                n->next=head;
        if(head==NULL){
            head=n;
            cout<<" First Node inserted";

        }
        else{
            Node* ptr=head;
            while(ptr!=head){
                ptr=ptr->next;
            }
            ptr->next=n;
            cout<<"Node inserted";
        }
    }
    void deleteNode(int d){
        Node* ptr=head;
        if(ptr->data==d){
            if(ptr->next==NULL){
                head=NULL;
                cout<<"First deleted";
            }
            else{
                while(ptr->next!=head){
                    ptr=ptr->next;
                }
                ptr->next=head->next;
                head=head->next;
                cout<<"Node deleted";
                
            }
        }
        else{
            Node* prev=head;
            Node* ptr=head->next;
            while(ptr->data!=d){
                ptr=ptr->next;
                prev=ptr;
            }
            prev->next=ptr->next;
            cout<<"Node deleted";
        }
    }
    void print(){
        Node* ptr=head;
        do{
            cout<<ptr->data;
            ptr=ptr->next;
        }
        while(ptr!=head);
    }
};
int main() {
Node* n1=new Node();
n1->data=10;
n1->key=1;
Node* n2=new Node();
n2->data=20;
n2->key=2;
Node* n3=new Node();
n3->data=30;
n3->key=3;
CircularList c;
c.insertNode(n1);
c.insertNode(n2);
c.insertNode(n3);
c.deleteNode(30);
c.print();
}*/


