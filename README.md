# malaria_recomb_MDR
Investigating the effect of recombination on the rate of emergence of  multi-drug resistance under different treatment strategies in Malaria.

A stochastic, agent-based model, built in C++. 
[Complete description of model architecture](model_architecture.md)

Includes python scripts for simple inference and visualizations in `data/plotting/`.

### Compile
```
mkdir build
cd build
cmake -S ../src -B .
make
```

### Run
```
./MalariaPopSim
```

### Configuration
1. In `fitness_values.csv`: Adjust fitness of wildtype clones according to assumed length of transmission cycle
2. In `simulator.cpp`: starting clones and starting clone frequencies
3. In `settings.h`: everything else (demography, genetics map, recombination, treatment)
