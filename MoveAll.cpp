/**
CSCI 335 Spring 2024
Project 1
Modified by Allison Lee on February 28, 2024
MoveAll.cpp implements the MoveAll function
*/

#include "MoveAll.hpp"
#include "Book.hpp"

// Moves all Books in "source" with the specified keyword to "dest".
// A Book is moved if any of its keywords match the one specified in this function.
// Use iterators whenever appropriate.
// Hint: you need a const iterator for a const vector, but this will be automatically handled using "auto".

/**
 * @param: a constant string keyword
 * @param: a vector of Books source
 * @param: a vector of Books dest
 * @post: if a book contains a keyword, move book from "source" into "dest"
*/
void moveAll (const std::string keyword, std::vector<Book> &source, std::vector<Book> &dest){
  const auto t1_start = std::chrono::steady_clock::now();
  int books_moved=0; // counts books moved
  // DO NOT ALTER ABOVE HERE

  // iterate through source
  for (auto i = source.begin(); i != source.end(); ++i){
    // iterate through source keywords
    for (auto j = i->getKeywords().begin(); j != i->getKeywords().end(); ++j){
      // check for keyword
      if (*j == keyword){
        books_moved++;
        
        // move book to dest, remove from source, decrement i
        dest.push_back(std::move(*i));
        source.erase(i);
        i--;

        break;
      }
    }
  }

  // DO NOT ALTER BELOW HERE
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "Moved " << books_moved << " books in " << t1 << " microseconds." << std::endl;
}