//1) Combination Sum II (C++)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    void backtrack(vector<int>& candidates, int target,
                   int start, vector<int>& curr,
                   vector<vector<int>>& result) {

        if(target == 0) {
            result.push_back(curr);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {

            if(i > start && candidates[i] == candidates[i-1])
                continue;

            if(candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            backtrack(candidates,
                      target - candidates[i],
                      i + 1,
                      curr,
                      result);

            curr.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> curr;

        backtrack(candidates, target, 0, curr, result);

        return result;
    }
};


void print(vector<vector<int>> ans){

    cout<<"[";

    for(auto v: ans){

        cout<<"[";

        for(int x:v)
            cout<<x<<" ";

        cout<<"]";
    }

    cout<<"]\n";
}


int main(){

    Solution obj;

    vector<int> candidates={10,1,2,7,6,1,5};

    vector<vector<int>> ans=obj.combinationSum2(candidates,8);

    cout<<"Combination Sum II: ";

    print(ans);

    return 0;
}
//2) Permutations of String (C++)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution{

public:

    void swapChar(char &a,char &b){

        char temp=a;
        a=b;
        b=temp;
    }


    void backtrack(string &s,int index,vector<string>& ans){

        if(index==s.length()){

            ans.push_back(s);
            return;
        }


        for(int i=index;i<s.length();i++){

            swapChar(s[index],s[i]);

            backtrack(s,index+1,ans);

            swapChar(s[index],s[i]);
        }
    }


    vector<string> permutation(string s){

        vector<string> ans;

        backtrack(s,0,ans);

        sort(ans.begin(),ans.end());

        return ans;
    }

};



int main(){

    Solution obj;

    vector<string> ans=obj.permutation("abc");


    cout<<"Permutations: ";

    for(string s:ans)
        cout<<s<<" ";

    return 0;
}
//3) Permutations of Array (C++)
#include <iostream>
#include <vector>
using namespace std;


class Solution{

public:

    void backtrack(vector<int>& nums,
                   int start,
                   vector<vector<int>>& result){


        if(start==nums.size()){

            result.push_back(nums);
            return;
        }


        for(int i=start;i<nums.size();i++){

            swap(nums[start],nums[i]);

            backtrack(nums,start+1,result);

            swap(nums[start],nums[i]);
        }
    }



    vector<vector<int>> permute(vector<int>& nums){

        vector<vector<int>> result;

        backtrack(nums,0,result);

        return result;
    }

};


void print(vector<vector<int>> ans){

    for(auto v:ans){

        for(int x:v)
            cout<<x<<" ";

        cout<<endl;
    }
}


int main(){

    Solution obj;

    vector<int> nums={1,2,3};

    vector<vector<int>> ans=obj.permute(nums);

    cout<<"Permutations:\n";

    print(ans);

    return 0;
}
//4) Permutations of Array with Duplicates (C++)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution{

public:

    void backtrack(vector<int>& nums,
                   vector<vector<int>>& result,
                   vector<int>& curr,
                   vector<bool>& used){


        if(curr.size()==nums.size()){

            result.push_back(curr);
            return;
        }


        for(int i=0;i<nums.size();i++){

            if(used[i])
                continue;


            if(i>0 && nums[i]==nums[i-1] && !used[i-1])
                continue;


            used[i]=true;

            curr.push_back(nums[i]);


            backtrack(nums,result,curr,used);


            curr.pop_back();

            used[i]=false;
        }
    }



    vector<vector<int>> permuteUnique(vector<int>& nums){

        sort(nums.begin(),nums.end());

        vector<vector<int>> result;

        vector<int> curr;

        vector<bool> used(nums.size(),false);


        backtrack(nums,result,curr,used);


        return result;
    }

};



int main(){

    Solution obj;

    vector<int> nums={1,1,2};


    auto ans=obj.permuteUnique(nums);


    for(auto v:ans){

        for(int x:v)
            cout<<x<<" ";

        cout<<endl;
    }


    return 0;
}
//5) Letter Combinations of Phone Number (C++)
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution{

public:

    void backtrack(string digits,
                   vector<string>& mp,
                   int index,
                   string curr,
                   vector<string>& ans){


        if(index==digits.length()){

            ans.push_back(curr);

            return;
        }


        string letters=mp[digits[index]-'0'];


        for(char ch:letters){

            curr.push_back(ch);


            backtrack(digits,
                      mp,
                      index+1,
                      curr,
                      ans);


            curr.pop_back();
        }
    }



    vector<string> letterCombinations(string digits){

        if(digits.empty())
            return {};


        vector<string> mp={
            "","","abc","def","ghi",
            "jkl","mno","pqrs","tuv","wxyz"
        };


        vector<string> ans;


        backtrack(digits,mp,0,"",ans);


        return ans;
    }

};



int main(){

    Solution obj;


    vector<string> ans=obj.letterCombinations("23");


    cout<<"Letter Combinations: ";

    for(string s:ans)
        cout<<s<<" ";


    return 0;
}