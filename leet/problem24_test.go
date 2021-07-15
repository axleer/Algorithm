package leet_test

import (
	"testing"

	"github.com/hidstarshine/Algorithm/leet"
)

var TDBenchmarkSwapPairs1 *leet.ListNode

func FTDBenchmarkSwapPairs1() {
	TDBenchmarkSwapPairs1 = &leet.ListNode{
		Val:  0,
		Next: nil,
	}
	changeNode := TDBenchmarkSwapPairs1
	for i := 1; i < 100; i++ {
		changeNode.Next = &leet.ListNode{
			Val:  i,
			Next: nil,
		}
		changeNode = changeNode.Next
	}
}

func BenchmarkSwapPairs1(b *testing.B) {
	FTDBenchmarkSwapPairs1()
	for i := 0; i < b.N; i++ {
		leet.SwapPairs1(TDBenchmarkSwapPairs1)
	}
}
