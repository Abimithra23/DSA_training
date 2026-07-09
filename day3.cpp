//1. Two Sum using HashSet (C++)
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {

    int arr[] = {2,7,11,15};
    int n = 4;
    int target = 9;

    unordered_set<int> set;

    for(int i=0;i<n;i++) {

        int complement = target - arr[i];

        if(set.find(complement) != set.end()) {
            cout << "Pair Found: " << complement << " " << arr[i];
            return 0;
        }

        set.insert(arr[i]);
    }

    cout << "No Pair Found";

    return 0;
}
//2. Remove Duplicates from Sorted Array
#include <iostream>
using namespace std;

int main() {

    int arr[] = {1,1,2,2,3,4,4};
    int n = 7;

    int index = 0;

    for(int i=1;i<n;i++) {

        if(arr[i] != arr[index]) {
            index++;
            arr[index] = arr[i];
        }
    }

    cout << "Array after removing duplicates: ";

    for(int i=0;i<=index;i++)
        cout << arr[i] << " ";

    return 0;
}
//3. Move Zeroes to End
#include <iostream>
using namespace std;

int main() {

    int arr[] = {0,1,0,3,12};
    int n = 5;

    int index = 0;

    for(int i=0;i<n;i++) {

        if(arr[i] != 0)
            arr[index++] = arr[i];
    }

    while(index<n)
        arr[index++] = 0;


    for(int i=0;i<n;i++)
        cout << arr[i] << " ";

    return 0;
}
//4. Negative First, Positive Next
#include <iostream>
using namespace std;

int main() {

    int arr[] = {-1,2,-3,4,-5,6};
    int n = 6;

    int left=0, right=n-1;

    while(left < right) {

        while(left<right && arr[left]<0)
            left++;

        while(left<right && arr[right]>=0)
            right--;

        if(left<right) {
            swap(arr[left],arr[right]);
        }
    }

    for(int i=0;i<n;i++)
        cout << arr[i] << " ";

    return 0;
}
//5. Positive First, Negative Next
#include <iostream>
using namespace std;

int main() {

    int arr[] = {-1,2,-3,4,-5,6};
    int n = 6;

    int left=0, right=n-1;

    while(left<right) {

        while(left<right && arr[left]>=0)
            left++;

        while(left<right && arr[right]<0)
            right--;

        if(left<right)
            swap(arr[left],arr[right]);
    }

    for(int i=0;i<n;i++)
        cout << arr[i] << " ";

    return 0;
}
//6. Segregate 0s and 1s
#include <iostream>
using namespace std;

int main() {

    int arr[] = {0,1,1,0,1,0,0,1};
    int n = 8;

    int countZero = 0;

    for(int i=0;i<n;i++) {

        if(arr[i]==0)
            countZero++;
    }

    for(int i=0;i<countZero;i++)
        arr[i]=0;

    for(int i=countZero;i<n;i++)
        arr[i]=1;


    for(int i=0;i<n;i++)
        cout << arr[i] << " ";

    return 0;
}
//7. Segregate 0s, 1s and 2s
#include <iostream>
using namespace std;

int main() {

    int arr[] = {2,0,1,2,1,0,1,2};
    int n = 8;

    int count0=0,count1=0,count2=0;


    for(int i=0;i<n;i++) {

        if(arr[i]==0)
            count0++;
        else if(arr[i]==1)
            count1++;
        else
            count2++;
    }


    int index=0;

    while(count0--)
        arr[index++]=0;

    while(count1--)
        arr[index++]=1;

    while(count2--)
        arr[index++]=2;


    for(int i=0;i<n;i++)
        cout << arr[i] << " ";

    return 0;
}