class Solution {
public:
    int sum(int num1, int num2) {
        // Base case: if num2 is 0, return num1 (no carry left)
        if (num2 == 0)
            return num1;

        // Recursive step: XOR num1 and num2 to get the sum without considering
        // carry, and left shift the bitwise AND of num1 and num2 by 1 to
        // calculate the carry. Then, recursively call sum with the new sum and
        // carry.
        return sum(num1 ^ num2, (num1 & num2) << 1);
    }
};
