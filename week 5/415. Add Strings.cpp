 class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        if(num1=="0")
        {
            return num2;
        }
        else if(num2=="0")
        {
            return num1;
        }
        else
        {
            int l1=num1.size()-1;
            int l2=num2.size()-1;
            int carry=0,i=0,sum=0;
            while(l1 >= 0 || l2 >= 0 || carry)
            {
                sum=carry;
                if(l1>=0)
                {
                    sum+=num1[l1--]-'0';
                }
                if(l2>=0)
                {
                    sum+=num2[l2--]-'0';
                }
                int rem=sum%10;
                carry=sum/10;
                ans.push_back(rem+'0');
            }
            
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};