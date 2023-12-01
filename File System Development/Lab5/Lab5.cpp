// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/AbstractFile.h "
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/LSCommand.h"
#include "../../SharedCode/RemoveCommand.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CatCommand.h"
#include "../../SharedCode/DisplayCommand.h"
#include "../../SharedCode/CopyCommand.h"
#include "../../SharedCode/MacroCommand.h"
#include "../../SharedCode/RenameParsingStrategy.h"

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char * argv[])
{
	AbstractFileFactory* ff = new SimpleFileFactory();
	AbstractFileSystem* fs = new SimpleFileSystem();

	AbstractCommand* com1 = new TouchCommand(fs, ff);
	AbstractCommand* com2 = new LSCommand(fs);
	AbstractCommand* com3 = new RemoveCommand(fs);
	AbstractCommand* com4 = new DisplayCommand(fs);
	AbstractCommand* com5 = new CatCommand(fs);
	AbstractCommand* com6 = new CopyCommand(fs);

	// now add command 
	// configure the command prompt with each of the implemented command
	CommandPrompt cp;
	cp.setFileSystem(fs);
	cp.setFileFactory(ff);
	cp.addCommand("touch", com1);
	cp.addCommand("ls", com2);
	cp.addCommand("rm", com3);
	cp.addCommand("ds", com4);
	cp.addCommand("cat", com5);
	cp.addCommand("cp", com6);
	
	// add rename command
	
	MacroCommand* mc = new MacroCommand(fs);
	RenameParsingStrategy* rps = new RenameParsingStrategy;
	mc->setParseStrategy(rps);
	mc->addCommand(com6);
	mc->addCommand(com3);
	cp.addCommand("rn", mc);


	// add support for an additional MacroCommand 
	// cat + ds: edit a file and then display it afterwards to see the edits.
	MacroCommand* mc2 = new MacroCommand(fs);
	RenameParsingStrategy* rps2 = new RenameParsingStrategy;
	mc2->setParseStrategy(rps2);
	mc2->addCommand(com5);
	mc2->addCommand(com4);
	cp.addCommand("cat ds", mc2);

	// now add some files to the system to allow the use of ls and ls -m
	AbstractFile* t = new TextFile("text.txt");
	vector<char> t1 = { 'h', 'e','l','l','o'};
	t->write(t1);
	fs->addFile(t->getName(),t);

	AbstractFile* t2 = new TextFile("text2.txt");
	vector<char> t2x = { 'n', 'i','h','a','o' };
	t2->write(t2x);
	fs->addFile(t2->getName(), t2);
	int quit = 10;

	AbstractFile* i = new ImageFile("image1.img");
	vector<char> i1 = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
	i->write(i1);
	fs->addFile(i->getName(), i);

	// run the command 
	int end = 0;
	while (end != quit) {
		end = cp.run();
	}

	// finally, delete all dynamically allocated resources to avoid memeory leak issues
	delete ff;
	delete fs; 

	delete com1;
	delete com2;
	delete com3;
	delete com4;
	delete com5;
	delete com6;

	return 0;
}


