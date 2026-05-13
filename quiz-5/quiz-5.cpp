
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Sensor{
    int sensor_id;
    float sicaklik;
};

int main(){

    int studentID;
    int N, E;

    cout << "Enter your student ID: ";
    cin >> studentID;

    N = studentID % 50;
    E = studentID % 100;

    fstream binFile("sensors.bin", ios::in | ios::out | ios::binary);

    if(!binFile){
        cout << "File could not be opened!" << endl;
        return 1;
    }

    Sensor temp;

    binFile.seekg(N * sizeof(Sensor), ios::beg);

    binFile.read((char*)&temp, sizeof(Sensor));

    float oldTemp = temp.sicaklik;

    temp.sicaklik = temp.sicaklik + E;

    binFile.seekp(N * sizeof(Sensor), ios::beg);

    binFile.write((char*)&temp, sizeof(Sensor));

    binFile.close();

    // Step 4
    string fileName = to_string(studentID) + "_Quiz5.txt";

    ofstream reportFile(fileName);

    reportFile << "Number: " << studentID << endl;
    reportFile << "Sensor Index Used in the Process: " << N << endl;
    reportFile << "First Temperature: " << oldTemp
               << " -> New Temperature: "
               << temp.sicaklik << endl;

    reportFile.close();

    cout << "Process completed successfully." << endl;

    return 0;
}