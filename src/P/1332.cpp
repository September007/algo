#ifdef LOCAL
#include<pch.h>
#else
#define TEST(nl,nr) nl##nr()
#define EXPECT_EQ(l,r) 
#endif
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int ans=0,sz=cost.size();
        int i=0;
        while(i<sz/3){
            ans+=cost[3*i]+cost[3*i+1];
            i+=1;
        }
        i*=3;
        while(i<sz)ans+=cost[i++];
        return ans;
    }
};

TEST(sol, base) {
    vector<int> costs = { 1,2,3,4,5,6,7 };
    Solution s;
    s.minimumCost(costs);
}