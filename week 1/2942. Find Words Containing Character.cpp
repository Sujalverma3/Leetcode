class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int l=words.size();
        vector<int>arr;
        char y,k=0;
        for(int i=0;i<l;i++)
        {
            string s=words[i];
            for(char y:s)
            {
                if(y==x)
                {
                    arr.push_back(i);
                    break;
                }
            }
        }
        return arr;
       
    }
};