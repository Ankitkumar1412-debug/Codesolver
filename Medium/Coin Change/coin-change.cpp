//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        long long t[N+1][sum+1];
        int i,j;
        for(i=0;i<N+1;i++){
            for(j=0;j<sum+1;j++){
                if(i==0)
                t[i][j]=0;
                if(j==0)
                t[i][j]=1;
            }
        }
        for(i=1;i<N+1;i++){
            for(j=1;j<sum+1;j++){
                if(coins[i-1]<=j){
                    t[i][j]=t[i-1][j]+t[i][j-coins[i-1]];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[N][sum];
        // code here.
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends