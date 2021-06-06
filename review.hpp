#include <vector>
#include <string>

class Review{
private:
    std :: string id;
    std :: string bookId;
    std :: string userId;
    int rating;
    std :: string date;
    double numberOfLikes;
public:
    double getNumberOfLikes();
    std :: string getId();
    std :: string getUserId();
    std :: string getBookId();
    int getRating();
    std :: string getDate();
    Review(std :: string id, std :: string bookId, std :: string userId,
        int rating, std :: string date, int numberOfLikes);
};
