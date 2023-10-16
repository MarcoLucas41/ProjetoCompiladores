#!/bin/sh

lex uccompiler.l
cc lex.yy.c -o lexer
./lexer -l < $1 > $2


