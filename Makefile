NAME 		= 	my_coloring

SRCS 		= 	main.c \
						graph/graph.c \
						coloring/coloring.c \
						welsh_powell/welsh_powell.c \
						greedy/greedy.c

OBJS 		= 	$(SRCS:.c=.o)

CFLAGS 	= 	-W -Wall -Wextra -Iinclude

CC 			= 	gcc -g

RM 			= 	rm

all: 				$(NAME)

$(NAME): 		$(OBJS)
						$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
						$(RM) -f $(NAME)

fclean:			clean
						$(RM) -f $(OBJS)

re: 				fclean all
