//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int n=S.length();
        
        int start=0;
        for(int i=0;i<n;i++)
        {
            if(S[i]=='.')
            {
                reverse(S.begin()+start,S.begin()+i);
                start=i+1;
            }
        }
        reverse(S.begin()+start,S.end());
        reverse(S.begin(),S.end());
        return S;
        
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends