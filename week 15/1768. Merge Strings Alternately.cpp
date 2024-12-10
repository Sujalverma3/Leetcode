class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string alter="";
        int i=0;
        while(i<word1.size() || i<word2.size()){
            if(i<word1.size()){
                alter+=word1[i];
            }
            if(i<word2.size()){
                alter+=word2[i];
            }
            i++;
        }
        return alter;
    }
};