#include <iostream>
#include <vector>
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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return{};
        return buildTrees(1,n);
    }

private:
    vector<TreeNode*> buildTrees(int start,int end){
        vector<TreeNode*> trees;
        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        for(int i = start; i<=end;++i){
            vector<TreeNode*> leftTrees = buildTrees(start,i-1);
            vector<TreeNode*> rightTrees = buildTrees(i+1,end);

            for(auto left: leftTrees){
                for(auto right: rightTrees){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
};

// Preorder print of a tree
void printTree(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Solution sol;
    int n = 3;
    vector<TreeNode*> result = sol.generateTrees(n);

    cout << "Total unique BSTs with " << n << " nodes: " << result.size() << endl;

    for (int i = 0; i < result.size(); ++i) {
        cout << "Tree " << i + 1 << ": ";
        printTree(result[i]);
        cout << endl;
    }

    return 0;
}