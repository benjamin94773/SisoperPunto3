#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Variable global que corresponde a la velocidad de lectura del disco (para calcular el tiempo en que se demora en leer todo)
//Velocidad en pistas por milisegundo
const int VEL = 2; 

void readRequests(vector<int>& requests) {
    string linea;
    while (getline(cin, linea)){
        requests.push_back(stoi(linea));
    }
}

int calculateTotalMovement(vector<int>& sequence, int start) {
    int totalMovement = 0;
    int currentPosition = start;
    int track;
    for (int i = 0; i < sequence.size(); i++) {
        track = sequence[i];
        totalMovement += abs(track - currentPosition);
        currentPosition = track;
    }
    return totalMovement;
}

void scanAlgorithm(vector<int> requests){
    int start = requests[0];
    sort(requests.begin(), requests.end());

    vector<int> sequence;
    for (int i = 0; i < requests.size(); i++) {
        if (requests[i] >= start){
            sequence.push_back(requests[i]);
        }
    }
    for (int i = requests.size() - 1; i >= 0; i--) {
        if (requests[i] < start){
            sequence.push_back(requests[i]);
        } 
    }
    int totalMovement = calculateTotalMovement(sequence, start);
    cout << "SCAN Sequence: ";
    for (int track : sequence) cout << track << " ";
    cout << "\nTotal Movement (SCAN): " << totalMovement << " tracks";
    cout << "\nTotal Time (SCAN): " << totalMovement * VEL << " ms" << endl;
    cout << endl;
}



void cscanAlgorithm(vector<int> requests) {
    int start = requests[0];
    sort(requests.begin(), requests.end());

    vector<int> sequence;
    for (int i = 0; i < requests.size(); i++) {
        if (requests[i] >= start){
            sequence.push_back(requests[i]);
        }
    }
    for (int i = 0; i < requests.size(); i++) {
        if (requests[i] < start){
            sequence.push_back(requests[i]);
        } 
    }

    int totalMovement = calculateTotalMovement(sequence, start);
    cout << "C-SCAN Sequence: ";
    for (int track : sequence) cout << track << " ";
    cout << "\nTotal Movement (C-SCAN): " << totalMovement << " tracks";
    cout << "\nTotal Time (C-SCAN): " << totalMovement * VEL << " ms" << endl;
    cout << endl;
}


int main(){
    vector<int> requests;
    readRequests(requests);
    cscanAlgorithm(requests);
    scanAlgorithm(requests);

    return 0;
}