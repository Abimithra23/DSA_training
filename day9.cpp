//1. Minimum Size Subarray Sum (Sliding Window) - C++
#include <iostream>
#include <climits>
using namespace std;

int main() {

    int nums[] = {2,3,1,2,4,3};
    int n = 6;

    int target = 7;

    int left = 0;
    int sum = 0;
    int minLen = INT_MAX;


    for(int right = 0; right < n; right++) {

        sum += nums[right];

        while(sum >= target) {

            minLen = min(minLen, right-left+1);

            sum -= nums[left];
            left++;
        }
    }


    cout << (minLen == INT_MAX ? 0 : minLen);

    return 0;
}
//2. Maximum Consecutive Ones III
#include <iostream>
using namespace std;

int main() {

    int nums[] = {1,1,1,0,0,0,1,1,1,1,0};
    int n = 11;

    int k = 2;

    int left = 0;
    int zeros = 0;
    int maxLen = 0;


    for(int right=0; right<n; right++) {

        if(nums[right]==0)
            zeros++;


        while(zeros > k) {

            if(nums[left]==0)
                zeros--;

            left++;
        }


        maxLen = max(maxLen, right-left+1);
    }


    cout << maxLen;

    return 0;
}
//3. Longest Substring Without Repeating Characters
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    string s = "pwwkew";


    unordered_map<char,int> lastIndex;


    int left = 0;
    int maxLen = 0;


    for(int right=0; right<s.length(); right++) {

        char c = s[right];


        if(lastIndex.find(c) != lastIndex.end()) {

            left = max(left, lastIndex[c]+1);
        }


        lastIndex[c] = right;


        maxLen = max(maxLen, right-left+1);
    }


    cout << maxLen;


    return 0;
}
 4. Binary Search
#include <iostream>
using namespace std;

int main() {

    int arr[] = {1,2,4,5,7,9};
    int n = 6;

    int target = 5;


    int left=0, right=n-1;


    while(left<=right) {

        int mid = left+(right-left)/2;


        if(arr[mid]==target) {

            cout << mid;
            return 0;
        }

        else if(arr[mid]<target)
            left=mid+1;

        else
            right=mid-1;
    }


    cout << -1;

    return 0;
}
//5. Order Agnostic Binary Search
#include <iostream>
using namespace std;

int main() {

    int arr[] = {9,7,5,4,2,1};
    int n = 6;

    int target = 5;


    int left=0,right=n-1;


    bool ascending = arr[left] < arr[right];


    while(left<=right) {

        int mid = left+(right-left)/2;


        if(arr[mid]==target) {

            cout << mid;
            return 0;
        }


        if(ascending) {

            if(arr[mid]<target)
                left=mid+1;
            else
                right=mid-1;
        }

        else {

            if(arr[mid]>target)
                left=mid+1;
            else
                right=mid-1;
        }
    }


    cout << -1;

    return 0;
}
//6. First Occurrence of Target
#include <iostream>
using namespace std;

int main() {

    int arr[] = {1,2,2,2,3,4};
    int n = 6;

    int target = 2;


    int left=0,right=n-1;
    int ans=-1;


    while(left<=right) {

        int mid=left+(right-left)/2;


        if(arr[mid]==target) {

            ans=mid;
            right=mid-1;
        }

        else if(arr[mid]<target)
            left=mid+1;

        else
            right=mid-1;
    }


    cout << ans;

    return 0;
}
//7. Last Occurrence of Target
#include <iostream>
using namespace std;

int main() {

    int arr[]={1,2,2,2,3,4};
    int n=6;

    int target=2;


    int left=0,right=n-1;
    int ans=-1;


    while(left<=right) {

        int mid=left+(right-left)/2;


        if(arr[mid]==target) {

            ans=mid;
            left=mid+1;
        }

        else if(arr[mid]<target)
            left=mid+1;

        else
            right=mid-1;
    }


    cout << ans;

    return 0;
}
//8. Count Occurrences of Target
#include <iostream>
using namespace std;

int main() {

    int arr[]={1,2,2,2,3,4};
    int n=6;

    int target=2;


    int first=-1,last=-1;


    for(int i=0;i<n;i++) {

        if(arr[i]==target) {

            if(first==-1)
                first=i;

            last=i;
        }
    }


    if(first==-1)
        cout << 0;
    else
        cout << last-first+1;


    return 0;
}
//9. Kth Rotation of Array
#include <iostream>
using namespace std;

int main() {

    int arr[]={1,2,3,4,5};
    int n=5;

    int k=2;


    k%=n;


    for(int i=n-k;i<n;i++)
        cout<<arr[i]<<" ";


    for(int i=0;i<n-k;i++)
        cout<<arr[i]<<" ";


    return 0;
}
 10. Search in Sorted Rotated Array
#include <iostream>
using namespace std;

int main() {

    int arr[]={4,5,6,7,0,1,2};
    int n=7;

    int target=0;


    int left=0,right=n-1;


    while(left<=right) {

        int mid=left+(right-left)/2;


        if(arr[mid]==target) {

            cout<<mid;
            return 0;
        }


        if(arr[left]<=arr[mid]) {

            if(target>=arr[left] && target<arr[mid])
                right=mid-1;
            else
                left=mid+1;
        }

        else {

            if(target>arr[mid] && target<=arr[right])
                left=mid+1;
            else
                right=mid-1;
        }
    }


    cout<<-1;

    return 0;
}