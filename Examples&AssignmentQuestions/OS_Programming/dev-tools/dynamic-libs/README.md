# Outline

## Hands-on Steps
```
gcc sum.c -c
gcc sqr.c -c
gcc -shared -o libsample.so sum.o sqr.o

gcc test.c -c
gcc -L. test.o -o d1.out -lsample
LD_LIBRARY_PATH=. ./d1.out
```

## Discussion
* Concept of dynamic libs & linking
* Advantages & Disadvantages with dynamic linking
* Need for -L, -l options
* Alternate ways of running d1.out, e.g. export
* How d1.out is different from s1.out, s2.out
* Should we distribute libsample.so along with executable
* How to link if `libsample.so` is in a diff dir, say `~/dlibs`
  ```
  gcc -shared -o ~/dlibs/libsample.so sum.o sqr.o
  #TODO: link with libsample.so in ~/dlibs
  #TODO: execute d1.out
  ```
* Usage of `ldconfig`, `/etc/ld.so.conf` 

## Analysis
```
file libsample.so
nm libsimple.so
objdump -so libsimple.a   # -t

file d1.out
ls -lh d1.out
size d1.out
ldd d1.out
```

## Versioning of shared object files
```
gcc -shared -Wl,-soname,libsample.so -o ~/dlibs/libsample.so.1.0.1 sum.o sqr.o
ldconfig -n ~/dlibs
```
> Write a Makefile for above steps of creating shared lib & linking

