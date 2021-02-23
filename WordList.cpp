#include "WordList.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using std::endl; using std::cout; using std::string; using std::swap;

// Functions of WordOccurrence

WordOccurrence::WordOccurrence(const string& word, int num){
    word_ = word;
    num_ = num;
}

bool WordOccurrence::matchWord(const string & new_word){
    int i = 0;
    for(; word_[i] != '\0'; i++){
        if(word_[i] != new_word[i])
            return false;
    }
    if(new_word[i] != '\0')
        return false;
    return true;
}

void WordOccurrence::increment(){
    ++num_;
}

string WordOccurrence::getWord() const{
    return word_;
}
int WordOccurrence::getNum() const{
    return num_;
}


// Functions of WordList


 WordList::WordList(){
    size_ = 0;
     wordArray_ = new WordOccurrence[size_];
}

 WordList::~WordList(){
    if(wordArray_ != NULL){
        delete[] wordArray_;
        size_ = 0;
    }
}

void WordList::print(){
    cout << std::setprecision(10);
    int filedLength = 35;
    cout << "word:" << std::setw(filedLength) << "occurred times:" << endl;
    
    for(int i = 0; i < size_; i++){
        cout << std::setprecision(10);
       // cout << "word: " << wordArray_[i].getWord() << "occurred times: " << //wordArray_[i].getNum() << endl;
        cout << std::left << std::setw(filedLength) << wordArray_[i].getWord() << wordArray_[i].getNum() << endl;
    }
}

bool equal(const WordList& lhs, const WordList& rhs){
    if(lhs.size_ != rhs.size_)
        return false;
    for(int i = 0; i < lhs.size_; i ++){
        if(lhs.wordArray_[i].getWord() != rhs.wordArray_[i].getWord())
            return false;
    }
    
    return true;
}


WordList::WordList(const WordList& other){
    size_ = other.size_;
    wordArray_ = size_ > 0 ? new WordOccurrence[size_] : nullptr;
    std::copy(other.wordArray_, other.wordArray_ + size_, wordArray_);
    
}

void swap(WordList& first, WordList& second){
    std::swap(first.size_, second.size_);
    std::swap(first.wordArray_, second.wordArray_);
}

WordList& WordList::operator=(WordList other){
   swap(*this, other);
    return *this;
}


void WordList::addWord(const string &new_string){
    bool check = true;

    for(int i = 0; i < size_; i++){
        if( wordArray_[i].matchWord(new_string)){
           check = false;
            wordArray_[i].increment();
        }
    }
    
    if(check){
        WordList obj;
        WordOccurrence obj2(new_string, 1);
        obj.size_ = size_ + 1;
        obj.wordArray_ = new WordOccurrence[obj.size_];
        int i = 0;
        for(; i < size_; i++){
            obj.wordArray_ [i] = wordArray_[i];
        }
        obj.wordArray_ [i] = obj2;
        swap(*this, obj);
    }
}
/*
void WordList::sort(){
    for(int i = 0; i < size_ - 1; ++i)
    {
        for(int j = 0; j < size_ - i - 1; ++j)
        {
            //sort in rarest word order
            if(wordArray_[j].getNum() > wordArray_[j + 1].getNum())
                {
                    WordOccurrence temp = wordArray_[j + 1];
                    wordArray_[j + 1] = wordArray_[j];
                    wordArray_[j] = temp;
                }
        }
    }
    }
 */
void WordList::sort(){
    WordOccurrence temp, temp2;
    WordList obj;
    obj.size_ = size_;
    obj.wordArray_ = new WordOccurrence[obj.size_];
    
    for(int i = size_ - 1; i >= 0; i--){
        int k = 0;
        for(int j = 0; j < size_; j++){
            if(wordArray_[j].getNum() > temp.getNum()) {
               temp = wordArray_[j];
                k = j;
            }
        }
        for(int g = 0; g < size_; g++){
            if(wordArray_[g].getNum() == temp.getNum()){
                if(wordArray_[g].getWord() > temp.getWord()){
                   
                    temp = wordArray_[g];
                     k = g;
                }
            }
        }
        obj.wordArray_[i] = temp;
        wordArray_[k] = temp2;
        temp = temp2;
    }
   
    swap(*this, obj);
}
