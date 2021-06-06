#include "user.hpp"
#include "author.hpp"
#include <fstream>
using namespace std;

#define delimiter ','

User findUser(string userId, vector < User > users);
Author findAuthor(string authorId, vector < Author > &authors);
vector < Book > inputBooks(vector < Author > &authors);
vector < string > splitToStringVector(string dataStr);
Book findBook(string id, vector < Book > books);
vector < Book > splitToBookVector(string bookStr, vector < Book > allBooks);
vector < Author > inputAuthors();
int strToInt(string s);
vector < Review > inputReviews();
vector < User > inputUsers(vector < Book > books);
void inputFollowEdges(vector < User > users);
