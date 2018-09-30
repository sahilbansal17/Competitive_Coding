package main

import (
	"code.google.com/p/go-tour/tree"
	"fmt"
)

//type Tree struct {
//    Left  *Tree
//    Value int
//    Right *Tree
//}

// Walk walks the tree t sending all values
// from the tree to the channel ch.
func Walk(t *tree.Tree, ch chan int) {
	walkTree(t, ch)
	close(ch)
}

func walkTree(t *tree.Tree, ch chan int) {
	if t.Left != nil {
		walkTree(t.Left, ch)
	}
	ch <- t.Value
	if t.Right != nil {
		walkTree(t.Right, ch)
	}
}

// Same determines whether the trees
// t1 and t2 contain the same values.
func Same(t1, t2 *tree.Tree) bool {
	ch1, ch2 := make(chan int), make(chan int)
	go Walk(t1, ch1)
	go Walk(t2, ch2)
	for i := range ch1 {
		if i != <-ch2 {
			return false
		}
	}
	return true
}

func main() {
	ch := make(chan int)
	go Walk(tree.New(1), ch)
	for i := range ch {
		fmt.Println(i)
	}
	fmt.Println("Should return true:", Same(tree.New(1), tree.New(1)))
	fmt.Println("Should return false:", Same(tree.New(1), tree.New(2)))
}
