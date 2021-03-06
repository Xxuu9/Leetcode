/// Source : https://leetcode.com/problems/count-complete-tree-nodes/
/// Author : liuyubobobo
/// Time   : 2018-08-02
/// Updated: 2020-10-22

#include <iostream>
#include <cassert>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// Recursion
/// Time Complexity: O(h^2) where h is the height of the tree
/// Space Complexity: O(h)
class Solution {

public:
    int countNodes(TreeNode* root) {

        if(root == NULL)
            return 0;

        int left = leftHeight(root);
        int right = rightHeight(root);
        if(left == right)
            return (1 << left) - 1;

//        assert(left == right + 1);
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    int leftHeight(TreeNode* root){
        if(root == NULL)
            return 0;
        return 1 + leftHeight(root->left);
    }

    int rightHeight(TreeNode* root){
        if(root == NULL)
            return 0;
        return 1 + rightHeight(root->right);
    }
};


int main() {

    TreeNode* root = new TreeNode(1);

    TreeNode* left = new TreeNode(2);
    root->left = left;

    TreeNode* right = new TreeNode(3);
    root->right = right;

    TreeNode* leftleft = new TreeNode(4);
    root->left->left = leftleft;

    TreeNode* leftright = new TreeNode(5);
    root->left->right = leftright;

    TreeNode* rightleft = new TreeNode(6);
    root->right->left = rightleft;

    cout << Solution().countNodes(root) << endl;

    return 0;
}