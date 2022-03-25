# minishell

Overcomplicated, as all things should be.

Use `make help` for build instructions. (GNU Make 4.2.1+ required)

## Missing features
+ <kbd>Ctrl</kbd> + <kbd>C</kbd> in heredoc should work like in bash

## Extra features
+ Colored output can be enabled using `-c`/`--use-colors` option
  or `export MSH_USE_COLORS=1` variable.
  `unset MSH_USE_COLORS` will disable colored output.