# Compiler Optimization
[Optimizations in C++ Compilers](https://queue.acm.org/detail.cfm?id=3372264)

To compile source file with different optimizations `-O1`, `-O2` or `-O3`:
```
g++ main.cpp -O3 -o main
```

To generate the assembly code of the source files:

```
g++ -S -fverbose-asm -g -O3 main.cpp -o main.s
```

## `volatile` keyword

The best definition that I found is this one :wink: :

```
volatile tells the compiler that,

    "Hey compiler, I'm volatile and, you know, I can be changed by some XYZ that you're not even aware of. That XYZ could be anything. Maybe some alien outside this planet called program. Maybe some lightning, some form of interrupt, volcanoes, etc can mutate me. Maybe. You never know who is going to change me! So O you ignorant, stop playing an all-knowing god, and don't dare touch the code where I'm present. Okay?"

```
