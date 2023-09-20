//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        int left,right,mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(a[i]==x){
                left=i;
            }
            if(a[i]==y){
                right=i;
            }
            mini=min(abs(left-right),mini);
        }
        if(mini>n){
            return -1;
        }
        else{
            return mini;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends