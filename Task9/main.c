//
//  main.c
//  Task9
//
//  Created by Pavel iPro on 25.01.2024.
//

// Задание 1
/*
#include <stdio.h>
#include <string.h>
 
int main(int argc, const char * argv[])
{
    char word1[100], word2[100];
    int array1[26] = {0};
    int array2[26] = {0};
    int counter = -1;
    
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");
    
    fscanf(f_in, "%s%s", word1, word2);
    
    while(word1[++counter] != '\0'){
        printf("%d", array1[word1[counter] - 'a']);
        ++array1[word1[counter] - 'a'];
    }
        
    counter = -1;
    while(word2[++counter] != '\0')
        ++array2[word2[counter] - 'a'];
    for (int i = 0; i < 26; ++i)
        if (array1[i] == 1 && array2[i] == 1)
            fprintf(f_out, "%c ", i + 97);
    fclose(f_in);
    fclose(f_out);
    return 0;
}
*/
// Задание 2
/*
#include <stdio.h>
#include <string.h>

const int string_width = 1024;

int main(int argc, const char * argv[])
{
    char string[string_width];
    char c;
    int i = 0;
    FILE *fp;
    
    fp = fopen("input.txt", "r");
    fscanf(fp, "%[^\n]", string);
    fclose(fp);
    
    while ((c = string[i]) != '\0')
    {
        if ((c == 'a') || (c == 'A'))
            string[i] += 1;
        else if ((c == 'b') || (c == 'B'))
            string[i] -= 1;
        i++;
    }
    
    fp = fopen("output.txt", "w");
    fprintf(fp, "%s", string);
    fclose(fp);
    return 0;
}
*/
// Задание 3
/*
#include <stdio.h>
#include <string.h>


int selectNums(char *str, int nums[])
{
    int i = 0, j = 0, num = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            while (str[i] >= '0' && str[i] <= '9')
            {
                num = num * 10 + (str[i] - 48);
                ++i;
            }
            nums[j++] = num;
            num = 0;
        }
        ++i;
    }
    return j;
}
    
void sortAscend(int a[], int size)
{
     int i, j;
    for (j = 1; j < size; ++j)
        for (i = 0; i < size - j; ++i)
            if (a[i] > a[i+1])
            {
                a[i]   = a[i] ^ a[i+1];
                a[i+1] = a[i] ^ a[i+1];
                a[i]   = a[i] ^ a[i+1];
            }
}

int main(int argc, const char * argv[])
{
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");
    int i, size;
    int nums[500];
    char str[1002];
    char *estr;
    
    while (1)
       {
           estr = fgets(str, 1000, f_in);
           if (estr == NULL)
           {
             if ( feof (f_in) != 0)
                break;
             else
             {
                 printf("Ошибка чтения из файла\n");
                break;
             }
          }
       }
    
    size = selectNums(str, nums);
    sortAscend(nums, size);
    for (i = 0; i < size; ++i)
        fprintf(f_out, "%d ", nums[i]);
    fclose(f_in);
    fclose(f_out);
    return 0;
}
*/
// Задание 4

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");
  
    char str1[1002];
    int j;
    char c;
    int i = -1;
    fgets(str1, 1000, f_in);
    while (str1[++i] != '\0')
        {
            c = str1[i];
            j = i;
            while(str1[++j] != '\0')
                if (str1[j] == c)
                    str1[j] = ' ';
        }
        i = -1;
        while (str1[++i] != '\0')
            if (str1[i] != ' ')
                fprintf(f_out, "%c", str1[i]);
    fclose(f_in);
    fclose(f_out);
    return 0;
}
