//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // code here
        int ans=-1;
        if(n<3||m<3){
            return ans;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(i-1>=0 && i+1<n && j-1>=0 && j+1<m){
                    int temp=mat[i][j]+mat[i-1][j-1]+mat[i-1][j]+mat[i-1][j+1]+mat[i+1][j-1]+mat[i+1][j]+mat[i+1][j+1];
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends