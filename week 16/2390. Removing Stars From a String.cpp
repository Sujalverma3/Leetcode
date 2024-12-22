// class Solution {
// public:
//     string removeStars(string s) {
//         stack<char> st;
//         string res = "";
//         for (auto ch : s) {
//             if (ch == '*') {
//                 st.pop();
//             } else {
//                 st.push(ch);
//             }
//         }
//         while (!st.empty()) {
//             res = st.top()+res;
//             st.pop();
//         }
//         return res;
//     }
// };
// class Solution {
// public:
//     string removeStars(string s) {
//         stack<char> stk;

//         for(int i=0;i<s.size();i++){
//             char cur = s[i];
//             if(cur == '*'){
//                 stk.pop();
//             }else{
//                 stk.push(cur);
//             }
//         }
//         string ans = "";
//         while(!stk.empty()){
//             ans += stk.top();
//             stk.pop();
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };
// class Solution {
// public:
//     string removeStars(string s) {
//         int index = 0;
//         for (int i = 0; i < s.size(); ++i){
//             if (s[i] == '*') --index;
//             else s[index++] = s[i];
//         }
//         s.resize(index);
//         return s;
//     }
// };
class Solution {
public:
    string removeStars(string s) {
        string res = "";
        for (char ch : s) {
            if (ch == '*') {
                res.pop_back(); // Removes the last character
            } else {
                res.push_back(ch); // Appends the character to the string
            }
        }
        return res;
    }
};
