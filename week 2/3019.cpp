class Solution {
public:
    int countKeyChanges(string s) {
        int i,ans=0;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout<<s;
        for(i=0;i<s.size()-1;i++)
        {
            if((s[i])!=(s[i+1]))
            {
                ans++;
            }
        }
        return ans;
    }
};