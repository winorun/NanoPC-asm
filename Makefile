all:lex.cc parse.cc main.cpp
	g++ $^ -o main

lex.cc: lexer Scanner.h
	flexc++ $<

parse.cc: grammar Parser.h
	bisonc++ $<
