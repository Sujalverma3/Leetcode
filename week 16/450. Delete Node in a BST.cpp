// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//  * right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if (root) {
//             if (key < root->val)
//                 root->left = deleteNode(root->left, key);
//             else if (key > root->val)
//                 root->right = deleteNode(root->right, key);
//             else {
//                 if (root->left == NULL && root->right == NULL)
//                     return NULL;
//                 if (root->left == NULL || root->right == NULL) {
//                     return root->left ? root->left : root->right;
//                 }
//                 TreeNode* temp = root->left;
//                 while (temp->right != NULL) {
//                     temp = temp->right;
//                 }
//                 root->val = temp->val;
//                 root->left = deleteNode(root->left, temp->val);
//             }
//         }
//         return root;
//     }
// };
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = nullptr;
        TreeNode* delete_target = root; // the node to delete
        // Find the node to delete
        while (delete_target && delete_target->val != key) {
            parent = delete_target;
            if (key < delete_target->val)
                delete_target = delete_target->left;
            else
                delete_target = delete_target->right;
        }
        if (delete_target) {
            // Build the node that should replace the delete_target
            TreeNode* replacement =
                mergeTrees(delete_target->left, delete_target->right);
            // Replace the delete_target in the parent, is any 
            if (parent) {
                replace(parent, delete_target, replacement);
            } else // No parent: replace the deleted the root.
                root = replacement;
        }
        return root;
    }
    TreeNode* mergeTrees(TreeNode* left, TreeNode* right) {
        if (!left)
            return right; // BUG missed this
        if (!right)
            return left; // BUG missed this
        TreeNode* r = right;
        while (r && r->left)
            r = r->left;
        r->left = left;
        return right;
    }
    void replace(TreeNode* root, TreeNode* child, TreeNode* new_child) {
        if (root->left == child)
            root->left = new_child;
        else {
            assert(root->right == child);
            root->right = new_child;
        }
    }
};