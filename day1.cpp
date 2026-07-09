//1. Call by Value
#include <iostream>
using namespace std;

void modify(int x){
    x += 5;
    cout << "Inside function: " << x;
}

int main(){
    int x = 10;
    cout << "Before: " << x << endl;
    modify(x);
    cout << "\nAfter: " << x;
    return 0;
}
//2. Call by Reference (Array)
#include <iostream>
using namespace std;

void modify(int &x){
    x += 5;
}

int main(){
    int x = 10;

    cout << "Before: " << x << endl;
    modify(x);
    cout << "After: " << x;

    return 0;
}
//3. Reverse String
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s = "hello";

    reverse(s.begin(), s.end());

    cout << s;

    return 0;
}
//4. Count Odd and Even Numbers
#include <iostream>
using namespace std;

int main(){

    int a[] = {1,2,3,4,5,6,7};
    int n = 7;

    int odd=0, even=0;

    for(int i=0;i<n;i++){
        if(a[i]%2==0)
            even++;
        else
            odd++;
    }

    cout<<"Odd: "<<odd<<endl;
    cout<<"Even: "<<even;

    return 0;
}
//5. Factorial
#include <iostream>
using namespace std;

int main(){

    int n=5;
    long long fact=1;

    for(int i=1;i<=n;i++)
        fact*=i;

    cout<<fact;

    return 0;
}
//6. Count Digits
#include <iostream>
using namespace std;

int main(){

    int n=12345;
    int count=0;

    while(n>0){
        n/=10;
        count++;
    }

    cout<<count;

    return 0;
}
7. Largest and Second Largest Element
#include <iostream>
using namespace std;

int main(){

    int a[]={4,9,1,7,9,3,5};
    int n=7;

    int large=-1, second=-1;

    for(int i=0;i<n;i++){

        if(a[i]>large){
            second=large;
            large=a[i];
        }
        else if(a[i]>second && a[i]!=large){
            second=a[i];
        }
    }

    cout<<"Largest: "<<large<<endl;
    cout<<"Second Largest: "<<second;

    return 0;
}
//8. Prime Number Check
#include <iostream>
using namespace std;

int main(){

    int n=29;
    bool prime=true;

    if(n<=1)
        prime=false;

    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            prime=false;
            break;
        }
    }

    if(prime)
        cout<<"Prime";
    else
        cout<<"Not Prime";

    return 0;
}
//9. Fibonacci Series
#include <iostream>
using namespace std;

int main(){

    int n=10;

    int a=0,b=1;

    for(int i=0;i<n;i++){

        cout<<a<<" ";

        int c=a+b;
        a=b;
        b=c;
    }

    return 0;
}