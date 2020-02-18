#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int BFS(TreeNode* root){
        queue<TreeNode*> Array;
        int MAX=1,cur=1,Sum=0;
        Array.push(root);
        while(!Array.empty()){
            int temp=0;
            int count=Array.size();
            for(int i=0;i<count;i++){
                TreeNode * NewTop=Array.front();
                Array.pop();
                if(NewTop->left){
                    Array.push(NewTop->left);
                }
                if(NewTop->right){
                    Array.push(NewTop->right);
                }
                temp+=NewTop->val;
            }
            if(temp>Sum){
                Sum=temp;
                MAX=cur;
            }
            cur++;
        }
        return MAX;
    }
    int maxLevelSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        else{
            return BFS(root);
        }
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().maxLevelSum(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
