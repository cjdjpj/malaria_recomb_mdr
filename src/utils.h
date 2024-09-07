#pragma once
#include <set>
#include <vector>

int weighted_dice_roll(const double weights[], int num_sides);

bool weighted_flip(double prob);

void find_bit_combinations_many(std::vector<uint8_t>& arr, std::set<uint8_t>& set);

void find_bit_combinations_pair(uint8_t a, uint8_t b, std::set<uint8_t>& set);

bool opposite_chr5_alleles(uint8_t x, uint8_t y);

bool diff_chr5_alleles(uint8_t x, uint8_t y);

bool are_same(double a, double b);