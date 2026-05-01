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
    void dfs(Node* node, unordered_map<Node*, Node*>& mp){
        // if(node==nullptr) return nullptr;

        // 1. node already pressent in map
         for(Node* n: node->neighbors){
            if(mp.find(n)==mp.end()){
                Node* clone = new Node(n->val);
                mp[n] = clone;
                mp[node]->neighbors.push_back(mp[n]);
            
                dfs(n, mp);
            }
            else{
                mp[node]->neighbors.push_back(mp[n]);
            }
         }
    }

    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;

        Node* clone_node = new Node(node->val);

        unordered_map<Node*, Node*> mp;

        mp[node] = clone_node;

        dfs(node, mp);

        return clone_node;
    }
};
