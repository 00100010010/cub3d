CFLAGS		=	-Wall -Wextra -Werror

NAME		=	libft.a

OS			=	$(shell uname)

HEADER = libft.h

CC = clang

SRC = ft_memset.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_isalpha.c \
	ft_strlen.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_isalnum.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_strmapi.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_int_size.c \
	ft_isspace.c \


ifeq ($(OS), Linux)
	SRC	+= get_next_line_linux.c

else
	SRC	+= get_next_line_osx.c

endif


BONUS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c	\
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJ = $(SRC:.c=.o)

OBJBONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[1;32m[OK]\x1b[37m all objects.o are generated\r"
	@ar rc $(NAME) $(OBJ) || printf "[ERREUR] [error] [ERREUR] [error]$(NAME)\r"
	@ranlib $(NAME)
	@echo "\033[1;32m[OK]\x1b[37m $(NAME) is compilated\r"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(CC) $(CFLAGS)  -o $@ -c $<

clean:
	@rm -f $(OBJ) $(OBJBONUS)
	@echo "\033[1;32m[OK]\x1b[37m\x1b[37m all objects.o deleted\r"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;32m[OK]\x1b[37m $(NAME) deleted\r"

re: fclean all
	@echo "\033[1;32m[OK]\x1b[37m fresh built\r"

bonus: $(OBJ) $(OBJBONUS)
	@ar rc $(NAME) $(OBJ) $(OBJBONUS)
	@ranlib	$(NAME)
	@echo "\033[1;32m[OK]\x1b[36m Bonus content \x1b[37mcreated\r"
