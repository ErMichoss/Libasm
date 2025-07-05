NAME = libasm.a
GCC = gcc
CFLAGS = -Wall -Wextra -Werror -g

NA  = nasm
NA_FLAGS = -f elf64

SRC_MANDATORY = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS_MANDATORY = $(SRC_MANDATORY:.s=.o)

TEST_MANDATORY_C = main.c
TEST_MANDATORY_EXEC = my_test_mandatory

RM = rm -f
AR = ar rcs  # Aquí está el cambio

%.o: %.s
	$(NA) $(NA_FLAGS) $< -o $@

$(NAME): $(OBJS_MANDATORY)
	$(AR) $(NAME) $(OBJS_MANDATORY)

all: $(NAME)

clean:
	$(RM) $(OBJS_MANDATORY)

fclean: clean
	$(RM) $(NAME) $(TEST_MANDATORY_EXEC)

re: fclean all

test: $(NAME) $(TEST_MANDATORY_C)
	$(GCC) $(CFLAGS) $(TEST_MANDATORY_C) -L. -lasm -o $(TEST_MANDATORY_EXEC)
	@echo "\n--- Running Mandatory Tests ($(TEST_MANDATORY_EXEC)) ---\n"
	./$(TEST_MANDATORY_EXEC)
	@echo "\n--- Mandatory Tests finished ---\n"

.PHONY: all clean fclean re test
