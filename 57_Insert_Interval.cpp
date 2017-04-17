/**
 * Insert Interval
 *
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int pos = 0, n = intervals.size();
        while (pos < n && (newInterval.start > intervals[pos].start)) pos++;
        intervals.insert(intervals.begin() + pos, newInterval);
        vector<Interval> res;
        if (pos == 0) res.push_back(intervals[pos++]);
        else res.assign(intervals.begin(), intervals.begin() + pos);
        for (int i = pos; i <= n; i++) {
            if (res.back().end >= intervals[i].start) res.back().end = max(res.back().end, intervals[i].end);
            else res.push_back(intervals[i]);
        }
        return res;
    }
};
