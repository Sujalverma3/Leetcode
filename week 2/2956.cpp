class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr;
        int n,m,i,j,temp=0,res=0;
        n=nums1.size();
        m=nums2.size();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(nums1[i]==nums2[j])
                {
                    temp++;
                    break;
                }
            }
            if(temp) res++;
            temp=0;
        }
        arr.push_back(res);
        res=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(nums2[i]==nums1[j])
                {
                    temp++;
                    break;
                }
            }
            if(temp) res++;
            temp=0;
        }
        arr.push_back(res);
        return arr;
    }
};