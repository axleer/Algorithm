package leet

// ID: 22
// Detail: https://leetcode.com/problems/generate-parentheses
// Recommend: Solution 2

// ---Solution 1---

// When you want to construct a well-formed parentheses
// You will find the last left parentheses's always has a follower, right parentheses
// Then every well-formed parentheses will have a closed '()'
// When you remove it you will find it's well-formed parentheses contains n-1 pairs
// So the solution can be recursion.
// func generateParenthesis(n int) []string {
// 	// handle error input
// 	if n < 1 {
// 		return nil
// 	}
// 	// init recursion, also the recursion condition
// 	if n == 1 {
// 		return []string{"()"}
// 	}
// 	// recursion call
// 	previous := generateParenthesis(n - 1)
// 	results := []string{}
// 	for i := 0; i < len(previous); i++ {
// 		// handle every n-1 results
// 		for j := 0; j < len(previous[i])+1; j++ {
// 			result := previous[i][:j] + "()" + previous[i][j:]
// 			// try to insert the result if not exist
// 			exist := false
// 			for k := 0; k < len(results); k++ {
// 				if result == results[k] {
// 					exist = true
// 					break
// 				}
// 			}
// 			if !exist {
// 				results = append(results, result)
// 			}
// 		}
// 	}
// 	return results
// }

// ---Solution 2---

// This solution was based on leftParenthesesNum >= rightParenthesesNum
// Also use the recursion, but need a helper function
// global result avoid an argument pass in helper, so imporve performance
var result []string

func generateParenthesis(n int) []string {
	// Set to empty, and let GC to clean the previous memory
	result = nil
	helper(n, 0, nil)
	return result
}

func helper(remainLeft, unpaired int, current []byte) {
	if remainLeft == 0 {
		// Handle the rightParenthesis in the end, and then append to result.
		for i := 0; i < unpaired; i++ {
			current = append(current, ')')
		}
		result = append(result, string(current))
		return
	}

	// Consume a leftParenthesis and remainLeft-1, so unpaired+1
	helper(remainLeft-1, unpaired+1, append(current, '('))

	// Unpaired in current position will add an new option.
	if unpaired != 0 {
		helper(remainLeft, unpaired-1, append(current, ')'))
	}
}
