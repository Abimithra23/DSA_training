//1. 2D Prefix Sum (Range Sum Query) C++
#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {

    vector<vector<int>> prefix;

public:

    NumMatrix(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        prefix.assign(rows+1, vector<int>(cols+1,0));


        for(int i=0;i<rows;i++) {

            for(int j=0;j<cols;j++) {

                prefix[i+1][j+1] =
                    matrix[i][j]
                    + prefix[i][j+1]
                    + prefix[i+1][j]
                    - prefix[i][j];
            }
        }
    }


    int sumRegion(int row1,int col1,int row2,int col2) {

        return prefix[row2+1][col2+1]
            - prefix[row1][col2+1]
            - prefix[row2+1][col1]
            + prefix[row1][col1];
    }
};


int main() {

    vector<vector<int>> matrix = {
        {3,0,1,4,2},
        {5,6,3,2,1},
        {1,2,0,1,5},
        {4,1,0,1,7},
        {1,0,3,0,5}
    };


    NumMatrix obj(matrix);


    cout << obj.sumRegion(2,1,4,3);


    return 0;
}
//2. Subarray Sum Equals K
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    int nums[] = {1,1,1};
    int n = 3;

    int k = 2;


    unordered_map<int,int> prefixCount;

    prefixCount[0] = 1;


    int currentSum = 0;
    int count = 0;


    for(int i=0;i<n;i++) {

        currentSum += nums[i];


        if(prefixCount.find(currentSum-k) != prefixCount.end()) {

            count += prefixCount[currentSum-k];
        }


        prefixCount[currentSum]++;
    }


    cout << count;


    return 0;
}
//3. Longest Subarray With Sum K
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    int nums[] = {10,5,2,7,1,9};
    int n = 6;

    int k = 15;


    unordered_map<int,int> firstOccurrence;


    int prefixSum = 0;
    int maxLen = 0;


    for(int i=0;i<n;i++) {

        prefixSum += nums[i];


        if(prefixSum == k)
            maxLen = i+1;


        if(firstOccurrence.find(prefixSum-k) != firstOccurrence.end()) {

            maxLen = max(
                maxLen,
                i - firstOccurrence[prefixSum-k]
            );
        }


        if(firstOccurrence.find(prefixSum) == firstOccurrence.end())
            firstOccurrence[prefixSum] = i;
    }


    cout << maxLen;


    return 0;
}