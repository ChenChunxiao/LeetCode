/**
 * Created on: 2014年11月7日
 *      Author: xiaochun
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 */

#include <stdio.h>

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for binary tree
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (NULL == root) {
            return true;
        }
        return check(root->left, root->right);
    }

private:
    bool check(TreeNode *left, TreeNode *right) {
        if (NULL == left && NULL == right) {
            return true;
        }

        if (NULL == left || NULL == right) {
            return false;
        }

        return left->val == right->val && check(left->left, right->right) && check(left->right, right->left);
    }
};
