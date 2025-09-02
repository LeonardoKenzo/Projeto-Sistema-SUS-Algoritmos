all: historico.o paciente.o main.o
	gcc historico.o paciente.o main.c -o main -std=c99 -Wall -lm
historico.o:
	gcc -c historico.c -o historico.o
paciente.o:
	gcc -c paciente.c -o paciente.o
run:
	./main
clean:
	rm *.o
<<<<<<< Updated upstream
memory:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main
=======
	
>>>>>>> Stashed changes
