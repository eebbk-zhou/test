#ifndef WordList_hpp
#define WordList_hpp

#include <iostream>
#include <string>

using std:: string;

class WordOccurrence {
public:
    WordOccurrence(const string& word="", int num=0);
    bool matchWord(const string &); // returns true if word matches stored
    void increment(); // increments number of occurrences
    string getWord() const;
    int getNum() const;

private:
    string word_;
    int num_;
};

class WordList{
public:
    // add copy constructor, destructor, overloaded assignment
    WordList();
    ~WordList();
    WordList(const WordList&);
    WordList& operator=(WordList);
    // implement comparison as friend
    friend bool equal(const WordList&, const WordList&);
    friend void swap(WordList& first, WordList& second);

    void addWord(const string &);
    void print();
    
    void sort();
     
private:
    WordOccurrence *wordArray_; // a dynamically allocated array of WordOccurrences
                                // may or may not be sorted
    int size_;
};
