/**
 * Course Schedule II
 * Topological Sort using DFS
 */
class Solution {
private:
    list<int> *adja;
    bool dfs(int v, vector<bool>& locally_visited, vector<bool>& globally_visited, vector<int>& ans) {
        if (globally_visited[v]) return false;
        locally_visited[v] = globally_visited[v] = true;
        for (list<int>::iterator it = adja[v].begin(); it != adja[v].end(); it++) {
            if (locally_visited[*it] || dfs(*it, locally_visited, globally_visited, ans)) return true;
        }
        locally_visited[v] = false;
        ans.insert(ans.begin(), v);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        adja = new list<int>[numCourses];
        vector<int> ans;
        vector<bool> locally_visited(numCourses ,false), globally_visited(numCourses ,false);
        for (auto p : prerequisites) {
            adja[p.second].push_back(p.first);
        }
        for (int i = 0; i < numCourses; i++) {
            if (dfs(i, locally_visited, globally_visited, ans)) return vector<int>();
        }
        return ans;
    }
};
