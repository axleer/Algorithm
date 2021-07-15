package leet

// ID: 24
// Detail: https://leetcode.com/problems/swap-nodes-in-pairs
// Recommend: Solution 1

// ---Solution 1---

// You can solve it by two close pointer and each loop move two steps to do it recursivly.
// And each you need to check id the two steps will out of range.
// Finally add some speical case at the start and provided the exit in the loop.

type ListNode struct {
	Val  int
	Next *ListNode
}

func SwapPairs1(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	behind, front := head, head.Next
	swapedHead := head.Next // return a new pointer
	for {
		if front.Next == nil {
			front.Next = behind
			behind.Next = nil
			break
		} else if front.Next.Next == nil {
			behind.Next = front.Next
			front.Next = behind
			break
		} else {
			behind.Next = front.Next.Next
			finalBehind := front.Next // record the pisition.
			front.Next = behind
			behind = finalBehind
			front = finalBehind.Next
		}
	}
	return swapedHead
}
