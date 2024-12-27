// class Solution {
// public:
//     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//         for (int i = 0; i < flowerbed.size(); i++) {
//             bool left = i == 0 || flowerbed[i - 1] == 0;
//             bool right = i == flowerbed.size() - 1 || flowerbed[i + 1] == 0;
            
//             if (left && right && flowerbed[i] == 0) {
//                 flowerbed[i] = 1;
//                 n--;
//             }
//         }
//         return n <= 0;        
//     }
// };
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        int i = 0;
        while (i < len && n > 0) {
            if (flowerbed[i] == 1) {
                i += 2;  // Skip the next spot since we can't plant adjacent to a flower
            } else if (i == len - 1 || flowerbed[i + 1] == 0) {
                // We can plant a flower if we're at the last spot or the next spot is empty
                n--;
                i += 2;  // Move two positions forward since we just planted
            } else {
                i += 3;  // Skip to the next valid empty spot if the next one is not available
            }
        }
        return n <= 0;  // Return true if we managed to plant all n flowers, false otherwise
    }
};