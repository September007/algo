#ifdef LOCAL
#include<pch.h>
#else
#define TEST(nl,nr) nl##nr()
#define EXPECT_EQ(l,r) 
#endif

#undef max
class Solution
{
public:
    //从前往后一趟遍历
    int Linear(vector<int> &nums)
    {
        int sz = nums.size(), cnt = 0, ans = INT_MIN;
        for (int i = 0; i < sz; ++i)
        {
            cnt = max(nums[i], cnt + nums[i]);
            ans = max(ans, cnt);
        }
        return ans;
    }
    //分治
    //子问题解
    struct status
    {
        int lsum, rsum, msum, asum;
    } ;
    //合并子问题解
    status PushUp(status l, status r)
    {
        return {
            max(l.lsum, l.asum + r.lsum),
            max(r.rsum, r.asum + l.rsum),
            max<int>({l.msum, r.msum, l.rsum + r.lsum}),
            l.asum + r.asum};
    }
    //domain l,r means [l,r)
    status GetStatus(vector<int>&nums,int l,int r){
        if(l>r-2)return {nums[l],nums[l],nums[l],nums[l]};
        return PushUp(GetStatus(nums,l,(r-l+1)/2+l),GetStatus(nums,(r-l+1)/2+l,r));
    }
    int maxSubArray(vector<int> &nums)
    {
       // return Linear(nums);
       
       return GetStatus(nums,0,nums.size()).msum;
    }
};