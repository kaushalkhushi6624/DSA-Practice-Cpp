class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> mpp;

        for (int num : nums) {
            if (num % 2 == 0) {
                mpp[num]++;
            }
        }

        if (mpp.empty()) return -1;

        int maxFreq = 0;
        int ans = INT_MAX;

        for (auto &it : mpp) {
            int num = it.first;
            int freq = it.second;

            if (freq > maxFreq) {
                maxFreq = freq;
                ans = num;
            }
            else if (freq == maxFreq) {
                ans = min(ans, num);
            }
        }

        return ans;
    }
};