include maketools/common_config.mk
include maketools/source_list.mk
include maketools/add_library.mk

NAME := minishell

SRC := $(call source_list,src)

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)

LDLIBS += -lreadline

ifndef DEBUG_MODE

export FT_OPTIONS := FT_MALLOC_EXIT

$(call add_library,lib/libft/libft.a,lib/libft/include)

else

export FT_OPTIONS := FT_MALLOC_ABORT

$(call add_library,lib/libft/libft.a,lib/libft/include,,debug)

endif

include maketools/common_rules.mk

-include $(OBJ:.o=.d)
