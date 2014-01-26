all: clean
	gcc -o quack *.c

debug: clean
	gcc -DDEBUG -o quack *.c

clean:
	if [ -f quack ]; then rm quack; fi
