/* https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/789/
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        int treeHeight = getTreeHeight(root);
        int heightLevel = 0;
        int counter = 0;
        
        Node* nodetoWrite = NULL;
        
        for (int i = 0; i < treeHeight; ++i) {
            nodetoWrite = NULL;
            writeNextPtr(root, i, nodetoWrite);
        }
        
        return root;
    }
    
    int getTreeHeight(Node* node) {
        if (node == NULL) {
            return 0;
        } else {
            int l = getTreeHeight(node->left);
            int r = getTreeHeight(node->right);
            if (l > r) {
                return l+1;
            } else {
                return r+1;
            }
        }
    }
    
    void writeNextPtr(Node* node, int traversalLevel, Node* &nextNodeToWrite) {      
        if (node == NULL) {
            return;
        }
        
        if (traversalLevel == 0) {
            // std::cout << node->val << " ";
            node->next = nextNodeToWrite;
            nextNodeToWrite = node;
        } else {
            writeNextPtr(node->right, traversalLevel - 1, nextNodeToWrite);
            writeNextPtr(node->left, traversalLevel - 1, nextNodeToWrite);
        }
    }
};
