SRC@src := \
	src/preparser/remove_whitespaces.c \
	src/preparser/merge_adjacent_words.c \
	src/preparser/split_simple_words.c \
	src/preparser/preparse.c \
	src/expander/find_next_var_placeholder.c \
	src/expander/expand_executables.c \
	src/expander/get_executable.c \
	src/expander/expand_tokens.c \
	src/expander/expand_env_variables.c \
	src/lexer/lexer_utils/is_redirection_char.c \
	src/lexer/lexer_utils/is_word_delimiter.c \
	src/lexer/lexer_utils/is_quote.c \
	src/lexer/token/is_redirection.c \
	src/lexer/lexer/lexer_analyze.c \
	src/lexer/lexer/lexer_lex_quoted_word.c \
	src/lexer/lexer/lexer_lex_redirection.c \
	src/lexer/lexer/lexer_lex_pipe.c \
	src/lexer/lexer/base/lexer_create.c \
	src/lexer/lexer/utils/lexer_set_status.c \
	src/lexer/lexer/utils/lexer_skip.c \
	src/lexer/lexer/utils/lexer_add_token.c \
	src/lexer/lexer/utils/lexer_peek.c \
	src/lexer/lexer/utils/lexer_is_end.c \
	src/lexer/lexer/lexer_lex_whitespace.c \
	src/lexer/lexer/lexer_lex_simple_word.c \
	src/builtins/builtins/builtin_unset.c \
	src/builtins/builtins/builtin_cd.c \
	src/builtins/builtins/bulitin_exit.c \
	src/builtins/builtins/builtin_echo.c \
	src/builtins/builtins/builtin_noop.c \
	src/builtins/builtins/builtin_env.c \
	src/builtins/builtins/bulitin_pwd.c \
	src/builtins/builtins/bulitin_export.c \
	src/builtins/builtin_utils/is_builtin.c \
	src/builtins/builtin_utils/is_builtin_command.c \
	src/builtins/builtin_utils/exec_builtin.c \
	src/builtins/builtin_utils/validate_env_identifier.c \
	src/parser/ast/ast_destroy.c \
	src/parser/parser_utils/stringify_expected_tokens.c \
	src/parser/parser/parser_parse_redirection.c \
	src/parser/parser/parser_parse_command.c \
	src/parser/parser/base/parser_create.c \
	src/parser/parser/utils/parser_is_end.c \
	src/parser/parser/utils/parser_set_status.c \
	src/parser/parser/utils/parser_peek.c \
	src/parser/parser/utils/parser_skip.c \
	src/parser/parser/utils/parser_consume.c \
	src/parser/parser/utils/parser_match.c \
	src/parser/parser/parser_parse_word.c \
	src/parser/parser/parser_parse.c \
	src/parser/parser/parser_parse_pipeline.c \
	src/shell/utils/parse_command.c \
	src/shell/utils/read_heredoc.c \
	src/shell/utils/print_lexer_error.c \
	src/shell/utils/print_parser_error.c \
	src/shell/execution/execution_context/execution_context_init.c \
	src/shell/execution/execution_context/execution_context_get_next_heredoc.c \
	src/shell/execution/execution_context/execution_context_skip_heredocs.c \
	src/shell/execution/execution/shell_execute_command.c \
	src/shell/execution/execution/shell_execute_line.c \
	src/shell/execution/execution/shell_apply_redirections.c \
	src/shell/execution/execution/shell_launch_command.c \
	src/shell/execution/execution/shell_execute_pipeline.c \
	src/shell/execution/execution/shell_execute_ast.c \
	src/shell/execution/execution/shell_close_redirections.c \
	src/shell/execution/execution/shell_execute_builtin.c \
	src/shell/signals/handle_signals.c \
	src/shell/signals/register_signal_handlers.c \
	src/shell/shell/shell_set_last_status.c \
	src/shell/shell/shell_get_state.c \
	src/shell/shell/shell_read_heredocs.c \
	src/shell/shell/shell_clear_heredocs.c \
	src/shell/shell/shell_start.c \
	src/shell/shell/shell_register_child_process.c \
	src/shell/shell/shell_await_children.c \
	src/main.c \
