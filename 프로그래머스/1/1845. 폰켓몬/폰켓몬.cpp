#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    bool cnt[200001] = {false, };
    int kinds = 0;
    for(int num : nums) {
        if(!cnt[num]) kinds++;
        cnt[num] = true;
    }
    
    return min(kinds, (int)nums.size()/2);
}