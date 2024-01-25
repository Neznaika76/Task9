//
//  main.c
//  Task9
//
//  Created by Pavel iPro on 25.01.2024.
//

// Задание 1

#include <stdio.h>
int main(int argc, const char * argv[])
{
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
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
