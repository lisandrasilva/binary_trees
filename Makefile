CFLAGS = -std=gnu11 -Wall -Wextra -pedantic-errors -O
CC = gcc

ex: main_arvore_binaria.o arvore_binaria_1.o
	$(CC) $(CFLAGS) -o Executavel $^ 

run: ex
	binary_trees

clean:
	@rm -rf binary_trees/*.o  

