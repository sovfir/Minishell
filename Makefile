NAME = minishell

HOMEBREW_PREFIX := $(shell test -n "$$(which brew)" \
      && brew config | grep HOMEBREW_PREFIX | cut -d' ' -f2)

RL_LIB = $(HOMEBREW_PREFIX)/opt/readline/lib
#$(HOMEBREW_PREFIX)/Cellar/readline/8.1.2/include
RL_INC = $(HOMEBREW_PREFIX)/opt/readline/include/readline
#$(HOMEBREW_PREFIX)/Cellar/readline/8.1.2/lib
SRCS = 

CC = cc


OBJS = $(SRCS:.c=.o)

HEADER = minishell.h

CFLAGS = -lreadline

all: $(NAME)

$(NAME): $(HEADER) $(OBJS) $(SRCS)
		$(CC) $(CFLAGS) -I$(RL_INC) -I$(RL_LIB) -g -L$(RL_LIB) $(OBJS) -o$(NAME) $@

clean: 
	@rm -f *.out
	@rm -f *.o
	@rm -f $(OBJS)
	make clean -C $(LIB_PATH)

fclean:	clean
	@rm -f $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean all

.PHONY: all clean fclean re bonus

cc -I/Users/lshonta/.brew/Cellar/readline/8.1.2/include/readline -I/Users/lshonta/.brew/Cellar/readline/8.1.2/lib -g -L/Users/lshonta/.brew/Cellar/readline/8.1.2/lib -lreadline ./src/*.c ./utils/*.c -o minishel

cc -I/Users/lshonta/.brew/opt/readline/include/readline -I/Users/lshonta/.brew/opt/readline/lib -g -L/Users/lshonta/.brew/opt/readline/lib -lreadline ./src/*.c ./utils/*.c -o minishel