class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>alphabet(26,0);
        for(int i=0;i<sentence.size();i++)
        {
            alphabet[sentence[i]-'a']=1;
        }
        for(bool x:alphabet)
        {
            if(x==0) return false;
        }
        return true;
    }
};