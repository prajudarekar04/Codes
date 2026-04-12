//Appliction of Stac.
/*
a+b => Infix Expression.
+ab => Prfix Expression.
ab+ => Postfix Expression.

Examples:
To convert Infix to equivalent Postfix Expression.

1.a+b=>ab+	

2.a+b-c=>ab+c-

3.(a+b)*(c-d)
=>(ab+)*(cd-)
=>ab+cd-*

4.a$b*c-d+e/f/(g+h)
=>a$b*c-d+e/f/gh+
=>ab$*c-d+e/f/gh+
=>ab$*c-d+ef/gh+/
=>ab$c*d-ef/gh+/+

5.((a+b)*c-(d-e))$(f+g)
=>(ab+*c-de-)$(fg+)
=>ab+c*de--fg+$

6.a-b/(c*d$e)
=>a-b/(c*de$)
=>a-b/cde$*
=>a-bcde$*/
=>abcde$*/-

To convert Infix to equivalent Prefix Expression.

1.a+b => +ab	

2.a+b-c => +ab-c

3.(a+b)*(c-d)
=>....

4.a$b*c-d+e/f/(g+h)
=> a$b*c-d+e/f/+gh
=>$ab*c-d+//ef+gh
=>*$abc-d+//ef+gh
=>-*$abcd+//ef+gh
=>+-*$abcd//ef+gh

5.((a+b)*c-(d-e))$(f+g)
=>((+ab)*c-(-de))$(+fg)
=>(*+abc--de)$(+fg)
=>$-*+abc-de+fg

6.a-b/(c*d$e)
=>a-b/(c*$de)
=>a-b/(*c$de)
=>a-b/*c$de
=>a-/b*c$de
=>-a/b*c$de

Alogorithm for Infix to Postfix Expression
1.Input an infix expression.
2.Scan expression from Left-Right.
3.During the scanning,
  3.1If we found an operand,insert it into the postfix string & continue scanning.
  3.2If we found an operator or parenthesis, having higher precidance	then push the operator or the parenthesis on stack.
	Provided it is not right parenthesis when it is right parenthesis pop the stac-top element &discord it.
	Initially the stac will be empty& you have to push any left parenthesis encountered.
  3.3If we found an operator or parenthesis having a lower precidence over the stac top element,
	then pop the stac top element &insert it to the post fix string.
	we must insure that the stac is non-empty before we pop element from it.
  3.4When the end of the string is reached pop-out all the elements from stac & insert it to the postfix string.
  3.5 Finally prints the posfix expre. that contains opertors and operands.

Alogorithm for evalution of Postfix expre.
1.input a postfix expre.
2.scan expre. from Left-Right.
3.During the scannibg,
  3.1If we encounter an operand,push it into the stac & continue scanning.
  3.2If we encounter an opertor,Pop only top 2 elements form the stac & allow your opertor to work on this opertor.
	Push this intermide result on to the stac & continue the scanning.
  3.3When we reach end of the string, there should be 1 element of the stac.Pop this element to get value of postfix expre.

Conversion of infix expression into its euivalent postfix expression.

1.a+b-c
char. scanned		remarks		stack		postfix string
    		   			  es    
    a		   operand,add to				a
    		   postfix string 
    +	     operator,push into stack     +   			a
    b		opernd,push into	  +		       ab
    		postfix string.
    -	     operator,push into stack     +-		       ab
    c           operand,push into 	  +-		      abc
		postfix string

2.(a+b)*c
char.scanned		remarks		stack		postfix string
         				  es
    (	   parenthesis,initially	  (		
    	   stack empty,push
    a      operand,insert to postfix      (			a
    +      operator,push into stack       (+                    
    b	  operand,insert into postfix     (+			ab
    )	  pop-out,insert to postfix       es		       ab+
    *	   operator,push into stack	   *		       
    c	  operand,insert into postfix	   *		      ab+c



1.((a+b)*c)-d
2.d-)c*)b+a((
3.d-(c*(b+a))
convert expression to postfix expression.
5.Reverse this expression
dcba+*-
6.*/
