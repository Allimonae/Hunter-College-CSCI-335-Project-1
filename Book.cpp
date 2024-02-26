#include "Book.hpp"

    // write and document all methods in this file.
    Book::Book():title_(""), author_(""), ISBN_(0), icon_(0), price_(0.0)
    {
        keywords_.clear();
    }

    Book::~Book()
    {

    }

    Book::Book(const Book& rhs) : Book()
    {
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        icon_ = rhs.icon_;
        price_ = rhs.price_;
        keywords_ = rhs.keywords_;
    }

    Book& Book::operator=(const Book& rhs)
    {
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        icon_ = rhs.icon_;
        price_ = rhs.price_;
        keywords_ = rhs.keywords_;
        return *this;
    }

    Book::Book(Book&& rhs)
    {
        
    }

    Book& Book::operator=(Book&& rhs)
    {

    }

    const std::string& Book::getTitle() const
    {
        return title_;
    }

    void Book::setTitle(const std::string& title)
    {
        title_ = title;
    }

    const std::string& Book::getAuthor() const
    {
        return author_;
    }

    void Book::setAuthor(const std::string& author)
    {
        author_ = author;
    }

    long long int Book::getISBN() const
    {
        return ISBN_;
    }

    void Book::setISBN(long long int ISBN)
    {
        ISBN_ = ISBN;
    }

    const int* Book::getIcon() const
    {
        return icon_;
    }

    void Book::setIcon(int* icon)
    {
        icon_ = icon;
    }

    float Book::getPrice() const
    {
        return price_;
    }

    void Book::setPrice(float price)
    {
        price_ = price;
    }

    const std::vector<std::string>& Book::getKeywords() const
    {
        return keywords_;
    }

    void Book::setKeywords(const std::vector<std::string>& keywords)
    {
        keywords_ = keywords;
    }

    const std::string& Book::getBlurb() const
    {
        return blurb_;
    }

    void Book::setBlurb(const std::string& blurb)
    {
        blurb_ = blurb;
    }

    void Book::print() const
    {
        std::cout << "Title: " << title_ 
                  << "\nAuthor: " << author_ 
                  << "\nISBN: " << ISBN_ 
                  << "\nIcon: " << icon_ 
                  << "\nPrice: " << price_ 
                  << "\nKeywords: ";
        for (std::vector<std::string>::const_iterator it = keywords_.begin(); it != keywords_.end(); ++it){
            std::cout << *it << " ";
        }
        std::cout << "\nBlurb: " << blurb_ << "\n";
    }