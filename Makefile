CC=g++

all:
	g++ -std=c++11 test.cpp -o test
	$(doc)

cleanall:
	rm -rf test doc

doc:
	doxygen doc_config


