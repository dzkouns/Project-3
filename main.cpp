#include <iostream>    
#include <fstream>   
#include <string>  
#include <map>

using namespace std;   


class FrequencyData {    
public:
 
    void readDataFromFile(const string& fileName) {
        ifstream inputFile(fileName);    

        string itemName;
        int itemCount;


        while (inputFile >> itemName >> itemCount) {
            data[itemName] += itemCount;
        }

        inputFile.close();  
    }


    int getItemFrequency(const string& itemName) {
        return data[itemName];
    }


    void printAllItems() {
        for (auto& item : data) {
            cout << item.first << " " << item.second << endl;
        }
    }


    void printHistogram() {
        for (auto& item : data) {
            cout << item.first << " ";
            for (int i = 0; i < item.second; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }


    void writeDataToFile(const string& fileName) {
        ofstream outputFile(fileName);    
      
        for (auto& item : data) {
            outputFile << item.first << " " << item.second << endl;
        }

        outputFile.close();    
    }

private:
    map<string, int> data;    
};


int displayMenuAndGetInput() {
    int input;
    cout << "\nMenu Options:" << endl;
    cout << "1. Get the frequency of a specific item" << endl;
    cout << "2. Print the frequency of all items" << endl;
    cout << "3. Print a histogram of item frequency" << endl;
    cout << "4. Exit the program" << endl;
    cout << "Enter your choice: ";
    cin >> input;   
    return input;
}

int main() {

    FrequencyData frequencyData;


    frequencyData.readDataFromFile("CS210_Project_Three_Input File.txt");


    int input = displayMenuAndGetInput();


    while (input != 4) {
        switch (input) {
        case 1: {

            string itemName;
            cout << "Enter the name of the item: ";
            cin >> itemName;
            int frequency = frequencyData.getItemFrequency(itemName);
            cout << "Frequency of " << itemName << ": " << frequency << endl;
            break;
        }
        case 2: {

            frequencyData.printAllItems();
            break;
        } 
        case 3: {

            frequencyData.printHistogram();
            break;
        }
        default: {
            cout << "Invalid choice" << endl;
            break;
        }
        }


        input = displayMenuAndGetInput();
    }


    frequencyData.writeDataToFile("frequency.dat");

    return 0;
}
