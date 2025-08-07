NAME 		= push_swap
CC 			= cc
AR 			= ar
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror
ARFLAGS 	= rcs

# プロジェクトのソースファイル
SRCS 		= push_swap.c push_swap_utils.c push.c reverse_rotate.c rotate.c sort.c sort2.c sort3.c swap.c index.c index2.c
OBJS 		= $(SRCS:.c=.o)

# プロジェクトのヘッダーファイル
HEADER 		= push_swap.h

# libftのパスとライブラリファイル
LIBFT_PATH 	= ./libft
LIBFT 		= $(LIBFT_PATH)/libft.a

all: $(NAME)

# push_swap実行ファイルの作成
# オブジェクトファイル、libft、ft_printfをリンクする
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF_LIB) -o $(NAME)

# libftをビルドする
$(LIBFT):
	@make -C $(LIBFT_PATH) $(notdir $@)

# .cファイルを.oファイルにコンパイルするルール
# ヘッダーファイルとlibft、ft_printfのヘッダーパスを追加
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@

# オブジェクトファイルを削除する
clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT_PATH)

# 実行ファイルとオブジェクトファイルを削除する
fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)

# 全てをクリーンして再ビルドする
re: fclean all

# .PHONYは、同名のファイルがあってもターゲットとして扱われるようにする
.PHONY: all clean fclean re
