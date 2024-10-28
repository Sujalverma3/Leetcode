class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //         int n = nums.size();
        //         if(n == 0){
        //             return 0;
        //         }
        //         sort(nums.begin(), nums.end());
        //         int currentConsecutiveSequence = 1;
        //         int longestConsecutiveSequence = 0;
        //         for(int i=1; i<n; i++){
        //             if(nums[i] != nums[i-1]){
        //                 if(nums[i] == nums[i-1] + 1){
        //                     currentConsecutiveSequence++;
        //                 }
        //                 else{
        //                     longestConsecutiveSequence =
        //                     max(longestConsecutiveSequence,
        //                     currentConsecutiveSequence);
        //                     currentConsecutiveSequence = 1;
        //                 }
        //             }
        //         }
        //         return max(longestConsecutiveSequence,
        //         currentConsecutiveSequence);

        // unordered_set<int> set;
        // for(int num : nums){
        //     set.insert(num);
        // }
        // int longestConsecutiveSequence = 0;
        // for(int num : nums){
        //     if(set.find(num-1) == set.end()){
        //         int currentNumber = num;
        //         int currentConsecutiveSequence = 1;
        //         while(set.find(currentNumber+1) != set.end()){
        //             currentNumber++;
        //             currentConsecutiveSequence++;
        //         }
        //         longestConsecutiveSequence = max(longestConsecutiveSequence,
        //         currentConsecutiveSequence);
        //     }
        // }
        // return longestConsecutiveSequence;

        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        if (size == 1) {
            return 1;
        }
        sort(nums.begin(), nums.end());

        int act = 1;
        int max = 0;
        int it = 1;
        for (int x : nums) {
            if (x != nums[size - 1]) {
                if (x == (nums[it] - 1)) {
                    act++;
                } else if (x == (nums[it])) {
                } else {
                    if (act > max) {
                        max = act;
                    }
                    act = 1;
                }
            } else {
                if (act > max) {
                    max = act;
                }
            }
            it++;
        }
        return max;

}
}
;