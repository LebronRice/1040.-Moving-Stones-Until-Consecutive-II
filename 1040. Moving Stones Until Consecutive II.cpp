class Solution {
public:
	vector<int> numMovesStonesII(vector<int>& nums) {
		const int n = nums.size();
		sort(nums.begin(), nums.end());
		int min_moves = n;
		int start = 0;
		int count = 0;
		for (int end = 0; end < n; ++end) {
			++count;
			while (nums[end] - nums[start] + 1 > n) {
				++start;
				--count;
			}
			if (count == n - 1 && nums[end] - nums[start] + 1 == n - 1) // edge case: need 2 moves to move end point
				min_moves = min(min_moves, 2);
			else
				min_moves = min(min_moves, n - count);
		}
		int holes = nums[n - 2] - nums[1] + 1 - (n - 2);    // holes between nums[1] and nums[n - 2]
		int max_moves = max(nums[n - 1] - nums[n - 2] - 1, nums[1] - nums[0] - 1) + holes;
		return { min_moves, max_moves };
	}
};