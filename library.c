#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "song.h"
#include "library.h"

//Helper methods, don't need to be exposed in library.h
int get_alphabet_index(struct song *s)
{
    char index = s->artist[0] - 97;
    return (int)index;
}
int get_alphabet_index_char(char a[])
{
    char index = a[0] - 97;
    return (int)index;
}

struct library *create_library()
{
    struct library *lib = malloc(sizeof(struct library));
    for (int i = 0; i < 27; i++)
    {
        lib->library_data[i] = NULL;
    }
    return lib;
}
void clear_library(struct library *lib)
{
    for (int i = 0; i < 27; i++)
    {
        lib->library_data[i] = NULL;
    }
}
void free_library(struct library *lib)
{
    free(lib);
}
void add_song(struct library *lib, struct song *s)
{
    int index = get_alphabet_index(s);
    if (lib->library_data[index])
    {
        lib->library_data[index]=insert_ordered(lib->library_data[index], s);
    }
    else
    {
        lib->library_data[index] = s;
    }
}
void delete_song(struct library *lib, struct song *s)
{
    int index = get_alphabet_index(s);
    if (lib->library_data[index])
    {
        lib->library_data[index] = remove_song(lib->library_data[index], s);
    }
}
struct song *search(struct library *lib, char n[], char a[])
{
    int index = get_alphabet_index_char(a);
    if (lib->library_data[index])
    {
        return search_songs(lib->library_data[index], n, a);
    }
    return NULL;
}
struct song *search_artist(struct library *lib, char a[])
{
    int index = get_alphabet_index_char(a);
    if (lib->library_data[index])
    {
        return search_first_song(lib->library_data[index], a);
    }
    return NULL;
}

void print_letter(struct library *lib, char letter)
{
    int index = (int)(letter - 97);
    if (lib->library_data[index])
    {
        printf("%c: ", letter);
        print_list(lib->library_data[index]);
    }
}
void print_library(struct library *lib)
{
    for (char i = 97; i < 124; i++)
    {
        print_letter(lib, i);
    }
}
void print_artist(struct library *lib, char a[])
{
    int index = get_alphabet_index_char(a);
    if (lib->library_data[index])
    {
        struct song *found = search_first_song(lib->library_data[index], a);
        if (found)
        {
            printf("Songs by \"%s\":\n", a);
            struct song *cur = found;
            while (cur)
            {
                if (strcmp(cur->artist, a) == 0)
                {
                    print_song(cur);
                    cur = cur->next;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            printf("Artist \"%s\" not found!", a);
        }
    }
    else
    {
        printf("Artist \"%s\" not found!", a);
    }
}
void shuffle(struct library *lib, int num)
{
    srand(time(NULL));
    printf("Shuffle:\n");
    struct song *roots[27];
    int j = 0;
    for (int i = 0; i < 27; i++)
    {
        if (lib->library_data[i])
        {
            roots[j] = lib->library_data[i];
            ++j;
        }
    }
    for (int i = 0; i < num; i++)
    {
        int index = rand() % j;
        print_song(random_song(roots[j]));
    }
}