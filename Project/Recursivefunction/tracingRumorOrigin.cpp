// Recursive function Task
//Deadline: Sunday, 27 September 2026, 02:42 PM

// Made by Michael Audrey Baday on Wednesday 23 September 2026; 08.02 PM WIB
// Finished: Thursday 24 September 2026; 03.43 AM WIB
// Time spent: 7 hours 39 minutes

// Study Case 1: Tracing the Origin of a Rumor

/*
Explanation: Imagine you are a detective investigating a rumor spreading around a workplace.
             Instead of guessing who started it, you ask the last person who heard it:
             "Who told you?" You then walk over to that source and ask the exact same question.

             You repeat this process step-by-step until you reach someone who says,
             "Nobody, I made it up!" or until you hit a dead end where someone doesn't remember.
*/ 

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <limits>

std::string traceRumor(
    const std::string& currentPerson,
    const std::unordered_map<std::string, std::string>& rumorNetwork,
    std::vector<std::string>& path
) {
    path.push_back(currentPerson);

    if (rumorNetwork.find(currentPerson) == rumorNetwork.end()) {
        return currentPerson + " (Dead end / Unknown source)";
    }

    const std::string& source = rumorNetwork.at(currentPerson);

    if (source == currentPerson || source.empty()) {
        return currentPerson;
    }

    if (std::find(path.begin(), path.end(), source) != path.end()) {
        path.push_back(source);
        return source + " (Infinite rumor loop detected)";
    }

    return traceRumor(source, rumorNetwork, path);
}

int main() {
    std::unordered_map<std::string, std::string> rumorNetwork;
    int linkCount;

    std::cout << "=== RUMOR ORIGIN TRACER ===\n";
   while (true) {
    std::cout << "How many rumor links do you want to enter? ";
    if (std::cin >> linkCount){
        break;
    }

    std::cout << "\n---------- PLEASE ENTER AN INTEGER! ----------\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   }

    std::cout << "\n\nEnter each link as: [Listener] [Source]\n";
    std::cout << "Example: Dave Charlie  (Means Dave heard it from Charlie)\n";
    std::cout << "Note: If someone created it, make them point to themselves (e.g. Alice Alice)\n\n";

    for (int i = 0; i < linkCount; ++i) {
        std::string listener, source;
        std::cout << "Link #" << (i + 1) << ": ";
        std::cin >> listener >> source;
        rumorNetwork[listener] = source;
    }

    std::string startPerson;
    std::cout << "\nWho do you want to start tracing from? ";
    std::cin >> startPerson;

    std::vector<std::string> path;
    std::string originator = traceRumor(startPerson, rumorNetwork, path);

    std::cout << "\n----------------------------------------\n";
    std::cout << "Rumor Originator: " << originator << "\n";
    std::cout << "Chain of Transmission: ";
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i] << (i + 1 < path.size() ? " -> " : "");
    }
    std::cout << "\n----------------------------------------\n";

    return 0;
}