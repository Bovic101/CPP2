# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 08:45:40 by vodebunm          #+#    #+#              #
#    Updated: 2024/11/27 08:48:22 by vodebunm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = talk

# Source file for the project
SRC = main.cpp ClassFixed.cpp

# Object files will be derived from the source files
OBJ = $(SRC:.cpp=.o)

# Compiler to be used
CC = g++

# Compilation flags for warnings and C++ standard compliance
FLAGS =  -Wall -Wextra -Werror -std=c++98

# Command to remove files
RM = rm -f

# Default target to build the executable
all: $(NAME)

# Target to link the object files and create the executable
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

# Target to remove the object files
clean:
	$(RM) $(OBJ)

# Target to remove both object files and the executable
fclean: clean
	$(RM) $(NAME)

# Target to clean and rebuild the project
re: fclean $(NAME)

# Special target to indicate that these targets do not represent files
.PHONY: all clean fclean re