//
// Created by Adam on 2/26/2017.
//
/*****************************************************************************
 *      Filename:hashtable_3358.cpp
 *      Created on: Apr 13, 2015
 *      Author: Adam C. De Leon
 *      Class: CS3358 Spring 2015 - Data Structors
 *      Section #: 253
 *      Instructor: Jill Seaman
 *      Assignment #: 5
 *      Description: This file implements the functions declared in
 *      hashtable_3358.cpp. The function receives its parameters from main.
 *      Each function definition has a description located
 *      above it.
 ****************************************************************************/
#include <iostream>
#include <string>
#include "hashtable_3358.h"

using namespace std;

/*****************************************************************************
constructor: Initializes hash table to a predetermined size.
*****************************************************************************/
HashTable_3358::HashTable_3358() {
    container.resize(101);
}

/*****************************************************************************
makeEmpty: Removes all the items from the hash table.
*****************************************************************************/
void HashTable_3358::makeEmpty() {
    for (int i = 0; i < container.size(); i++) {
        container[i] = "";
    }
}

/*****************************************************************************
 findPos - This function receives a string as input and generates a hash value
 for that string and assigns it to an integer variable named currentPos. Then
 the function checks to see if the table at that position is empty and does
 not equal another string already in the table. During this process the
 function performs quadratic probing.
 ****************************************************************************/
int HashTable_3358::findPos(string s) const {
    int i = 0;
    int currentPos = hash(s) % container.size();

    while (container[currentPos] != "" && container[currentPos] != s) {
        currentPos += 2 * ++i - 1;
        if (currentPos >= container.size()) {
            currentPos -= container.size();
        }
    }
    return currentPos;
}

/*****************************************************************************
find: Returns true if s is in the hash table, else false.
*****************************************************************************/
bool HashTable_3358::find(string s) const {
    int currentPos = findPos(s);

    if (container[currentPos] == s)
        return true;
    else
        return false;
}

/*****************************************************************************
insert: Adds the string to the hash table, if it is not
already there. (If the hash table becomes 50% full, it rehashes.
*****************************************************************************/
void HashTable_3358::insert(string s) {
    int currentPos = findPos(s);
    if (inserted >= container.size() / 2) {
        reHash();
    }
    if (!container[currentPos].empty()) {
        return;
    } else {
        container[currentPos] = s;
        inserted++;
    }
}

/*****************************************************************************
 hash - this function receives a string as input and generates and returns
 hash value for that string.
 ****************************************************************************/
int HashTable_3358::hash(string key) const {
    int hashVal = 0;
    for (unsigned int i = 0; i < key.length(); i++) {
        hashVal = hashVal * 37 + key[i];
    }
    return hashVal % container.size();
}

/*****************************************************************************
 reHash - this function is called when the load factor of the table has
 reached 50%. Once called it resizes the size of the vector by doubling and
 finding the next prime number greater than the double value. It does this by
 calling nextPrime.
 ****************************************************************************/
void HashTable_3358::reHash() {

    vector<string> oldContainer = container;
    int tmp;
    tmp = (nextPrime(2 * oldContainer.size()));

    makeEmpty();
    container.resize(tmp);

    for (int i = 0; i < oldContainer.size(); i++) {
        if (!oldContainer[i].empty()) {
            insert(oldContainer[i]);
        }
    }
}

/*****************************************************************************
 isPrime - this function takes an integer as a parameter and returns true if
 that number is prime or false otherwise.
 ****************************************************************************/
bool HashTable_3358::isPrime(int number) {
    int i;
    for (i = 2; i < number / 2; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

/*****************************************************************************
 nextPrime - This function receives an integer number as a parameter and find
 the next prime number greater than it.
 ****************************************************************************/
int HashTable_3358::nextPrime(int number) {
    int x = number + 1;
    while (!isPrime(x))
        x++;
    return x;
}

