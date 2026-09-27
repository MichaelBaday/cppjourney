// Recursive function Task
//Deadline: Sunday, 27 September 2026, 02:42 PM

// Made by Michael Audrey Baday on Friday 25 September 2026; 05.39 PM WIB
// Finished: Friday 25 September 2026; 06.37 PM WIB
// Time spent: 58 minutes

// Study Case 3: Fibonacci Sequence

/*
Explanation: The Fibonacci Sequence is a famous series of numbers where each numer is the sum
             of two previous numbers.This series of numbers typically starts from 0 and 1.
             Creating a progression that looks like this: 0, 1, 1, 2, 3, 5, 8, 13, 21, ....
*/ 

#include <iostream>
#include <limits>

long long fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

void validationloop (int& position) {
    while (true) {
        std::cout << "Enter position (n): ";
        if (std::cin >> position && position >= 0) {
            break;
        }

        std::cout << "--------- PLEASE ENTER A NON-NEGATIVE INTEGER! ---------\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void positionis(int position) {
    std::cout << "\nFibonacci number at position " << position << " is " << fibonacci(position)
    << "\n\n";
}

void fullSequence(int position) {
    std::cout << "Full sequence up to " << position << " position is:\n";
    for (int i = 0; i <= position; i++) {
        std::cout << fibonacci(i) << (i < position ? "," : "");
    }
    std::cout << "\n";
}



int main() {
    int n;

    std::cout << "========== FIBONACCI CALCULATOR ==========\n";
    validationloop(n);
    fibonacci(n);
    positionis(n);
    fullSequence(n);

    return 0;
}