#!/bin/bash
: '
Finds the occurance of first matching character of substring in string
'
STRING="This is a string"
SUBSTRING="find"
expr index "$STRING" "$SUBSTRING"