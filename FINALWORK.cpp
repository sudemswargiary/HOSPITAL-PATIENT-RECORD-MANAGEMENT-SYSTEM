#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_PATIENTS = 25;
const string DATA_FILE = "patients.csv";

int main() {
    string name[MAX_PATIENTS], father[MAX_PATIENTS], mother[MAX_PATIENTS];
    string gender[MAX_PATIENTS], address[MAX_PATIENTS], disease[MAX_PATIENTS];
    string contact[MAX_PATIENTS];
    int age[MAX_PATIENTS], room[MAX_PATIENTS];

    int patientCount = 0;
    int choice;

    ifstream fin(DATA_FILE);
    if (fin) {
        while (patientCount < MAX_PATIENTS && getline(fin, name[patientCount], '|')) {
            getline(fin, father[patientCount], '|');
            getline(fin, mother[patientCount], '|');
            getline(fin, gender[patientCount], '|');
            fin >> age[patientCount];
            fin.ignore();
            getline(fin, contact[patientCount], '|');
            getline(fin, address[patientCount], '|');
            getline(fin, disease[patientCount], '|');
            fin >> room[patientCount];
            fin.ignore();
            patientCount++;
        }
        fin.close();
    }

    do {
        cout << "\n===== HOSPITAL PATIENT RECORD MANAGEMENT SYSTEM =====\n";
        cout << "1. Add New Patient\n";
        cout << "2. Show All Patients\n";
        cout << "3. View Room by Patient Name\n";
        cout << "4. Show a Patient Full Details\n";
        cout << "5. Show Billing Details\n";
        cout << "6. Save & Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "\nPatient Name: ";
            getline(cin, name[patientCount]);
            cout << "Father's Name: ";
            getline(cin, father[patientCount]);
            cout << "Mother's Name: ";
            getline(cin, mother[patientCount]);
            cout << "Gender: ";
            cin >> gender[patientCount];
            cout << "Age: ";
            cin >> age[patientCount];
            cout << "Contact Number: ";
            cin >> contact[patientCount];
            cin.ignore();
            cout << "Address: ";
            getline(cin, address[patientCount]);
            cout << "Disease: ";
            getline(cin, disease[patientCount]);

            room[patientCount] = patientCount + 1;
            cout << "Assigned Room No: " << room[patientCount] << endl;

            patientCount++;
        }

        else if (choice == 2) {
            if (patientCount == 0) cout << "\nNo patients yet.\n";
            else {
                cout << "\n--- All Patients ---\n\n";
                cout << left << setw(5) << "No." << setw(20) << "Name"
                     << setw(10) << "Age" << setw(10) << "Gender"
                     << setw(12) << "Contact" << setw(8) << "Room" << endl;
                cout << string(70, '-') << endl;
                for (int i = 0; i < patientCount; i++) {
                    cout << left << setw(5) << i+1 << setw(20) << name[i]
                         << setw(10) << age[i] << setw(10) << gender[i]
                         << setw(12) << contact[i] << setw(8) << room[i] << endl;
                }
            }
        }

        else if (choice == 3) {
            string search;
            cout << "\nEnter Patient Name: ";
            getline(cin, search);

            bool found = false;
            for (int i = 0; i < patientCount; i++) {
                if (name[i] == search) {
                    cout << "Room No: " << room[i] << endl;
                    found = true;
                }
            }
            if (!found) cout << "Patient not found.\n";
        }

        else if (choice == 4) {
            string search;
            cout << "\nEnter Patient Name: ";
            getline(cin, search);

            bool found = false;
            for (int i = 0; i < patientCount; i++) {
                if (name[i] == search) {
                    cout << "\n--- FULL DETAILS ---\n";
                    cout << "Name: " << name[i] << endl;
                    cout << "Father's Name: " << father[i] << endl;
                    cout << "Mother's Name: " << mother[i] << endl;
                    cout << "Gender: " << gender[i] << endl;
                    cout << "Age: " << age[i] << endl;
                    cout << "Contact: " << contact[i] << endl;
                    cout << "Address: " << address[i] << endl;
                    cout << "Disease: " << disease[i] << endl;
                    cout << "Room No: " << room[i] << endl;
                    found = true;
                }
            }
            if (!found) cout << "Patient not found.\n";
        }

        else if (choice == 5) {
            string search;
            cout << "\nEnter Patient Name for Billing: ";
            getline(cin, search);

            bool found = false;
            for (int i = 0; i < patientCount; i++) {
                if (name[i] == search) {
                    int days;
                    cout << "Enter Number of Days Stayed: ";
                    cin >> days;

                    int roomCharge = days * 2500; 
                    int doctorCharge = 5000;
                    int total = roomCharge + doctorCharge;

                    cout << "\n----- BILL SUMMARY -----\n";
                    cout << "Name: " << name[i] << endl;
                    cout << "Disease: " << disease[i] << endl;
                    cout << "Room Charge (2500/day): " << roomCharge << endl;
                    cout << "Doctor Charge: " << doctorCharge << endl;
                    cout << "Total Bill: " << total << endl;

                    found = true;
                }
            }
            if (!found) cout << "Patient not found.\n";
        }

        else if (choice == 6) {
            ofstream fout(DATA_FILE);
            for (int i = 0; i < patientCount; i++) {
                fout << name[i] << "|" << father[i] << "|" << mother[i] << "|"
                     << gender[i] << "|" << age[i] << "|"
                     << contact[i] << "|" << address[i] << "|" << disease[i] << "|"
                     << room[i] << "\n";
            }
            fout.close();
            cout << "\nSaved & Exiting...\n";
        }

    } while (choice != 6);

    return 0;
}

