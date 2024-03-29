//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    //Kosajaru's algorithm
    private:
    void dfs(int node, vector<bool> &vis, stack<int> &st, vector<int> adj[])
    {
        vis[node]=true;
        for(int neigh: adj[node]) {
            if(!vis[neigh]) 
            dfs(neigh,vis,st,adj);
        }
        st.push(node);
    }
    
    void check(int node, vector<bool> &vis, int &cnt, vector<int> adj[])
    {
        vis[node]=true;
        cnt++;
        for(int neigh: adj[node]) {
            if(!vis[neigh]) 
            check(neigh,vis,cnt,adj);
        }
    }
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool> vis(V,false);
	    stack<int> st;
	    int cnt=0;
	    
	     for(int i=0; i<V; i++) {
	        if(!vis[i]) dfs(i,vis,st,adj);
	    }
	    
	     for(int i=0; i<V; i++)    
	     vis[i]=false;
	     
	    check(st.top(),vis,cnt,adj);
	   
	    if(cnt==V)  
	    return st.top();
	    return -1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends