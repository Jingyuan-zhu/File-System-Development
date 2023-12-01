#include "LSCommand.h"
#include "MetadataDisplayVisitor.h"
#include <iomanip>
#include <iostream>

// Constructer
LSCommand::LSCommand(AbstractFileSystem* file_system) : file_system(file_system) {}

// Tells the user how to invoke the ls command and describes the command.
void LSCommand::displayInfo() {
    cout << "ls command ouputs all files' names, ls can be invoked with the command: ls (or ls -m)" << endl;
    cout << "-m can display a single file per line along with the metadata associated with the file" << endl;
}

// ls command ouputs all files' names
int LSCommand::execute(string input) {
    int result = success;
    set<string> files = file_system->getFileNames();
    int counter = 1;
    if (input == "") {
        for (auto it = files.begin(); it != files.end(); ++it) {
            cout << *it;
            cout << "     ";
            if (counter % 2 == 0) {
                cout << endl;
            }
            counter++;
        }
        cout << endl;
    }
    else if (input == "-m") {      // aditional option "-m"
        AbstractFileVisitor* visitor = new MetadataDisplayVisitor();
        for (auto it = files.begin(); it != files.end(); ++it) {
            AbstractFile* f = file_system->openFile(*it);
            f->accept(visitor);
            file_system->closeFile(f);
        }
    }
    else {
        cout << "Command failed for wrong argument." << endl;
        result = wrong_argument_number;
    }
    return result;
}