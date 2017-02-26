//
// Created by Adam on 2/26/2017.
//

#ifndef COPYCAT_HASHTABLE_3358_H
#define COPYCAT_HASHTABLE_3358_H

/*****************************************************************************
 *      Filename:hashtable_3358.h
 *      Created on: Apr 13, 2015
 *      Author: Adam C. De Leon
 *      Class: CS3358 Spring 2015 - Data Structors
 *      Section #: 253
 *      Instructor: Jill Seaman
 *      Assignment #: 5
 *      Description: This is a header file that declares the functions that
 *      will be defined in the implementation file hashtable_3358.cpp
 ****************************************************************************/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class HashTable_3358
{
public:

	/****************************
	constructor: Initializes hash table to a predetermined size.
	*****************************/
	HashTable_3358 ();
	/****************************
	makeEmpty: Removes all the items from the hash table.
	*****************************/
	void makeEmpty();
	/****************************
	find: Returns true if s is in the hash table, else false.
	*****************************/
	bool find(string s) const;
	/****************************
	insert: Adds the string to the hash table, if it is not
	already there. (If the hash table becomes 50% full, it rehashes.)
	*****************************/
	void insert (string s);

private:

	vector<string> container;
	int inserted = 0;
	int hash(string s) const;
	void reHash();
	bool isPrime(int number);
	int nextPrime (int number);
	int findPos(const string s) const;

};

#endif //COPYCAT_HASHTABLE_3358_H
