# continous-mem-mgnt-simulator
Simulates the allocation and dealloaction of continous memory.

## Usage:
```
Strategy (best-fit, worst-fit, first-fit)? best-fit
Allocations number? 2

Enter allocations / deallocations:

1 0 2
Allocating 2 for process 0

========
|      |
| P0 2 |
|      |
========

0 0
Deallocating 0

==========
|        |
| Free 2 |
|        |
==========
```

**Allocation command:**
```
1 process_index memory
```

**Deallocation**
```
0 process_index
```
