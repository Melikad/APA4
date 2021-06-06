#include "book.hpp"
#include <algorithm>

bool booksComparator(Book a, Book b);

class Shelf{
private:
    std :: vector < Book > books;
public:
    //Shelf(std :: vector < Book > inputBooks);
    void setBooks(std :: vector < Book > inputBooks);
    void showBooksOutput(std :: vector < Book > &books);
    void showSortedShelf(std :: string genre, std :: vector < Book > books);
    int shelfNumberOfBooks();
};
