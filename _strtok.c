#include "shell.h"


char *My_Strtok(char *_String, const char *_Delemiter)
{
        static char *_BUFF;
        int j, Copy, Match;
       char *Start, *End, *Token;

       if (_String != NULL)
               _BUFF = _String;
       if (!_BUFF || *_BUFF == '\0')
               return (NULL);
       Token = _BUFF;

       for (; *_BUFF != '\0'; _BUFF++)

       {
               j = 0;

               if (*_BUFF == _Delemiter[j++])
               {
                       Match = Copy = 0;
                       End = _BUFF++;
                       Start = _BUFF;
                       
                       for (; _Delemiter[j] != '\0'; j++)
                       {       
                               if (*Start++ != _Delemiter[j])
                               {       
                                       Match = (-1);
                                       break;
                               }       
                               Copy++;
}
                       if (Match == 0)
                       {
                               _BUFF = Start;
                               *End = '\0';
                               if (*Token != '\0')
                               {
                                       return (Token);
                               }
                               else
                                       return (My_Strtok(NULL, _Delemiter));
                       }
               }
       }
       _BUFF = NULL;
       return (Token);
}
