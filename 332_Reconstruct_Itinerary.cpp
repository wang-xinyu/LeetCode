/**
 * Reconstruct Itinerary 
 *
 * Trick: reversely visiting the airports
 */
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> map;
        vector<string> route;
        for (auto p : tickets) {
            map[p.first].push(p.second);
        }
        visit(route, map, "JFK");
        return vector<string>(route.rbegin(), route.rend());
    }
private:
    void visit(vector<string> &route, unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &map, string airport) {
        while (!map[airport].empty()) {
            string next = map[airport].top();
            map[airport].pop();
            visit(route, map, next);
        }
        route.push_back(airport);
    }
};
