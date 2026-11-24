package main

import "fmt"

type Stack struct{ top *Link }

func (s *Stack) Push(v string) { s.top = &Link{value: v, next: s.top} }
func (s *Stack) Peek() (string, error) {
	if s.top == nil {
		return "", fmt.Errorf("empty stack")
	}
	return s.top.value, nil
}
func (s *Stack) Pop() (string, error) {
	v, e := s.Peek()
	if e == nil {
		s.top = s.top.next
	}
	return v, e
}

