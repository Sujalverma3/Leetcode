class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int st=0,end=nums.size()-1,mid=0;
        while(st<=end){
            mid=st+(end-st)/2;
            if(nums[mid]>tar){
                end=mid-1;
            }
            else if(nums[mid] < tar){
                st=mid+1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};