class Solution {
private:
    int direction(vector<int> pi,vector<int> pj,vector<int> pk){
        return ((pj[0]-pi[0])*(pk[1]-pi[1]))-((pj[1]-pi[1])*(pk[0]-pi[0]));
    }
    vector<vector<int>> convexHull(vector<vector<int>> points){
        int n = points.size();
        if(3>=n)
            return points;
        
        sort(points.begin(),points.end());
        
        vector<vector<int>> lchpoints;
        lchpoints.push_back(points[0]);
        lchpoints.push_back(points[1]);
    
        for(int i=2;i<n;i++){
            int chsz = lchpoints.size();
            while(2<=lchpoints.size() and 0<direction(lchpoints[chsz-2],lchpoints[chsz-1],points[i])){
                lchpoints.pop_back();
                chsz--;
            }
            lchpoints.push_back(points[i]);
        }
    
        vector<vector<int>> rchpoints;
        rchpoints.push_back(points[n-1]);
        rchpoints.push_back(points[n-2]);
        for(int i=n-3;0<=i;i--){
            int chsz = rchpoints.size();
            while(2<=rchpoints.size() and 0<direction(rchpoints[chsz-2],rchpoints[chsz-1],points[i])){
                rchpoints.pop_back();
                chsz--;
            }
            rchpoints.push_back(points[i]);
        }
        for(auto &rp : rchpoints)
            lchpoints.push_back(rp);
        sort(lchpoints.begin(),lchpoints.end());
        lchpoints.erase(std::unique(lchpoints.begin(),lchpoints.end()),lchpoints.end());
        return lchpoints;
    }
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        return convexHull(trees);
    }
};