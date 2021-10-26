NAME = miniRT
UNAME = $(shell uname)
SRCS_DIR = srcs
SRCS += $(SRCS_DIR)/ambient.c
SRCS += $(SRCS_DIR)/calc_sq.c
SRCS += $(SRCS_DIR)/get_next_line.c
SRCS += $(SRCS_DIR)/main.c
SRCS += $(SRCS_DIR)/read_pl.c
SRCS += $(SRCS_DIR)/read_tr.c
SRCS += $(SRCS_DIR)/shadow.c
SRCS += $(SRCS_DIR)/calc_cy.c
SRCS += $(SRCS_DIR)/calc_tr.c
SRCS += $(SRCS_DIR)/get_next_line_utils.c
SRCS += $(SRCS_DIR)/ray.c
SRCS += $(SRCS_DIR)/read_rt.c
SRCS += $(SRCS_DIR)/read_utils.c
SRCS += $(SRCS_DIR)/vec_utils2.c
SRCS += $(SRCS_DIR)/calc_pl.c
SRCS += $(SRCS_DIR)/camera.c
SRCS += $(SRCS_DIR)/key.c
SRCS += $(SRCS_DIR)/raytrace.c
SRCS += $(SRCS_DIR)/read_sp.c
SRCS += $(SRCS_DIR)/resolution.c
SRCS += $(SRCS_DIR)/vector_utils.c
SRCS += $(SRCS_DIR)/calc_sp.c
SRCS += $(SRCS_DIR)/col_utils.c
SRCS += $(SRCS_DIR)/light.c
SRCS += $(SRCS_DIR)/read_cy.c
SRCS += $(SRCS_DIR)/read_sq.c
SRCS += $(SRCS_DIR)/save.c
SRCS += $(SRCS_DIR)/window.c
SRCS += $(SRCS_DIR)/comp.c
SRCS += $(SRCS_DIR)/read_check.c
SRCS += $(SRCS_DIR)/error.c
SRCS += $(SRCS_DIR)/read_utils2.c



LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJS = $(SRCS:.c=.o)
INCLUDE = -I./includes -I./$(LIBFT_DIR)
CC = gcc -Wall -Wextra -Werror
RM = rm -f


ifeq ($(UNAME), Linux)
# ------------------- Linux -------------------
LIBS = -lXext -lX11 -L $(LIBFT_DIR) -lft libmlx_Linux.a
else
# ------------------- MacOS -------------------
LIBS = libmlx.dylib -framework OpenGL -framework AppKit -L $(LIBFT_DIR) -lft
endif


ifeq ($(UNAME), Linux)
# ------------------- Linux -------------------
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(INCLUDE) $(OBJS) -L. -L.minilibx-linux -lmlx_Linux $(LIBS) -lm -o $(NAME)

bonus: $(NAME)
else
# ------------------- MacOS -------------------
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(INCLUDE) $(OBJS) $(LIBS) -lm -o $(NAME)

bonus: $(NAME)
endif

$(LIBFT): $(LIBFT_DIR)/*.c
	$(MAKE) -C $(LIBFT_DIR)
.c.o:
	$(CC) $(INCLUDE) -c $< -o $@
clean:
	$(MAKE) -C $(LIBFT_DIR)	clean
	$(RM) $(OBJS)
fclean: clean
	$(MAKE) -C $(LIBFT_DIR)	fclean
	$(RM) $(NAME)
re: fclean all


.PHONY: all clean fclean re .c.o
