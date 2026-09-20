class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int m=nums.size();
        vector<int> v(m + 1, 0);

        int c=0;
        for(int i=0;i<m;i++){
            int n=nums[i];
            if(v[n]==0){
                v[n]=1;
            }else{
                 c=nums[i];
            }
        }return c;


    }
};