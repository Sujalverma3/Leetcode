class Solution {
public:
    int maximumSwap(int num) {

        string nums = to_string(num);//convert num to character arr
        int maxidx = -1, swap = -1, swap1 = -1;//-1 index means does not exist
        int i = 0, n = nums.size();
        for (i = n - 1; i >= 0; i--) {
            if (maxidx == -1 || nums[i] > nums[maxidx]) {
                maxidx = i;                                          //maxelement index
            } else if (nums[i] < nums[maxidx]) {    //all possible swaps
                swap = i;
                swap1 = maxidx;
            }
        }
        if (swap != -1 && swap1 != -1) {
            int temp;
            temp = nums[swap];
            nums[swap] = nums[swap1];
            nums[swap1] = temp;
        }
        return stoi(nums);
    }
};