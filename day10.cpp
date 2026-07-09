//1. Floor in a Sorted Array (Largest element ≤ target)
#include <iostream>
using namespace std;

int main() {

    int nums[] = {1,2,4,6,8};
    int n = 5;

    int target = 5;

    int left = 0, right = n-1;
    int floorIndex = -1;


    while(left <= right) {

        int mid = left + (right-left)/2;


        if(nums[mid] == target) {
            floorIndex = mid;
            break;
        }

        else if(nums[mid] < target) {
            floorIndex = mid;
            left = mid + 1;
        }

        else {
            right = mid - 1;
        }
    }


    cout << "Floor Index: " << floorIndex;


    return 0;
}
//2. Search in Almost Sorted Array
#include <iostream>
using namespace std;

int main() {

    int nums[] = {10,3,40,20,50,80,70};
    int n = 7;

    int target = 40;


    int left = 0;
    int right = n-1;


    while(left <= right) {

        int mid = left + (right-left)/2;


        if(nums[mid] == target) {
            cout << mid;
            return 0;
        }


        if(mid-1 >= left && nums[mid-1] == target) {
            cout << mid-1;
            return 0;
        }


        if(mid+1 <= right && nums[mid+1] == target) {
            cout << mid+1;
            return 0;
        }


        if(nums[mid] > target)
            right = mid-2;
        else
            left = mid+2;
    }


    cout << -1;


    return 0;
}
//3. Find Peak Element in Array
#include <iostream>
using namespace std;

int main() {

    int nums[] = {1,2,1,3,5,6,4};
    int n = 7;


    int left = 0;
    int right = n-1;


    while(left < right) {

        int mid = left + (right-left)/2;


        if(nums[mid] > nums[mid+1])
            right = mid;
        else
            left = mid+1;
    }


    cout << "Peak Element Index: " << left;


    return 0;
}
//4. Koko Eating Bananas (Binary Search)
#include <iostream>
using namespace std;


bool canEatAll(int piles[], int n, int h, int speed) {

    long long hours = 0;


    for(int i=0;i<n;i++) {

        hours += (piles[i] + speed - 1) / speed;


        if(hours > h)
            return false;
    }


    return true;
}


int main() {

    int piles[] = {3,6,7,11};
    int n = 4;

    int h = 8;


    int left = 1;
    int right = 0;


    for(int i=0;i<n;i++)
        right = max(right,piles[i]);


    while(left < right) {

        int mid = left + (right-left)/2;


        if(canEatAll(piles,n,h,mid))
            right = mid;
        else
            left = mid+1;
    }


    cout << "Minimum Eating Speed: " << left;


    return 0;
}