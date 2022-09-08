#****VARIABLES****
NAME = push_swap
#NAME_BONUS = push_swap_bonus

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -f
LIBFT = libft.a
DIR_LIBFT = includes/libft/
DIR_BONUS = bonus/

#****COLORS****
LRED = \033[91m
LGREEN = \033[92m
LYELLOW = \033[93
LMAGENTA = \033[95m
LCYAN = \033[96m
DEF_COLOR = \033[0;39m

NO_OF_FILES := $(words $(wildcard *.c))

#****SOURCES****
SRC = push_swap.c\
	  push_swap_utils.c\
	  indexing_numbers.c\
	  sorting_numbers.c\
	  pushs.c\
	  swaps.c\
	  single_rotations.c\
	  double_rotations.c\
	  sorting_algo.c\
	  check_order.c

#SRC_BONUS = \

OBJ = $(SRC:.c=.o)
#OBJ_BONUS = $(SRC_BONUS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

#$(V).SILENT:

all:	$(NAME)

$(NAME):	$(DIR_LIBFT)/$(LIBFT) $(OBJ) $(SRC)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(DIR_LIBFT)$(LIBFT)
	@echo "$(LGREEN)Software Compilation completed : $(NO_OF_FILES) files done !$(DEF_COLOR)"

$(DIR_LIBFT)/$(LIBFT):
	make -C $(DIR_LIBFT)

#$(NAME_BONUS): $(DIR_LIBFT)/$(LIBFT) $(OBJ_BONUS) $(SRC_BONUS)
#	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) $(DIR_LIBFT)$(LIBFT)
#	@echo "$(LGREEN)Compilation complete !$(DEF_COLOR)"

#bonus: $(DIR_LIBFT)/$(LIBFT) $(NAME_BONUS)

tests:	all
	@echo ""
	@echo "Test 1 : Pas d'argument, pas d'erreur !"
	./$(NAME)
	@echo ""
	@echo "Test 2 : 1 seul argument valide, pas d'erreur !"
	./$(NAME) 1
	./$(NAME) "1"
	./$(NAME) -1
	./$(NAME) "+1"
	./$(NAME) 0
	./$(NAME) "0"
	@echo ""
	@echo "Test 3 : 1 seul argument non valide = erreur"
	./$(NAME) a
	./$(NAME) "a"
	./$(NAME) -a
	./$(NAME) "-a"
	./$(NAME) H3ll0
	@echo ""
	@echo "Test 4 : plusieurs arguments valides, pas d'erreur !"
	./$(NAME) 1 03 6 4 5 2
	./$(NAME) "1 03 6 4 5 2"
	./$(NAME) -1 -03 +6 4 5 -2
	./$(NAME) "-1 -03 +6 4 5 -2"
	@echo ""
	@echo "Test 5 : attention aux doublons !"
	./$(NAME) 1 03 3 4 5 5
	./$(NAME) "1 03 3 4 5 5"
	./$(NAME) -1 -03 -3 4 5 -2
	./$(NAME) "-1 -03 -3 4 5 -2"
	@echo ""
	@echo "Test 6 : pas de mots-vais caracteres svp !"
	./$(NAME) 1 trois 6 4 cinq 2
	./$(NAME) " 1 trois 6 4 cinq 2"
	./$(NAME) 1 # 6 4 == 2
	./$(NAME) "1 # 6 4 == 2"
	./$(NAME) -1 trois +6 4 cinq -2
	./$(NAME) "-1 trois +6 4 cinq -2"
	@echo ""
	@echo "Test 7 : Les limites OK !"
	./$(NAME) 1 2147483647
	./$(NAME) "1 2147483647"
	./$(NAME) -1 -2147483648
	./$(NAME) "-1 -2147483648"
	@echo ""
	@echo "Test 8 : au-dela KO !"
	./$(NAME) 1 2147483648
	./$(NAME) "1 2147483648"
	./$(NAME) -1 -2147483649
	./$(NAME) "-1 -2147483649"

#btests : bonus
	
clean:
	$(RM) $(OBJ)
#	$(RM) $(OBJ_BONUS)
	make -C $(DIR_LIBFT) clean
	@echo "$(LCYAN)Objects files cleaned !$(DEF_COLOR)"

fclean:	clean
	$(RM) $(DIR_LIBFT)$(LIBFT)
	$(RM) $(NAME)
#	$(RM) $(NAME_BONUS)
	@echo "$(LCYAN)Executables files cleaned !$(DEF_COLOR)"

re:	fclean all