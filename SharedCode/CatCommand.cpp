#include "CatCommand.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Constructor 
CatCommand::CatCommand(AbstractFileSystem* file_system) : file_system(file_system) {}

// Tells the user how to invoke the cat command and describes the command.
void CatCommand::displayInfo() {
    cout << "cat command writes into a file, cat can be invoked with the command: cat <filename> [-a]" << endl;
    cout << "the -a option stands for append" << endl;
}

// cat command writes into a file
int CatCommand::execute(string input) {
    int result = success;
    string name = "";
    string arg = "";
    string user_input = ""; // user's input
    vector<char> data; // input data
    vector<char> print; // print the current file
    int wq_tracker; // track where wq: appears
    int q_tracker;   // track where q: appears

    istringstream s(input);
    s >> name >> arg;

    AbstractFile* file = file_system->openFile(name);

    if (file != nullptr) { //checking if file can be opened
        if (arg == "-a") {
            print = file->read();

            for (char& c : print) { //contents of the file should be displayed as bytes only
                cout << c;
            }
            cout << endl;
            cout << "Enter data you would like to append to the existing file. Enter :wq to save the file and exist, enter :q to exist without saving." << endl;
            while (getline(cin, user_input)) {
                wq_tracker = user_input.find(":wq");
                q_tracker = user_input.find(":q");
                if (wq_tracker == string::npos && q_tracker == string::npos) { // When no wq or q has been entered
                    for (char& c : user_input) {
                        data.push_back(c);
                    }
                    data.push_back('\n');
                }
                if (wq_tracker != string::npos) {
                    if (data.size() > 0) {
                        data.pop_back();
                    }
                    for (int i = 0; i < wq_tracker; i++) {
                        data.push_back(input[i]);
                    }
                    result = file->append(data);
                    file_system->closeFile(file);
                    return result;
                }
                if (q_tracker != string::npos) {
                    file_system->closeFile(file);
                    return result;
                }
            }
        }
        else if (arg == "") {
            cout << "Enter data you would like to append to the existing file. Enter :wq to save the file and exist, enter :q to exist without saving." << endl;
            while (getline(cin, user_input)) {
                wq_tracker = user_input.find(":wq");
                q_tracker = user_input.find(":q");
                if (wq_tracker == string::npos && q_tracker == string::npos) {
                    for (char& c : user_input) {
                        data.push_back(c);
                    }
                    data.push_back('\n');
                }
                if (wq_tracker != string::npos) {
                    if (data.size() > 0) {
                        data.pop_back();
                    }
                    for (int i = 0; i < wq_tracker; i++) {
                        data.push_back(user_input[i]);
                    }
                    result = file->write(data);
                    file_system->closeFile(file);
                    return result;
                }
                if (q_tracker != string::npos) {
                    file_system->closeFile(file);
                    return result;
                }
            }
        }
        else {
            cout << "Failed to command with wrong argument" << endl;
            result = wrong_argument_number;
        }
    }
    else {
        cout << "Cannot open file" << endl;
        result = cannot_open_file;
    }
    file_system->closeFile(file);
    return result;
}