class Solution {
private:
    void dfs(int node, vector<int> adjlst[] , vector<int> &vis){
        vis[node]=1;
        for(auto it : adjlst[node]){
            if(!vis[it]){
                dfs(it,adjlst,vis);
            }
        }
    }    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<int> adjlst[n];
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(isConnected[i][j]==1&& i!=j){
                    adjlst[j].push_back(i);
                    adjlst[i].push_back(j);
                }
            }
        }
        vector<int> vis(n,0);
        int c=0;
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                c++;
                dfs(i,adjlst,vis);
            }
        }
        return c;
    }
};