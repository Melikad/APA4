all: goodreads.out

goodreads.out: goodreads.o author.o shelf.o book.o user.o review.o inputFunctions.o
	g++ -std=c++11 goodreads.o author.o shelf.o book.o user.o review.o inputFunctions.o -o goodreads.out

goodreads.o: goodreads.cpp user.hpp
	g++ -std=c++11 -c goodreads.cpp

author.o: author.cpp book.hpp
	g++ -std=c++11 -c author.cpp

shelf.o: shelf.cpp shelf.hpp
	g++ -std=c++11 -c shelf.cpp

book.o: book.cpp book.hpp review.hpp
	g++ -std=c++11 -c book.cpp

user.o: user.cpp book.hpp review.hpp shelf.hpp
	g++ -std=c++11 -c user.cpp

review.o: review.cpp review.hpp
	g++ -std=c++11 -c review.cpp

inputFunctions.o: inputFunctions.hpp inputFunctions.cpp
	g++ -std=c++11 -c inputFunctions.cpp

clean:
	rm *.o
	rm goodreads.out
