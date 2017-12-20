*******************************************************
*  Name      :  Brian Pina
*  Student ID:  104790387
*  Class     :  CSC 2421           
*  HW#       :  5
*  Due Date  :  march, 09 2016
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************
This program simulates a grocery store of 5 lines using a vector of queues, that will hold time stamps from  3 classes that are used to create customers, average times, and ring a customer up

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions,creates a vector of queues, and has a non member fucntion that is used to determine which line has the fewest amount of customers or if all have the same amount of customers
Name:  grocerystore.h
   Contains the definition for the class bool_source, cashier, averager and also non member functions

Name: grocerystore.cpp
   Defines and implements bool_ssource which provides the program with the probablilty of their being a customer using rand() also averager class whichs recieves all the times from the cashier lines and 
calculates a average time for all customers rung, chasier class handels all the customer innpuut , probabilty.
   
   
*******************************************************
*  Circumstances of programs
*******************************************************

   Program Compiles and runs on csegrid
developed on cLion using mingw
does all task but i think generates the same random number for each register


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [PinaHW6]

   Now you should see a directory named homework with the files:
        main.cpp
        grocerystore.cpp
	grocerystore.h
	    makefile

2. Build the program.

    Change to the directory that contains the file by:
    % cd [PinaHW6]

    Compile the program by:
    % make

3. Run the program by:
   % ./[Homework6]

4. Delete the obj files, executables, and core dump by
   %./make clean
