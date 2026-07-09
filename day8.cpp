//1. Container With Most Water (Two Pointer) - C++
#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    int left = 0;
    int right = height.size()-1;
    int maxArea = 0;


    while(left < right) {

        int width = right - left;
        int currentHeight = min(height[left], height[right]);

        maxArea = max(maxArea, currentHeight * width);


        if(height[left] < height[right])
            left++;
        else
            right--;
    }


    cout << "Maximum Area: " << maxArea;

    return 0;
}
//2. Maximum Subarray Sum of Size K (Sliding Window)
#include <iostream>
using namespace std;

int main() {

    int nums[] = {2,1,5,1,3,2};
    int n = 6;

    int k = 3;

    int sum = 0;
    int maxSum = -1e9;


    for(int i=0;i<n;i++) {

        sum += nums[i];


        if(i >= k)
            sum -= nums[i-k];


        if(i >= k-1)
            maxSum = max(maxSum,sum);
    }


    cout << "Maximum Sum: " << maxSum;

    return 0;
}
//3. Maximum Average Subarray of Size K
#include <iostream>
using namespace std;

int main() {

    int nums[] = {1,12,-5,-6,50,3};
    int n = 6;

    int k = 4;


    int sum = 0;
    int maxSum = -1e9;


    for(int i=0;i<n;i++) {

        sum += nums[i];


        if(i >= k)
            sum -= nums[i-k];


        if(i >= k-1)
            maxSum = max(maxSum,sum);
    }


    cout << "Maximum Average: " << (double)maxSum/k;


    return 0;
}
//4. Maximum Number of Vowels in Substring of Length K
#include <iostream>
using namespace std;


bool isVowel(char c) {

    c = tolower(c);

    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}


int main() {

    string s = "azerdii";

    int k = 5;

    int count = 0;
    int maxCount = 0;


    for(int i=0;i<s.length();i++) {

        if(isVowel(s[i]))
            count++;


        if(i >= k && isVowel(s[i-k]))
            count--;


        if(i >= k-1)
            maxCount = max(maxCount,count);
    }


    cout << "Maximum Vowels: " << maxCount;


    return 0;
}
//5. Number of Subarrays With Average >= Threshold
#include <iostream>
using namespace std;

int main() {

    int nums[] = {2,2,2,2,5,5,5,8};
    int n = 8;

    int k = 3;
    int threshold = 4;


    int sum = 0;
    int count = 0;

    int required = k * threshold;


    for(int i=0;i<n;i++) {

        sum += nums[i];


        if(i >= k)
            sum -= nums[i-k];


        if(i >= k-1 && sum >= required)
            count++;
    }


    cout << "Count: " << count;


    return 0;
}
//6. Minimum Recolors to Get K Consecutive Black Blocks
#include <iostream>
#include <climits>
using namespace std;

int main() {

    string blocks = "WBBWWBBWBW";

    int k = 7;


    int whiteCount = 0;

    int minRecolors = INT_MAX;


    for(int i=0;i<blocks.length();i++) {

        if(blocks[i]=='W')
            whiteCount++;


        if(i >= k && blocks[i-k]=='W')
            whiteCount--;


        if(i >= k-1)
            minRecolors = min(minRecolors,whiteCount);
    }


    cout << "Minimum Recolors: " << minRecolors;


    return 0;
}
7. First Negative Number in Every Window of Size K
#include <iostream>
#include <deque>
using namespace std;

int main() {

    int nums[] = {12,-1,-7,8,-15,30,16,28};

    int n = 8;

    int k = 3;


    deque<int> dq;


    for(int i=0;i<n;i++) {

        if(nums[i] < 0)
            dq.push_back(i);


        if(i >= k && !dq.empty() && dq.front()==i-k)
            dq.pop_front();


        if(i >= k-1) {

            if(dq.empty())
                cout << "0 ";
            else
                cout << nums[dq.front()] << " ";
        }
    }


    return 0;
}