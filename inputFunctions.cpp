#include "inputFunctions.hpp"


User findUser(string userId, vector < User > users){
    for(int i = 0; i < users.size(); i++)
        if(users[i].getId() == userId)
            return users[i];
    cout << "user not found" << endl;
}


Author findAuthor(string authorId, vector < Author > &authors){
    for(int i = 0; i < authors.size(); i++)
        if(authors[i].getId() == authorId)
            return authors[i];
    cout << "author not found" << endl;
}


vector < Book > inputBooks(vector < Author > &authors){
    vector < Book > books;
    ifstream booksInputFile;
    booksInputFile.open("Assets//books.csv");
    string id, name, author, genre;
    string input;
    getline(booksInputFile, input);
    while(!booksInputFile.eof()){
        getline(booksInputFile, id, delimiter);
        getline(booksInputFile, name, delimiter);
        getline(booksInputFile, author, delimiter);
        getline(booksInputFile, genre, '\n');
        Book book = Book(id, name, findAuthor(author, authors).getName(), genre);
        books.push_back(book);
    }
    return books;
}




vector < string > splitToStringVector(string dataStr){
    int i = 0;
    vector < string > datas;
    while(i < dataStr.size()){
        string nextData = "";
        while(i < dataStr.size() && dataStr[i] != '$' && dataStr[i] != '\n'){
            nextData += dataStr[i];
            i++;
        }
        datas.push_back(nextData);
        i++;
    }
    return datas;
}



Book findBook(string id, vector < Book > books){
    for(int i = 0; i < books.size(); i++)
        if(books[i].getId() == id)
            return books[i];
    cout << "book not found" << endl;
}



vector < Book > splitToBookVector(string bookStr, vector < Book > allBooks){
    int i = 0;
    vector < Book > books;
    while(i < bookStr.size()){
        string nextBookId = "";
        while(i < bookStr.size() && bookStr[i] != '$' && bookStr[i] != '\n'){
            nextBookId += bookStr[i];
            i++;
        }
        Book nextBook = findBook(nextBookId, allBooks);
        books.push_back(nextBook);
        i++;
    }
    return books;
}


vector < Author > inputAuthors(){
    vector < Author > authors;
    ifstream authorsInputFile;
    authorsInputFile.open("Assets//authors.csv");
    string input;
    string id, name, gender, memberSince, yearOfBirth, placeOfBirth, genres;
    getline(authorsInputFile, input);
    while(!authorsInputFile.eof()){
        getline(authorsInputFile, id, delimiter);
        getline(authorsInputFile, name, delimiter);
        getline(authorsInputFile, gender, delimiter);
        getline(authorsInputFile, memberSince, delimiter);
        getline(authorsInputFile, yearOfBirth, delimiter);
        getline(authorsInputFile, placeOfBirth, delimiter);
        getline(authorsInputFile, genres);
        vector < string > authorGenres = splitToStringVector(genres);
        Author author = Author(id, name, gender, memberSince, yearOfBirth, placeOfBirth, authorGenres);
        authors.push_back(author);
    }
    return authors;
}


int strToInt(string s){
    int i = 0;
    int number = 0;
    while(i < s.size() && s[i] != '\n'){
        number *= 10;
        number += s[i]-'0';
        i++;
    }
    return number;
}



vector < Review > inputReviews(){
    vector < Review > reviews;
    ifstream reviewsInputFile;
    reviewsInputFile.open("Assets//reviews.csv");
    string input, inputId, inputBookId, inputUserId, inputRating, inputDate, inputNumberOfLikes;
    getline(reviewsInputFile, input);
    while(!reviewsInputFile.eof()){
        getline(reviewsInputFile, inputId, delimiter);
        getline(reviewsInputFile, inputBookId, delimiter);
        getline(reviewsInputFile, inputUserId, delimiter);
        getline(reviewsInputFile, inputRating, delimiter);
        getline(reviewsInputFile, inputDate, delimiter);
        getline(reviewsInputFile, inputNumberOfLikes);
        int rating = strToInt(inputRating);
        int numberOfLikes = strToInt(inputNumberOfLikes);
        Review review = Review(inputId, inputBookId, inputUserId, rating, inputDate, numberOfLikes);
        reviews.push_back(review);
    }
    return reviews;
}


vector < User > inputUsers(vector < Book > books){
    vector < User > users;
    ifstream usersInputFile;
    usersInputFile.open("Assets//users.csv");
    string input, id, name, placeOfBirth, memberSince;
    string favoriteAuthors, favoriteGenres, wantToRead, currentlyReading, read;
    getline(usersInputFile, input);
    while(!usersInputFile.eof()){
        getline(usersInputFile, id, delimiter);
        getline(usersInputFile, name, delimiter);
        getline(usersInputFile, placeOfBirth, delimiter);
        getline(usersInputFile, memberSince, delimiter);
        getline(usersInputFile, favoriteAuthors, delimiter);
        getline(usersInputFile, favoriteGenres, delimiter);
        getline(usersInputFile, wantToRead, delimiter);
        getline(usersInputFile, currentlyReading, delimiter);
        getline(usersInputFile, read);
        vector < string > favoriteAuthorsId = splitToStringVector(favoriteAuthors);
        vector < string > favoriteGenresId = splitToStringVector(favoriteGenres);
        vector < Book > _wantToRead = splitToBookVector(wantToRead, books);
        vector < Book > _currentlyReading = splitToBookVector(currentlyReading, books);
        vector < Book > _read = splitToBookVector(read, books);
        User user = User(id, name, placeOfBirth, memberSince, favoriteAuthorsId, favoriteGenresId,
                        _wantToRead, _currentlyReading, _read);
        users.push_back(user);
    }
    return users;
}


void inputFollowEdges(vector < User > users){
    ifstream inputFile;
    inputFile.open("Assets//follow_edges.csv");
    string input;
    getline(inputFile, input);
    int cnt = 131;
    while(!inputFile.eof()){
        cnt--;
        string userId;
        getline(inputFile, userId, delimiter);
        string followings;
        getline(inputFile, followings, delimiter);
        string followers;
        getline(inputFile, followers);
        vector < string > followingsId = splitToStringVector(followings);
        User user = findUser(userId, users);
        user.setFollowing(followingsId);
    }
}
