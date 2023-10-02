package leetcode

func WinnerOfGame(colors string) bool {
	alice, bob := 0, 0
	for i := 1; i < len(colors); i++ {
		if i+1 != len(colors) && colors[i-1] == 'A' && colors[i] == 'A' && colors[i+1] == 'A' {
			alice++
		}
		if i+1 != len(colors) && colors[i-1] == 'B' && colors[i] == 'B' && colors[i+1] == 'B' {
			bob++
		}
	}
	return alice > bob
}
