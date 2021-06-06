#include "shelf.hpp"


class User{
private:
    std :: string id;
    std :: string name;
    std :: string placeOfBirth;
    std :: string memberSince;
    std :: vector < std :: string > favoriteAuthorsId;
    std :: vector < std :: string > favoriteGenresId;
    std :: vector < Review* > reviews;
    Shelf shelf[3];
    std :: vector < std :: string > followingsId;

public:
    void setFollowing(std :: vector < std :: string > ids);
    std :: vector < std :: string > getFollowings();
    void addReview(Review* inputReview);
    std :: vector < std :: string > getFavoriteGenres();
    int getTotallNumberOfLikes();
    void showUserInfo();
    std :: vector < Review* > getReviews();
    std :: string getId();
    User(std :: string _id, std :: string _name, std :: string _placeOfBirth, std :: string _memberSince,
        std :: vector < std :: string > _favoriteAuthorsId, std :: vector < std :: string > _favoriteGenresId,
        std :: vector < Book > wantToRead_, std :: vector < Book > currentlyReading_, std :: vector < Book > read_);
    Shelf getShelf(std :: string shelfType);
};
