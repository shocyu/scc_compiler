#!/bin/bash

assert(){
  expected="$1"
  input="$2"

  ./scc "$input" > tmp.s
  gcc -o tmp tmp.s
  ./tmp
  actual="$?"

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual, test succeed!"
  else
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

assert 21 '5+20-4'

echo OK
