#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
       int i=0;//left
       int j;//right
       string res;
        for(int i = 0;i<s.length();i++)
        {
            if(((int)s[i] > 64 && (int)s[i] < 91) || ((int)s[i] > 96 && (int)s[i] < 123) || ((int)s[i] > 47 && (int)s[i] < 58))
            {
                res += tolower(s[i]);
            }
        }
        s=res;
        j=s.length()-1;
       while(i<j)
       {
        if(s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
       }
       return true;
    }
};