# Subject

## Mandatory part

* Not interpret unclosed quotes or unspecified special characters like `\` or `;`.
* Not use more than one global variable, think about it and be ready to explain why you do it.
* Show a prompt when waiting for a new command.
* Have a working History.
* Search and launch the right executable (based on the PATH variable or by using relative or absolute path).
* It must implement the builtins:
    * `echo` with option `-n`.
    * `cd` with only a relative or absolute path.
    * `pwd` with no options.
    * `export` with no options.
    * `unset` with no options.
    * `env` with no options or arguments.
    * `exit` with no options.
* `'` inhibit all interpretation of a sequence of characters.
* `"` inhibit all interpretation of a sequence of characters except for `$`.
* Redirections:
    * `<` should redirect input.
    * `>` should redirect output.
    * `<<` read input from the current source until a line containing only the delimiter is seen. it doesn’t need to update history!
    * `>>` should redirect output with append mode.
* Pipes `|` The output of each command in the pipeline is connected via a pipe to the input of the next command.
* Environment variables ($ followed by characters) should expand to their values.
* `$?` should expand to the exit status of the most recently executed foreground pipeline
* <kbd>Ctrl</kbd> + <kbd>C</kbd>, <kbd>Ctrl</kbd> + <kbd>D</kbd> and <kbd>Ctrl</kbd> + <kbd>\\</kbd> should work like in bash.
* When interactive:
    * <kbd>Ctrl</kbd> + <kbd>C</kbd> should print a new prompt on a newline.
    * <kbd>Ctrl</kbd> + <kbd>D</kbd> should exit the shell.
    * <kbd>Ctrl</kbd> + <kbd>\\</kbd> should do nothing.

## Bonus part

* `&&`, `||` with parenthesis for priorities.
* The wildcard `*` should work for the current working directory.