/*
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
        unordered_map<Node*, Node*>p;
        return dfs(node, p);
    }
    Node* dfs(Node*node, unordered_map<Node*, Node*>&p){
        if(node==nullptr)return nullptr;
        if(p.count(node))return p[node];
        Node*copy=new Node(node->val);
        p[node]=copy;
        for(Node*nei:node->neighbors){
            copy->neighbors.push_back(dfs(nei, p));
        }
        return copy;
    }
};