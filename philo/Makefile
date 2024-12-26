SRCS =  init_threads.c init_mutex.c check_routine.c\
atoi_itoa.c main.c philo_utils.c\
routine_philo.c routine_monitor.c\
store_data.c\

OBJDIR = obj

OUT = obj

OBJS = ${SRCS:%.c=$(OBJDIR)/%.o}
NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	cc -Wall -Wextra -Werror -g -o $(NAME) $(SRCS) -Iincludes

$(OBJDIR)/%.o:%.c 
	mkdir -p $(OUT)
	cc -Wall -Wextra -Werror -g -o $@ -c $< -Iincludes

clean:
	rm -f $(OBJS)
	rm -r $(OUT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

basictest:
	./philo 3 700 400 200 2
	valgrind --tool=helgrind ./philo 3 700 400 200 2
	valgrind --leak-check=full ./philo 3 700 400 200 2
	valgrind --tool=drd ./philo 3 700 400 200 2

longtest:
	./philo 5 1300 400 200 2
	valgrind --tool=helgrind ./philo 5 1300 400 200 2
	valgrind --leak-check=full ./philo 5 1300 400 200 2
	valgrind --tool=drd ./philo 5 1300 400 200 2

onetest:
	./philo 1 1300 400 200 2
	valgrind --tool=helgrind ./philo 1 1300 400 200 2
	valgrind --leak-check=full ./philo 1 1300 400 200 2
	valgrind --tool=drd ./philo 1 1300 400 200 2