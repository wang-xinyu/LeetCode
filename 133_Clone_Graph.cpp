/**
 * Clone Graph
 *
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        if (map[node]) return map[node];
        map[node] = new UndirectedGraphNode(node->label);
        for (int i = 0; i < node->neighbors.size(); i++) {
            map[node]->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return map[node];
    }
};
