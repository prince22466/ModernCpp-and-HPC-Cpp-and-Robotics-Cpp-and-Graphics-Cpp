# Concepts in performance profiling and Processor archetecture(linux perf)

### context switch(OS)
context switch means one cpu core execute instructions for one execution context(physical thread) then switch to another then switch back, and so on.  

### threads(hardware)
hardware threads(aka, physical threads) are execution contexts connected to on CPU core.  

### multi-threads(program)
this is thread written in code. which are arranged by OS, to be distribute programs to physical threads.

### async(program)
essentially it is an event_loop, which loops over tasks to execute to avoid being slowed down by slow progress(such as IO tasks).  
