# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/08 16:56:07 by dlim              #+#    #+#              #
#    Updated: 2019/06/26 17:16:29 by dlim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SOURCES = sources/*.c
LIBFT = resources/libft/*.c
GETNEXTLINE = resources/get_next_line/*.c
OBJECTS = *.o

all: $(NAME)

$(NAME):
	@echo "\x1B[32mInitialize Compilation :)\x1B[37m"
	@cd ./resources/minilibx_macos && make re
	@echo "\x1B[33m(1/2) Minilibx Compilation Completed Successfully!\x1B[37m"
	gcc -Wall -Wextra -Werror -o fdf -I ./includes $(SOURCES) $(LIBFT) $(GETNEXTLINE) -L ./resources/minilibx_macos/ -lmlx -framework OpenGL -framework Appkit
	@echo "\x1B[33m(2/2) FdF Compilation Completed Successfully!\x1B[37m"
	@echo "\x1B[32mCompilation Compilation :D\x1B[37m"
	@echo "\x1B[32mUsage: ./fdf map_file\x1B[37m"
	@echo "\x1B[32mCheck: make norm\x1B[37m"

clean: 
	rm -f $(OBJECTS)
	@cd ./resources/minilibx_macos && make clean

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette ./sources/*.c
	norminette ./includes/*.h
	norminette ./resources/get_next_line/*.c
	norminette ./resources/libft/*.c
