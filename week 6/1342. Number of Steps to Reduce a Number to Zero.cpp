class Solution {
public:
    int numberOfSteps(int nums) {
        int step = 0;
        while (nums) {
            if (nums % 2 == 0) 
                nums /= 2;
            else 
                nums--;
            step++;
        }
        return step;
    }
};