//#include "Book.hpp"
#include <iostream>
#include <vector>

int main(){
    //Book test_book;
    std::vector<std::string> test_keywords;
    test_keywords.push_back("Spanish Literature");
    test_keywords.push_back("Magical Realism");
    test_keywords.push_back("Romanian Literature");
    for (std::vector<std::string>::iterator it = test_keywords.begin(); it != test_keywords.end(); ++it){
        std::cout << *it << " ";
        //keywords_.push_back(it);
    }
    return 0;
}