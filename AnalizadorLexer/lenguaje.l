%{
    #include <math.h>
%}

DIGITO [0-9]
DATA_TYPE int|float|char|short
ID [a-z][a-z0-9]*
OPERATOR <|>|>=|<=|==
END_INSTRUCTION ;
ASSIGN =
EXPRESION [DATA_TYPE && ID && END_INSTRUCTION | DATA_TYPE ID ASSIGN DIGITO END_INSTRUCTION]  

%%

{DIGITO}+ {
    printf("Entero: %s (%d) \n", yytext, atoi(yytext));
}

{OPERATOR} {
    printf("Operator: %s \n", yytext);
}

{END_INSTRUCTION}+ {
    printf("Fin instruccion: %s \n", yytext);
}

{ASSIGN} {
    printf("Asignacion: %s \n", yytext);
}

{DIGITO}"."{DIGITO} {
    printf("Real: %s (%q)", yytext, atof(yytext));
}

if|then|begin|end {
    printf("Palabra Clave: %s \n", yytext);
}

{ID} {
    printf("Variable: %s \n ", yytext);
}

{EXPRESION} {
    printf("EXPRESION: %s \n ", yytext);
}

%%

void main(int* argv, char** args)
{
    yylex();
}