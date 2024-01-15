#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pr(a) cout << a << endl;


class Solution {
public:
    
    
    void computeLPS(string s, string a, vector<int>& v){
        
        string t = a + "@" + s;
        
        vector<int> LPS(t.size(), 0);
        
        int j = 0;
        
        for (int i = 1; i<t.size(); i++){
            
            while (j > 0 && t[j] != t[i]){
                j = LPS[j-1];
            }
            
            if (t[i] == t[j]){
                ++j;
            }
            
            LPS[i] = j;
            
        }
        
        for (int i = 0; i<LPS.size(); i++){
            if (LPS[i] == a.size()){
                v.push_back(i-2*a.size());
            }
        }
        
      
    }
    
    
    
    
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        
        vector<int> aa, bb;
        
        computeLPS(s, a, aa);
        computeLPS(s, b, bb);
        
        vector<int> ans;
        
        for (int i = 0, j = 0; i<aa.size(); i++){
            while (j<bb.size() && aa[i] > bb[j]  && abs(aa[i] - bb[j]) > k) ++j;
            if (j<bb.size() && abs(aa[i] - bb[j]) <= k) ans.push_back(aa[i]);
        }
        return ans;
    }
};