#include "review.hpp"

double Review :: getNumberOfLikes(){
    return numberOfLikes;
}

std :: string Review :: getUserId(){
    return userId;
}

int Review :: getRating(){
    return rating;
}


Review :: Review(std :: string _id, std :: string _bookId, std :: string _userId,
    int _rating, std :: string _date, int _numberOfLikes){
        id = _id;
        bookId = _bookId;
        userId = _userId;
        rating = _rating;
        date = _date;
        numberOfLikes = _numberOfLikes;
}


std :: string Review :: getBookId(){
    return bookId;
}


std :: string Review :: getId(){
    return id;
}


std :: string Review :: getDate(){
    return date;
}
