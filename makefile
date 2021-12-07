paint.out: main.o commands.o canvas.o resize.o add.o
	gcc -g -Wall -Werror -o paint.out main.o commands.o canvas.o resize.o add.o

main.o: main.c commands.h
	gcc -g -Wall -Werror -c main.c

commands.o: commands.c commands.h
	gcc -g -Wall -Werror -c commands.c

canvas.o: canvas.c canvas.h
	gcc -g -Wall -Werror -c canvas.c

resize.o: resize.c resize.h
	gcc -g -Wall -Werror -c resize.c

add.o: add.c add.h
	gcc -g -Wall -Werror -c add.c

clean:
	rm -rf *.o *.out
