// Recursive function Task
// Deadline: Sunday, 27 September 2026, 02:42 PM
// Made by Michael Audrey Baday on Wednesday 26 September 2026; 07.54 PM WIB
// Finished: Saturday 26 September 2026; 10.31 PM WIB
// Time spent: 2 hours 25 minutes

// Study Case 4: Indomaret/Alfamart Jatinangor Coffee Stamp & Free Exchange Simulator
/*
Explanation: To survive late-night coding assignments, you frequently buy bottled coffee at
             Indomaret Ciseke or Alfamart Raya Jatinangor. The store is running a promotion:
             Every time you buy a bottle of coffee for Rp 10,000, you get 1 promo stamp.
             Once you collect $K$ stamps (e.g., 3 stamps), you can trade them in for 1 free
             bottle of coffee.
             
             The twist: Every free bottle you redeem also includes 1 new promo stamp attached to it,
             which can be saved to redeem even more free bottles!
             
             You want to write a recursive function to calculate the total number of coffee
             bottles a student can consume given an initial amount of money.
*/

#include <iostream>
#include <limits>

void header() {
    std::cout << "===========================================\n";
    std::cout << "  Indomaret Coffee Stamp Exchange Simulator \n";
    std::cout << "===========================================\n";
}

void inputMoney(int& m) {
    while (true) {
        std::cout << "Enter pocket money (Rp): ";
        if (std::cin >> m && m >= 0) {
            break;
        }
        std::cout << "---------- PLEASE ENTER A NON-NEGATIVE INTEGER! ----------\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void inputPrice(int& p) {
    while (true) {
        std::cout << "Enter price per bottle (Rp): ";
        if (std::cin >> p && p > 0) {
            break;
        }
        std::cout << "---------- PLEASE ENTER A POSITIVE INTEGER (> 0)! ----------\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void inputStampsNeeded(int& k) {
    while (true) {
        std::cout << "Enter stamps needed for 1 free bottle: ";
        if (std::cin >> k && k > 1) {
            break;
        }
        std::cout << "---------- PLEASE ENTER AN INTEGER GREATER THAN 1! ----------\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void getUserInputs(int& money, int& price, int& stamps_needed) {
    inputMoney(money);
    inputPrice(price);
    inputStampsNeeded(stamps_needed);
}

int countFreeBottles(int current_stamps, int stamps_needed, int step = 1) {
    if (current_stamps < stamps_needed) {
        std::cout << "[Step " << step << "] Unused stamps remaining: " << current_stamps 
                  << " (Insufficient for exchange, stopping recursion)\n";
        return 0;
    }

    int free_bottles = current_stamps / stamps_needed;
    int leftover_stamps = current_stamps % stamps_needed;
    int new_stamps = leftover_stamps + free_bottles;

    std::cout << "[Step " << step << "] Redeemed " << (free_bottles * stamps_needed) 
              << " stamps -> Received " << free_bottles << " free bottle(s) | New stamp total: " 
              << new_stamps << "\n";

    return free_bottles + countFreeBottles(new_stamps, stamps_needed, step + 1);
}

void printProgressLogHeader(int initial_bottles, int initial_stamps) {
    std::cout << "\n-------------------------------------------\n";
    std::cout << "           Exchange Progress Log            \n";
    std::cout << "-------------------------------------------\n";
    std::cout << "Initial purchase: " << initial_bottles << " bottle(s) | Stamps earned: " 
              << initial_stamps << "\n";
}

void printSummaryResults(int initial_bottles, int free_bottles) {
    int total_bottles = initial_bottles + free_bottles;

    std::cout << "-------------------------------------------\n";
    std::cout << "Simulation Results:\n";
    std::cout << " - Purchased Bottles  : " << initial_bottles << "\n";
    std::cout << " - Free Bonus Bottles : " << free_bottles << "\n";
    std::cout << " - Total Consumption  : " << total_bottles << " bottle(s)\n";
    std::cout << "===========================================\n";
}

int main() {
    int money, price, stamps_needed;

    header();
    getUserInputs(money, price, stamps_needed);

    int initial_bottles = money / price;
    if (initial_bottles == 0) {
        std::cout << "\nYour balance is too low to buy even one bottle!\n";
        return 0;
    }

    printProgressLogHeader(initial_bottles, initial_bottles);
    
    int free_bottles = countFreeBottles(initial_bottles, stamps_needed);
    
    printSummaryResults(initial_bottles, free_bottles);

    return 0;
}