#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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

// 1. Root to Leaf Paths
class Solution1 {
public:
    void solve(TreeNode* root, vector<int>& curr, vector<vector<int>>& allPaths) {
        if (root == nullptr)
            return;

        curr.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            allPaths.push_back(curr);
        } else {
            solve(root->left, curr, allPaths);
            solve(root->right, curr, allPaths);
        }

        curr.pop_back();
    }

    vector<vector<int>> paths(TreeNode* root) {
        vector<vector<int>> allPaths;
        vector<int> curr;
        solve(root, curr, allPaths);
        return allPaths;
    }
};

// 2. Diameter of Binary Tree
class Solution2 {
public:
    int maxDiameter = 0;

    int calculateHeight(TreeNode* node) {
        if (node == nullptr)
            return 0;

        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);

        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        calculateHeight(root);
        return maxDiameter;
    }
};

// 3. Binary Tree Level Order Traversal
class Solution3 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == nullptr)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> curr;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                curr.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            result.push_back(curr);
        }

        return result;
    }
};

// 4. Vertical Order Traversal
class Solution4 {
public:
    void dfs(TreeNode* root, int row, int col,
             map<int, map<int, multiset<int>>>& nodes) {

        if (root == nullptr)
            return;

        nodes[col][row].insert(root->val);

        dfs(root->left, row + 1, col - 1, nodes);
        dfs(root->right, row + 1, col + 1, nodes);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;

        dfs(root, 0, 0, nodes);

        vector<vector<int>> result;

        for (auto& p : nodes) {
            vector<int> colNodes;

            for (auto& q : p.second) {
                colNodes.insert(colNodes.end(),
                                q.second.begin(), q.second.end());
            }

            result.push_back(colNodes);
        }

        return result;
    }
};

int main() {

    // Create sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 1. Root to Leaf Paths
    cout << "1. Root to Leaf Paths:\n";
    Solution1 sol1;
    vector<vector<int>> paths = sol1.paths(root);

    for (auto &path : paths) {
        for (int x : path)
            cout << x << " ";
        cout << endl;
    }

    // 2. Diameter of Binary Tree
    cout << "\n2. Diameter of Binary Tree:\n";
    Solution2 sol2;
    cout << "Diameter: " << sol2.diameterOfBinaryTree(root) << endl;

    // 3. Level Order Traversal
    cout << "\n3. Level Order Traversal:\n";
    Solution3 sol3;
    vector<vector<int>> levels = sol3.levelOrder(root);

    for (auto &level : levels) {
        for (int x : level)
            cout << x << " ";
        cout << endl;
    }

    // 4. Vertical Order Traversal
    cout << "\n4. Vertical Order Traversal:\n";
    Solution4 sol4;
    vector<vector<int>> vertical = sol4.verticalTraversal(root);

    for (auto &col : vertical) {
        for (int x : col)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}