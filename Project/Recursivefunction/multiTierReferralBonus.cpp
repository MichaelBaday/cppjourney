// Recursive function Task
//Deadline: Sunday, 27 September 2026, 02:42 PM

// Made by Michael Audrey Baday on Thursday 24 September 2026; 07.50 AM WIB
// Finished Thursday 24 September 2026; 11.20 AM WIB
// Time spent: 3 hours 30 minutes

// Study Case 2: Multi-Tier Friend Referral Rewards

/*
Explanation: Imagine an app where you earn referral bonuses in multi-tier cascading levels:
             Tier 1 (Direct Friends): You invite Bob --> You earn $10.00
             Tier 2 (Friends of Friends): Bob invites Charlie --> You earn $5.00 (50%)
             Tier 3 (3rd Degree): Charlie invites Dave --> You earn $2.50 (25%)
             Tier 4 (Beyond Limit): Dave invites Eve --> You earn $0.00 (Depth limit hit!)
             Because one person can invite multiple friends, each person branches into a list
             of invited users.
*/ 

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

double calculateReferralReward(const std::string& person, const std::unordered_map<std::string,
    std::vector<std::string>>& referralTree, int currentTier, int maxTier) {
    if (currentTier > maxTier) {
        return 0.0;
    }

    if (referralTree.find(person) == referralTree.end()) {
        return 0.0;
    }

    double rewardPerFriend = 0.0;
    if (currentTier == 1)      rewardPerFriend = 10.00;
    else if (currentTier == 2) rewardPerFriend = 5.00;
    else if (currentTier == 3) rewardPerFriend = 2.50;

    double totalReward = 0.0;
    const std::vector<std::string>& friends = referralTree.at(person);

    for (const std::string& friendName : friends) {
        totalReward += rewardPerFriend;

        totalReward += calculateReferralReward(friendName, referralTree, currentTier + 1, maxTier);
    }

    return totalReward;
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> referralTree;
    int linkCount;

    std::cout << "=== MULTI-TIER REFERRAL CALCULATOR ===\n";
    std::cout << "How many referral connections do you want to add? ";
    if (!(std::cin >> linkCount)) return 0;

    std::cout << "\nEnter each connection as: [Inviter] [InvitedFriend]\n";
    std::cout << "Example: Alice Bob  (Means Alice invited Bob)\n\n";

    for (int i = 0; i < linkCount; ++i) {
        std::string inviter, friendName;
        std::cout << "Connection #" << (i + 1) << ": ";
        std::cin >> inviter >> friendName;
        referralTree[inviter].push_back(friendName);
    }

    std::string targetUser;
    int maxDepth = 3;

    std::cout << "\nEnter person's name to calculate earnings for: ";
    std::cin >> targetUser;

    std::cout << "Enter maximum payout tier depth (e.g., 3): ";
    std::cin >> maxDepth;

    double totalEarnings = calculateReferralReward(targetUser, referralTree, 1, maxDepth);

    std::cout << "\n----------------------------------------\n";
    std::cout << "Target User: " << targetUser << "\n";
    std::cout << "Max Tier Depth: " << maxDepth << "\n";
    std::cout << "Total Calculated Referral Earnings: $" << totalEarnings << "\n";
    std::cout << "----------------------------------------\n";

    return 0;
}