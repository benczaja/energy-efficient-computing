# Energy and power monitoring hands on session:
## Section Outline

1. [Basic Concepts](#concepts)
2. [Linux tools](#linux)
3. [Profilers](#profiler)
4. [Libraries](#libraries)


<h2 id="concepts">Basic Concepts</h2>

### What is Frequency 

The Frequency or "clock speed" of your CPU is a measure of the number of cycles a CPU executes per second. This value is measured in GHz (gigahertz). A “cycle” (also called a instruction cycle or fetch-execute cycle) is the basic unit of operation that a CPU does to "compute". During each cycle, billions of transistors within the processor open and close . This is how the CPU executes the calculations contained in the instructions it receives.

In order to get an overview of the CPU arctecture of the physical (host) system use the linux tool `lscpu`. 
```
lscpu 
```

You can look at the files that show you the current and available rfrequencies of your CPU. Lets look at CPU #0 for example....

- List the available Freqs.
    - ``` cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_available_frequencies ```
- List the maximum Freq.
    - ```  cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq ```
- List the minimum Freq.
    - ```  cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_min_freq ```
- List the current Freq.
    - ``` cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq ```
- Better ... watch the cpufreq it in realtime...
    - ```  watch -n 0.1 cat /sys/devices/system/cpu/cpu0*/cpufreq/scaling_cur_freq ```

This is can be accessed more easily with the linux tool `cpupower`
```
cpupower -c 0 frequency-info
```

### C-States/P-States


### What is Power
### What is Energy

### How does Power scale with Frequency


<h2 id="linux">Linux tools</h2>

### Here is where we want some content



<h2 id="profiler">Profilers</h2>

<h2 id="libraries">Libraries</h2>


## Simple Matrix multiplication
How to compile compile the program:
```
module purge
module load 2022
module load foss/2022a

g++ -fopenmp mat_mul.cpp -o mat_mul
```
Note: `-fopenmp` needed here because we use a simple OpenMP parallelization example.

How to run:
```
./mat_mul
```
Suggestion: Play around with the `OMP_NUM_THREADS` for your execution
```
OMP_NUM_THREADS=2 ./mat_mul
```

# Energy Monitoring Excersize

## AMDuProf
```
module load 2022
module load AMD-uProf/4.0.341
```
Display system information
```
AMDuProfCLI info --system
```
Interesting commands
List the available "events"
```
AMDuProfCLI info --list predefined-events
```
List the available " system events" availble from timechart
```
AMDuProfCLI timechart --list
```

Profile specific core/s power and set the affinity of the program to the core
```
AMDuProfCLI timechart --event core=0-3,power -o AMDuProf_output --interval 10 --affinity 1 ../bin/mat_mul 
```
Profile the Frequency
```
AMDuProfCLI timechart --event core=0-5,frequency -o AMDuProf_output --interval 500 --affinity 1 ../bin/mat_mul 
```

Profile temperature
```
 AMDuProfCLI timechart --event temperature -o AMDuProf_output --interval 10 --affinity 1 ../bin/mat_mul 
```


## 1. PMT ([Power Measurement Toolkit](https://git.astron.nl/RD/pmt/)) is available as a module on Snellius
How to compile a c++ source code with PMT library: All you need to do is load the PMT module on Snellius and link to it ( `-lpmt`)  during compilation....
```
module purge
module load 2022
module load foss/2022a
module load pmt/1.1.0-foss-2022a

g++ -fopenmp -lpmt mat_mul_pmt.cpp -o mat_mul_pmt
```
Now run it and see what you observe.....
```
./mat_mul_pmt
```

-------

## How does Performance, Power and Energy Scale?

<div class="image-single-row">
          <img style="height:250px;width:30%" src="size_v_time.png"></img>
          <img style="height:250px;width:30%" src="size_v_joule.png"></img>
          <img style="height:250px;width:30%" src="size_v_watt.png"></img>
</div>

### Run the "Energy study script"


```
sh energy_monitoring_study.sh
```
This will output the results to the file `results.txt` 


You will need python as a plotting tool, which will read in `results.txt` and plot three pngs (`size_v_joule.png`,`size_v_time.png`, `size_v_watt.png`)

```
module load 2022
module load Python/3.10.4-GCCcore-11.3.0

pip install matplotlib --user
pip install numpy --user
```
