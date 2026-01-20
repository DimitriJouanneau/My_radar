##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

NAME = my_radar

SRC = src/core/init_radar.c \
      src/core/h_dash.c \
      src/core/main.c \
      src/aircraft/update_aircrafts.c \
      src/window/window.c \
	  src/collision/collision.c \
	  src/parser/parser.c \
	  src/parser/parse_aircraft.c \
	  src/parser/parse_tower.c \
	  src/display/display.c \
	  src/aircraft/simulation_end.c \
	  src/window/background.c

OBJ = $(SRC:.c=.o)

CFLAGS = -I./include -I./lib/my/my_printf
FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm
LIB_PRINTF = -Llib/my/my_printf -lmy

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C lib/my
		epiclang $(OBJ) -o $(NAME) $(FLAGS) $(LIB_PRINTF)
		rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all