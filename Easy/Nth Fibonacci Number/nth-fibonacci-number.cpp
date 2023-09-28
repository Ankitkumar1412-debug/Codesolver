//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        int a=0;
        int b=1;
        int ans=0;
        if(n==0){
            return a;
        }
        if(n==1 ||n==2){
            return b;
        }
        for(int i=1;i<n;i++){
            ans=(a+b)%1000000007;
            a=b;
            b=ans;
        }
        return ans%1000000007;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends