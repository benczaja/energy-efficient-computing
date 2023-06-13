
# Kernel Tuner

## Installing Kernel Tuner

First we need to load the appropriate modules on Snellius.

```bash
module purge
module load 2022
module load foss/2022a
```

After the appropriate modules are loaded, we can install the Python backends for CUDA and OpenCL.

```bash
pip install pycuda
pip install pyopencl
pip install cupy
```

While in general [Kernel Tuner](https://github.com/KernelTuner/kernel_tuner) is available via PyPI, we need a specific branch for this tutorial, so we are going to install it from GitHub.

```bash
pip install git+https://github.com/KernelTuner/kernel_tuner.git@energy_tutorial
```

We can also install the [KT Dashboard](https://github.com/KernelTuner/dashboard) to visualize the data after (or during) tuning.

```bash
pip install git+https://github.com/KernelTuner/dashboard
```

We only need to do install all the necessary software once.

## GEMM (cached version)

To use the cached version of the GEMM kernel we need to download the compressed Kernel Tuner cache file, and move it to the proper directory.

```bash
wget -O GEMM_A100_cache.json.bz2 https://github.com/KernelTuner/kernel_tuner_tutorial/blob/master/energy/data/GEMM_NVML_NVIDIA_A100-PCIE-40GB_freq_cache.json.bz2?raw=true
bunzip2 GEMM_A100_cache.json.bz2
mv GEMM_A100_cache.json gemm/gemm_cache.json
```

You can now read the tuning script for the GEMM kernel, it is called `tuning_gemm_cached.py`.
We suggest you to first check how it works, before executing it.
After you are done, the variable `to_optimize` contains the metric that should be optimized: throughput in GFLOP/s or energy efficiency in GFLOPS/W.

You can also examine the search space visually using the Dashboard.

```bash
ktdashboard hands-on/KT/gemm/gemm_cache.json
```

## Hotspot

