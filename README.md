# Energy efficient computing

## Schedule (Draft Version 15-May-2023)
---
### Day 1  - June 15 (start 11:00 end 17:00)
- (11:00-12:00) Course introduction [Sagar Dolas SURF]
    - Define goals of course ... What is energy efficiency? 
    - Overview of data center energy usage/footprint
- (12:00-13:00) Lunch
- (13:00-13:45) Introduction/refresher on system architecture [Prof. Ana Lucia Varbanescu UvA/UTwente]
    - What is a CPU? (Intro to multi-core CPUs and modern cluster architecture)
    - What is a GPU? (Intro to General purpose GPUs)
- (13:45-14:30) Introduction/refresher on characteristics of applications [Xavier Álvarez Farré SURF (Online)]
    - Compute/Memory Bound, Heterogeneous, Parallel
- (14:30-15:00) Coffee Break & Tech-Setup
- (15:00-17:00) [Monitoring tools/techniques tutorial](hands-on/monitoring/README.md): Introduction to tools that can be used to monitor CPU performance and energy consumption [Benjamin Czaja SURF]
    - Introduction to Concepts:
        - What is Energy, Power, Frequency, P-States, C-States?
    - Introduction to tools:
        - AMD-uProf
        - PMT
    - Monitoring Excersize/s


### Day 2  - June 16 (start 10:00 end 17:00)

- (10:00-10:45) Define energy efficiency and ways to improve energy efficiency (algorithms, scheduling, DVFS) [Sagar Dolas SURF]
    - How can we better use resources 
- (10:45-11:00) Coffee Break
- (11:00-12:00) [DVFS by hand tutorial](hands-on/DVFS/README.md) [Benjamin Czaja SURF]
    - Using self-defined policies for reducing/increasing frequency
- (13:00-14:30) [Kernel Tuner tutorial](https://github.com/KernelTuner/kernel_tuner) [Alessio Sclocco Netherlands eScience Center]
    - Kernel/node level user-intervention
- (14:30-15:00) Coffee Break 
- (15:00-15:45) [EAR tutorial](hands-on/EAR/README.md) [Benjamin Czaja SURF]
    - Introduce Energy Aware Runtime (EAR) as a solution for improving the energy efficiency of large-scale applications
- (15:45-16:00) Coffee Break
- (16:00-17:00) Hands-on with KernelTuner and/or EAR [Alessio Sclocco, Benjamin Czaja]
    - Choice given to the participants using a couple of pre-defined applications and/or their own applications

---