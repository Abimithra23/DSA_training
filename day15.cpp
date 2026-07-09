//1. Valid Parentheses (C++)
#include <iostream>
#include <stack>
using namespace std;


bool isValid(string s) {

    stack<char> st;


    for(char c : s) {


        if(c=='(' || c=='{' || c=='[') {

            st.push(c);
        }

        else {

            if(st.empty())
                return false;


            char top = st.top();
            st.pop();


            if(c==')' && top!='(')
                return false;

            if(c=='}' && top!='{')
                return false;

            if(c==']' && top!='[')
                return false;
        }
    }


    return st.empty();
}



int main() {


    cout << isValid("(){}[]") << endl;

    cout << isValid("([)]") << endl;


    return 0;
}
//2. Power Set / Subsequences (C++)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



void subSequences(int index, string s, string curr, vector<string>& res) {


    if(index == s.length()) {

        res.push_back(curr);
        return;
    }


    subSequences(index+1,s,curr+s[index],res);


    subSequences(index+1,s,curr,res);
}



vector<string> powerSet(string s) {


    vector<string> res;


    subSequences(0,s,"",res);


    sort(res.begin(),res.end());


    return res;
}



int main() {


    vector<string> ans = powerSet("abc");


    cout<<"Power Set:"<<endl;


    for(string x:ans)
        cout<<x<<" ";


    return 0;
}
//3. Subsets Using Backtracking (C++)
#include <iostream>
#include <vector>
using namespace std;



void backtrack(int start, vector<int>& nums,
               vector<int>& current,
               vector<vector<int>>& result) {


    result.push_back(current);



    for(int i=start;i<nums.size();i++) {


        current.push_back(nums[i]);


        backtrack(i+1,nums,current,result);


        current.pop_back();
    }
}



vector<vector<int>> subsets(vector<int>& nums) {


    vector<vector<int>> result;


    vector<int> current;


    backtrack(0,nums,current,result);


    return result;
}



int main() {


    vector<int> nums={1,2,3};


    vector<vector<int>> ans=subsets(nums);



    cout<<"Subsets:"<<endl;


    for(auto x:ans) {

        cout<<"{ ";

        for(int n:x)
            cout<<n<<" ";

        cout<<"}";
        cout<<endl;
    }


    return 0;
}