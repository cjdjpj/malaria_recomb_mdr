#pragma once

#define NUM_RUNS 1

//transmission
#define STARTING_POISSON_MEAN 0.05

#define R_NAUGHT 2

#define NUM_GENERATIONS 300

#define NUM_HOSTS 300000

#define TERMINATE_WHEN_ENDEMIC_OR_ELIMINATED

//genetics
#define NUM_LOCI 6

#define NUM_UNIQUE_CLONES 64 //2^NUM_LOCI

#define MUTATION_RATE 1e-6

#define RECOMBINATION_RATE 1

#define CHR5_UNLINKED_PROB 1.3067e-4

//drug treatment
#define TREATED_PROP 0.4

#define NUM_DRUGS 11 // 10 therapies + NO_DRUG

enum drug {AS = 0, LM, AQ, PPQ, MQ, CQ, AL, ASAQ, DHAPPQ, ASMQ, NO_DRUG};

#define DTS_SINGLE

#define CYCLING_DRUG1 DHAPPQ
#define CYCLING_DRUG2 ASAQ
#define CYCLING_DRUG3 AL

#define SINGLE_DRUG ASAQ

#define MFT_DRUG1 DHAPPQ
#define MFT_DRUG2 ASAQ
#define MFT_DRUG3 AL

#define DEBUG_DRUG
// #define DEBUG_G_CLONE
// #define DEBUG_HOST
// #define DEBUG_TRANSMISSION