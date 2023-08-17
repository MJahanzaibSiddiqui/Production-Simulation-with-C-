#include <iostream>
#include <string>
using namespace std;

int main() {
    int batchsize, weightperpart, numberofprocess, numberofworkers, ct, shiftTimings, n, breaktime,breaktime1;
    int shiftDays;
    cout << "Enter the number of days for the shift: ";
    cin >> shiftDays;
    cout << "Enter the shift timings in hours: ";
    cin >> shiftTimings;
    cout<<"Please enter the break time for the shift in minutes: "<<endl;
    cin>>breaktime1;
    cout << "Enter the cycle time in seconds: ";
    cin >> ct;
    cout << "Enter The Number of processes: ";
    cin >> numberofprocess;
    cout << "Entered Number of processes are: " << numberofprocess << endl;
    string name;
    cout << "Please enter the name of the process: ";
    cin.ignore();
    getline(cin, name);
    cout << "Working for: " << name << endl;
    cout << "Please Enter the Number of workers in this process: ";
    cin >> numberofworkers;

    // Step 1: Input batch size and weight per part
    cout << "Enter starting input quantity  in Kg: ";
    cin >> batchsize;
    cout << "Entered starting input quantity is: " << batchsize << " Kg" << endl;
    cout << "Enter the weight per part in Kg: ";
    cin >> weightperpart;
    cout << "Entered Weight Per Part is: " << weightperpart << " Kg" << endl;
    cout<<"Does the process have any break? or it's an automated process (yes=1 or no=0):"<<endl;
    cin >> n;
    if (n == 1) {
        cout << "This process includes automation" << endl;
        cout << "Assuming No break in the process." << endl;
    } else {
        cout << "As this process contains manual work, please enter the break time in minutes: ";
        cin >> breaktime;
        cout << "Break Time is: " << breaktime << " minutes" << endl;
    }

    // Step 2: Input process details
//    cout << "Enter The Number of processes: ";
//    cin >> numberofprocess;
//    cout << "Entered Number of processes are: " << numberofprocess << endl;
//    string name;
//    cout << "Please enter the name of the process: ";
//    cin.ignore();
//    getline(cin, name);
//    cout << "Working for: " << name << endl;
//    cout << "Please Enter the Number of workers in this process: ";
//    cin >> numberofworkers;
//    cout << "Enter the cycle time in seconds: ";
//    cin >> ct;
  

    // Step 3: Check for automation and break time
//    cout << "Please let us know if the entered Process includes automation (machine work) (yes=1 or no=0): ";
//    cin >> n;
//    if (n == 1) {
//        cout << "This process includes automation" << endl;
//        cout << "Assuming No break in the process." << endl;
//    } else {
//        cout << "As this process contains manual work, please enter the break time in minutes: ";
//        cin >> breaktime;
//        cout << "Break Time is: " << breaktime << " minutes" << endl;
//    }

    // Step 4: Perform production
    int totalPartsProduced = 0;
    int remainingMaterial = batchsize;
    int totalCycles = numberofprocess * numberofworkers;
    int totalCycleTime = totalCycles * ct;

    // Calculate potential parts produced with no loss time and value-added time
    int potentialPartsProduced = min(totalCycles, (shiftTimings * 3600 / totalCycleTime) * (batchsize / weightperpart));

    int shiftDuration = shiftTimings * 3600; // Convert shift timings to seconds
    int elapsedTime = 0;

    while (elapsedTime < shiftDuration) {
        int partsProduced = min(totalCycles, remainingMaterial / weightperpart);
        totalPartsProduced += partsProduced;
        remainingMaterial -= partsProduced * weightperpart;

        cout << "Parts Produced in this batch: " << partsProduced << endl;
        cout << "Remaining Material: " << remainingMaterial << " Kg " << endl;

        // Simulate the cycle time
        int cycleTime = totalCycleTime / totalCycles;
        cout << "Cycle Time for this batch: " << cycleTime << " seconds" << endl;

        // Update elapsed time
        elapsedTime += cycleTime;

        if (remainingMaterial <= 0) {
            cout << "\nMaterial is exhausted for this batch. Please enter more material for the next batch." << endl;
            int additionalMaterial;
            cout << "Enter the additional batch size (in Kg): ";
            cin >> additionalMaterial;
            remainingMaterial += additionalMaterial;
        }
    }

    cout << "\nTotal output or Parts Produced: " << totalPartsProduced << " parts" << endl;
    cout << "Elapsed Time in Shift: " << elapsedTime << " seconds" << endl;
    cout<<"              "<<endl;
    cout<<"elapsed time refers to the total time that has passed during the production process";
	cout<< "It represents the time duration from the start of the production until the end of the shift or until the material is exhausted (whichever occurs first)"<<endl;
	cout<<"              "<<endl;
    cout << "Potential Parts Produced (assuming no loss time and value-added time): " << potentialPartsProduced << " parts" << endl;

    return 0;
}

