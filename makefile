# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mstegema <mstegema@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/08/11 12:04:50 by mstegema      #+#    #+#                  #
#    Updated: 2022/08/11 12:44:13 by mstegema      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =
SRCS =
OBJS = $(SRCS:.c=.o)
BONUS =
BONUS_OBJS = $(BONUS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=n
HEADER =

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "object files have been created"
	@echo "$(NAME) has been created"

%.o: %.c $(HEADER)
	@cc -c $(CFLAGS) $< -o $@

clean:

fclean:

re:

bonus:

.PHONY:
