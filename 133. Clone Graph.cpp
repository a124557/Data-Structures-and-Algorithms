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

class Solution
{
    unordered_map<Node *, Node *> visited;

public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;
        if (visited.count(node))
            return visited[node];

        visited[node] = new Node(node->val, {});
        for (auto neighbor : node->neighbors)
        {
            visited[node]->neighbors.push_back(cloneGraph(neighbor));
        }

        return visited[node];
    }
};