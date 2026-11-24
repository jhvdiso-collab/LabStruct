package main

import "fmt"

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
