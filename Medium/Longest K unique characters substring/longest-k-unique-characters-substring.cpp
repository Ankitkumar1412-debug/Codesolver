//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    vector<int> vec(26,0);
    int n=s.length();
    int i=0,c=0,j=0;
    int ans=-1;
    
    while(j<n){
        vec[s[j]-'a']++;
        if(vec[s[j]-'a']==1)
        c++;
        
        while(i<j && c>k){
            vec[s[i]-'a']--;
            if(vec[s[i]-'a']==0)
            c--;
            i++;
        }
        if(c==k){
            ans=max(ans,j-i+1);
        }
        j++;
    }
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends