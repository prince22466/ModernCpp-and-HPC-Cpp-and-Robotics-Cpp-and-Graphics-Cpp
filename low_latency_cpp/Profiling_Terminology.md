# Concepts in performance profiling and Processor archetecture(linux perf)

### context switch
context switch means one cpu core execute instructions for one execution context(physical thread) then switch to another then switch back, and so on.  

### threads(hardware)
hardware threads(aka, physical threads) are execution contexts connected to on CPU core.  

### multi-threads(program)
this is thread written in code. which are arranged by OS, to be distributed to physical threads.

### async(program)
