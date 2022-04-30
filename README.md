# minishell

Overcomplicated, as all things should be.

Use `make help` for build instructions. (GNU Make 4.2.1+ required)

## Missing features

* <kbd>Ctrl</kbd> + <kbd>C</kbd> does not exit heredoc

## Extra features

* Colored output

    Enable: `-c` (`--use-colors`) or `export MSH_USE_COLORS`  
    Disable: `unset MSH_USE_COLORS`

    ![Default colors](assets/screenshots/default.png)
    ![Extra colors](assets/screenshots/use_colors.png)

* Detailed error messages:

    Enable: `-e` (`--detailed-errors`) or `export MSH_USE_DETAILED_ERRORS`  
    Disable: `unset MSH_USE_DETAILED_ERRORS`

    ![Default errors](assets/screenshots/default_error.png)
    ![Detailed errors](assets/screenshots/detailed_error.png)
