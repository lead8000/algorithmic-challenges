package leetcode

import "fmt"

func LongestSubarray(nums []int) int {
	max_and, max_len := nums[0], 1
	continous_subarray := 1

	for i := 0; i < len(nums); i++ {
		if nums[i] > max_and {
			max_and = nums[i]
			max_len = 1
		}
		if i != 0 && nums[i-1] == nums[i] {
			continous_subarray++
		} else {
			continous_subarray = 1
		}
		if continous_subarray > max_len && nums[i] == max_and {
			max_len = continous_subarray
		}
	}
	fmt.Println(max_and)
	return max_len
}
