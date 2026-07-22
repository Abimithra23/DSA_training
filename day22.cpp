#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Pair {
public:
    TreeNode* node;
    int hd;

    Pair(TreeNode* n, int h) {
        node = n;
        hd = h;
    }
};

// 1. Top View of Binary Tree
class Solution1 {
public:
    vector<int> topView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        map<int, int> topNodeMap;
        queue<Pair> q;
        q.push(Pair(root, 0));

        while (!q.empty()) {
            Pair temp = q.front();
            q.pop();

            if (topNodeMap.find(temp.hd) == topNodeMap.end())
                topNodeMap[temp.hd] = temp.node->val;

            if (temp.node->left)
                q.push(Pair(temp.node->left, temp.hd - 1));
            if (temp.node->right)
                q.push(Pair(temp.node->right, temp.hd + 1));
        }

        for (auto x : topNodeMap)
            result.push_back(x.second);

        return result;
    }
};

// 2. Bottom View of Binary Tree
class Solution2 {
public:
    vector<int> bottomView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        map<int, int> bottomNodes;
        queue<Pair> q;
        q.push(Pair(root, 0));

        while (!q.empty()) {
            Pair temp = q.front();
            q.pop();

            bottomNodes[temp.hd] = temp.node->val;

            if (temp.node->left)
                q.push(Pair(temp.node->left, temp.hd - 1));
            if (temp.node->right)
                q.push(Pair(temp.node->right, temp.hd + 1));
        }

        for (auto x : bottomNodes)
            res.push_back(x.second);

        return res;
    }
};

// 3. Left View of Binary Tree
class Solution3 {
public:
    void helper(TreeNode* root, int level, vector<int>& res) {
        if (!root) return;

        if (res.size() == level)
            res.push_back(root->val);

        helper(root->left, level + 1, res);
        helper(root->right, level + 1, res);
    }

    vector<int> leftView(TreeNode* root) {
        vector<int> res;
        helper(root, 0, res);
        return res;
    }
};

// 4. Right View of Binary Tree
class Solution4 {
public:
    vector<int> rightView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (i == sz - 1)
                    result.push_back(curr->val);

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }

        return result;
    }
};

// 5. Insert into BST
class Solution5 {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);

        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);

        return root;
    }
};

// 6. Search in BST
class Solution6 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val)
            return root;

        if (val < root->val)
            return searchBST(root->left, val);

        return searchBST(root->right, val);
    }
};

// 7. Delete Node in BST
class Solution7 {
public:
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* curr = node;
        while (curr && curr->left)
            curr = curr->left;
        return curr;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;

        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};

// 8. Convert Sorted Array to BST
class Solution8 {
public:
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
};

int main() {

    // Sample BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution1 s1;
    Solution2 s2;
    Solution3 s3;
    Solution4 s4;
    Solution5 s5;
    Solution6 s6;
    Solution7 s7;
    Solution8 s8;

    cout << "1. Top View:\n";
    for (int x : s1.topView(root))
        cout << x << " ";
    cout << endl;

    cout << "\n2. Bottom View:\n";
    for (int x : s2.bottomView(root))
        cout << x << " ";
    cout << endl;

    cout << "\n3. Left View:\n";
    for (int x : s3.leftView(root))
        cout << x << " ";
    cout << endl;

    cout << "\n4. Right View:\n";
    for (int x : s4.rightView(root))
        cout << x << " ";
    cout << endl;

    cout << "\n5. Insert into BST:\n";
    TreeNode* bst = nullptr;
    bst = s5.insertIntoBST(bst, 4);
    bst = s5.insertIntoBST(bst, 2);
    bst = s5.insertIntoBST(bst, 6);
    bst = s5.insertIntoBST(bst, 1);
    bst = s5.insertIntoBST(bst, 3);
    cout << "BST created.\n";

    cout << "\n6. Search in BST:\n";
    cout << (s6.searchBST(root, 3) ? "Found 3" : "Not Found") << endl;
    cout << (s6.searchBST(root, 10) ? "Found 10" : "Not Found") << endl;

    cout << "\n7. Delete Node 2:\n";
    root = s7.deleteNode(root, 2);
    cout << "Node deleted.\n";

    cout << "\n8. Sorted Array to BST:\n";
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* bst2 = s8.sortedArrayToBST(nums);
    cout << "BST created from sorted array.\n";

    return 0;
}