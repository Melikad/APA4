#include "book.hpp"

class Author{
private:
    std :: string id;
    std :: string name;
    std :: string gender;
    std :: string memberSince;
    std :: string yearOfBirth;
    std :: string placeOfBirth;
    std :: vector < std :: string > genres;
public:
    Author(std :: string aId, std :: string aName, std :: string aGender, std :: string aMemberSince, std :: string aYearOfBirth,
         std :: string aPlaceOfBirth, std :: vector < std :: string > aGenres);
    void showAuthorsBooks(std :: string id, std :: vector < Book > &books);
    void showAuthorInfo(std :: vector < Book > &books);
    std :: string getId();
    std :: string getName();
};
