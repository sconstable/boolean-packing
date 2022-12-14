# boolean-packing
tricks to pack booleans into ints in C

some friends and I were talking about how to pack booleans into C data types 
more efficiently.  See, in C they use `int` to store the truthiness or 
falsiness of a boolean expression.  This means that, naively, you need
`n * sizeof(int)` to store n boolean values.

You can view an `int` as 32 individual bits, and to truly represent a boolean 
which can only have 2 values you only need a single bit.  Therefore, with 
some work you can compress up to 32 boolean values into a single int!

I have taken this a step further and modeled the boolean packing using 
prime numbers.  The prime factorization of every number is unique, so by 
using a constant reference array of the prime numbers, you can store 
boolean values by measuring the divisibility by each prime number.  Note that 
the "information density" (or something) is quite loose compared to the 
binary case.  While the binary can store 32 independent booleans, the prime 
scheme is best suited for "large sparse" bundles of binaries - i.e. we want to
choose from a large set of possible values but only a handful of booleans can 
be switched on at the same time.  If you set too many at the same time, you 
will get an integer overflow.
