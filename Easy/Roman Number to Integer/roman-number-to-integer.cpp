//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char, int> mp;
        mp['I'] =1;
        mp['V'] =5;
        mp['X'] =10;
        mp['L'] =50;
        mp['C'] =100;
        mp['D'] =500;
        mp['M'] =1000;
        int max = mp[str[str.length()-1]];
        int ans = 0;
        for(int i =str.length()-1;i>=0; i--){
            int num =mp[str[i]];
            if(num>=max){
                ans = num+ans;
                max = num;
            }
            else 
                ans -= num;
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
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends