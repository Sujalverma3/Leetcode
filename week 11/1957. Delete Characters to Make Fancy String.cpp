// class Solution {
// public:
//     string makeFancyString(string s) {
//         int n = s.size(), count = 0;
//         string ans;
//         if(s.size()<3) 
//         {
//             return s;
//         }
//         for (int i = 0; i < n; i++) {
//             if (s[i] == s[i + 1]) {
//                 count++;
//                 if (count < 2) {
//                     ans+=s[i];
//                 } 
//                 // else {
//                 //     continue;
//                 // }
//             } else {
//                 count=0;
//                 ans+=s[i];
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    string makeFancyString(string s) {
        // Return original string if length is less than 3
        // since we can't have 3 consecutive same characters
        if(s.length() < 3) {
            return s;
        }
        
        // j keeps track of the position where we'll place
        // the next valid character
        int j = 2;
        
        // Iterate through string starting from index 2
        for (int i = 2; i < s.size(); ++i) {
            // Add current character if it's different from
            // either of the two previous characters
            // This prevents three consecutive same characters
            if (s[i] != s[j - 1] || s[i] != s[j - 2]) {
                s[j++] = s[i];
            }
        }
        
        // Resize string to remove any excess characters
        // j represents the new length of the fancy string
        s.resize(j);
        return s;
    }
};