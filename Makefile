include maketools/common_config.mk
include maketools/source_list.mk
include maketools/add_library.mk

NAME := minishell

SRC := $(call source_list,src)

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)

LDLIBS += -lreadline

ifdef DEBUG_MODE
    export FT_OPTIONS := FT_MALLOC_ABORT
    FT_TARGET := debug
else
    export FT_OPTIONS := FT_MALLOC_EXIT
endif

$(call add_library,lib/libft/libft.a,lib/libft/include,$(FT_TARGET))

include maketools/common_rules.mk

-include $(OBJ:.o=.d)
