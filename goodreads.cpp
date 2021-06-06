#include "inputFunctions.hpp"
#include <stdio.h>
#include <string.h>
//using namespace std;

#define maxUsers 1000


double getUserCredit(string userId, vector < Review > &reviews){
    double totallLikes = 0;
    double totallReviews = reviews.size();
    double userLikes = 0;
    double userReviews = 0;
    for(int i = 0; i < reviews.size(); i++){
        totallLikes += reviews[i].getNumberOfLikes();
        if(reviews[i].getUserId() == userId){
            userLikes += reviews[i].getNumberOfLikes();
            userReviews++;
        }
    }
    return 1/2 * (userLikes/(totallLikes == 0? 1: totallLikes) + userReviews/totallReviews);
}



void getAndShowBestBook(vector < Book > &books){
    double maxScore = 0;
    Book* bestBook;
    for(int i = 0; i < books.size(); i++){
        double thisBookRating = books[i].getAverageRating();
        cout << i << " : " << fixed << setprecision(6) << thisBookRating << endl;
        if(thisBookRating > maxScore){
            maxScore = thisBookRating;
            bestBook = &books[i];
        }
    }
    (*bestBook).showInfo();
}




void getAndShowBestReviewer(vector < User > &users){
    User* maxLikesUser;
    int maxLikes = 0;
    for(int i = 0; i < users.size(); i++){
        if(users[i].getTotallNumberOfLikes() > maxLikes){
            maxLikes = users[i].getTotallNumberOfLikes();
            maxLikesUser = &users[i];
        }
    }
    (*maxLikesUser).showUserInfo();
}



double getScore(Book book, vector < User > users, vector < Review > &reviews, User user){
    vector < Review* > bookReviews = book.getReviews();
    double rating = 0;
    for(int i = 0; i < bookReviews.size(); i++){
        double reviewRating = bookReviews[i]->getRating();
        User user = findUser(bookReviews[i]->getUserId(), users);
        double userCredit = getUserCredit(bookReviews[i]->getUserId(), reviews);
        rating += reviewRating * userCredit;
    }
    rating /= (double)(reviews.size());
    return rating + book.commonGenres(user.getFavoriteGenres());
}



void recommendFirstApproach(vector < Book > &books, vector < User > users, vector < Review > &reviews, string userId){
    User user = findUser(userId, users);
    Book* recommendedBook;
    double maxScore = 0;
    for(int i = 0; i < books.size(); i++){
        double thisBookScore = getScore(books[i], users, reviews, user);
        if(maxScore < thisBookScore){
            maxScore = thisBookScore;
            recommendedBook = &books[i];
        }
    }
    (*recommendedBook).showInfo();
}




void splitReviewsToUsersAndBooks(vector < Review > &reviews, vector < User > &users, vector < Book > &books){
    for(int i = 0; i < reviews.size(); i++){
        User ownerUser = findUser(reviews[i].getUserId(), users);
        ownerUser.addReview(&reviews[i]);
        Book ownerBook = findBook(reviews[i].getBookId(), books);
        ownerBook.addReview(&reviews[i]);
    }
}



Book* findBestDFS(User user, bool mark[maxUsers], double maxScore, vector < Book > &books, vector < User > &users, vector < Review > &reviews){
    mark[strToInt(user.getId())] = 1;
    vector < string > followings = user.getFollowings();
    Book* recommendedBook;
    double currentMaxScore = maxScore;
    for(int i = 0; i < books.size(); i++){;
        double thisBookScore = getScore(books[i], users, reviews, user);
        if(currentMaxScore < thisBookScore){
            currentMaxScore = thisBookScore;
            recommendedBook = &books[i];
        }
    }
    for(int i = 0; i < followings.size(); i++){
        if(!mark[strToInt(followings[i])]){
            Book* thisUserBestBook = findBestDFS(findUser(followings[i], users), mark, currentMaxScore, books, users, reviews);
            double thisUserScore = getScore(*thisUserBestBook, users, reviews, findUser(followings[i], users));
            if(thisUserScore > currentMaxScore){
                currentMaxScore = thisUserScore;
                recommendedBook = thisUserBestBook;
            }
        }
    }
    return recommendedBook;
}



void recommendSecondApproach(string userId, vector < User > &users, vector < Book > &books, vector < Review > &reviews){
    User currentUser = findUser(userId, users);
    bool mark[maxUsers];
    memset(mark, 0, maxUsers);
    (*findBestDFS(currentUser, mark, 0, books, users, reviews)).showInfo();
}



int main(int argc, char* argv[]){
    vector < Author > authors = inputAuthors();
    cout << "authors input done" << endl;
    vector < Book > books = inputBooks(authors);
    cout << "books input done" << endl;
    vector < Review > reviews = inputReviews();
    cout << "reviews input done" << endl;
    vector < User > users = inputUsers(books);
    inputFollowEdges(users);
    cout << "follow edges input done" << endl;
    splitReviewsToUsersAndBooks(reviews, users, books);
    cout << "done" << endl;
    string command;
    while(cin >> command){
        if(command == "show_author_info"){
            cout << "yes" << endl;
            string authorId;
            cin >> authorId;
            findAuthor(authorId, authors).showAuthorInfo(books);
        }
        if(command == "show_sorted_shelf"){
            string userId;
            string shelfType;
            string genre;
            cin >> userId >> shelfType >> genre;
            User user = findUser(userId, users);
            (user.getShelf(shelfType)).showSortedShelf(genre, books);
        }
        if(command == "credit"){
            string userId;
            cin >> userId;
            cout << fixed << setprecision(6) << getUserCredit(userId, reviews) << endl;
        }
        else if(command == "best_book"){
            getAndShowBestBook(books);
        }
        else if(command == "best_reviewer"){
            getAndShowBestReviewer(users);
        }
        else if(command == "recommend_first_approach"){
            string user;
            cin >> user;
            recommendFirstApproach(books, users, reviews, user);
        }
        else if(command == "recommend_second_approach"){
            string userId;
            cin >> userId;
            recommendSecondApproach(userId, users, books, reviews);
        }
        else
            cout << "command not found " << command << endl;
    }
}
