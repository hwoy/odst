CC=clang
CXX=clang++
INCLUDE=../../include
CXXFLAGS=-std=c++14 -g -Wall -pedantic -stdlib=libc++ -I$(INCLUDE)
LDFLAGS=-stdlib=libc++
