package main

import "fmt"

type Array struct {
	data []string
	size int
}

func (a *Array) Push(v string) {
	if a.size == len(a.data) {
		capacity := len(a.data) * 2
		if capacity == 0 {
			capacity = 1
		}
		data := make([]string, capacity)
		copy(data, a.data[:a.size])
		a.data = data
	}
	a.data[a.size] = v
	a.size++
}
func (a *Array) Get(i int) (string, error) {
	if i < 0 || i >= a.size {
		return "", fmt.Errorf("array index out of range")
	}
	return a.data[i], nil
}
func (a *Array) Insert(i int, v string) error {
	if i < 0 || i > a.size {
		return fmt.Errorf("array index out of range")
	}
	a.Push(v)
	copy(a.data[i+1:a.size], a.data[i:a.size-1])
	a.data[i] = v
	return nil
}
func (a *Array) Delete(i int) (string, error) {
	v, e := a.Get(i)
	if e != nil {
		return "", e
	}
	copy(a.data[i:a.size-1], a.data[i+1:a.size])
	a.size--
	return v, nil
}
func (a *Array) Set(i int, v string) error {
	if _, e := a.Get(i); e != nil {
		return e
	}
	a.data[i] = v
	return nil
}

type Link struct {
	value      string 
	next, prev *Link
}
type List struct {
	head, tail *Link
	doubly     bool
}

func (l *List) At(i int) (*Link, error) {
	if i < 0 {
		return nil, fmt.Errorf("list index out of range")
	}
	p := l.head
	for ; p != nil && i > 0; i-- {
		p = p.next
	}
	if p == nil {
		return nil, fmt.Errorf("list index out of range")
	}
	return p, nil
}
func (l *List) Len() int {
	n := 0
	for p := l.head; p != nil; p = p.next {
		n++
	}
	return n
}
func (l *List) Find(v string) int { 
	i := 0
	for p := l.head; p != nil; p = p.next {
		if p.value == v {
			return i
		}
		i++
	}
	return -1
}
func (l *List) PushBack(v string) {
	node := &Link{value: v}
	if l.head == nil {
		l.head = node
	} else {
		last := l.tail
		if !l.doubly {
			last = l.head
			for last.next != nil {
				last = last.next
			}
		}
		last.next = node
		if l.doubly {
			node.prev = last
		}
	}
	l.tail = node
}
func (l *List) Insert(i int, v string) error {
	if i == 0 {
		node := &Link{value: v, next: l.head}
		if l.head != nil && l.doubly {
			l.head.prev = node
		}
		if l.head == nil {
			l.tail = node
		}
		l.head = node
		return nil
	}
	prev, e := l.At(i - 1)
	if e != nil {
		return e
	}
	node := &Link{value: v, next: prev.next}
	if l.doubly {
		node.prev = prev
		if node.next != nil {
			node.next.prev = node
		}
	}
	prev.next = node
	if node.next == nil {
		l.tail = node
	}
	return nil
}
func (l *List) Delete(i int) (string, error) {
	if i < 0 {
		return "", fmt.Errorf("list index out of range")
	}
	var prev *Link
	node := l.head
	if i > 0 {
		var e error
		prev, e = l.At(i - 1)
		if e != nil {
			return "", e
		}
		node = prev.next
	}
	if node == nil {
		return "", fmt.Errorf("list index out of range")
	}
	if prev == nil {
		l.head = node.next
	} else {
		prev.next = node.next
	}
	if node.next == nil {
		l.tail = prev
	} else if l.doubly {
		node.next.prev = prev
	}
	return node.value, nil
}
func (l *List) PopBack() (string, error) {
	if !l.doubly {
		return l.Delete(l.Len() - 1)
	}
	if l.tail == nil {
		return "", fmt.Errorf("empty list")
	}
	node := l.tail
	l.tail = node.prev
	if l.tail == nil {
		l.head = nil
	} else {
		l.tail.next = nil
	}
	return node.value, nil
}
func (l *List) Values(reverse bool) []string {
	out := []string{}
	if reverse && l.doubly {
		for p := l.tail; p != nil; p = p.prev {
			out = append(out, p.value)
		}
		return out
	}
	for p := l.head; p != nil; p = p.next {
		out = append(out, p.value)
	}
	if reverse {
		for i, j := 0, len(out)-1; i < j; i, j = i+1, j-1 {
			out[i], out[j] = out[j], out[i]
		}
	}
	return out
}

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

type Queue struct{ head, tail *Link }

func (q *Queue) Push(v string) {
	p := &Link{value: v}
	if q.tail == nil {
		q.head = p
	} else {
		q.tail.next = p
	}
	q.tail = p
}
func (q *Queue) Peek() (string, error) {
	if q.head == nil {
		return "", fmt.Errorf("empty queue")
	}
	return q.head.value, nil
}
func (q *Queue) Pop() (string, error) {
	v, e := q.Peek()
	if e == nil {
		q.head = q.head.next
		if q.head == nil {
			q.tail = nil
		}
	}
	return v, e
}
