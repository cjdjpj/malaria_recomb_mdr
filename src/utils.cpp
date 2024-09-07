#include <numeric>

#include "utils.h"

int weighted_dice_roll(const double weights[], int num_sides) {
    if (num_sides <= 0) {
        throw std::invalid_argument("Number of sides must > 0");
    }
    if(!are_same(std::accumulate(weights, weights + num_sides, 0.0), 1.0)){
        throw std::invalid_argument("Invalid weighted dice state");
    }
    uint32_t random_number = arc4random();
    double current_weight = 0;
    
    for (int k=0; k<num_sides; ++k) {
        current_weight += weights[k];
        if (random_number < current_weight * UINT32_MAX) {
            return k; 
        }
    }
    return num_sides-1;
}

bool weighted_flip(double prob){
    uint32_t random_number = arc4random();
    if(random_number < prob * UINT32_MAX){
        return true;
    }
    else{
        return false;
    }
}

void find_bit_combinations_many(std::vector<uint8_t>& arr, std::set<uint8_t>& set) {
    for (uint8_t mask = 1; mask != 0; mask <<= 1) {
        for(int i = 0; i < arr.size()-1; i++){
            if((arr[i] & mask) != (arr[i+1] & mask)){ 
                std::vector<uint8_t> rep1(arr.size());
                std::vector<uint8_t> rep2(arr.size());
                for(int j = 0; j < arr.size(); j++){
                    rep1[j] = arr[j] & ~mask;
                    rep2[j] = arr[j] | mask;
                }
                find_bit_combinations_many(rep1, set);
                find_bit_combinations_many(rep2, set);
                return;
            }
        }
    }
    set.insert(arr[0]);
}

void find_bit_combinations_pair(uint8_t a, uint8_t b, std::set<uint8_t>& set) {
    if (a == b) {
        set.insert(a);
        return;
    }

    uint8_t xor_ab = a ^ b;
    uint8_t mask = 1 << std::countr_zero(xor_ab); // Start at the lowest set bit in a ^ b
    uint8_t highest_bit = 1 << (7 - std::countl_zero(xor_ab)); // Greatest set bit in a ^ b, 7 for 8-bit numbers

    for (; mask <= highest_bit; mask <<= 1) {
        if ((a & mask) != (b & mask)) {
            find_bit_combinations_pair(a & ~mask, b & ~mask, set);
            find_bit_combinations_pair(a | mask, b | mask, set);
            return;
        }
    }
}

bool opposite_chr5_alleles(uint8_t x, uint8_t y){
    return (((x >> 3) & 1) != ((y >> 3) & 1) && ((x >> 4) & 1) != ((y >> 4) & 1));
}

bool diff_chr5_alleles(uint8_t x, uint8_t y){
    return ((x >> 3) & 1) != ((y >> 3) & 1) || ((x >> 4) & 1) != ((y >> 4) & 1);
}

bool are_same(double a, double b){
    return fabs(a - b) < 1e-10;
}
