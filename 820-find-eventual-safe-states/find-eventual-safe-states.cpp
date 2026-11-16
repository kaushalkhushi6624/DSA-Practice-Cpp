class Solution {
private :
    bool iscycle(vector<vector<int>> & g, int i, vector<bool> &visit,vector<bool> &in){
        visit[i]=true;
        in[i]=true;
        for(int &v : g[i]){
            if(visit[v]==false && iscycle(g,v,visit,in)){
                return true;
            }else if(in[v]==true){
                return true;
            }
        }
        in[i]=false;
        return false;
    }    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int v=g.size();
        vector<bool> visit(v,false);
        vector<bool> in(v,false);
        for(int i=0 ; i < v ; i++){
            if(!visit[i]){
                iscycle(g,i,visit,in);
            }
        }vector<int> safe;
        for(int i=0 ; i<v ; i++){
            if(in[i]==false){
                safe.push_back(i);
            }
        }
        return safe;
    }
};