/*
Esc characters are represented as \x in C string, such as \n and \t.

Function prt_esc_chars() gets a string which may contains esc characters, 
and prints the string into the standard ouput with all esc characters been replaced by a \x format combination.

For example, using printf("%s"..., a string with a \n between the words will be printed as:

Hello
World
But the same string will be printed by prt_esc_chars() as:

Hello\nWorld
Your function should be able to recognize esc characters below:

\n
\r
\t
\b
And all other characters below 0x20 should be printed as:

\hh
where hh is the hexadecimal of the value, all letters in capital.
 For a value below 0x10, a leading 0 is needed to keep two positions.

And as a C string, 0x00 will not be part of the string but the terminator.

Be aware, printf() is forbidden in the function.

函数接口定义：

int prt_esc_char(const char *s);
s is the string to be printed. 
The function returns the number of characters printed.
 An esc character is counted as two or three according to the characters it uses.
*/
#include <stdio.h>

int prt_esc_char(const char *s);

int main()
{
    char *line = NULL;
    size_t linecap = 0;
    getline(&line, &linecap, stdin);
    int len = prt_esc_char(line);
    printf("%d\n", len);
}

/* 请在这里填写答案 */
int prt_esc_char(const char *s){
  int i,j=0;
  char c[3];//为什么是3呢？因为最多也就3个了：\+n+\0，一共3个字符
  for(i=0;s[i];i++){
    if(s[i]<0x20){//当小于20的时候，要么就是'\n'这类的东西，要么就是特殊处理
      putchar('\\');
      if(s[i]=='\t') putchar('t');
      else if(s[i]=='\n') putchar('n');
      else if(s[i]=='\r') putchar('r');
      else if(s[i]=='\b') putchar('b');
      else { 
        sprintf(c,"%X",s[i]);
        j++;
        if(s[i]<0x10){ putchar('0'); putchar(c[0]); }
        else { putchar(c[0]); putchar(c[1]);}
      }
      j++;
     } 
    else putchar(s[i]);
    j++;
  }
  return j;
}
