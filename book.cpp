#include "book.hpp"

std :: string Book :: getId(){
    return id;
}


std :: string Book :: getName(){
    return name;
}


std :: string Book :: getGenre(){
    return genre;
}


std :: string Book :: getAuthor(){
    return author;
}


std :: vector < Review* > Book :: getReviews(){
    return reviews;
}


void Book :: setId(std :: string inputId){
    id = inputId;
}


void Book :: setName(std :: string inputName){
    name = inputName;
}


void Book :: setGenre(std :: string inputGenre){
    genre = inputGenre;
}


void Book :: setAuthor(std :: string inputAuthor){
    author = inputAuthor;
}


void Book :: setAverageRating(double inputAverageRating){
    rating = inputAverageRating;
}


double Book :: getAverageRating(){
    if(reviews.size() == 1)
        return 0;
    double totallLikes = 0;
    for(int i = 0; i < reviews.size(); i++)
        totallLikes += (*reviews[i]).getRating();
    return totallLikes / reviews.size();
}


void Book :: showInfo(){
    std :: cout << "id: " << id << std :: endl;
    std :: cout << "Title: " << name << std :: endl;
    std :: cout << "Genre: " << genre << std :: endl;
    std :: cout << "Author: " << author << std :: endl;
    std :: cout << "Average Rating: " << std :: fixed << std :: setprecision(2) << getAverageRating() << std :: endl;
    for(int i = 0; i < reviews.size(); i++){
        Review review = *reviews[i];
        std :: cout << "id: " << review.getId() << " Rating: " << review.getRating() << " Likes: " << review.getDate() << std :: endl;
    }
}


int Book :: commonGenres(std :: vector < std :: string > genres){
    for(int i = 0; i < genres.size(); i++)
        if(genre == genres[i])
            return 5;
    return 0;
}


Book :: Book(std :: string inputId, std :: string inputName, std :: string inputAuthor, std :: string inputGenre){
    id = inputId;
    name = inputName;
    author = inputAuthor;
    genre = inputGenre;
}



void Book :: addReview(Review* inputReview){
    reviews.push_back(inputReview);
}
