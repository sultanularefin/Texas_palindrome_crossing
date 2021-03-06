// Texas_palindrome_crossing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
using namespace std;

// Complete longestPalindromeSubstring function
// DO NOT MODIFY anything outside the below function


int longestPalindromeSubstring(string str)
{
	vector<int> result;
	list <string> subsets;
	list <string>::iterator p = subsets.begin();
	stack <char> p_stack;

	std::transform(str.begin(), str.end(), str.begin(), ::tolower);

	//greater than 3
	char words[50]; // assming string length is around 50 ; 53-3= 50; // 3 min. palindorome word length
	int psi; // primaryStringindex  outer counter
	int str_j_counter;//2nd counter for string (str) traversing.
	;
	int innerloop;

	int len = str.length();
	int min_p_word_length = 3;
	int saved_min_p_word_length = min_p_word_length;

	for (psi = 0; psi <= len - saved_min_p_word_length; psi++)
	{
		min_p_word_length = saved_min_p_word_length;

		while (min_p_word_length <= (len - psi)) {

			for (str_j_counter = 0; ((str_j_counter <= min_p_word_length - 1) && (str[psi] != '\n')); str_j_counter++) {
				words[str_j_counter] = str[psi + str_j_counter];

				if (str_j_counter == min_p_word_length - 1) {
					words[str_j_counter + 1] = '\0';
					//string termination in c++ ==>
					//If you want to be explicit, you could write: char a[] = {'a','b','c','\0'};
				}
			}

			subsets.push_front(words);

			min_p_word_length++;
		}
	}

	//for (std::list<std::string>::iterator i = subsets.begin(); i != subsets.end(); ++i)


	p = subsets.begin();
	//for (list<string>::iterator i = subsets.begin(); i != subsets.end(); ++i)
	while (p != subsets.end())

	{
		cout << *p;
		cout << "\n";
		//printf("%s\n", i->c_str());
		p++;
		// msvc string --> c_str() is : // return pointer to null-terminated immutable array
	}

	p = subsets.begin();
	char char_array[50 + 1];
	int output;

	while (p != subsets.end())
	{
		strcpy(char_array, p->c_str());
		output = (unsigned)strlen(char_array);

		string str = "";

		for (int i = 0; char_array[i]; i++) {
			// ch is a stack
			p_stack.push(char_array[i]);
			str = str + char_array[i];
		}

		int len = str.length();

		int count = 0;

		for (int i = 0; i < len / 2; i++) {

			if (char_array[i] == p_stack.top()) {
				p_stack.pop();
				count++;
			}
			else break;
		}

		if (count == len / 2)
			result.push_back(output);

		p++;
	}

	std::sort(result.begin(), result.end());


	if (!result.empty())
	{
		return result.back(); // return length of LPS
	}
	else {
		return 0; // no palindrome.
	}
}

// DO NOT MODIFY anything outside the above function

int main() {
	/* Read input from STDIN. Print output to STDOUT */
	string inputString;
	getline(cin, inputString); //Skip line break
	int output = longestPalindromeSubstring(inputString);
	cout << output;
	return 0;
}
