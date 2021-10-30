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
command             = { redirection } [ WORD { redirection } ]
redirection         = ( RL | RR | RRA | RHD ) WORD
```