#!/bin/bash
#SBATCH --time=0:10:00   # Walltime limit (HH:MM:SS)
#SBATCH --nodes=1        # Number of nodes
#SBATCH --ntasks-per-node=32  # 32 processor cores per node
#SBATCH --job-name=test_job   # Job name
#SBATCH --output=slurm-%j.out # Output log file

# Create output directory if it doesn't exist
mkdir -p output

# Load necessary modules (if required)
# module load gcc

# Change to the directory where your executable is located
cd $SLURM_SUBMIT_DIR  

# Run the program and redirect both stdout and stderr to the output files in the output folder
./main 1 1e-8 > output/output1.txt 2>&1
./main 2 1e-8 > output/output2.txt 2>&1
./main 4 1e-8 > output/output4.txt 2>&1
./main 8 1e-8 > output/output8.txt 2>&1
./main 16 1e-8 > output/output16.txt 2>&1
