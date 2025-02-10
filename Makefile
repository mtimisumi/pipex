NAME := pipex

HEADERFILE := pipex.h

SRCS := pipex.c sources.c

OBJS := $(SRCS:.c=.o)

CC := cc

CFLAGS := -Wall -Werror -Wextra

RM := rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADERFILE)
	$(CC) $(CFLAGS) -c $< -o $@
# -c flag tells the compiler to compile the source file into an object file but to not link it, without it it would produce an executable instead of a .o file
# -o is whats followed by the name of the file you want the compiler to produce
# $< automatic variable that points to the first dependency in the rule, in this case the source file (%.c)
# $@ automatic variable that refers to the target of the rule (%.o) and ensure that the taarget has the correct name

#this is how the structre look:
# target: dependencies
#	command

clean:
	$(RM) $(OBJS)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re