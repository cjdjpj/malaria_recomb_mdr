# Model Architecture
This model assumes a pool of Malaria clones and a population of anonymous hosts. It is stochastic and is run over discrete time steps equivalent to one Malaria generation/transmission cycle, which is approximately 28 days in high transmission regions.

Here I will describe each step in the order that it occurs in the model.

#### (1) Transmission
1. Multiplicity of Infection (MOI): each host is assigned a MOI drawn from a poisson distribution with poisson mean $\lambda$

2. Selecting clones: each host selects MOI times from the clone pool with chance of selecting clone equal to that clones frequency in population
	- each clone has frequency $\frac{1}{\text{MOI}}$ within host (total frequency = 1)
	- same clone can be selected multiple times

3. Selecting drugs
	- **Single drug strategy**: all hosts receive one drug
	- **MFTs strategy**: each drug is distributed evenly across host population
	- **Adaptive cycling strategy**: all hosts receive one drug, until mean fitness of population is greater than average fitness of all clones to current drug, at which point all hosts swap to another drug

#### (2) Selection
Each host is assigned a mean fitness $m$ which is equal to
$$m = \sum^C_{c \in C} f_c \times w_{c,d}$$
where $C$ is set of all clones the host is infected with. $w_c$ is the fitness of the clone $c$ under the current drug $d$ and $f_c$ is its frequency ($m=0$ if host uninfected).
The new frequency of each clone ($f_c'$) is equal to
$$f_c' = \frac{f_c \times w_{c,d}}{m}$$

Fitness values are drawn from Appendix 2 of Nguyen et al. 2023
The untreated fitness values for clones are calculated as:
$$w_{c,\text{untreated}} = (0.9995)^{n\times d}$$
where $n$ is the number of resistance conferring mutations and $d$ is the assumed number of days in a transmission cycle (e.g. 28).

#### (3) Recombination
We assume mosquitoes (not simulated) pick up Malaria clones in exactly the frequency that they were in after selection within the host. We don't consider interrupted feeding.

A parameter $\theta$ controls the proportion of the population that undergoes recombination.

Every possible clone pair produces sexual offspring with frequency equal to the probability of their parental pairing divided by the total number of recombinants given no linkage. Therefore, during sexual recombination, complete recombination occurs - i.e. parental clones are completely split up into possible recombinants.

##### Linkage
Currently, the only loci exhibiting linkage in the model are Y184F and N86Y - both at *pfmdr1* on chromosome 5. *pfmdr1* has 1 exon, meaning the sites are 294bp apart.

Using the genetic map estimate of $1.5-3.0 \times 10^4$ bp for 1 cM in Conway 1998, this means a 0.013% chance of independent inheritance $(r = 0.00013067)$. Therefore, recombinant clones with a different combination of alleles to both parents at both these loci have their frequency multiplied by $2r$. Recombinant clones with the same combination of alleles as either parent at both these loci have their frequency multiplied by $2(1-r)$

#### (4) Census
The new global frequency of each clone $F_c$ is collected with each host's contribution weighted according to their mean fitness. That is, for host $j$ and mean fitness $m_j$:
$$F_c = \sum^J_{j \in J} f_{j,c} \times \frac{m_j}{M}$$
where $M$ is the total fitness of all hosts in the population:
$$M = \sum_{j \in J}^{J} m_j$$

The poisson mean in the next generation ($\lambda'$) is calculated.
$$\lambda' = R_0 \times \frac{M}{\text{num hosts}} \times \text{proportion of hosts uninfected}$$

#### (5) Mutation
In the model, mutations occur in the global pool of clones rather than within hosts. This means mutants do not recombine unless selected by chance by a host in the next generation.

We assume no backwards mutations and 1 allele is mutated (if not already mutant) for each mutant clone. The initial frequency of a single mutant is $10^{-6}$ which is also the parameter assumed in Hastings 2002.

The frequency of each mutant is:
$$f_{\text{mutant}}' = 10^{-6} \times f_{\text{parent}}$$
and the original parent clone has new frequency:
$$f_{\text{parent}}' = f_{\text{parent}} - f_{\text{parent}} \times 10^{-6} \times \text{num mutants}$$
