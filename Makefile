NAME	=	libasm.a
SRCS	=	ft_strlen.s \
			ft_write.s \
			ft_strdup.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_read.s

OBJS	=	$(SRCS:.s=.o)

.s.o:
	nasm -lc -f elf64 $< -o $@

$(NAME): ${OBJS}
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

test: all
	clang -Wall -Wextra -Werror test_libasm/*.c -L. -lasm -o libasm
