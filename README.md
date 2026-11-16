# Round-Robin CPU Scheduling
Exploring Round-Robin CPU Scheduling through a C simulation and presentation

## Overview

This project explores Round-Robin CPU Scheduling, a preemptive scheduling algorithm that distributes CPU time among ready processes using a fixed time quantum.

I explored how Round-Robin works, how the time quantum affects responsiveness, and why context switching creates overhead. I also looked at limitations such as scheduling urgent tasks and wrote a small C simulation to better understand the algorithm.

## Key Concepts

- **CPU Scheduling:** Determines which ready process or thread runs on the CPU next.
- **Time Quantum:** The maximum CPU time a process receives before the scheduler can move to another ready process.
- **Ready Queue:** Contains tasks that are ready to execute but are waiting for CPU time.
- **Context Switching:** Saves and restores execution state when the CPU changes between tasks.

## C Simulation

The simulation models three processes with CPU burst times of 5 ms, 3 ms, and 1 ms. All processes arrive at time 0.

The default time quantum is 2 ms.

### Compile

```bash
gcc -Wall -Wextra -std=c11 round_robin.c -o round_robin
```

### Run

```bash
./round_robin
```

To experiment with a different time quantum:

```bash
./round_robin 5
```

The program prints the order in which processes execute and how much CPU time each process has remaining.

## What I Learned

One important discovery was that a smaller time quantum does not automatically mean better scheduling. It can allow processes to receive CPU time more frequently, but it may also increase context-switching overhead.

I also learned that basic Round-Robin does not account for urgent deadlines, which can make it unsuitable for certain real-time tasks.

## Limitations of the Simulation

This is a simplified model rather than an operating-system scheduler. It assumes one CPU core, processes arriving simultaneously, and no I/O blocking or context-switching overhead.

## Project Files

- `src/round_robin.c` — C simulation
- `presentation/` — Presentation slides
- `sample_output/` — Sample program output
