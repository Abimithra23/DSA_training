//1. Range Sum Query 2D (Prefix Sum Matrix) - C++
#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {

    vector<vector<int>> prefix;

public:

    NumMatrix(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        prefix.assign(rows + 1, vector<int>(cols + 1, 0));


        for(int i = 0; i < rows; i++) {

            for(int j = 0; j < cols; j++) {

                prefix[i+1][j+1] = matrix[i][j]
                    + prefix[i][j+1]
                    + prefix[i+1][j]
                    - prefix[i][j];
            }
        }
    }


    int sumRegion(int row1, int col1, int row2, int col2) {

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
        {4,1,0,3,2}
    };


    NumMatrix obj(matrix);


    cout << obj.sumRegion(1,1,2,3) << endl;
    cout << obj.sumRegion(0,0,3,3);


    return 0;
}
//2. Subarray Sum Equals K (LeetCode 560) - C++
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    int nums[] = {1,1,1};
    int n = 3;

    int k = 2;


    unordered_map<int,int> prefixCount;

    prefixCount[0] = 1;


    int prefixSum = 0;
    int count = 0;


    for(int i = 0; i < n; i++) {

        prefixSum += nums[i];


        int needed = prefixSum - k;


        if(prefixCount.find(needed) != prefixCount.end()) {
            count += prefixCount[needed];
        }


        prefixCount[prefixSum]++;
    }


    cout << count;


    return 0;
}
//3. Longest Subarray With Sum K - C++
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    int nums[] = {1,2,1,0,1,1,1};
    int n = 7;

    int k = 3;


    unordered_map<int,int> firstSeen;

    firstSeen[0] = -1;


    int prefixSum = 0;
    int longest = 0;


    for(int i = 0; i < n; i++) {

        prefixSum += nums[i];


        int needed = prefixSum - k;


        if(firstSeen.find(needed) != firstSeen.end()) {

            longest = max(longest, i - firstSeen[needed]);
        }


        if(firstSeen.find(prefixSum) == firstSeen.end()) {

            firstSeen[prefixSum] = i;
        }
    }


    cout << longest;


    return 0;
}