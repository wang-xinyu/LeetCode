/**
 * Course Schedule
 * Topological Sort using DFS
 */
class Solution {
private:
    list<int> *adja;
    bool cycleSearch(int v, vector<bool>& locally_visited, vector<bool>& globally_visited) {
        if (globally_visited[v]) return false;
        locally_visited[v] = globally_visited[v] = true;
        for (list<int>::iterator it = adja[v].begin(); it != adja[v].end(); it++) {
            if (locally_visited[*it] || cycleSearch(*it, locally_visited, globally_visited)) return true;
        }
        locally_visited[v] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        adja = new list<int>[numCourses];
        for (auto p : prerequisites) {
            adja[p.first].push_back(p.second);
        }
        vector<bool> locally_visited(numCourses, false), globally_visited(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (cycleSearch(i, locally_visited, globally_visited)) return false;
        }
        return true;
    }
};
