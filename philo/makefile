CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS =	philo.c\
		ft_atoi.c\
		timestamp.c\
		ft_usleep.c\
		check_die.c\
		utils_philo.c\
		create_data.c\
		mutex_init.c\


OBJS_BONUS = ${BONUS:.c=.o}

OBJS = ${SRCS:.c=.o}

NAME = philo

REM = rm -f

all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  -o $(NAME)

clean :
	${REM} ${OBJS} ${OBJS_BONUS}

fclean : clean
	${REM} ${NAME} ${NAME_BONUS}

re : fclean all

.PHONY : all clean fclean bonus re