NAME=minishell

SRC_DIR=src
OBJ_DIR=obj
SRC= $(wildcard $(SRC_DIR)/*.c)
OBJ= $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))


CC=cc
CFLAGS= -Wall -Wextra -Werror -g
LDFLAGS = -L /opt/homebrew/lib -lreadline

LIBFT_DIR=ftlib
LIBFT=$(LIBFT_DIR)/libft.a
INC=-I./include -I./$(LIBFT_DIR) -I/opt/homebrew/include

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[1;33m
RESET = \033[0m

all: $(NAME)
	@echo "$(YELLOW)... Compilation de $(NAME) ...$(RESET)"
	@echo "$(GREEN)✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔$(RESET)"

$(NAME): $(OBJ) $(LIBFT)
	@echo "$(YELLOW)... Compilation de $(LIBFT) ...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) -o $@
	@echo "$(GREEN)✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@echo "$(RED)... Destruction des .O ...$(RESET)"
	@rm -f $(OBJ)
	@echo "$(GREEN)✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔$(RESET)"
	@echo "$(RED)... Destruction des objets de LIBFT ...$(RESET)"
	@make -C $(LIBFT_DIR) clean
	@echo "$(GREEN)✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔$(RESET)"

fclean: clean
	@echo "$(RED)... Destruction de l executable ...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔$(RESET)"
	@echo "$(RED)... Destruction de LIBFT.A ...$(RESET)"
	@make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔✔$(RESET)"

re: fclean all
