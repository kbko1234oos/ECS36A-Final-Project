paint.out: main.o commands.o canvas.o resize.o add.o delete.o write.o erase.o inputValidation.o load.o save.o
	gcc -g -Wall -Werror -o paint.out main.o commands.o canvas.o resize.o add.o delete.o write.o erase.o inputValidation.o load.o save.o

main.o: main.c commands.h canvas.h resize.h add.h write.h erase.h
	gcc -g -Wall -Werror -c main.c

commands.o: commands.c commands.h canvas.h erase.h inputValidation.h write.h resize.h write.h delete.h save.h
	gcc -g -Wall -Werror -c commands.c

canvas.o: canvas.c canvas.h
	gcc -g -Wall -Werror -c canvas.c

resize.o: resize.c resize.h canvas.h
	gcc -g -Wall -Werror -c resize.c

add.o: add.c add.h canvas.h resize.h
	gcc -g -Wall -Werror -c add.c

delete.o: delete.c delete.h canvas.h resize.h add.h
	gcc -g -Wall -Werror -c delete.c

write.o: write.c write.h canvas.h
	gcc -g -Wall -Werror -c write.c

erase.o: erase.c canvas.h
	gcc -g -Wall -Werror -c erase.c

inputValidation.o: inputValidation.c inputValidation.h write.h canvas.h add.h
	gcc -g -Wall -Werror -c inputValidation.c

load.o: load.c load.h canvas.h
	gcc -g -Wall -Werror -c load.c

save.o: save.c save.h canvas.h
	gcc -g -Wall -Werror -c save.c

clean:
	rm -rf *.o *.out
