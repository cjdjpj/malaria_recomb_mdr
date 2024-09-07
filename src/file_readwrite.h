#pragma once
#include <fstream>
#include <sstream>
#include "settings.h"

void read_csv_to_2d_array_drug(const std::string& file_path, double data[NUM_DRUGS][NUM_UNIQUE_CLONES]) {
    std::ifstream file(file_path);

    std::string line;
    int row = 0;
    while (getline(file, line) && row < NUM_UNIQUE_CLONES) {
        std::stringstream ss(line);
        std::string cell;
        int col = 0;
        while (getline(ss, cell, ',') && col < NUM_DRUGS) {
            data[col++][row] = std::stod(cell);
        }
        ++row;
    }
    file.close();
}

template <class T>
void append_to_csv(T value, const std::string& filename){
    static bool firstCall = true;
    std::fstream file;

    if (firstCall) {
        file.open(filename, std::ios::out);
        firstCall = false;
    } else {
        file.open(filename, std::ios::out | std::ios::app);
    }

    file << value << ",\n";
    file.close();
}

template <class T>
void write_2d_array_to_csv(const std::string& file_path, int generation, const T data[][NUM_UNIQUE_CLONES]) {
    std::ofstream file(file_path);

    for (int row=0; row<generation; row++) {
        for (int col=0; col<NUM_UNIQUE_CLONES; col++){
            if(col == NUM_UNIQUE_CLONES-1){
                file << std::setprecision(17) << data[row][col] << '\n';
                break;
            }
            file << data[row][col] <<',';
        }
    }
    file.close();
}

template <class T>
void write_array_to_csv(const std::string& file_path, int generation, const T data[]) {
    std::ofstream file(file_path);

    for (int row = 0; row < generation; row++) {
        file << std::setprecision(17) << data[row] << "\n";
    }
    file.close();
}