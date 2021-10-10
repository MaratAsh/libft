# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcierra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 12:53:24 by alcierra          #+#    #+#              #
#    Updated: 2021/10/10 17:35:48 by alcierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCS	=	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	\
			ft_isascii.c	ft_isprint.c	ft_strlen.c		\
			ft_memset.c		ft_bzero.c		ft_memcpy.c		\
			ft_memmove.c	ft_strlcpy.c	ft_strlcat.c	\
			ft_toupper.c	ft_tolower.c	ft_strchr.c		\
			ft_strrchr.c	ft_strncmp.c	ft_memchr.c		\
			ft_memcmp.c		ft_strnstr.c	ft_atoi.c		\
			ft_calloc.c		ft_strdup.c						\
			ft_substr.c		ft_strjoin.c	ft_strtrim.c	\
			ft_split.c		ft_itoa.c		ft_strmapi.c	\
			ft_striteri.c 	ft_putchar_fd.c	ft_putstr_fd.c	\
			ft_putendl_fd.c	ft_putnbr_fd.c

B_SRCS	=	ft_lstnew.c

OBJS	=	${SRCS:.c=.o}
B_OBJS	=	${B_SRCS:.c=.o}
FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)
		
$(NAME): ${OBJS}
		ar rcs $(NAME) $?

clean:
		rm -rf ${OBJS} ${B_OBJS}

fclean: clean
		rm -rf ${NAME}

%.o : %.c
		gcc ${FLAGS} -c $< -o $@

re: fclean all

norm:
		norminette -R CheckForbiddenSourceHeader
		norminette libft.h

bonus:
		make OBJS="$(B_OBJS)" all

.PHONY: all clean fclean re	
