all:lex.cc parse.cc main.cpp Parser.cpp
	g++ -std=c++17 $^ -o nanopc-asm

lex.cc: lexer Scanner.h
	flexc++ $<

parse.cc: grammar Parser.h
	bisonc++ $<
