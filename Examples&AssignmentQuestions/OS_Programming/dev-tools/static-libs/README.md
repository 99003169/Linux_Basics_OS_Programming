# Outline

## Hands-on Steps
```
gcc sum.c -c
gcc sqr.c -c
ar rc libsimple.a sum.o sqr.o

gcc test.c -c
gcc -L. test.o -o s1.out -lsimple
gcc -L. test.o -o s2.out -lsimple -static
```

## Discussion
* Concept of static libs & linking
* Advantages & Disadvantages with static linking
* Need for -L, -l options
* What's the difference between s1.out, s2.out
* Should we distribute libsimple.a along with executable

## Analysis
```
file libsimple.a
nm libsimple.a
objdump -d libsimple.a   # -t

file s1.out s2.out
ls -lh s1.out s2.out
size s1.out s2.out
ldd s1.out
ldd s2.out

strip s2.out
ls -lh s2.out
size s2.out
```

> Write a Makefile for above steps of creating static lib & linking


