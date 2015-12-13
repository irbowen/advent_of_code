all:
	g++ -Wall -Werror -Wextra -ansi -pedantic -std=c++14 -O3 day1.cc -o day1.o
	g++ -Wall -Werror -Wextra -ansi -pedantic -std=c++14 -O3 day2.cc -o day2.o
	g++ -Wall -Werror -Wextra -ansi -pedantic -std=c++14 -O3 day3.cc -o day3.o

clean:
	rm *.o

