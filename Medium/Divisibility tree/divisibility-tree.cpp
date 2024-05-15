//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int dfs(vector<int>* adj,int node,int parent,int& ans)
    {
        int cnt=1;
        for(auto& it:adj[node])
        {
            if(it!=parent)
            {
                int cntNode=dfs(adj,it,node,ans);
                if(cntNode%2==0)
                ans++;
                else
                cnt++;
            }
        }
        return cnt;
    }
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> adj[n+1];
	    for(auto& it:edges)
	    {
	        adj[it[0]].push_back(it[1]);
	        adj[it[1]].push_back(it[0]);
	    }
	    
	    int ans=0;
	    dfs(adj,1,-1,ans);
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends