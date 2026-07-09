//1) Subsets With Duplicates (C++)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    void backtrack(vector<int>& nums, int start,
                   vector<int>& path,
                   vector<vector<int>>& result) {

        result.push_back(path);

        for(int i = start; i < nums.size(); i++) {

            if(i > start && nums[i] == nums[i-1])
                continue;

            path.push_back(nums[i]);

            backtrack(nums, i + 1, path, result);

            path.pop_back();
        }
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> path;

        sort(nums.begin(), nums.end());

        backtrack(nums, 0, path, result);

        return result;
    }
};


void printResult(vector<vector<int>> result) {

    cout << "[";

    for(int i = 0; i < result.size(); i++) {

        cout << "[";

        for(int j = 0; j < result[i].size(); j++) {

            cout << result[i][j];

            if(j + 1 < result[i].size())
                cout << ",";
        }

        cout << "]";

        if(i + 1 < result.size())
            cout << ",";
    }

    cout << "]\n";
}


int main() {

    Solution obj;

    vector<int> nums = {1,2,2};

    vector<vector<int>> ans = obj.subsetsWithDup(nums);

    cout << "Subsets with duplicates: ";

    printResult(ans);

    return 0;
}
//2) Combination Sum (C++)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {

public:

    void backtrack(vector<int>& candidates,
                   int target,
                   int index,
                   vector<int>& curr,
                   vector<vector<int>>& result) {


        if(target == 0) {

            result.push_back(curr);
            return;
        }


        for(int i = index; i < candidates.size(); i++) {

            if(candidates[i] <= target) {

                curr.push_back(candidates[i]);


                backtrack(candidates,
                          target - candidates[i],
                          i,
                          curr,
                          result);


                curr.pop_back();
            }
        }
    }



    vector<vector<int>> combinationSum(vector<int>& candidates,
                                      int target) {


        vector<vector<int>> result;

        vector<int> curr;


        sort(candidates.begin(), candidates.end());


        backtrack(candidates,
                  target,
                  0,
                  curr,
                  result);


        return result;
    }

};



void printResult(vector<vector<int>> result) {

    cout << "[";

    for(int i=0;i<result.size();i++) {

        cout << "[";

        for(int j=0;j<result[i].size();j++) {

            cout << result[i][j];

            if(j+1 < result[i].size())
                cout << ",";
        }

        cout << "]";

        if(i+1 < result.size())
            cout << ",";
    }

    cout << "]\n";
}



int main() {

    Solution obj;


    vector<int> candidates = {2,3,6,7};

    int target = 7;


    vector<vector<int>> ans =
        obj.combinationSum(candidates,target);


    cout << "Combination Sum: ";

    printResult(ans);


    return 0;
}