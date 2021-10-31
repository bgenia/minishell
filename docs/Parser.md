# Lexer/Parser

## Tokens
```
# Mandatory part

PIPE    =   |
RL      =r  \d?<
RR      =r  \d?>
RRA     =r  \d?>>
RHD     =r  \d?<<
WORD    =r  [^|<>\s]+
        |r  "*?"
        |r  '*?'
SPACE   =r  \s+

# Bonus part

AND     =   &&
OR      =   ||
LP      =   (
RP      =   )
```

> `=r`, `|r` - Regular expressions

## Grammar

```
# Bonus part

and_or              = pipeline
                    | and_or ( AND | OR ) and_or
                    | LP and_or RP

# Mandatory part

pipeline            = command { PIPE command }
command             = { redirection } [ WORD { redirection | WORD } ]
redirection         = ( RL | RR | RRA | RHD ) WORD
```