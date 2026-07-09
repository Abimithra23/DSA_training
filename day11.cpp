L,//inked List Implementation in C++ (Single Program)
#include <iostream>
using namespace std;

class LinkedList {

    class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            next = NULL;
        }
    };

    Node* head;

public:

    LinkedList() {
        head = NULL;
    }


    // Insert at End
    void insertAtEnd(int data) {

        Node* newNode = new Node(data);

        if(head == NULL) {
            head = newNode;
            return;
        }


        Node* temp = head;

        while(temp->next != NULL)
            temp = temp->next;


        temp->next = newNode;
    }


    // Take Input
    void takeInput() {

        int value;

        cout << "Enter values (-1 to stop): ";

        while(true) {

            cin >> value;

            if(value == -1)
                break;

            insertAtEnd(value);
        }
    }


    // Print Linked List
    void printList() {

        Node* temp = head;


        if(temp == NULL) {
            cout << "Linked List is empty";
            return;
        }


        cout << "Linked List: ";

        while(temp != NULL) {

            cout << temp->data << " -> ";

            temp = temp->next;
        }


        cout << "NULL" << endl;
    }


    // Length of Linked List
    int length() {

        int count = 0;

        Node* temp = head;


        while(temp != NULL) {

            count++;

            temp=temp->next;
        }


        return count;
    }


    // Print Nth Node
    void printNthNode(int n) {

        Node* temp=head;

        int count=1;


        while(temp!=NULL && count<n) {

            temp=temp->next;
            count++;
        }


        if(temp==NULL)
            cout<<"Position out of range"<<endl;

        else
            cout<<"Node at position "<<n<<" is: "<<temp->data<<endl;
    }


    // Kth Node From End
    void printKthNodeFromEnd(int k) {

        Node* fast=head;
        Node* slow=head;


        for(int i=0;i<k;i++) {

            if(fast==NULL) {

                cout<<"K is greater than length"<<endl;
                return;
            }

            fast=fast->next;
        }


        while(fast!=NULL) {

            slow=slow->next;
            fast=fast->next;
        }


        cout<<"Kth node from end is: "<<slow->data<<endl;
    }


    // Middle Node
    void printMiddleNode() {

        Node* slow=head;
        Node* fast=head;


        while(fast!=NULL && fast->next!=NULL) {

            slow=slow->next;
            fast=fast->next->next;
        }


        cout<<"Middle node is: "<<slow->data<<endl;
    }


    // Insert at Given Index
    void insertAtIth(int index,int data) {


        Node* newNode=new Node(data);


        if(index==0) {

            newNode->next=head;
            head=newNode;
            return;
        }


        Node* temp=head;


        for(int i=0; temp!=NULL && i<index-1; i++)
            temp=temp->next;


        if(temp==NULL) {

            cout<<"Index out of range"<<endl;
            return;
        }


        newNode->next=temp->next;
        temp->next=newNode;
    }


    // Delete at Given Index
    void deleteAtIth(int index) {


        if(head==NULL) {

            cout<<"Linked List Empty"<<endl;
            return;
        }


        if(index==0) {

            head=head->next;

            cout<<"Deleted node at index 0"<<endl;

            return;
        }


        Node* temp=head;


        for(int i=0; temp!=NULL && i<index-1; i++)
            temp=temp->next;


        if(temp==NULL || temp->next==NULL) {

            cout<<"Index out of range"<<endl;
            return;
        }


        temp->next=temp->next->next;


        cout<<"Deleted node at index "<<index<<endl;
    }
};



int main() {


    LinkedList list;


    list.takeInput();


    list.printList();


    cout<<"Length: "<<list.length()<<endl;


    int n;

    cout<<"Enter position for nth node: ";

    cin>>n;

    list.printNthNode(n);



    int k;

    cout<<"Enter k for kth node from end: ";

    cin>>k;

    list.printKthNodeFromEnd(k);



    list.printMiddleNode();



    int index,value;

    cout<<"Enter index to insert: ";

    cin>>index;


    cout<<"Enter value: ";

    cin>>value;


    list.insertAtIth(index,value);


    list.printList();



    cout<<"Enter index to delete: ";

    cin>>index;


    list.deleteAtIth(index);


    list.printList();


    return 0;
}