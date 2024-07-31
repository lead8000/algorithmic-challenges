
class Solution {
private: 
    TreeNode* findLowerNode(TreeNode* currNode, TreeNode* parent) {
        if (currNode->left == nullptr) {
            if (parent) {
                parent->left = currNode->right;
            }
            return currNode;
        }
        return findLowerNode(currNode->left, currNode);
    }

    TreeNode* auxDeleteNode(int key, TreeNode* root, TreeNode* parent) {
        if (!root) return nullptr;

        if (root->val == key) {
            if (root->right != nullptr) {
                auto node = findLowerNode(root->right, nullptr);

                if (parent && parent->left == root) {
                    parent->left = node;
                }
                else if (parent) {
                    parent->right = node;
                }
                if (node != root->right) {
                    node->right = root->right;
                }
                node->left = root->left;

                return node;
            }
            else if (root->left != nullptr) {
                if (parent && parent->left == root) {
                    parent->left = root->left;
                }
                else if (parent) {
                    parent->right = root->left;
                }
                return root->left;
            }
            else {
                if (parent) {
                    if (parent->left == root) {
                        parent->left = nullptr;
                    }
                    else {
                        parent->right = nullptr;
                    }
                } 
                return nullptr;
            }
        }
        else if (root->val > key) {
            return auxDeleteNode(key, root->left, root);
        }
        else {
            return auxDeleteNode(key, root->right, root);
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        auto node = auxDeleteNode(key, root, nullptr);
        if (root->val != key)
            return root;
        return node;
    }
};