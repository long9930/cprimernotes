##.PHONY: clean

CXX = gcc
OBJS = count_words.o lexer.o
CFLAGS = -Wall -O2

count_words: $(OBJS)
	$(CXX) count_words.o lexer.o -ll -o count_words
##	gcc count_words.o lexer.o -lfl -o count_words

count_words.o: count_words.c
	$(CXX) -c count_words.c

lexer.o: lexer.c
	$(CXX) -c lexer.c


# $(OBJECTS): %.o: %.c
# 	$(CXX) -c $(CFLAGS) $< -o $@

lexer.c: lexer.l
	flex -t lexer.l > lexer.c

clean:
	rm -rf *.o lexer.c count_words
