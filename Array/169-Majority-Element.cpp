//Brute-Force
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for (int val : nums) {
            int freq = 0;
            for (int ele : nums) {
                if (ele == val) {
                    freq++;
                }
            }
            if (freq > n / 2) {
                return val;
            }
        }
        return -1;
    }
};

//Middle Index Sorting
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int freq = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                freq++;
                if (freq > n / 2) {
                return nums[i];
            }
            } else {
                freq = 1;
            }
        }
        return nums[0];
    }
};

//Boyer-Moore Voting
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int freq = 0;
        int ans = 0;
        for (int  i = 0; i < n; i++) {
            if (freq == 0) {
                ans = nums[i];
                freq = 1;
            } else if (nums[i] == ans) {
                freq++;
            } else {
                freq--;
            }
        }
        return ans;
    }
};