/**
CSCI 335 Spring 2024
Project 1
Modified by Allison Lee on February 28, 2024
Book.cpp declares the Book class and implements its private and public members
*/

#include "Book.hpp"

    // write and document all methods in this file.

    /**
     * Default constructor
    */
    Book::Book():title_(""), author_(""), ISBN_(0), icon_(nullptr), price_(0.0), blurb_("")
    {
        keywords_.clear();
    }

    /**
     * Destructor
    */
    Book::~Book()
    {

    }

    /**
     * Copy Constructor
    */
    Book::Book(const Book& rhs) : Book()
    {
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;

        icon_ = new int[80];
        for (int i = 0; i < 80; i++){
            icon_[i] = rhs.icon_[i];
        }

        price_ = rhs.price_;
        keywords_ = rhs.keywords_;
        blurb_ = rhs.blurb_;
    }

    /**
     * Copy Assignment Operator
    */
    Book& Book::operator=(const Book& rhs)
    {
        Book copy = rhs;
        delete[] icon_;
        std::swap(*this, copy);
        icon_ = nullptr;
        return *this;
    }

    /**
     * Move Constructor
    */
    Book::Book(Book&& rhs): title_(rhs.title_), author_(rhs.author_), ISBN_(rhs.ISBN_), 
        icon_(rhs.icon_), price_(rhs.price_), keywords_(std::move(rhs.keywords_)), blurb_(rhs.blurb_)
    {
        delete[] rhs.icon_;
        rhs.icon_ = nullptr;
    }

    /**
     * Move Assignment Operator
    */
    Book& Book::operator=(Book&& rhs)
    {
        if (&rhs != this){
            std::swap(title_, rhs.title_);
            std::swap(author_, rhs.author_);
            std::swap(ISBN_, rhs.ISBN_);
            std::swap(price_, rhs.price_);
            std::swap(keywords_, rhs.keywords_);
            std::swap(blurb_, rhs.blurb_);

            // delete rhs.icon_
            delete[] icon_;
            std::swap(icon_, rhs.icon_);
            rhs.icon_ = nullptr;
        }
        return *this;
    }

    /**
     * title_ Accessor
     * @return: a const reference to string title_
    */
    const std::string& Book::getTitle() const
    {
        return title_;
    }

    /**
     * title_ Mutator
     * @param: a const reference to string title
    */
    void Book::setTitle(const std::string& title)
    {
        title_ = title;
    }

    /**
     * author_ Accessor
     * @return: a const reference to string author_
    */
    const std::string& Book::getAuthor() const
    {
        return author_;
    }

    /**
     * author_ Mutator
     * @param: a const reference to string author
    */
    void Book::setAuthor(const std::string& author)
    {
        author_ = author;
    }

    /**
     * ISBN_ Accessor
     * @return: a long long integer ISBN_
    */
    long long int Book::getISBN() const
    {
        return ISBN_;
    }

    /**
     * ISBN_ Mutator
     * @param: a long long integer ISBN
    */
    void Book::setISBN(long long int ISBN)
    {
        ISBN_ = ISBN;
    }

    /**
     * icon_ Accessor
     * @return: a const pointer to array of integers icon_
    */
    const int* Book::getIcon() const
    {
        return icon_;
    }

    /**
     * icon_ Mutator
     * @param: a pointer to array of integers icon
    */
    void Book::setIcon(int* icon)
    {
        delete[] icon_;
        icon_ = icon;
    }

    /**
     * price_ Accessor
     * @return: a float price_
    */
    float Book::getPrice() const
    {
        return price_;
    }

    /**
     * price_ Mutator
     * @param: a float price
    */
    void Book::setPrice(float price)
    {
        price_ = price;
    }

    /**
     * keywords_ Accessor
     * @return: a const reference to a vector of strings keywords_
    */
    const std::vector<std::string>& Book::getKeywords() const
    {
        return keywords_;
    }

    /**
     * keywords_ Mutator
     * @param: a const reference to a vector of strings keywords
    */
    void Book::setKeywords(const std::vector<std::string>& keywords)
    {
        keywords_ = keywords;
    }

    /**
     * blurb_ Accessor
     * @return: a const reference to string blurb_
    */
    const std::string& Book::getBlurb() const
    {
        return blurb_;
    }

    /**
     * blurb_ Mutator
     * @param: a const reference to string blurb
    */
    void Book::setBlurb(const std::string& blurb)
    {
        blurb_ = blurb;
    }

    /**
     * @post: print Book information
    */
    void Book::print() const
    {
        //print title
        std::cout << "Title: " << title_

        //print author
                  << "\nAuthor: " << author_ 

        //print ISBN
                  << "\nISBN: " << ISBN_ ;

        //print every integer in array icon, separate by space
        std::cout << "\nIcon: ";
        // check if icon_ exists
        if (icon_){
            for (int i = 0; i < 80; i++){
                std::cout << icon_[i] << " ";
            }
        }

        //print price, must be 2 decimal places
        std::cout << "\nPrice: $" << std::fixed << std::setprecision(2) << price_;

        //print every string in vector keywords, separate by comma
        std::cout << "\nKeywords: ";
        //check if keywords isn't empty
        if (!keywords_.empty()){
            // iterate through keywords_
            for (auto it = keywords_.begin(); it != keywords_.end() - 1; ++it){
                std::cout << *it << ", ";
            }
                std::cout << keywords_.back();
        }

        //print blurb
        std::cout << "\nBlurb: " << blurb_ << "\n";
    }