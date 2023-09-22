//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        long long sum = accumulate(arr,arr+N,0);
        if(sum&1){
            return 0;
        }
        vector<long long> dp(sum+1,0);
        dp[0]=1;
        for(int i=0;i<N;i++){
            for(int j=sum;j>=arr[i];j--){
                dp[j] = dp[j]|dp[j-arr[i]];
                
                
            }
        }
        return dp[sum/2];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends