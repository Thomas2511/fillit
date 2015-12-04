# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 16:00:53 by tdieumeg          #+#    #+#              #
#    Updated: 2015/12/02 14:57:47 by tdieumeg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# binaries
CC		= /usr/bin/clang
RM		= /bin/rm
MAKE	= /usr/bin/make
MKDIR	= /bin/mkdir

# app name
NAME	= fillit

# dir
ROOT	= $(shell pwd)
OBJDIR	= $(ROOT)/objs
SRCDIR	= $(ROOT)/srcs
INCDIR	= $(ROOT)/includes
LIBDIR	= $(ROOT)/libft
LFTINC	= $(LIBDIR)/includes

# compil flags
CFLAGS	= -I $(INCDIR) -I $(LFTINC) -Wall -Wextra -Werror
LIBS = -L $(LIBDIR) -lft

# source files
SRC		= fillit.c \
		  check_file.c \
		  is_tetriminos.c \
		  solver.c

# obj
OBJS	= $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

.PHONY: all clean fclean re

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBDIR)
	@echo "Compiling fillit..."
	@$(CC) $(OBJS) -o $@ $(LIBS) $(CFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $< -o $@ -c $(CFLAGS)

$(OBJDIR):
	@$(MKDIR) $@

clean:
	$(RM) -rf $(OBJDIR)

fclean: clean
	$(RM) -f $(NAME)

lib.fclean:
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all
