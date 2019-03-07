// practiceMakesPerfectInPlace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*assignment was a technical interview question given to some other 
person on youtube in Java

I was inspired to try the same assignment in C-style C++ code

the goal was to have original string 
"perfect makes practice"
transformed into
"practice makes perfect

"*/

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

char original[] = {"perfect makes practice"};
const char * result = {"practice makes perfect"};

int findTokenInd(char *str, char token) {
	int i = 0;
	while (true) {
		if (*(str+i) == token)
			return i;
		else if (*(str+i) == '\0')
			return -1;
		i++;
	}
}

char * reverseStr(char *str, int length){
	//reverse entire string
	//return resulting string
	int finalPos = length - 1;
	int j = 0;
	while (j < finalPos ) {
		char temp = str[finalPos];
		str[finalPos] = str[j];
		str[j] = temp;
		j++;
		finalPos--;
	}
	return str;
}

char * reverseSubStr(char*str) {
	//find the tokens i.e. substrings and for each substring 
	//reverse that substring
	//return original pointer
	char*origStr = str;
	char* str0 = str;
	int i = 0, j = 0;
	int spaceInd = 0;
	while (spaceInd != -1) { 
		spaceInd = findTokenInd(str0,' ');
		if (spaceInd != -1) {
			//youre good you found substrings
			j = spaceInd ; //length variable
			reverseStr(str0, j); //reverse the substring from strpointer into the length of substring
			str0 += (j + 1); //increment the strpointer to advance into the next substring
		} else {
			//you found final token, substring limited by endingchar and startpointer
			// strpointer should be in the correct position already by now
			//such that you can get the final token and break from loop
			j = strlen(str0);
			reverseStr(str0, j);
		}	
	}

	return str; //return the original string 
}


char * reverseInPlace(char *str){

	//reverse entire string
	//reverse substrings
	//return result
	str = reverseStr(str, strlen(str));
	return reverseSubStr(str);

	//with regular C++ strings this would have been easier
	//but with good old C strings you had to think about the 
	//tokenizing, but if you've ever done tokenizers, used strtok, 
	//or written parsers which have tokenizing
	//then you get the basic idea.

}


int main()
{
	cout << "original was:" << original << endl;
	cout << "resulted was:"<<reverseInPlace(original) << endl;
    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
