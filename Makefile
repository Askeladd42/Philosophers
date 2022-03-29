# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plam <plam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 09:31:35 by plam              #+#    #+#              #
#    Updated: 2022/03/29 14:11:06 by plam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		+=	utils/ft_atol.c\
				utils/ft_memset.c\
				utils/ft_isdigit.c

SRCS		+=	init/set_table.c\
				init/init_forks.c\
				init/init_rules.c\
				init/init_philo.c\
				init/init_threads.c\

SRCS		+=	routine/print_funcs.c\
				routine/chk_routine.c\
				routine/eat_routine.c\
				routine/gen_routine.c

SRCS		+=	time/ms_sleep.c\
				time/set_time.c

SRCS		+=	main.c\
				errors/error.c\
				threads/pthread.c\
				parsing/arg_parsing.c

MAKE		=	/bin/make

PATH		=	philosophers/srcs/

OBJS		= 	$(addprefix $(PATH), $(SRCS:.c=.o))

OBJS_BONUS	= 	$(addprefix $(PATH_BONUS), $(SRCS_BONUS:.c=.o))

HEADERS		+=	philosophers/headers/

NAME		=	philo

NAME_BONUS	=	philo_bonus

RM			=	/bin/rm -f

CC			=	/usr/bin/clang

CFLAGS		=	-g -Wall -Wextra -Werror -I $(HEADERS)

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo "\n\t\033[36;1m*-------------------------*"
				@echo "\n\t* Compiling $(NAME) *\t \033[32;1m ------->>> \033[4;5mComplete !\033[0m"
				@echo "\n\t\033[36;1m*-------------------------*\033[0m\n"


$(NAME_BONUS):	$(OBJS_BONUS)
				$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

%.o: %.c	
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)
				@echo "\033[36;1m ------>>	clean\033[0m"

fclean:			clean
				$(RM) $(NAME)
				@echo "\033[36;1m ------>>	fclean\033[0m"

re:				fclean all

.PHONY:			all clean fclean re