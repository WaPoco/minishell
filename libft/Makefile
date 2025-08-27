# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)

# Directories and files
FTPRINTF_SRC = ft_printf.c \
utils/ft_nbrlen.c utils/ft_putnbr_hex.c utils/ft_putunnbr_fd.c \
helper/print_chr.c helper/print_hex.c helper/print_num.c helper/print_ptr.c helper/print_str.c helper/print_un_num.c

SRCS = ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memchr.c ft_memmove.c ft_putendl_fd.c ft_split.c ft_striteri.c ft_strlcpy.c ft_strncmp.c ft_strtrim.c ft_toupper.c \
ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c ft_putnbr_fd.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strnstr.c ft_substr.c \
ft_calloc.c ft_isascii.c ft_itoa.c ft_memcpy.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c \
$(FTPRINTF_SRC) get_next_line.c ft_strcmp.c ft_isnumeric.c

OBJS = $(SRCS:.c=.o)
INCLUDES = ../includes
NAME = libft.a

# rules
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
