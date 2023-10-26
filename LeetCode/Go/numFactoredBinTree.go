package leetcode

import (
	"sort"
)

func NumFactoredBinaryTrees(arr []int) int {
	sort.Ints(arr)
	amount_ways := 0

	dp := make(map[int]int)

	for _, i := range arr {
		dp[i] = 1

		for _, j := range arr {
			if j*j > i {
				break
			}
			if i%j == 0 && dp[i/j] != 0 {
				if j*j == i {
					dp[i] += dp[j] * dp[j]
				} else {
					dp[i] += 2 * dp[j] * dp[i/j]
				}
			}
		}

		amount_ways += dp[i]
	}

	return amount_ways % 1000000007
}

func NumFactoredBinaryTrees2(arr []int) int {
	sort.Ints(arr)
	amount_ways := 0

	memo := make(map[int]int)

	for _, num := range arr {
		amount_ways += memoization(num, arr, memo)
	}

	return amount_ways % (1000000007)
}

func memoization(num int, arr []int, memo map[int]int) int {
	if memo[num] != 0 {
		return memo[num]
	}

	amount_ways := 0
	div := make(map[int]bool)

	for _, v := range arr {
		if v == num {
			amount_ways++
			break
		}
		if num%v == 0 {
			if v*v == num {
				amount_ways += memoization(v, arr, memo) * memoization(v, arr, memo)
				continue
			}
			div[num/v] = true
		}
		if div[v] {
			amount_ways_1 := memoization(v, arr, memo)
			amount_ways_2 := memoization(num/v, arr, memo)
			amount_ways += 2 * amount_ways_1 * amount_ways_2
		}
	}

	memo[num] = amount_ways
	return memo[num]
}
