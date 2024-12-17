// class Solution {
// public:
//     string reverseWords(string s) {
//         int n = s.size();
//         string res = "";
//         int i = n - 1;

//         while (i >= 0) {
//             // Skip trailing spaces
//             while (i >= 0 && s[i] == ' ')
//                 i--;
//             if (i < 0)
//                 break;

//             string word = "";
//             // Build the word
//             while (i >= 0 && s[i] != ' ') {
//                 word.push_back(s[i]);
//                 i--;
//             }

//             // Reverse the word and add to result
//             reverse(word.begin(), word.end());
//             if (!res.empty())
//                 res.append(" ");
//             res.append(word);
//         }

//         return res;
//     }
// };
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n=s.size();
        int left=0;
        int right=0;
        int i=0;
        while(i<n){
            while(i<n && s[i]==' ')i++;
            if(i==n)break; 
            while(i<n && s[i]!=' '){
                s[right++]=s[i++];
            }
            reverse(s.begin()+left,s.begin()+right);
            s[right++]=' ';
            left=right;
            i++;
        }
        s.resize(right-1);
        return s;
    }
};