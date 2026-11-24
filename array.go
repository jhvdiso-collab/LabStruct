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

