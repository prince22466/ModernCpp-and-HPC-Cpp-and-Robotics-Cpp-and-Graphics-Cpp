# General Guide for performance(low lantency)

## Profiling
1. assembly code exam
2. profiling profile exam( perf in linux)

## General code guide - explore modern processor architecture
### why modern CPU make insertion faster in std::vector than std::list

early cpu multiple clock cycles per instruction
modern several instructions per cycle on a single core(due to piplining)


cache friendly code cpp means use cache in CPU?
cache of modern process make linear memory access much faster than random access.


modern processer have multiple layers of cache(L1, L2, L3, L4) between register and RAM,

an exmaple of layers of memory size and latency of processor

L1: 32KB, 4cycles
L2: 256 KB, 12cycles
L3: 6M, 20cycles
L4: 128M, 58cycels,
RAM: 8GB, 115 cycels


waterfall logic of accessing memory,
when a memory address is accessed in code, it goes to L1 first, if not found L2, and so on to RAM


Modern processor's prefetching, when a memery address is accessed, nearby 
data is also fetched into catch, that is why sequential(or linear) access is faster than random access

https://lwn.net/Articles/250967/


the by-book algo complexity(time of running) needs to be binded with data locality(how data are spread over memory system affects, such as processor cache,prefetching, L1...->RAM) for real-world performance analysis.


old-time code instruction reorgnization(such as changing the order of code block) for performance optimization is largely being done by modern complier. modoern developer should focus on data access pattern to take advantage of caching of modern processor.

cache unfriendly code:
not using local variable(stack is always 'hot', data is binded closely, use local variable as long as possible)
dynamically allocated objects most of time located in different places in memory, not cache friendly, try make a pool of them.
pointer-based data structures(trees, list) have nodes in differnt places in memory, very bad performance for memory access
runtime dispatch of virtual functions invalidate the instruction cache, very bad for performance



array of structs(objects) vs struct of arrays
struct of arrays could be much faster



boost.geometry, boost.graph, boost.internavl


what is branch instruction

code friendly to branch prediction
