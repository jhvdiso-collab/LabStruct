package main

import "testing"

func TestStringListCommands(t *testing.T) {
	for _, prefix := range []string{"F", "L"} {
		db := Database{}
		for _, tc := range [][2]string{
			{"PUSH x beta", "beta"}, {"PUSHFRONT x alpha", "alpha"},
			{"PUSHBACK x delta", "delta"}, {"PUSHBEFORE x delta gamma", "gamma"},
			{"PUSHAFTER x alpha extra", "extra"}, {"GET x 1", "extra"},
			{"FIND x gamma", "3"}, {"DELBEFORE x beta", "extra"},
			{"DELAFTER x beta", "gamma"}, {"GETFRONT x", "alpha"},
			{"GETBACK x", "delta"}, {"REVERSE x", "[delta beta alpha]"},
			{"DELVAL x beta", "TRUE"}, {"DELFRONT x", "alpha"},
			{"DELBACK x", "delta"}, {"LEN x", "0"},
		} {
			out, _, err := db.Execute(prefix + tc[0])
			if err != nil || out != tc[1] { t.Fatalf("%s%s: %q %v", prefix, tc[0], out, err) }
		}
		for _, op := range []string{"GET x nope", "DELBEFORE x missing", "DELAFTER x missing", "PUSHBEFORE x missing value"} {
			if _, _, err := db.Execute(prefix + op); err == nil { t.Fatal(op) }
		}
	}
}
func TestStringArrayAndIndex(t *testing.T) {
	db := Database{}
	for _, q := range []string{"MPUSH a hello", "MINSERT a 0 world", "MSET a 1 text"} {
		if _, _, err := db.Execute(q); err != nil { t.Fatal(err) }
	}
	if out, _, err := db.Execute("PRINT a"); err != nil || out != "[world text]" { t.Fatal(out, err) }
	if _, _, err := db.Execute("MGET a nope"); err == nil { t.Fatal("invalid index accepted") }
}
