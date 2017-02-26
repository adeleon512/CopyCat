/*****************************************************************************
 *      Filename: driver.cpp
 *      Created on: Apr 13, 2015
 *      Author: Adam C. De Leon
 *      Class: CS3358 Spring 2015 - Data Structors
 *      Section #: 253
 *      Instructor: Jill Seaman
 *      Assignment #: 5
 *      Description: This file prompts the user for the name of two input
 *      files. Then it opens those input files and passes them to a function
 *      called getSentences that parses the file into segments of n number of
 *      words. Then it passes those segments to a hash table via an insert
 *      function. While inserting the function checks for duplicates within
 *      each respective hash table and checks to see if the values entered in
 *      the second hash table are in the first hash table. If the values
 *      entered into the second hash table already exist in the first hash
 *      table a count is implemented and recorded to determine how many times
 *      a copied sequence exists. This information is then sent to the user
 *      via the console and the input files are closed.
 ****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <vector>
#include "hashtable_3358.h"

using namespace std;

//prototype
vector<string> &getSentence(string, vector<string> &, unsigned int);

int main() {
    HashTable_3358 table1, table2;
    string file1 = "";
    string file2 = "";
    ifstream fin1, fin2;
    vector<string> seq1, seq2;
    unsigned int seq_qty;

    //Prompt user for input.
    cout << "Please enter name of the first file to analyze: ";
    cin >> file1;
    fin1.open(file1.c_str());

    cout << "Please enter name of the second file to analyze: ";
    cin >> file2;
    fin2.open(file2.c_str());

    cout << "Please enter the number of words per sequence: ";
    cin >> seq_qty;

    getSentence(file1.c_str(), seq1, seq_qty);
    getSentence(file2.c_str(), seq2, seq_qty);

    //file the first hash table with sequences while checking for duplicates.
    for (unsigned int i = 0; i < seq1.size(); i++) {
        if (!table1.find(seq1[i])) {
            table1.insert(seq1[i]);
        }
    }

    cout << endl;

    /*fill in the second hash table while checking for duplicates and checking
     * to see if the entry exists inside the first hash table.*/
    int copy = 0;
    for (unsigned int j = 0; j < seq2.size(); j++) {
        if (!table2.find(seq2[j])) {
            table2.insert(seq2[j]);
        }
        if (table1.find(seq2[j])) {
            copy = copy + 1;
        }
    }

    //Send output to user.
    cout << "Word count " << file1.c_str() << " " << seq1.size() << endl;
    cout << "Word count " << file2.c_str() << " " << seq2.size() << endl;
    cout << "Sequences in common: " << copy << endl;

    fin1.close();
    fin2.close();

    return 0;
}

/*****************************************************************************
 * getSentence - this function reads input file and parses the strings into
 * sequences of n words defined by the user as it iterates over the file one
 * word at a time. Then it returns these sequences one at a time for further
 * processing.
 ****************************************************************************/
vector<string> &getSentence(string file, vector<string> &sentences,
                            unsigned int seq_qty) {
    string word, words, str;
    deque<string> dq_str;
    ifstream infile;
    int count = 0;

    infile.open(file.c_str());

    while (infile >> word) {
        dq_str.push_back(word);
        count++;
        if (count == seq_qty) {
            for (int i = 0; i < seq_qty; i++) {
                if (i < seq_qty - 1) {
                    words.append(dq_str[i] + " ");
                } else {
                    words.append(dq_str[i]);
                }
            }
            sentences.push_back(words);
            words.erase(words.begin(), words.end());
            dq_str.pop_front();
            count = seq_qty - 1;
        }
    }
    return sentences;
}
