CC=clang
CXX=clang++
INCLUDE=../../include
CXXFLAGS=-std=c++11 -g -Wall -pedantic -stdlib=libc++ -I$(INCLUDE)
LDFLAGS=-stdlib=libc++
