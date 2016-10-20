# named-code
A unit allows you quickly translate between code values and string names. It is much readable to dump code names in logs rather than the code values, in the same time it's an advange to allow code names to be accepted rather than code values in cofiguration files or command lines etc.

## Usage
Just include nc.h, and define the list of codes, and define the named code by using DEFINE_NAMEDCODE

Check examples in test.cc

## Test
```
g++ -std=c++11 test.cc && ./a.out
all good.
```
