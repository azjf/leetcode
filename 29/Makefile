CPP = /usr/bin/g++

all: a.out
	./a.out

a.out: *.cpp *.h
	$(CPP) *.cpp -o $@ -Wall -g

clean:
	rm a.out

run: a.out
	./a.out
