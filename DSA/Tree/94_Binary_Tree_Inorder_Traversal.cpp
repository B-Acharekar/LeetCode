#include <iostream>
#include <vector>
#include <stack>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            stack<TreeNode*> stack;
            TreeNode* current = root;

            while(current || !stack.empty()){
                while(current){
                    stack.push(current);
                    current = current->left;
                }
                current = stack.top();
                stack.pop();
                result.push_back(current->val);
                current = current->right;
            }
            return result;
        }
    };

int main() {
    // Creating the tree: [1,null,2,3]
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}