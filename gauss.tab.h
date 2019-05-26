/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     IS = 314,
     END = 315,
     FUNCAO = 316,
     PROC = 317,
     RETURN = 318,
     TBEGIN = 319,
     CONSTANTE = 320,
     PRINTF = 321,
     SCANF = 322,
     CARACTERE = 323,
     STRING = 324,
     INTEIRO = 325,
     FLOAT = 326,
     DOUBLE = 327,
     VOID = 328,
     BOOLEANO = 329,
     TRUE = 330,
     FALSE = 331,
     JUMP = 332,
     BREAK = 333,
     TNULL = 334,
     DIGITO = 335,
     ID = 336,
     LITERAL_QUALQUER = 337
   };
#endif
/* Tokens.  */
#define CHAVE_ESQUERDA 258
#define CHAVE_DIREITA 259
#define PARENTESE_ESQUERDA 260
#define PARENTESE_DIREITA 261
#define COLCHETE_ESQUERDA 262
#define COLCHETE_DIREITA 263
#define PONTO_E_VIRGULA 264
#define VIRGULA 265
#define PONTO 266
#define DOIS_PONTOS 267
#define E_LOGICO 268
#define E_LOGICO_CURTO_CIRCUITO 269
#define OU_LOGICO 270
#define OU_LOGICO_CURTO_CIRCUITO 271
#define EXCLAMACAO 272
#define ASTERISCO 273
#define PRINT_INT 274
#define PRINT_FLOAT 275
#define PRINT_CHAR 276
#define PRINT_STRING 277
#define MODULO 278
#define BARRA 279
#define INCREMENTO 280
#define DECREMENTO 281
#define MAIS 282
#define MENOS_UNARIO 283
#define EXPONENCIACAO 284
#define ATRIBUICAO 285
#define OPERADOR_TERNARIO 286
#define MENOR_QUE 287
#define MAIOR_QUE 288
#define MENOR_OU_IGUAL_A 289
#define MAIOR_OU_IGUAL_A 290
#define IGUAL_A 291
#define DIFERENTE_DE 292
#define MAIS_IGUAL 293
#define MENOS_IGUAL 294
#define VEZES_IGUAL 295
#define DIV_IGUAL 296
#define EXPONENCIACAO_IGUAL 297
#define FOR 298
#define END_FOR 299
#define DO 300
#define WHILE 301
#define END_WHILE 302
#define SWITCH 303
#define END_SWITCH 304
#define CASE 305
#define END_CASE 306
#define DEFAULT 307
#define IF 308
#define END_IF 309
#define ELSE 310
#define ELSEIF 311
#define THEN 312
#define STRUCT 313
#define IS 314
#define END 315
#define FUNCAO 316
#define PROC 317
#define RETURN 318
#define TBEGIN 319
#define CONSTANTE 320
#define PRINTF 321
#define SCANF 322
#define CARACTERE 323
#define STRING 324
#define INTEIRO 325
#define FLOAT 326
#define DOUBLE 327
#define VOID 328
#define BOOLEANO 329
#define TRUE 330
#define FALSE 331
#define JUMP 332
#define BREAK 333
#define TNULL 334
#define DIGITO 335
#define ID 336
#define LITERAL_QUALQUER 337




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 14 "gauss.y"
{
  int    iValue;  /* integer value */
  float  fValue;  /* float value */
  double dValue;  /* double value */
  int   bValue;  /* boolean value */
  char   cValue;  /* char value */
  char * sValue;  /* string value */
}
/* Line 1529 of yacc.c.  */
#line 222 "gauss.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

