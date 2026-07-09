//1. Prefix Sum (C++)
#include <iostream>
using namespace std;

int main() {

    int arr[] = {1,2,3,4,5};
    int n = 5;

    int prefix[n];

    prefix[0] = arr[0];

    for(int i=1;i<n;i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }

    cout << "Prefix Sum: ";

    for(int i=0;i<n;i++)
        cout << prefix[i] << " ";

    return 0;
}
//2. Range Sum Query using Prefix Sum
#include <iostream>
using namespace std;

int main() {

    int arr[] = {1,2,3,4,5};
    int n = 5;

    int prefix[n];

    prefix[0] = arr[0];

    for(int i=1;i<n;i++)
        prefix[i] = prefix[i-1] + arr[i];


    int left = 1;
    int right = 3;

    int sum;

    if(left == 0)
        sum = prefix[right];
    else
        sum = prefix[right] - prefix[left-1];


    cout << "Range Sum = " << sum;

    return 0;
}
//3. Suffix Sum
#include <iostream>
using namespace std;

int main() {

    int arr[] = {1,2,3,4,5};
    int n = 5;

    int suffix[n];

    suffix[n-1] = arr[n-1];


    for(int i=n-2;i>=0;i--) {
        suffix[i] = suffix[i+1] + arr[i];
    }


    cout << "Suffix Sum: ";

    for(int i=0;i<n;i++)
        cout << suffix[i] << " ";


    return 0;
}
//4. Equilibrium Point Index
#include <iostream>
using namespace std;

int main() {

    int arr[] = {-7,1,5,2,-4,3,0};
    int n = 7;


    int totalSum = 0;

    for(int i=0;i<n;i++)
        totalSum += arr[i];


    int leftSum = 0;


    for(int i=0;i<n;i++) {

        totalSum -= arr[i]; // right sum


        if(leftSum == totalSum) {
            cout << "Equilibrium Index: " << i;
            return 0;
        }


        leftSum += arr[i];
    }


    cout << "No Equilibrium Index";


    return 0;
}
//5. Pivot Index (LeetCode 724)
#include <iostream>
using namespace std;

int main() {

    int nums[] = {1,7,3,6,5,6};
    int n = 6;


    int totalSum = 0;

    for(int i=0;i<n;i++)
        totalSum += nums[i];


    int leftSum = 0;


    for(int i=0;i<n;i++) {

        int rightSum = totalSum - leftSum - nums[i];


        if(leftSum == rightSum) {
            cout << "Pivot Index: " << i;
            return 0;
        }


        leftSum += nums[i];
    }


    cout << "No Pivot Index";


    return 0;
}