#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
# include "libft.h"


int count_words(char *line, char sep)
{
    int i = 0;
    int count_words = 0;
    int start_word = 1;

    while (line[i] != 0)
    {
        if (start_word == 1)
        {
            count_words++;
            start_word = 0;
        }
        if (line[i] == sep)
        {
            start_word = 1;
        }
        i++;
    }
    return count_words;
}

int count_letters(char *line, char sep)
{
    int i = 0;

    while (line[i] != sep && line[i] != '\0')
    {
        i++;
    }
    return i;
}


char **get_array_words(char *line, char sep)
{

    int nwords = 0;
    int nletters = 0;
    char **space_words;
    char *word;
    int cursor = 0;
    int i_word = 0;
    int i = 0;


    nwords = count_words(line, sep);
    space_words = malloc(sizeof(char *) * (nwords + 1));
    space_words[nwords] = NULL;

    while (line[cursor] != '\0')
    {   
        if (line[cursor] == sep)
        {
            cursor++;
        } 
        nletters = count_letters(&line[cursor], ' ');
        word = malloc(sizeof(char) * (nletters + 1));
        printf("number of the word %d\n", nletters);
        i = 0;
        while (i < nletters)
        {
            word[i] = line[cursor + i];
            i++;
        }
        word[nletters] = '\0';
        space_words[i_word] = word;
        i_word++;
        cursor = cursor + nletters + 1;
    }
    return space_words;
}





int main()
{
    char *mystr = "dddd frrrfr e2rew";
    int count = count_words(mystr, ' ');
    printf("count words : %d\n", count);
    char **res = get_array_words(mystr, ' ');
    int i = 0;
    while (i < count)
    {
        printf("word %d %s\n", i, res[i]);
        i++;
    }
}


// int BUFF_SIZE = 10;
// static char line[10];

// int main(void)
// {
//     int fd;

//     char *error_msg = "error with file\n";

//     fd = open("README.md", O_RDONLY);
//     if (fd == -1)
//     {
//         write(2, error_msg, ft_strlen(error_msg));
//         return (1);
//     }

//     while (1)
//     {
//         ssize_t nread = (fd, line, BUFF_SIZE)

//         ft_split(line, "\n");
//         SPLIT LINE on \n :=> return what is before LINE => returned
//                             LINE = LINE from \n till the end 
//         return   
//     }
//     close(fd);
//     return (0);
// }