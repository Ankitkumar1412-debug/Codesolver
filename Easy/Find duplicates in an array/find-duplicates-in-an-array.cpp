//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        map<int,int> mp;
        vector<int> vec;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto x : mp){
            if(x.second>1){
                vec.push_back(x.first);
            }
        }
        if(vec.empty()){
           vec.push_back(-1);
           return vec;
        }
        else
        return vec;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends