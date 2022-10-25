

#include <stdio.h>
#include "lex.h"

statements()
{
  expression();
  if (match(SEMI))
  {
    advance();
  }
  else
  {
    fprintf(stderr, "%d:Inserting missing semicolon \n", yylineno);
  }

  if (!match(EOI))
  {
    statements();
  }
}

expression()
{
  term();
  expr_prime();
}

expr_prime()
{
  if (match(PLUS))
  {
    advance();
    term();
    expr_prime();
  }
}

term()
{
  factor();
  term_prime();
}

term_prime(){
  if(match(TIMES))
  {
    advance();
    factor();
    term_prime();
  }
}

factor(){
  if(match(NUM_OR_ID)){
    advance();
  } 
  else if(match(LP)){
    advance();
    expression();
    if(match(RP)){
      advance();
    }else{
      fprintf(stderr,"%d,Mismatched parenthesis \n",yylineno);
    }

  }
  else{
    fprintf(stderr,"%d Number or iden expected \n",yylineno);
  }
}



