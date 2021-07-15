package leet_test

import (
	"testing"

	"github.com/hidstarshine/Algorithm/leet"
)

func BenchmarkGenerateParenthesis1(b *testing.B) {
	for i := 0; i < b.N; i++ {
		leet.GenerateParenthesis1(8)
	}
}

func BenchmarkGenerateParenthesis2(b *testing.B) {
	for i := 0; i < b.N; i++ {
		leet.GenerateParenthesis2(8)
	}
}
