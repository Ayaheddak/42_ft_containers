NAME	=	containers

UTILS	=	containers/vector

FLAGS	=	-Wall -Wextra -Werror -std=c++98

RM		=	rm -f

CC		=	c++

OBJS 	= ${UTILS:.cpp=.o}

all		:	$(NAME)

$(NAME)	:	$(UTILS)	
	@$(CC) $(FLAGS) $(UTILS) -o $(NAME)

clean :
	@${RM} $(OBJCT)

fclean :	clean
	@${RM} ${NAME}

re : fclean all