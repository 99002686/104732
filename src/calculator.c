#include "calculator.h"
/*
long int sum(long int a,long int b){
return(a+b);
}
long int sub(long int a,long int b){
return(a-b);
}
long int mul(long int a,long int b){
return(a*b);
}
long int div(long int a,long int b){
return(a/b);
}
long int mod(long int a,long int b){
return(a%b);
}
long int who(long int a,long int b){
return((a*a)+(b*b)+(2*a*b));
}
*/
double evaluate(char expr[])
{
    double numbers[5]; int nsi = 0;
    char operators[5]; int osi = 0;
    char numbuf[16]; int nbi = 0;
    char ch; int  i = 0;

    while ((ch = expr[i]) != 0) {
        if (checknumber(ch)) 
        {
            numbuf[nbi++] = ch;
            if (!checknumber(expr[i + 1])) 
            {
                numbuf[nbi] = 0; nbi = 0;
                sscanf(numbuf, "%lf", &numbers[nsi++]); 
            }
        }
        else
        {
            while ((osi > 0) && (precedence(ch) <= precedence(operators[osi - 1])))
            {
                numbers[nsi - 2] = calculate(operators[osi - 1], numbers[nsi - 2], numbers[nsi - 1]);
                osi--; nsi--;
            }
            operators[osi++] = ch;          
        }
        i++;
    }
    while (osi > 0) {
        numbers[nsi - 2] = calculate(operators[osi - 1], numbers[nsi - 2], numbers[nsi - 1]);
        osi--; nsi--;
    }
    return numbers[0];
}

char checknumber(char ch) 
{
    if ((ch >= '0' && ch <= '9') || ch == '.') return 1; else return 0;
}
int precedence(char ch)
{
    int precedence;
    switch (ch) 
    {
    case '+':
    case '-':
        precedence = 0;
        break;
    case '*':
    case '/':
        precedence = 1;
        break;
    case '^':
        precedence = 2;
    }
    return precedence;
}

double calculate(char moperator, double num1, double num2) 
{
    double result;
    switch (moperator)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    case '^':
        result = pow(num1, num2);
        break;
    
    default:
        printf("Invalid Operator\n");
        exit(-1);
    }
    return result;
}
