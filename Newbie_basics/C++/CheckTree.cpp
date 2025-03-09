/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}//这个构造函数将节点的值初始化为 0，左子节点和右子节点都设置为 nullptr，即节点没有子节点。
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}//这个构造函数将节点的值初始化为 x，左子节点和右子节点都设置为 nullptr。
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}//这个构造函数除了初始化节点的值外，还初始化左右子节点。left 和 right 是指向二叉树左右子节点的指针。
};
class Solution {
public:
    bool checkTree(TreeNode* root) {
        return root->val == root->left->val + root->right->val;
    }
};

main(int argc, char const *argv[])
{
    Solution solution;
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    cout << solution.checkTree(root) << endl;
    return 0;
}

