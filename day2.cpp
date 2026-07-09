//1. Calculate Mid
#include <iostream>
using namespace std;

int main() {

    int low = 10, high = 20;

    int mid = low + (high - low) / 2;

    cout << "Mid = " << mid;

    return 0;
}
//2. Binary Search
#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> arr = {2,4,6,8,10,12,14};
    int target = 10;

    int low = 0, high = arr.size()-1;

    while(low <= high) {

        int mid = low + (high-low)/2;

        if(arr[mid] == target) {
            cout << "Target found at index: " << mid;
            return 0;
        }
        else if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << "Target not found";

    return 0;
}
//3. Print N Natural Numbers Using Recursion
#include <iostream>
using namespace std;

void printNatural(int n) {

    if(n == 0)
        return;

    printNatural(n-1);

    cout << n << " ";
}

int main() {

    int n = 10;

    printNatural(n);

    return 0;
}
//4. Sum of First N Natural Numbers Using Recursion
#include <iostream>
using namespace std;

int sumNatural(int n) {

    if(n == 0)
        return 0;

    return n + sumNatural(n-1);
}

int main() {

    int n = 10;

    cout << "Sum = " << sumNatural(n);

    return 0;
}
//5. Nth Fibonacci Using Recursion
#include <iostream>
using namespace std;

int fibonacci(int n) {

    if(n <= 1)
        return n;

    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {

    int n = 10;

    cout << n << "th Fibonacci = " << fibonacci(n);

    return 0;
}
//6. Array of Squares
#include <iostream>
using namespace std;

int main() {

    int arr[] = {1,2,3,4,5};
    int n = 5;

    for(int i=0;i<n;i++) {
        cout << arr[i]*arr[i] << " ";
    }

    return 0;
}
//7. Count Factors
#include <iostream>
using namespace std;

int main() {

    int n = 36;
    int count = 0;

    for(int i=1;i*i<=n;i++) {

        if(n%i==0) {

            if(i == n/i)
                count++;
            else
                count += 2;
        }
    }

    cout << "Number of factors = " << count;

    return 0;
}
//8. Prime Check
#include <iostream>
using namespace std;

int main() {

    int n = 29;
    bool prime = true;

    if(n <= 1)
        prime = false;

    for(int i=2;i*i<=n;i++) {

        if(n%i==0) {
            prime = false;
            break;
        }
    }

    if(prime)
        cout << "Prime";
    else
        cout << "Not Prime";

    return 0;
}