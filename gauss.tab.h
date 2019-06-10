
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CHAVE_ESQUERDA = 258,
     CHAVE_DIREITA = 259,
     PARENTESE_ESQUERDA = 260,
     PARENTESE_DIREITA = 261,
     COLCHETE_ESQUERDA = 262,
     COLCHETE_DIREITA = 263,
     PONTO_E_VIRGULA = 264,
     VIRGULA = 265,
     PONTO = 266,
     DOIS_PONTOS = 267,
     E_LOGICO = 268,
     E_LOGICO_CURTO_CIRCUITO = 269,
     OU_LOGICO = 270,
     OU_LOGICO_CURTO_CIRCUITO = 271,
     EXCLAMACAO = 272,
     ASTERISCO = 273,
     PRINT_INT = 274,
     PRINT_FLOAT = 275,
     PRINT_CHAR = 276,
     PRINT_STRING = 277,
     MODULO = 278,
     BARRA = 279,
     INCREMENTO = 280,
     DECREMENTO = 281,
     MAIS = 282,
     MENOS_UNARIO = 283,
     EXPONENCIACAO = 284,
     ATRIBUICAO = 285,
     OPERADOR_TERNARIO = 286,
     MENOR_QUE = 287,
     MAIOR_QUE = 288,
     MENOR_OU_IGUAL_A = 289,
     MAIOR_OU_IGUAL_A = 290,
     IGUAL_A = 291,
     DIFERENTE_DE = 292,
     MAIS_IGUAL = 293,
     MENOS_IGUAL = 294,
     VEZES_IGUAL = 295,
     DIV_IGUAL = 296,
     EXPONENCIACAO_IGUAL = 297,
     FOR = 298,
     END_FOR = 299,
     DO = 300,
     WHILE = 301,
     END_WHILE = 302,
     SWITCH = 303,
     END_SWITCH = 304,
     CASE = 305,
     END_CASE = 306,
     DEFAULT = 307,
     IF = 308,
     END_IF = 309,
     ELSE = 310,
     ELSEIF = 311,
     THEN = 312,
     STRUCT = 313,
     ENDSTRUCT = 314,
     IS = 315,
     END = 316,
     FUNCAO = 317,
     PROC = 318,
     RETURN = 319,
     TBEGIN = 320,
     CONSTANTE = 321,
     PRINTF = 322,
     SCANF = 323,
     CARACTERE = 324,
     STRING = 325,
     INTEIRO = 326,
     FLOAT = 327,
     DOUBLE = 328,
     VOID = 329,
     BOOLEANO = 330,
     TRUE = 331,
     FALSE = 332,
     JUMP = 333,
     BREAK = 334,
     TNULL = 335,
     DIGITO = 336,
     ID = 337,
     LITERAL_QUALQUER = 338
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 23 ".\\gauss.y"

  int    iValue;  /* integer value */
  float  fValue;  /* float value */
  double dValue;  /* double value */
  int   bValue;  /* boolean value */
  char   cValue;  /* char value */
  char * sValue;  /* string value */
  struct valor sStruct;



/* Line 1676 of yacc.c  */
#line 147 "gauss.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


