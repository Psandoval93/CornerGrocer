/*Phillip Sandoval
  CS-210 - Programming Languages
  Project 3: Corner Grocer*/

#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonFile");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonFile");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonFile");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


#include <iostream>

using namespace std;

void main()
{
	int userChoice = -1;	   // Variable declared and intialized to store user choice

	while (userChoice != 4) {  // Creates while loop and executes until user enters 4 to exit

	/* Displays user menu and asks for input for userChoice then assigns input to userChoice*/
			cout << "========================================================" << endl;	// Prints 56 equal signs on a line followed by a new line
			cout << "MENU" << endl;														// Prints MENU in center of 56 spaces followed by a new line
			cout << "1: Check number of time each individual item appears" << endl;		// Prints "1: Check number of time each individual item appears" followed by a new line
			cout << "2: Determine the frequency of a specific item" << endl;			// Prints "2: Determine the frequency of a specific item" followed by a new line
			cout << "3: Graphically display a data file as a text-based histogram" << endl; // Prints "3: Graphically display a data file as a text-based histogram" followed by a new line
			cout << "4: To Exit" << endl;												// Prints "4: To Exit"
			cout << "========================================================" << endl;	// Prints 56 equal signs on a line followed by a new line
			cout << "Please enter your choice: " << endl;								// Prints "Please enter your choice: " to prompt user for input followed by a new line
			cin >> userChoice;															// Receives user input and assigns it to variable userChoice
				if (userChoice == 1) {													// If user input is equal to 1
					cout << "Frequency of item is: " << endl;							// Prints "Frequency of item is: " followed by a new line
					cout << endl;														// Prints empty line
					CallProcedure("GetFrequencyOfEachItem");							// Calls function to get frequency of each item prints function followed by a new line
				}

				else if (userChoice == 2) {												// If user input is equal to 2
					cout << callIntFunc("GetFrequencyOfSingleItem", "item") << endl;	// Calls function to get frequency of a single item prints function followed by a new line
				}

				else if (userChoice == 3) {												// If user input is equal to 3
					cout << "The histogram of the data is: " << endl;					// Prints "The histogram of the data is: " followed by a new line
					CallProcedure("ShowHistogram");										// Calls function to get histogram and prints function followed by a new line
				}
				else if (userChoice == 4) {												// If user inputs is equal to 4
					cout << "You have exited the program. Goodbye!" << endl;			// Prints "You have exited the program. Goodbye!" followed by a new line
					break;																// Terminates program
				}
				else {																	// Else prints "You have entered an invalid option. Try again." followed by a new line then prompts user again
					cout << "You have entered an invalid option. Try again." << endl;
				}
			}

		}


	//CallProcedure("printsomething");
	//cout << callIntFunc("PrintMe","House") << endl;
	//cout << callIntFunc("SquareValue", 2);