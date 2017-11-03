Parallel MATLAB Example
Ben Pharr <bnpharr@olemiss.edu>
Time-stamp: <2012-04-27 16:47:53 bnp>
===============================================================================

This example shows how to use parallel MATLAB on the sequoia cluster. The
primary MATLAB script is in prime.m. Note that it utilizes parfor, a parallel
for loop. The script uses the isPrime function, a local function defined in
isPrime.m. The script simply calculates (not particularly efficiently) the
primes up to 10,000,000. It should take only a few minutes to run.

Also note that the number of CPUs requested in the PBS script is 4, one more
than the number of MATLAB workers requested in prime.m. This accounts for the
"master" or head MATLAB process. MCSR does not currently have a license for
the software required to run MATLAB across multiple nodes, so parallel jobs
are limited to the number of cores on a single node, which is 12 on the more
modern sequoia nodes.

At the end of the script, the MATLAB save() function is used to save the
contents of the 'p' variable, which contains the computed primes. This file
can be loaded into subsequent MATLAB sessions on sequoia or on your local
system using the MATLAB load() function.
