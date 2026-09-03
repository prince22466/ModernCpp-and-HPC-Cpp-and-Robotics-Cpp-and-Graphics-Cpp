# General Guide for modern CPU performance(low latency)

## methods of Profiling
1. assembly code exam
2. performance profile exam( perf in Linux ), perf record + perf report, perf report can show assembly code.

## General code guide - explore modern processor architecture
### memory access pattern in modern processor shows why modern CPU make insertion faster in std::vector than std::list
good reference: https://lwn.net/Articles/250967/

early cpu multiple clock cycles per instruction
modern several instructions per cycle on a single core(due to piplining)

cache of modern process make linear memory access much faster than random access.

modern processer have multiple layers of cache(L1, L2, L3, L4) between register and RAM,

an exmaple of layers of memory size and latency of processor

L1: 32KB, 4cycles

L2: 256 KB, 12cycles

L3: 6M, 20cycles

L4: 128M, 58cycels,

RAM: 8GB, 115 cycels

waterfall logic of accessing memory,


Modern processor's prefetching, when a memery address is accessed, nearby data is also fetched into catch, that is why sequential(or linear) access is faster than random access.


### why by-book algo complexity doesnt work in real life.
data locality(variables spread over different locations in memory, cache line prefetching, etc) is missed.


### modern complier optimize code automatically
old-time code instruction reorgnization(such as changing the order of code block) for performance optimization is largely being done by modern complier. 
modoern developer should focus on data access pattern to take advantage of caching of modern processor.
key words, atomic, volatile can avoid complier optimization.

### cache unfriendly/friendly code to notice(or avoid)
not using local variable(stack is always 'hot', data is binded closely, use local variable as much as possible).

dynamically allocated objects most of time located in different places in memory, not cache friendly, try *make a pool of them*.

pointer-based data structures(trees, list) have nodes in differnt places in memory, very bad performance for memory access.

runtime dispatch of virtual functions invalidate the instruction cache, very bad(generally) for performance. It could have  something to do with indirect-branching and could easily impact performance due to data locality problem.

integer division, multiplication, modulus are generally slow on x86.

use && and || for condition operations.

use reserve() for vector (if applicable, if the size can be known), it can avoid further memory reallocation.

use const (if applicable), especially for non-primitive data types. 


### array of structs(objects) vs struct of arrays
struct of arrays could be much faster


### use highly optimized libs such as boost
boost.geometry, boost.graph, boost.internavl


### branch prediction friendly code
modern CPU do branching which triggers speculative execution, speculative execution is like hardware level async
in the code below,  
if(cond1):  
  A()  
else:  
  B()  


The CPU then speculatively executes instructions from A(), becasue it predicts A() will be excuted, while the instructions required to resolve cond1 are still in flight. If finally it turns out, cond1 == True, then it saves time because A() is already calucated(or already being calculated), if  it turns out, cond1 == False, then it needs to do B().
so, hot loops/paths which are **more predictable by CPU**, will lower latency.
branches + branch-misses in perf is used to check the its impact on performance.
