package main

import "fmt"

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


// Relative operations use the first matching value, never an index.
func (l *List) InsertRelative(target, value string, after bool) error {
	i := l.Find(target)
	if i < 0 { return fmt.Errorf("element not found") }
	if after { i++ }
	return l.Insert(i, value)
}
func (l *List) DeleteRelative(target string, after bool) (string, error) {
	i := l.Find(target)
	if i < 0 { return "", fmt.Errorf("element not found") }
	if after { i++ } else { i-- }
	return l.Delete(i)
}
