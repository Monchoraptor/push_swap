# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoracho <amoracho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/13 16:23:00 by amoracho          #+#    #+#              #
#    Updated: 2022/02/03 16:30:22 by amoracho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c push_swap.c utils.c utils2.c	\
		stuff_from_libft.c moves.c ft_split.c

HEADER	= -I./includes/

OBJS	=	${SRCS:.c=.o} 

NAME	=	push_swap

CC	=	cc

CFLAGS		=-Wall -Wextra -Werror

RM	=	rm -f

.c.o:
	${CC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} 
			${CC} ${CFLAGS} ${HEADER} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all bonus

.PHONY:		all clean fclean re bonus
