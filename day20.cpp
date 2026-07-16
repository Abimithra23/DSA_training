#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

// Inorder Traversal
void solveInOrder(TreeNode* root, vector<int>& ans) {
    if (root == nullptr) return;
    solveInOrder(root->left, ans);
    ans.push_back(root->val);
    solveInOrder(root->right, ans);
}

vector<int> inOrder(TreeNode* root) {
    vector<int> ans;
    solveInOrder(root, ans);
    return ans;
}

// Preorder Traversal
void solvePreOrder(TreeNode* root, vector<int>& ans) {
    if (root == nullptr) return;
    ans.push_back(root->val);
    solvePreOrder(root->left, ans);
    solvePreOrder(root->right, ans);
}

vector<int> preOrder(TreeNode* root) {
    vector<int> ans;
    solvePreOrder(root, ans);
    return ans;
}

// Postorder Traversal
void solvePostOrder(TreeNode* root, vector<int>& ans) {
    if (root == nullptr) return;
    solvePostOrder(root->left, ans);
    solvePostOrder(root->right, ans);
    ans.push_back(root->val);
}

vector<int> postOrder(TreeNode* root) {
    vector<int> ans;
    solvePostOrder(root, ans);
    return ans;
}

// Maximum Depth
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// Balanced Tree
int checkHeight(TreeNode* root) {
    if (root == nullptr) return 0;

    int left = checkHeight(root->left);
    if (left == -1) return -1;

    int right = checkHeight(root->right);
    if (right == -1) return -1;

    if (abs(left - right) > 1) return -1;

    return max(left, right) + 1;
}

bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}

// Count Nodes in Complete Binary Tree
int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;

    int leftHeight = 0, rightHeight = 0;

    TreeNode* l = root;
    while (l) {
        leftHeight++;
        l = l->left;
    }

    TreeNode* r = root;
    while (r) {
        rightHeight++;
        r = r->right;
    }

    if (leftHeight == rightHeight)
        return (1 << leftHeight) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Path Sum
bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;

    if (root->left == nullptr && root->right == nullptr)
        return targetSum == root->val;

    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}

// Same Tree
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;

    if (p == nullptr || q == nullptr || p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

// Print Vector
void printVector(vector<int> v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Inorder: ";
    printVector(inOrder(root));
    cout << endl;

    cout << "Preorder: ";
    printVector(preOrder(root));
    cout << endl;

    cout << "Postorder: ";
    printVector(postOrder(root));
    cout << endl;

    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Balanced: " << (isBalanced(root) ? "true" : "false") << endl;
    cout << "Node Count: " << countNodes(root) << endl;
    cout << "Path Sum 12: " << (hasPathSum(root, 12) ? "true" : "false") << endl;

    TreeNode* same1 = new TreeNode(1);
    same1->left = new TreeNode(2);

    TreeNode* same2 = new TreeNode(1);
    same2->left = new TreeNode(2);

    cout << "Same Tree: " << (isSameTree(same1, same2) ? "true" : "false") << endl;

    return 0;
}