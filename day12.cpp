//1. Remove Nth Node From End of Linked List (C++)
#include <iostream>
using namespace std;


class ListNode {

public:
    int val;
    ListNode* next;


    ListNode(int val) {
        this->val = val;
        next = NULL;
    }
};


ListNode* removeNthFromEnd(ListNode* head, int n) {

    if(head == NULL || n <= 0)
        return head;


    ListNode* dummy = new ListNode(0);
    dummy->next = head;


    ListNode* fast = dummy;
    ListNode* slow = dummy;


    for(int i=0;i<=n;i++)
        fast = fast->next;


    while(fast != NULL) {

        slow = slow->next;
        fast = fast->next;
    }


    slow->next = slow->next->next;


    return dummy->next;
}


void printList(ListNode* head) {

    while(head != NULL) {

        cout << head->val;

        if(head->next)
            cout << " -> ";

        head=head->next;
    }

    cout << endl;
}



int main() {


    ListNode* head = new ListNode(1);

    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);



    cout<<"Before Removing: ";
    printList(head);


    head = removeNthFromEnd(head,2);


    cout<<"After Removing: ";
    printList(head);


    return 0;
}
//2. Flatten a Multi-Level Linked List (C++)
#include <iostream>
using namespace std;


class Node {

public:

    int val;
    Node* next;
    Node* child;


    Node(int val) {

        this->val = val;
        next = NULL;
        child = NULL;
    }
};



Node* flattenLinkedList(Node* head) {


    Node* current = head;


    while(current != NULL) {


        if(current->child != NULL) {


            Node* tail = current->child;


            while(tail->next != NULL)
                tail = tail->next;



            tail->next = current->next;


            current->next = current->child;


            current->child = NULL;
        }


        current = current->next;
    }


    return head;
}



void printList(Node* head) {


    while(head != NULL) {

        cout << head->val;


        if(head->next)
            cout << " -> ";


        head = head->next;
    }


    cout << endl;
}



int main() {


    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);



    node1->next = node2;
    node2->next = node3;


    node1->child = node4;
    node4->next = node5;


    node2->child = node6;


    node3->child = node7;
    node7->next = node8;



    cout<<"Before Flattening: ";
    printList(node1);



    Node* result = flattenLinkedList(node1);



    cout<<"After Flattening: ";
    printList(result);



    return 0;
}