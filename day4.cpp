//1. Merge Two Sorted Linked Lists (C++)
#include <iostream>
using namespace std;

class Node {

public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};


Node* mergeTwoLists(Node* list1, Node* list2) {

    Node* dummy = new Node(0);
    Node* tail = dummy;

    while(list1 != NULL && list2 != NULL) {

        if(list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        }
        else {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    if(list1 != NULL)
        tail->next = list1;
    else
        tail->next = list2;


    return dummy->next;
}


void printList(Node* head) {

    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
}


int main() {

    Node* l1 = new Node(1);
    l1->next = new Node(2);
    l1->next->next = new Node(4);


    Node* l2 = new Node(1);
    l2->next = new Node(3);
    l2->next->next = new Node(4);


    Node* result = mergeTwoLists(l1,l2);

    printList(result);

    return 0;
}
//2. Merge Sorted Array
#include <iostream>
using namespace std;

int main() {

    int nums1[] = {1,2,3,0,0,0};
    int nums2[] = {2,5,6};

    int m = 3;
    int n = 3;


    int i = m-1;
    int j = n-1;
    int k = m+n-1;


    while(i>=0 && j>=0) {

        if(nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }


    while(j>=0)
        nums1[k--] = nums2[j--];


    for(int i=0;i<m+n;i++)
        cout << nums1[i] << " ";


    return 0;
}
//3. Maximum Consecutive Ones
#include <iostream>
using namespace std;

int main() {

    int arr[] = {1,1,0,1,1,1};
    int n = 6;

    int count = 0;
    int maxCount = 0;


    for(int i=0;i<n;i++) {

        if(arr[i] == 1) {

            count++;

            if(count > maxCount)
                maxCount = count;
        }
        else {
            count = 0;
        }
    }


    cout << maxCount;

    return 0;
}
//4. Maximum Subarray Sum (Kadane's Algorithm)
#include <iostream>
using namespace std;

int main() {

    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = 9;


    int currentSum = arr[0];
    int maxSum = arr[0];


    for(int i=1;i<n;i++) {

        currentSum = max(arr[i], currentSum + arr[i]);

        maxSum = max(maxSum, currentSum);
    }


    cout << maxSum;


    return 0;
}