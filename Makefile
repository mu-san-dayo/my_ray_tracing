NAME = miniRT
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
#temp
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
#temp_end
MLX		= minilibx-linux
all: $(NAME)
LIBS = -lXext -lX11 -L $(LIBFT_DIR) -lft libmlx_Linux.a
#temp
else
MLX		= minilibx-macos
all: $(NAME)
LIBS = libmlx.dylib -framework OpenGL -framework AppKit -L $(LIBFT_DIR) -lft
endif
#temp_end
CC = gcc -Wall -Wextra -Werror
RM = rm -f
#temp
ifeq ($(UNAME), Linux)
$(NAME): $(OBJS) $(LIBFT)
#temp_end
$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@ $(MAKE) -C ./minilibx-linux > /dev/null 2>&1
	cp ./minilibx-linux/libmlx_Linux.a .
	$(CC) $(INCLUDE) $(OBJS) -L. -L.minilibx-linux -lmlx_Linux $(LIBS) -lm -o $(NAME)
$(MLX) :
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX)
$(LIBFT): $(LIBFT_DIR)/*.c
	$(MAKE) --print-directory -C $(LIBFT_DIR)
.c.o:
	$(CC) $(INCLUDE) -c $< -o $@
clean:
	$(MAKE) -C $(LIBFT_DIR)	clean
	$(RM) $(OBJS)
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) img.bmp
	$(RM) -r minilibx-linux
	$(RM) -r libmlx_Linux.a
re: fclean all
#temp
else
$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(MAKE) -C ./minilibx_mms_20200219
	cp ./minilibx_mms_20200219/libmlx.dylib .
	$(CC) $(INCLUDE) $(OBJS) $(LIBS) -lm -o $(NAME)
$(MLX) :
	wget -O "minilibx_mms_20200219.zip" "https://www.dropbox.com/s/0fkqams3ay4056s/minilibx_mms_20200219.zip?dl=0"
	rm -rf __MACOSX
	rm -rf minilibx_mms_20200219
	unzip minilibx_mms_20200219.zip
	rm -rf minilibx_mms_20200219.zip

$(LIBFT): $(LIBFT_DIR)/*.c
	$(MAKE) -C $(LIBFT_DIR)
.c.o:
	$(CC) $(INCLUDE) -c $< -o $@
all: $(NAME)
clean:
	$(MAKE) -C $(LIBFT_DIR)	clean
	$(RM) $(OBJS)
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) img.bmp
	$(RM) -r minilibx_mms_20200219
	$(RM) -r libmlx.dylib
	$(RM) -r $(MLX).zip
	$(RM) -r __MACOSX
re: fclean all
endif
#temp_end
.PHONY: all clean fclean re .c.o
