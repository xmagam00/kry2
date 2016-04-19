#xmagam00
#KRY 2
build:
	g++ -lgmp -Wall kry.cpp -o kry
pack:
	zip xmagam00.zip kry.cpp Makefile
clean:
	rm -f xmagam00.zip kry
