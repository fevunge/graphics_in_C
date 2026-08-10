CC=cc
NAME=a.out
CCFLAGS=
SDL_FLAGS=-I/usr/include/SDL3 -lSDL3
INC=
SRC=main.c put_pixel.c clear_buffer.c
OBJ=$(SRC:.c=.o)

build: $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) $(SDL_FLAGS) -o $(NAME)

run:
	./$(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
