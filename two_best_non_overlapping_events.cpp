// https://leetcode.com/problems/two-best-non-overlapping-events/
// Input: events = [[1,3,2],[4,5,2],[2,4,3]]
// Output: 4
// Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.

class Solution
{
public:
  int maxTwoEvents(vector<vector<int>> &events)
  {
    sort(events.begin(), events.end());
    int mxVal = 0, res = 0;
    priority_queue<pair<int, int>> pq;
    for (auto &e : events)
    {
      for (; !pq.empty() && -pq.top().first < e[0]; pq.pop())
      {
        mxVal = max(mxVal, pq.top().second);
      }
      res = max(res, mxVal + e[2]);
      pq.push({-e[1], e[2]});
    }
    return res;
  }
};
