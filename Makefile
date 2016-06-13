##
## Makefile for Duo in /home/juquet_q/Hub/Duo
## 
## Made by juquet_q
## Login   <juquet_q@epitech.net>
## 
## Started on  Mon Jun 13 15:21:54 2016 juquet_q
## Last update Mon Jun 13 16:22:03 2016 juquet_q
##

CC	= gcc

DSRC	= ./src/

SRC	= $(DSRC)main.c \
	$(DSRC)tekpixel.c \
	$(DSRC)background.c

RM	= rm -f

OBJ	= $(SRC:.c=.o)

LIB     =       -L/home/${USER}/.froot/lib/ -llapin \
		-L/usr/local/lib \
                -lsfml-audio \
		-lsfml-graphics \
                -lsfml-window \
		-lsfml-system \
                -lstdc++ -ldl \
		-lm

CFLAGS	= -Wall -Wextra -Werror \
	-I./include/ -I/home/${USER}/.froot/include/

NAME	= Duo

all: $(OBJ) $(NAME)

$(NAME):
	@$(CC) $(OBJ) $(LIB) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
