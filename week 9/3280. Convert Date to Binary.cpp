class Solution {
    string convert(int num)
    {
        string s;
        while(num)
        {
            s+= to_string(num%2);
            num /= 2;
        }
        reverse(s.begin(), s.end());

        return s;
    }
public:
    string convertDateToBinary(string date) {
        string ans;
        string temp;
        for(auto c: date)
        {
            if(c == '-')
            {
                if(!ans.empty()) ans += '-';
                ans += convert(stoi(temp));
                temp = "";
            }
            else
                temp += c;
        }
        ans += '-';
        ans += convert(stoi(temp));
        return ans;
    }
};