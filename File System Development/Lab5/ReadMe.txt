Lab 5 Readme.txt

group member:
Jingyuan Zhu, Mingzhen Li
jzhu22@wustl.edu, l.mingzhen@wustl.edu

work split:
Jingyuan Zhu works on the DisplayCommand, BasicDisplayVisitor, CopyCommand, CommandPrompt, TouchCommand, and main function.
Mingzhen Li works on CatCommand, LSCommand, MacroCommand, RemoveCommand, and RenameCommand.

Errors occurred:
we do not encounter any error when testing in the ternimal because we only start testing when all the tests in the test explore have
passed.


tests we've run in the main function:

test the ls command
H:\CSE332s\cse332s-su22-wustl\cse332s-su22-wustl\oop-work-gang\Lab5\x64\Debug> Lab5.exe
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
image1.txt     text.txt
text2.txt

test the ls -m command
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls -m
image1.img  image      9
text.txt   text      5
text2.txt   text      5

continue to test the rm command
$  ls
image1.img     text.txt
text2.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  rm text.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
image1.img     text2.txt

the text.txt is removed by expectation

now test the touch command (also includes seting password for the file)
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch file.txt
Successfully added the file
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch file.txt -p
What is the passowrd?
1234
fail to add the file
command fails to execute
The command dose not exist
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$

continue to test the cat command
$  cat file.txt
Enter data you would like to append to the existing file. Enter :wq to save the file and exist, enter :q to exist without saving.
123
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat file.txt -a
123
Enter data you would like to append to the existing file. Enter :wq to save the file and exist, enter :q to exist without saving.
321
:wq

now display the result for the file.txt that is run by the cat command
$  ds file.txt
123321
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$

we can also display another existed file with the correct format
$  ds image1.img
X X
 X
X X
we can also display the image file with no format 
$  ds image1.img -d
X X X X X
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.

Next, test the copy command
$  touch file1.txt
Successfully added the file
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat file1.txt
Enter data you would like to append to the existing file. Enter :wq to save the file and exist, enter :q to exist without saving.
123456
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cp file1.txt file2
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds file2
The file does not exist
command fails to execute
The command dose not exist
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds file2.txt
123456
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat file2.txt
Enter data you would like to append to the existing file. Enter :wq to save the file and exist, enter :q to exist without saving.
hello
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds file1.txt
123456
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$

The copied file does not influence the original file

now, test the rename command
$  rn file1.txt file3
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat file1.txt
Cannot open file
command fails to execute
The command dose not exist
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat file3.txt
Enter data you would like to append to the existing file. Enter :wq to save the file and exist, enter :q to exist without saving.

The file's name has been changed to file3.txt

Finally, test the macroCommand
$  cat file3.txt
Enter data you would like to append to the existing file. Enter :wq to save the file and exist, enter :q to exist without saving.
:q
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.

Lastly, when the user prompts q, the program exits
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  q

H:\CSE332s\cse332s-su22-wustl\cse332s-su22-wustl\oop-work-gang\Lab5\x64\Debug>


