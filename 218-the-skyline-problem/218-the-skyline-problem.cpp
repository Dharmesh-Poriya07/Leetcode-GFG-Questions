class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        int cur=0, cur_X, cur_H =-1,  len = buildings.size();
        priority_queue< pair<int, int>> liveBlg;
        while(cur<len || !liveBlg.empty())
        { 
            cur_X = liveBlg.empty()? buildings[cur][0]:liveBlg.top().second;

            if(cur>=len || buildings[cur][0] > cur_X)
            { 
                while(!liveBlg.empty() && ( liveBlg.top().second <= cur_X) ) liveBlg.pop();
            }
            else
            { 
                cur_X = buildings[cur][0];
                while(cur<len && buildings[cur][0]== cur_X)  
                {  
                    liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            }
            cur_H = liveBlg.empty()?0:liveBlg.top().first; 
            if(ans.empty() || (ans.back()[1] != cur_H) ) ans.push_back({cur_X, cur_H});
        }
        return ans;
    }
};