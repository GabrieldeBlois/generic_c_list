NAME	= program

CC	= gcc

RM	= rm -f

SRCS	= ./src/list.c \
	  ./src/list_ctrl.c \
	  ./src/list_sort.c \
	  ./src/main.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
