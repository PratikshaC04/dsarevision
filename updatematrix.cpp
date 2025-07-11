class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m =mat[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                     q.push({i,{j,0}});
                     vis[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            auto it =q.front();
            q.pop();
            int i=it.first;
            int j=it.second.first;
            int dis=it.second.second;
            int x[4]={-1,1,0,0};
            int y[4]={0,0,-1,1};
            for(int k=0;k<4;k++){
                int newx=x[k]+i;
                int newy=y[k]+j;
                if(newx>=0 && newy>=0 && newx<n && newy<m && mat[newx][newy]==1 && vis[newx][newy]==false){
                    ans[newx][newy]=dis+1;
                    q.push({newx,{newy,dis+1}});
                    vis[newx][newy]=true;
                }
            }
    }
    return ans;
    }
};