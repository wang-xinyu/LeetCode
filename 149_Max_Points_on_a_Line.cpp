/**
 * Max Points on a Line
 * 
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int ans= 0, n = points.size();
        for (int i = 0; i < n; i++) {
            int samePoint = 1;
            map<pair<int, int>, int> map;
            for (int j = i+1; j < n; j++) {
                int dx = points[i].x - points[j].x;
                int dy = points[i].y - points[j].y;
                if (dx == 0 && dy == 0) {
                    samePoint++;
                } else {
                    int _gcd = gcd(dy, dx);
                    map[make_pair(dy/_gcd, dx/_gcd)]++;
                }
            }
            int maxPoints = 0;
            for (auto it = map.begin(); it != map.end(); it++) {
                maxPoints = max(maxPoints, it->second);
            }
            maxPoints += samePoint;
            ans = max(ans, maxPoints);
        }
        return ans;
    }
private:
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a%b);
    }
};
