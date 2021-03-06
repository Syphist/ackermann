// ackermann.cpp : Defines the entry point for the console application.
// By Syphist
// Don't try this at home kids

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include <boost/multiprecision/cpp_int.hpp> //this allows for REALLY big numbers
//I found a way not to need this as it was unstable and didn't compile right half the time, but it is worth seeing so I just commented it out
//#pragma comment(linker, "/STACK:4294967296")

using namespace std;
using namespace boost::multiprecision; //LOL

int1024_t ackermann(int1024_t, int1024_t); //KiB integers are the best kind of integers

int main()
{
	try
	{
		//fancy loops with no curly brackets
		for (int i = 0; i <= 4; i++)
			for (int j = 0; j <= (10 - (2 * i)); j++) //no way in hell do you wanna calculate A(4,10) That is 2↑↑13 - 3
				cout << "m = " << i << ", n = " << j << ": " << ackermann(i, j) << endl;
	}
	catch (exception e) //just in case your stack does overflow
	{
		cerr << "Your stack overflowed you dumbo." << endl;
	}

	//prevent window from closing
	cin.ignore();
	return 0;
}

//where the magic happens, see https://en.wikipedia.org/wiki/Ackermann_function for details
int1024_t ackermann(int1024_t m, int1024_t n)
{
	//this is for error catching purposes only
	if (n < 0)
		return -1;

	//having no curly brackets is a borderline fetish
	if (m == 0)
		return n + 1; //remember, to get to those high numbers it has to count there 1 at a time
	else if (m > 0 && n == 0)
		return ackermann(m - 1, 1); //recursion
	else if (m > 0 && n > 0)
		return ackermann(m - 1, ackermann(m, n - 1)); //WE NEED TO GO DEEPER

	//If something goes VERY wrong
	return -1;
}