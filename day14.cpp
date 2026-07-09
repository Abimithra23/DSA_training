//1. Largest Rectangle in Histogram (C++)
#include <iostream>
#include <stack>
using namespace std;


int getMaxArea(int arr[], int n) {

    stack<int> st;

    int maxArea = 0;


    for(int i=0;i<=n;i++) {

        int current = (i==n)?0:arr[i];


        while(!st.empty() && arr[st.top()] >= current) {


            int height = arr[st.top()];
            st.pop();


            int width;


            if(st.empty())
                width = i;
            else
                width = i - st.top() - 1;


            maxArea = max(maxArea,height*width);
        }


        if(i<n)
            st.push(i);
    }


    return maxArea;
}



int main() {

    int histogram[] = {2,1,5,6,2,3};


    cout<<"Largest Rectangle Area: "
        <<getMaxArea(histogram,6);


    return 0;
}
//2. Largest Rectangle in Binary Matrix (C++)
#include <iostream>
#include <stack>
using namespace std;



int largestRectangleArea(int h[], int n) {


    stack<int> st;

    int ans = 0;


    for(int i=0;i<=n;i++) {


        int current = (i==n)?0:h[i];


        while(!st.empty() && h[st.top()] > current) {


            int height = h[st.top()];
            st.pop();


            int width;


            if(st.empty())
                width=i;
            else
                width=i-st.top()-1;


            ans=max(ans,height*width);
        }


        if(i<n)
            st.push(i);
    }


    return ans;
}



int maxArea(int mat[][5], int n, int m) {


    int h[5]={0};

    int ans=0;



    for(int i=0;i<n;i++) {


        for(int j=0;j<m;j++) {


            if(mat[i][j]==1)
                h[j]++;
            else
                h[j]=0;
        }


        ans=max(ans,largestRectangleArea(h,m));
    }


    return ans;
}



int main() {


    int matrix[4][5]={
        {1,0,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    };


    cout<<"Largest Rectangle in Binary Matrix: "
        <<maxArea(matrix,4,5);


    return 0;
}
//3. Trapping Rain Water (C++)
#include <iostream>
using namespace std;


int trap(int height[], int n) {


    int left=0;
    int right=n-1;


    int leftMax=0;
    int rightMax=0;


    int water=0;



    while(left<right) {


        if(height[left] < height[right]) {


            if(height[left]>=leftMax)
                leftMax=height[left];

            else
                water += leftMax-height[left];


            left++;
        }


        else {


            if(height[right]>=rightMax)
                rightMax=height[right];

            else
                water += rightMax-height[right];


            right--;
        }
    }


    return water;
}



int main() {


    int water[]={
        0,1,0,2,1,0,1,3,2,1,2,1
    };


    cout<<"Trapped Water: "
        <<trap(water,12);


    return 0;
}