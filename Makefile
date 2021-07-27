NAME	= MyGKrellm

CC	= g++

RM	= rm -f

SRCS	= ./main.cpp \
	  ./ncurse/ncurses.cpp \
	  ./sfml/sfml.cpp \
	  ./Modules/cpu.cpp	\
	  ./Modules/date.cpp	\
	  ./Modules/net.cpp	\
	  ./Modules/ram.cpp	\
	  ./Modules/infos.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./pp
CPPFLAGS += -Wall -Wextra

COMPIL = -l sfml-graphics -l sfml-window -l sfml-system -l sfml-audio -lcurses

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(COMPIL)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
