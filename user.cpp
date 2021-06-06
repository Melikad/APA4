#include "user.hpp"

#define want_to_read 0
#define currently_reading 1
#define read 2


void User :: setFollowing(std :: vector < std :: string > ids){
    followingsId = ids;
}


std :: vector < std :: string > User :: getFollowings(){
    return followingsId;
}


void User :: addReview(Review* inputReview){
    reviews.push_back(inputReview);
}


std :: vector < std :: string > User :: getFavoriteGenres(){
    return favoriteGenresId;
}


int User :: getTotallNumberOfLikes(){
    int totallLikes = 0;
    for(int i = 0; i < reviews.size(); i++)
        totallLikes += reviews[i]->getNumberOfLikes();
    return totallLikes;
}


void User :: showUserInfo(){
    std :: cout << "id: " << id << std :: endl;
    std :: cout << "Name: " << name << std :: endl;
    std :: cout << "Place of Birth: " << placeOfBirth << std :: endl;
    std :: cout << "Member Since: " << memberSince << std :: endl;
    std :: cout << "favorite Genres: ";
    for(int i = 0; i < favoriteGenresId.size(); i++)
        std :: cout << favoriteGenresId[i] << " ";
    std :: cout << std :: endl;
    std :: cout << "Favorite Authors: ";
    for(int i = 0; i < favoriteAuthorsId.size(); i++)
        std :: cout << favoriteAuthorsId[i] << " ";
    std :: cout << std :: endl;
    for(int i = 0; i < 3; i++)
        std :: cout << shelf[i].shelfNumberOfBooks() << std :: endl;
    std :: cout << getTotallNumberOfLikes() << std :: endl;
}


std :: vector < Review* > User :: getReviews(){
    return reviews;
}


std :: string User :: getId(){
    return id;
}



User :: User(std :: string _id, std :: string _name, std :: string _placeOfBirth, std :: string _memberSince,
    std :: vector < std :: string > _favoriteAuthorsId, std :: vector < std :: string > _favoriteGenresId,
    std :: vector < Book > wantToRead_, std :: vector < Book > currentlyReading_, std :: vector < Book > read_){
        id = _id;
        name = _name;
        placeOfBirth = _placeOfBirth;
        memberSince = _memberSince;
        favoriteAuthorsId = _favoriteAuthorsId;
        favoriteGenresId = _favoriteGenresId;
        shelf[0].setBooks(wantToRead_);
        shelf[1].setBooks(currentlyReading_);
        shelf[2].setBooks(read_);
}


Shelf User :: getShelf(std :: string shelfType){
    if(shelfType == "want_to_read")
        return shelf[want_to_read];
    if(shelfType == "currently_reading")
        return shelf[currently_reading];
    else
        return shelf[read];
}
