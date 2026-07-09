//1. Intersection of Two Linked Lists (C++)
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};


Node* insertAtEnd(Node* head, int data) {

    Node* newNode = new Node(data);

    if(head == NULL)
        return newNode;


    Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;


    temp->next = newNode;

    return head;
}


int length(Node* head) {

    int count = 0;

    while(head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}


Node* getIntersectionNode(Node* headA, Node* headB) {

    int lenA = length(headA);
    int lenB = length(headB);


    while(lenA > lenB) {
        headA = headA->next;
        lenA--;
    }


    while(lenB > lenA) {
        headB = headB->next;
        lenB--;
    }


    while(headA && headB) {

        if(headA == headB)
            return headA;


        headA = headA->next;
        headB = headB->next;
    }


    return NULL;
}


int main() {

    Node* headA = NULL;
    Node* headB = NULL;


    int a[] = {1,2,3,4,5};
    int b[] = {9,8,3,4,5};


    for(int x:a)
        headA = insertAtEnd(headA,x);


    for(int x:b)
        headB = insertAtEnd(headB,x);



    Node* result = getIntersectionNode(headA,headB);


    if(result)
        cout<<"Common node starts at value: "<<result->data;
    else
        cout<<"No intersection";


    return 0;
}
//2. Basic Stack Implementation (C++)
#include <iostream>
using namespace std;


class Stack {

    int arr[100];
    int top;


public:

    Stack() {
        top=-1;
    }


    void push(int value) {

        if(top==99) {
            cout<<"Stack Overflow";
            return;
        }

        arr[++top]=value;
    }


    int pop() {

        if(top==-1) {
            cout<<"Stack Underflow";
            return -1;
        }

        return arr[top--];
    }


    int peek() {

        if(top==-1)
            return -1;

        return arr[top];
    }


    bool isEmpty() {

        return top==-1;
    }


    int size() {

        return top+1;
    }
};



int main() {


    Stack s;


    s.push(10);
    s.push(20);
    s.push(30);


    cout<<"Top: "<<s.peek()<<endl;

    cout<<"Pop: "<<s.pop()<<endl;


    return 0;
}
//3. Next Greater Element (C++)
#include <iostream>
using namespace std;


void nextGreater(int arr[], int n) {

    for(int i=0;i<n;i++) {

        int ans=-1;


        for(int j=i+1;j<n;j++) {

            if(arr[j]>arr[i]) {
                ans=arr[j];
                break;
            }
        }

        cout<<ans<<" ";
    }
}


int main() {

    int arr[]={4,5,2,25,7,3,8};

    int n=7;


    nextGreater(arr,n);


    return 0;
}
//4. Previous Greater Element (C++)
#include <iostream>
using namespace std;


void previousGreater(int arr[], int n) {


    for(int i=0;i<n;i++) {


        int ans=-1;


        for(int j=i-1;j>=0;j--) {


            if(arr[j]>arr[i]) {

                ans=arr[j];
                break;
            }
        }


        cout<<ans<<" ";
    }
}


int main() {


    int arr[]={4,5,2,25,7,3,8};


    previousGreater(arr,7);


    return 0;
}
//5. Next Smaller Element (C++)
#include <iostream>
using namespace std;


void nextSmaller(int arr[], int n) {


    for(int i=0;i<n;i++) {


        int ans=-1;


        for(int j=i+1;j<n;j++) {


            if(arr[j]<arr[i]) {

                ans=arr[j];
                break;
            }
        }


        cout<<ans<<" ";
    }
}


int main() {


    int arr[]={4,5,2,25,7,3,8};


    nextSmaller(arr,7);


    return 0;
}
//6. Previous Smaller Element (C++)
#include <iostream>
using namespace std;


void previousSmaller(int arr[], int n) {


    for(int i=0;i<n;i++) {


        int ans=-1;


        for(int j=i-1;j>=0;j--) {


            if(arr[j]<arr[i]) {

                ans=arr[j];
                break;
            }
        }


        cout<<ans<<" ";
    }
}


int main() {


    int arr[]={4,5,2,25,7,3,8};


    previousSmaller(arr,7);


    return 0;
}
//7. Stock Span Problem (C++)
#include <iostream>
using namespace std;


void stockSpan(int prices[], int n) {


    for(int i=0;i<n;i++) {


        int count=1;


        for(int j=i-1;j>=0;j--) {


            if(prices[j]<=prices[i])
                count++;

            else
                break;
        }


        cout<<count<<" ";
    }
}


int main() {


    int prices[]={100,80,60,70,60,75,85};


    stockSpan(prices,7);


    return 0;
}