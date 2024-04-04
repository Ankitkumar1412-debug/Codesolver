//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long getVol(int A, int B) {
        // code here
        long long a = (long double)A, b = (long double)B;
       
       long double side = ((a*a)-(24.0*b));
       long double l = (a-sqrt(side))/12.0;
       
       long double ans = ((b/2.0)*l)-((a/4.0)*(l*l))+(l*l*l);
       long long int k = floor(ans);
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int A,B;
        
        cin>>A>>B;

        Solution ob;
        cout << ob.getVol(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends