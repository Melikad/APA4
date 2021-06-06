#include "shelf.hpp"

/*
Shelf :: Shelf(std :: vector < Book > inputBooks){
    books = inputBooks;
}
*/

void Shelf :: setBooks(std :: vector < Book > inputBooks){
    books = inputBooks;
}


void Shelf :: showBooksOutput(std :: vector < Book > &books){
    for(int i = 0; i < books.size(); i++){
        std :: cout << "id: " << books[i].getId() << std :: endl;
        std :: cout << "Title: " << books[i].getName() << std :: endl;
        std :: cout << "Genre: " << books[i].getGenre() << std :: endl;
        std :: cout << "Author: " << books[i].getAuthor() << std :: endl;
        std :: cout << "***" << std :: endl;
    };
}


bool booksComparator(Book a, Book b){
    return a.getName() < b.getName();
}


void Shelf :: showSortedShelf(std :: string genre, std :: vector < Book > books){
    std :: vector < Book > thisGenre, otherGenres;
    for(int i = 0; i < books.size(); i++){
        if(books[i].getGenre() == genre)
            thisGenre.push_back(books[i]);
        else
            otherGenres.push_back(books[i]);
    }
    sort(thisGenre.begin(), thisGenre.end(), booksComparator);
    showBooksOutput(thisGenre);
    sort(otherGenres.begin(), otherGenres.end(), booksComparator);
    showBooksOutput(otherGenres);
}


int Shelf :: shelfNumberOfBooks(){
    return books.size();
}
