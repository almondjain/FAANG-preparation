class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i,n=nums.size();
        vector<vector<int>> res={};
        sort(nums.begin(),nums.end());
        
        for(i=0;i<n-1;i++)
        {
            int a=nums[i];
            int l=i+1;
            int h=n-1;
            while(l<h)
            {
                int x=a+nums[l]+nums[h];
                if(x==0)
                {
                    res.push_back({a,nums[l],nums[h]});
                    l++;
                    h--;
                }
                else if(x<0)
                    l++;
                else
                    h--;
            }
        }
        
        return res;
    }
};