#pragma once
#include "settings.h"

#include <set>

class Host{
private:
	const int id;
public:
	Host();
	static int next_id;
	int moi;
	drug host_drug;
	double mean_fitness;

	// storing clones and clone freqs for INDIVIDUALS
	std::set<uint8_t> i_clones;
	double i_freqs[NUM_UNIQUE_CLONES];

	void choose_clones(const double g_freqs[NUM_UNIQUE_CLONES]);
	void choose_drugs(int generation, const double avg_fitness_data[NUM_DRUGS], const double generational_mean_fitness[NUM_GENERATIONS]);
	void recombine();
	void naturally_select(const double clone_drug_fitness[NUM_DRUGS][NUM_UNIQUE_CLONES]);
	void reset();

	//debug
	void validate_i_freq() const;
	void print_summary() const;
};
