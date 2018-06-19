# Using PBS on MCSR Supercomputers

## What is the MCSR and what do the MCSR do?
For a quick intro to supercomputers, visit http://mcsr.olemiss.edu/supercomputers. The MCSR currently has 3 supercomputers

1. `Sequoia` - Cluster - multiple nodes connected via high-speed network; Infiniband - 40Gbps; 1200 CPU cores, 36GB memory per node

2. `Catalpa` - Single OS image, more of a traditional supercomputer; 192 CPU cores, 1.5TB memory; Used for large memory jobs

3. `Maple` - Cluster w/ GPUs on each node; 1228 cores, 3.3TB of memory

## Why does the MCSR need PBS?

PBS properly allocates resources.

## Qsub Interactive example

```bash 
qsub -I
qsub -I -l ncpus=4 -l mem=1GB
````

### Where can I find sample pbs scripts?

`cd /usr/local/apps/example_jobs`
