#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Running Sum
vector<int> runningSum(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        nums[i] += nums[i - 1];
    }
    return nums;
}

// Palindrome Check
bool isPalindromeHelper(string &s, int left, int right) {
    if (left >= right)
        return true;

    if (s[left] != s[right])
        return false;

    return isPalindromeHelper(s, left + 1, right - 1);
}

bool isPalindrome(string s) {
    return isPalindromeHelper(s, 0, s.length() - 1);
}

// Tower of Hanoi (Count Moves)
long long towerOfHanoi(int n, int from, int to, int aux) {
    if (n == 1)
        return 1;

    long long left = towerOfHanoi(n - 1, from, aux, to);
    long long right = towerOfHanoi(n - 1, aux, to, from);

    return left + right + 1;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = runningSum(nums);

    cout << "Running Sum: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    string word = "madam";
    cout << "Is palindrome: " << (isPalindrome(word) ? "true" : "false") << endl;

    int n = 4;
    cout << "Tower of Hanoi moves for n=" << n << ": "
         << towerOfHanoi(n, 1, 3, 2) << endl;

    return 0;
}