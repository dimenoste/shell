# include "libft.h"
# include<stdio.h>

int main() {

    char *mystr = "hello world";

    char **parts = ft_split(mystr, ' ');
    
    int i = 0;
    printf("len is %ld\n", ft_strlen(parts[1]));
    while (*(parts + i) !=  0) {
        printf("part is : %s\n", *(parts + i));
        i++;
    }
    printf("number incr %d\n", i);
    return (0);
}




