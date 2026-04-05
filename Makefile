# Library name
NAME = libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = ft_printf.c spf_helper1.c spf_helper2.c

# Object files (same location as .c files)
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(NAME)

# Rule to create the library
$(NAME): $(OBJS)
	@echo "Creating library $(NAME)..."
	ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) created successfully!"

# Rule to compile .c files into .o files
%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

# clean rule: removes object files
clean:
	@echo "Removing object files..."
	rm -f $(OBJS)
	@echo "Cleanup complete!"

# fclean rule: removes object files and the library
fclean: clean
	@echo "Removing $(NAME)..."
	rm -f $(NAME)
	@echo "Full cleanup complete!"

# re rule: rebuilds everything from scratch
re: fclean all

# Indicates that these rules are not files
.PHONY: all clean fclean re
