# Outline

## Building a simple program, phase wise
```
gcc hello.c -E          # stop with preprocess, actual tool is cpp        
# cpp hello.c           # observe preprocessed code (transformed)
gcc hello.c -c          # compile only (no link), hello.o generated
gcc hello.o -o h.out    # link with std libs, startup code
```

## Sections of a C/C++ Process

Refer [code](layout-demo.c) for this, dump symbol table using these steps

```
gcc layout-demo.c -c -o demo.o
nm demo.o
objdump -t demo.o
```
> observe symbol states like D,C/B,T,R, d,b,t,r
> What is the meaning of these symbol states in nm/objdump output?

## More GNU Tools, gcc/g++ options
```
gcc hello.c   -S            # generate assebly code
gcc hello.s -c -o hello.o   # assemble the code
as hello.s -o hello.o       # assemble the code
gcc hello.o -o h.out        # link, generate executable

file hello.o                # check file type
file h.out                  # check file type
nm hello.o                  # symbol table
objdump -t hello.o          # symbol table
objdump -d hello.o          # disassemble the code
readelf -h hello.o          # header analysis, decode magic number
readelf -h h.out            # header analysis
size hello.o                # section wise footprint    
size h.out                  # section wise footprint
```


