class Solution {
public:
    int compress(vector<char>& chars) {
        int count, n = chars.size();
        int ind=0;
        for (int i = 0; i < n; i++) {
            count = 0;
            char ch = chars[i];
            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }
            if(count==1) chars[ind++]=ch;
            else{
                chars[ind++]=ch;
                string str=to_string(count);
                for(char dig:str){
                    chars[ind++]=dig;
                }
            }
            i--;
        }
        chars.resize(ind);
        return ind;
    }
};