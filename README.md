# Energy-efficient-computing

## Schedule (Draft Version 15-May-2023)
---
### Day 1  - June 15 (start 11:00 end 17:00)
- (11:00-12:00) Course introduction [Sagar Dolas SURF]
    - Define goals of course ... What is energy efficiency? 
    - Overview of data center energy usage/footprint
    - What is Power, Energy, and DVFS (maybe Ana could help here)?
- (12:00-13:00) Lunch
- (13:00-13:45) Introduction/refresher on system architecture [Prof. Ana Lucia Varbanescu UvA/UTwente]
    - What is a CPU? (Intro to multi core CPUs and modern cluster architecture)
    - What is a GPU? (Intro to General purpose GPUs)
- (13:45-14:30) Introduction/refresher on characteristics of applications [Xavier Álvarez Farré SURF (Online)]
    - Compute/Memory Bound, Heterogeneous, Parallel
    - Saxpy
    - SGEMM
- (14:30-15:00) Coffee Break & Tech-Setup
- (15:00-17:00) [Monitoring tools/techniques tutorial](monitoring/README.md): Introduction to tools that can be used to monitor CPU performance and energy consumption [Benjamin Czaja SURF]
    - Likwid
    - AMD-uProf
    - PMT


### Day 2  - June 16 (start 10:00 end 17:00)

- Define energy efficiency and ways to improve energy efficiency (algorithms, scheduling, DVFS) [Sagar]
- Hands-on #2: DVFS by hand (using tools and system-calls and self-defined policies for reducing/increasing frequency) [Ben + Ana]
- Introduce KernelTuner as a solution automate DVFS at kernel/node level, with user-intervention [Alessio]
- Introduce EAR as a solution for improving the energy efficiency of large-scale applications [Ben]
- Hands-on #3 and #4: work with KernelTuner and EAR, choice given to the participants using a couple of pre-defined applications and/or their own applications [Marco(L) + Ben + Alessio]

---