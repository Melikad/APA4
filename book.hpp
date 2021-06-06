#ifndef BOOK_HPP
#define BOOK_HPP "BOOK_HPP"

#include "review.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

class Book{
private:
    std :: string id;
    std :: string name;
    std :: string author;
    std :: string genre;
    double rating;
    std :: vector < Review* > reviews;
public:
    std :: string getId();
    std :: string getName();
    std :: string getGenre();
    std :: string getAuthor();
    std :: vector < Review* > getReviews();
    void addReview(Review* inputReview);
    void setId(std :: string inputId);
    void setName(std :: string inputName);
    void setGenre(std :: string inputGenre);
    void setAuthor(std :: string inputAuthor);
    void setAverageRating(double inputAverageRating);
    double getAverageRating();
    void showInfo();
    int commonGenres(std :: vector < std :: string > genres);
    Book(std :: string inputId, std :: string inputName, std :: string inputAuthor, std :: string inputGenre);
};

#endif
