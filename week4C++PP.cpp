//
// Created by Princess B on 9/10/26. 
//
#include <iostream>

int main() {
    // Outer loop controls the last number printed in each row
    for (int end = 1; end <= 5; ++end) {
        // Inner loop prints from 5 down to the current 'end' value
        for (int j = 5; j >= end; --j) {
            std::cout << j << " ";
        }
        // Move to the next line after finishing a row
        std::cout << std::endl;
    }
    return 0;
}
