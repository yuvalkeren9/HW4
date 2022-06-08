//
// Created by eladm on 07/06/2022.
//

#ifndef HW4_EXCEPTION_H
#define HW4_EXCEPTION_H

#include <exception>
#include <iostream>

class Exception : public std::runtime_error{
public:
    explicit Exception(const std::string& what) : std::runtime_error(what){
    }
};

class DeckFileNotFound : public Exception {
public:
    DeckFileNotFound() : Exception("Deck File Error: File not found"){
    }
};

class DeckFileFormatError: public Exception {
public:
    DeckFileFormatError(std::string& numberOfLine)
    : Exception(std::string("Deck File Error: File format error in line ") + numberOfLine){}
};

class DeckFileInvalidSize : public Exception {
public:
    DeckFileInvalidSize() : Exception("Deck File Error: Deck size is invalid"){
    }
};



#endif //HW4_EXCEPTION_H
