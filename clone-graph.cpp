/*
// https://leetcode.com/problems/clone-graph
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        unordered_map<int, Node*> visited;
        Node* head = new Node;
        head->val = node->val;
        DfsHelper(node, visited, head);

        return head;
    }
    
    void DfsHelper(Node* node, unordered_map<int, Node*>& visited, Node* out) {       
        // if this node has not been visited, flag this as visited
        if (visited.find(node->val) == visited.end()) {
            visited[node->val] = out;
        }
        
        for (int i = 0; i < node->neighbors.size(); ++i) {
            if (visited.find(node->neighbors[i]->val) == visited.end()) {
                Node* new_neighbor = new Node;
                new_neighbor->val = node->neighbors[i]->val;
                out->neighbors.push_back(new_neighbor);
                DfsHelper(node->neighbors[i], visited, out->neighbors[i]);
            } else {
                out->neighbors.push_back(visited[node->neighbors[i]->val]);
            }
        }
        
    }
};
