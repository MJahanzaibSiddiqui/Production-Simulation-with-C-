#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

class DisplayProcess {
public:
    void display() {
        cout << "Hierarchy:" << endl;
        cout << "Store (ST)=1" << endl;
        cout << "Inventory (IN)=2" << endl;
        cout << "Transport (TP)=3" << endl;
        cout << "Process (PR)=4" << endl;
        cout << "Testing (TS)=5" << endl;
    }
};

class Stages {
public:
    void displayStages() {
        cout << "There are 5 stages where you can replace your processes:" << endl;
        cout << "Stage 'A'" << endl;
        cout << "Stage 'B'" << endl;
        cout << "Stage 'C'" << endl;
        cout << "Stage 'D'" << endl;
        cout << "Stage 'E'" << endl;
    }
};

class Placement {
private:
    set<int> selectedOptions; // Set to store selected options for each stage
    map<string, int> stageTotalTimes; // Map to store the total time for each stage

public:
    void selectProcess(const string& stage, const string& process, int processTime) {
        cout << "You selected " << process << " for " << stage << " stage" << endl;

        // Update the total time for the stage
        stageTotalTimes[stage] += processTime;

        // Display the time taken for the process in the second line
        cout << "Time taken: " << processTime << " minutes" << endl;
    }

    void working(const string& stage) {
        cout << "Enter the process for " << stage << " stage" << endl;
        cout << "Options:" << endl;
        cout << "int ST=1 IN=2 TP=3 PR=4 TS=5" << endl;
        cout << "Important!! You can not reselect any process!!!" << endl;

        int option;
        while (selectedOptions.size() < 5) {
            cin >> option;

            if (selectedOptions.find(option) == selectedOptions.end()) {
                selectedOptions.insert(option);
                break;
            } else {
                cout << "Option " << option << " has already been selected. Choose a different option." << endl;
            }
        }

        switch (option) {
            case 1: selectProcess(stage, "Store", 10); break;
            case 2: selectProcess(stage, "Inventory", 15); break;
            case 3: selectProcess(stage, "Transport", 12); break;
            case 4: selectProcess(stage, "Process", 8); break;
            case 5: selectProcess(stage, "Testing", 14); break;
            default: cout << "Invalid option. " << stage << " stage" << endl; break;
        }
    }

    void displayTotalTimes() {
        cout << "Total time taken for all stages:" << endl;
        int totalTime = 0;
        for (map<string, int>::iterator it = stageTotalTimes.begin(); it != stageTotalTimes.end(); ++it) {
            cout << it->first << " stage: " << it->second << " minutes" << endl;
            totalTime += it->second;
        }
        cout << "Total time for all stages: " << totalTime << " minutes" << endl;
    }
};

int main() {
    DisplayProcess dp;
    dp.display();
    Stages s;
    s.displayStages();

    Placement p;
    p.working("A");
    p.working("B");
    p.working("C");
    p.working("D");
    p.working("E");

    p.displayTotalTimes();

    return 0;
}

