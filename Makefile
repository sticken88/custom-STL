CC=g++

all:
	g++ test.cpp -o test
	$(doc)

cleanall:
	rm -rf test doc

doc:
	doxygen doc_config


