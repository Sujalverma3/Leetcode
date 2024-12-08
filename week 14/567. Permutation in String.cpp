// class Solution {
// public:
//     bool solve(string s,string s1){
//         sort(s.begin(),s.end());
//         sort(s1.begin(),s1.end());
//         return s==s1;
//     }
//     bool checkInclusion(string s1, string s2) {
//         int n1=s1.size(),n2=s2.size();
//         if(n1>n2) return 0;
//         int i=0;
//         while(i<=n2-n1){
//             string s=s2.substr(i,s1.size());
//             if(solve(s,s1)) return 1;
//             i++;
//         }
//         return 0;
//     }
// };

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        if (n1 > n2) {
            return false;
        }
        
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        
        for (char c : s1) {
            count1[c - 'a']++;
        }
        
        for (int i = 0; i < n2; i++) {
            count2[s2[i] - 'a']++;
            if (i >= n1) {
                count2[s2[i - n1] - 'a']--;
            }
            
            if (count1 == count2) {
                return true;
            }
        }
        
        return false;
    }
};