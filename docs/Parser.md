# Lexer/Parser

## 1. Lexer
Tokens
```
# Mandatory part

PIPE    =   |
RL      =r  \d?<
RR      =r  \d?>
RRA     =r  \d?>>
RHD     =r  \d?<<
WORD    =r  [^|<>\s]+
        |r  ".*?"
        |r  '.*?'
SPACE   =r  \s+

# Bonus part

AND     =   &&
OR      =   ||
LP      =   (
RP      =   )
```

> `=r`, `|r` - Regular expressions

## 2. Expander
Variable placeholder pattern (regexp): `\$[^$\s]+`

(Bonus) Wildcard (`*`, `~`) expansion happens here.

## 3. Preparser (temporary name)
1. If an unquoted word contains a whitespace, it must be split into multiple unquoted words.
1. If a quoted and an unquoted word are not separated by whitespace, they must be merged into single quoted word.
1. All remaining whitespace tokens must be removed.

## 4. Parser
Grammar
```
# Bonus part

and_or              = pipeline
                    | and_or ( AND | OR ) and_or
                    | LP and_or RP

# Mandatory part

pipeline            = [ SPACE ] command { [ SPACE ] PIPE command [ SPACE ] }
command             = { [ SPACE ] redirection | word [ SPACE ] }
redirection         = ( RL | RR | RRA | RHD ) [ SPACE ] word
word                = WORD { WORD }
```