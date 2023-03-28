class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs, int cost = 0) {
      queue<pair<int, int>> last_seven, last_thirty;
      for (auto d : days) {
        while (!last_seven.empty() && last_seven.front().first + 7 <= d) last_seven.pop();
        while (!last_thirty.empty() && last_thirty.front().first + 30 <= d) last_thirty.pop();
        last_seven.push({ d, cost + costs[1] });
        last_thirty.push({ d, cost + costs[2] });
        cost = min({ cost + costs[0], last_seven.front().second, last_thirty.front().second });
      }
      return cost;
    }
};