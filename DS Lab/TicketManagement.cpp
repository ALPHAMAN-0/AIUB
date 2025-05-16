#include <iostream>
#include <string>

using namespace std;

struct Applicant {
    string visaType;
    int tokenNumber;
    bool served;
};

struct Counter {
    string primaryVisaType;
    int applicantsServed[4]; // TR, MED, BS, GO
};

Applicant applicants[100]; // Store up to 100 applicants
int applicantCount = 0; // Total applicants
int tokenCounter = 1; // Global token counter
int visaCounts[4] = {0}; // TR, MED, BS, GO counts


Counter counters[4] = {
    {"TR", {0, 0, 0, 0}},
    {"MED",{0,  0, 0,0}},
    {"BS", {0, 0, 0, 0}},
    {"GO", {0, 0, 0, 0}}
};



const string visaTypes[4] = {"TR", "MED", "BS", "GO"};
const string VISA[4] ={"Travel","Medical","Business","Government Offcials"};


void issueToken(string visaType) {
    int visaIndex = -1;
    for (int i = 0; i < 4; i++) {
        if (visaTypes[i] == visaType) {
            visaIndex = i;
            break;
        }
    }

    if (visaIndex == -1) {
        cout << "Invalid visa type!" << endl;
        return;
    }

    if (visaCounts[visaIndex] >= 25) {
        cout << "Daily limit reached for " << visaType << " visa!" << endl;
        return;
    }

    if (applicantCount >= 100) {
        cout << "Daily total applicant limit reached!" << endl;
        return;
    }

    applicants[applicantCount].visaType = visaType;
    applicants[applicantCount].tokenNumber = tokenCounter++;
    applicants[applicantCount].served = false;
    visaCounts[visaIndex]++;
    applicantCount++;

    cout << "Your token is: " << visaType << " - " << applicants[applicantCount-1].tokenNumber << endl;
}


void NumberOfApplicants(){
    cout<<endl;
    cout<<"Counter Available sits"<<endl;
    for(int i=0;i<4;i++){
        cout<<VISA[i]<<"("<<visaTypes[i]<<") :"<<visaCounts[i]<<" Applicant"<<endl;
    }
    cout<<endl;
}

int getLongestLine() {
    int remaining[4] = {0};
    for (int i = 0; i < applicantCount; i++) {
        if (!applicants[i].served) {
            for (int j = 0; j < 4; j++) {
                if (applicants[i].visaType == visaTypes[j]) {
                    remaining[j]++;
                    break;
                }
            }
        }
    }

    int maxCount = -1;
    int longestLine = -1;
    for (int i = 0; i < 4; i++) {
        if (remaining[i] > maxCount) {
            maxCount = remaining[i];
            longestLine = i;
        }
    }

    return longestLine;
}

void callNextCustomer(int counterIndex) {
    int primaryIndex = -1;
    for (int i = 0; i < 4; i++) {
        if (visaTypes[i] == counters[counterIndex].primaryVisaType) {
            primaryIndex = i;
            break;
        }
    }

   
    for (int i = 0; i < applicantCount; i++) {
        if (applicants[i].visaType == counters[counterIndex].primaryVisaType && !applicants[i].served) {
            applicants[i].served = true;
            counters[counterIndex].applicantsServed[primaryIndex]++;
            cout << "Counter " << counterIndex + 1 << ", Please serve the token number \""
                 << applicants[i].visaType << "-" << applicants[i].tokenNumber << "\"" << endl;
            return;
        }
    }


    int longestLine = getLongestLine();
    if (longestLine == -1) {
        cout << "Counter " << counterIndex + 1 << " is idle" << endl;
        return;
    }

    for (int i = 0; i < applicantCount; i++) {
        if (applicants[i].visaType == visaTypes[longestLine] && !applicants[i].served) {
            applicants[i].served = true;
            counters[counterIndex].applicantsServed[longestLine]++;
            cout << "Counter " << counterIndex + 1 << ", Please serve the token number \""
                 << applicants[i].visaType << "-" << applicants[i].tokenNumber << "\"" << endl;
            return;
        }
    }
}


void generateDailySummary() {
    cout << "Daily Summary Report" << endl;

   
    cout << "1. Applicants served by Visa Type" << endl;
    int totalServed = 0;
    int servedByType[4] = {0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            servedByType[i] += counters[j].applicantsServed[i];
        }
        cout << "- " << visaTypes[i] << " (" << (i == 0 ? "Travel" : i == 1 ? "Medical" : i == 2 ? "Business" : "Government Officials")
             << "): " << servedByType[i] << endl;
        totalServed += servedByType[i];
    }

    cout << "\n2. Applicants served by Counter\n" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "- Counter " << i + 1 << " (" << counters[i].primaryVisaType << "): ";
        bool first = true;
        for (int j = 0; j < 4; j++) {
            if (counters[i].applicantsServed[j] > 0) {
                if (!first) cout << ", ";
                cout << visaTypes[j] << ": " << counters[i].applicantsServed[j];
                first = false;
            }
        }
        cout << endl;
    }

    cout << "Total Applicants Served: " << totalServed << endl;
}

int main() {
    string command, visaType;

    while (true) {
        cout << "Enter command (issue/call/summary/available/exit): ";
        cin >> command;

        if (command == "issue") {
            cout << "Enter visa type (TR/MED/BS/GO): ";
            cin >> visaType;
            issueToken(visaType);
        }
        else if(command=="available"){
            NumberOfApplicants();
        }
        else if (command == "call") {
            int counter;
            cout << "Enter counter number (1-4): ";
            cin >> counter;
            if (counter >= 1 && counter <= 4) {
                callNextCustomer(counter - 1);
            } else {
                cout << "Invalid counter number!" << endl;
            }
        }
        else if (command == "summary") {
            generateDailySummary();
        }
        else if (command == "exit") {
            break;
        }
        else {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}
