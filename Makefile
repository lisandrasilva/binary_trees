CFLAGS = -std=gnu11 -Wall -Wextra -pedantic-errors -O
CC = gcc

ex: Btree_main.o Btree_functions.o
	$(CC) $(CFLAGS) -o Executavel $^ 

run: ex
	binary_trees

clean:
	@rm -rf binary_trees/*.o  

