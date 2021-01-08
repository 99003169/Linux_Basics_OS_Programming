# Outline

## How to compile and link
```
gcc test.c -c                        # generates test.o
gcc sum.c -c                         # generates sum.o
gcc sqr.c -c                         # generates sqr.o
gcc test.o sum.o sqr.o -o all.out    # linking, combines several object files & std libs, generates executable
```
> Identify errors when one of the object file is missing during linking

## Analysis
```
nm sum.o sqr.o
objdump -t sum.o sqr.o
nm test.o
objdump -t test.o
```
