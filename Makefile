include maketools/common_config.mk
include maketools/source_list.mk
include maketools/add_library.mk

NAME := minishell

SRC := $(call source_list,src)

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)

LDLIBS += -lreadline

MODIFIERS := use_colors no_colors

include maketools/modifiers.mk

ifdef MODIFIERS[use_colors]
    CPPFLAGS += -DUSE_COLORS
endif

ifdef MODIFIERS[no_colors]
    CPPFLAGS += -DNO_COLORS
endif

ifdef DEBUG_MODE
    export FT_OPTIONS := FT_MALLOC_ABORT
    FT_TARGET := debug
else
    export FT_OPTIONS := FT_MALLOC_EXIT
endif

$(call add_library,lib/libft/libft.a,lib/libft/include,$(FT_TARGET))

include maketools/common_rules.mk

-include $(OBJ:.o=.d)

define .HELP_MESSAGE
$(_MKT_COMMON_HELP_MESSAGE)
Additional modifiers:
    use_colors  - Use colored error/warning messages
    no_colors   - Disable colored prompts

endef
