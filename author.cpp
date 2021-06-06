#include "author.hpp"

Author :: Author(std :: string aId, std :: string aName, std :: string aGender, std :: string aMemberSince, std :: string aYearOfBirth,
        std :: string aPlaceOfBirth, std :: vector < std :: string > aGenres) {
    id = aId;
    name = aName;
    gender = aGender;
    memberSince = aMemberSince;
    yearOfBirth = aYearOfBirth;
    placeOfBirth = aPlaceOfBirth;
    genres = aGenres;
}


void Author ::  showAuthorsBooks(std :: string id, std :: vector < Book > &books){
    std :: cout << "Books:" << std :: endl;
    for(int i = 0; i < books.size(); i++)
        if(books[i].getAuthor() == id)
            std :: cout << "id: " << books[i].getId() << " Title: " << books[i].getName() << std :: endl;
}


void Author :: showAuthorInfo(std :: vector < Book > &books){
    std :: cout << "id: " << id << std :: endl;
    std :: cout << "name: " << name << std :: endl;
    std :: cout << "year of birth: " << yearOfBirth << std :: endl;
    std :: cout << "place of birth: " << placeOfBirth << std :: endl;
    std :: cout << "Member since" << memberSince << std :: endl;
    std :: cout << "Genres: ";
    for(int i = 0; i < genres.size(); i++)
        std :: cout << genres[i] << (i+1 < genres.size()? " ": "");
    std :: cout << std :: endl;
    showAuthorsBooks(id, books);
}


std :: string Author :: getId(){
    return id;
}


std :: string Author :: getName(){
    return name;
}
