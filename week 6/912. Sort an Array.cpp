//SELECTION SORT O(N2)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int index = i;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[index]) {
                    index = j;
                }
            }
            swap(nums[i], nums[index]);
        }
        return nums;
    }
};

//BUBBLE SORT O(N2)
// selection Sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            int f = 0;
            for (int j = 0; j <= i; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    f = 1;
                }
            }
            if (f==0) {
                break;
            }
        }
        return nums;
    }
};

//INSERTION SORT O()
// selection Sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i <n; i++) {
            for (int j = i; j >0; j--) {
                if (nums[j] < nums[j - 1]) {
                    swap(nums[j], nums[j - 1]);
                }
                else
                {
                    break;
                }
            }

        }
        return nums;
    }
};
//MERGE SORT O(nlogn)
class Solution {
public:
    vector<int> sortArray(vector<int>& a) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int big = a[0];
        int small = a[0];
        for (int i : a) {
            big = max(big, i);
            small = min(small, i);
        }
        vector<int> b(big - small + 1);
        for (int i : a)
            b[i - small]++;
        int index = 0;
        for (int i = 0; i < b.size(); i++) {

            for (int j = 0; j < b[i]; j++) {
                a[index++] = i + small;
            }
        }
        return a;
    }
};