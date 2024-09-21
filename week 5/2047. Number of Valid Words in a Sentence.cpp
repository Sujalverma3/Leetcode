class Solution {
private:
    bool validateChar(char c) {
        return (c>='a' and c<='z') ? true : false;
    }
    bool validateSymbol(int i,string &s) {
        if(s[i]==',' or s[i]=='!' or s[i]=='.') 
            return (s[i+1]=='\0' or s[i+1]==' ') ? true : false;
        if(s[i]=='-') 
            return (i > 0 and i+1 < s.size() and validateChar(s[i-1]) and validateChar(s[i+1])) ? true : false;
        return false;
    }
public:
    int countValidWords(string sentence) {
        int i = 0;
        int n = sentence.size();
        int validWords = 0;
        while(i < n) {
            if(sentence[i]== ' ') {
                i++;
                continue;
            }
            int hypenCnt = 0;
            int punctuationCnt = 0;
            int isValid = 1;
            while(i < n and sentence[i] != ' ') {
                if(sentence[i] == '-') hypenCnt++;
                if(!validateChar(sentence[i]) and !validateSymbol(i,sentence)) 
                    isValid = 0;
                i++;
            }
            if(isValid and hypenCnt <= 1) validWords++;
        }
        return validWords;
    }
};