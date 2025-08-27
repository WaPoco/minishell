NAME    := minishell

CC      := cc
CFLAGS  := -Wall -Wextra -Werror -Iinclude -g

SRC     := main.c src/init_shell.c src/signal.c src/parse.c src/execute.c src/execute_builtins.c src/execute_external.c src/utils.c ./src/builtins/echo.c ./src/builtins/pwd.c ./src/builtins/cd.c ./src/builtins/env.c \
./src/builtins/export.c ./src/builtins/unset.c ./src/builtins/exit.c ./src/utils/expand_tools.c ./src/utils/ft_split_quotes.c ./src/utils/ft_qsort.c ./src/expand.c src/redirection_apply.c ./src/pipeline.c ./src/utils/pipeline_tools.c ./src/redirection.c \
./src/utils/reset_std_fds.c ./src/utils/is_quoted.c ./src/utils/execute_tools.c \
./src/helpers/execute_helper.c ./src/helpers/env_helper.c
OBJ     := $(SRC:.c=.o)
LIBFT	:= libft/libft.a
LIBS    := -lreadline -L./libft -lft

# Create object files directory structure
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LIBS)

clean:
	rm -rf $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re