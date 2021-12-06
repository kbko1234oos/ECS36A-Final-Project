paint.out: main.o commands.o
	gcc -g -Wall -Werror -o paint.out main.o commands.o

main.o: main.c commands.h
	gcc -g -Wall -Werror -c main.c


commands.o: commands.c commands.h
	gcc -g -Wall -Werror -c commands.c

clean:
	rm -rf *.o *.out
