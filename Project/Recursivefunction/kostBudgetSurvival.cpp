// Recursive function Task
//Deadline: Sunday, 27 September 2026, 02:42 PM

// Made by Michael Audrey Baday on Friday 25 September 2026; 06.54 PM WIB
// Finished: Saturday 26 September 2026; 12.29 AM WIB
// Time spent: 5 hours 23 minutes


// Study Case 4: The Jatinangor Kost Budget Survival Simulator

/*
Explanation: As an Informatics student living in a kost around Cikuda street(me XD),
             you need to manage your monthly allowance wisely. You start with an
             initial cash balance from your parents. Every day, you have a fixed
             minimum expenditure (meals at Warung Nenek, water refills, laundry, etc.).

             However, your financial flow isn't entirely linear:
             Every 5th day, you receive a small allowance top-up or e-wallet cashback
             (e.g., side-gig payout or regular family micro-transfer).

             You want to know exactly how many full days you can survive before your
             balance falls below your daily minimum living cost.
*/

#include <iostream>
#include <limits>

void initialBalance(int& m) {
    while (true) {
        std::cout << "Enter your initial balance (Rp): ";
        if (std::cin >> m && m >= 0) {
            break;
        } 

        std::cout << "\n---------- PLEASE ENTER A NON-NEGATIVE INTEGER! ----------\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void dailyCost(int& c) {
    while (true) {
        std::cout << "\nEnter your daily cost (Rp): ";
        if (std::cin >> c && c > 0) {
            break;
        } 

        std::cout << "---------- PLEASE ENTER A POSITIVE INTEGER (> 0) FOR DAILY COST! ----------\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void cashbackAmount(int& b) {
    while (true) {
        std::cout << "\nEnter your cashback amount (Rp): ";
        if (std::cin >> b && b >= 0) {
            break;
        } 

        std::cout << "---------- PLEASE ENTER A NON-NEGATIVE INTEGER FOR CASHBACK! ----------\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void cashbackInterval(int& k) {
    while (true) {
        std::cout << "\nEnter your cashback interval (days): ";
        if (std::cin >> k && k > 0) {
            break;
        }

        std::cout << "---------- PLEASE ENTER A POSITIVE INTEGER (> 0) FOR INTERVAL! ----------\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int daysSurvived(int current_balance, int current_day, int daily_cost, int cashback_amount, int cashback_interval) {
    if (current_balance < daily_cost) {
        std::cout << "\nInsufficient funds on Day " << current_day << "!\n";
        return 0;
    }

    int remaining_balance = current_balance - daily_cost;

    bool receives_bonus = (current_day % cashback_interval == 0);
    if (receives_bonus) {
        remaining_balance += cashback_amount;
    }

    std::cout << "Day " << current_day << " | Spent: Rp " << daily_cost;
    if (receives_bonus) {
        std::cout << " (+ Bonus: Rp " << cashback_amount << ")";
    }
    std::cout << " | End Balance: Rp " << remaining_balance << "\n";

    return 1 + daysSurvived(remaining_balance, current_day + 1, daily_cost, cashback_amount, cashback_interval);
}

bool checkIndefiniteSurvival(int cashback_amount, int daily_cost, int cashback_interval) {
    if (cashback_amount >= (daily_cost * cashback_interval)) {
        std::cout << "\n[Warning] Your cashback rate is higher than or equal to your spending rate.\n";
        std::cout << "You can survive indefinitely! Skipping recursion to prevent infinite loop.\n";
        return true;
    }
    return false;
}

int main() {
    int m, c, b, k;

    std::cout << "===========================================\n";
    std::cout << " Jatinangor Kost Budget Survival Simulator \n";
    std::cout << "===========================================\n";
    
    initialBalance(m);
    dailyCost(c);
    cashbackAmount(b);
    cashbackInterval(k);

    if (checkIndefiniteSurvival(b, c, k)) {
        return 0;
    }

    std::cout << "\n-------------------------------------------\n";
    std::cout << "           Simulation Progress             \n";
    std::cout << "-------------------------------------------\n";

    int total_days = daysSurvived(m, 1, c, b, k);

    std::cout << "-------------------------------------------\n";
    std::cout << "Total Survival Days: " << total_days << " day(s)\n";

    return 0;
}