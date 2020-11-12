#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "song.h"

struct song *new_song(char n[], char a[])
{
    struct song *s = malloc(sizeof(struct song));
    strncpy(s->name, n, sizeof(s->name) - 1);
    strncpy(s->artist, a, sizeof(s->artist) - 1);
    s->next = NULL;
    return s;
}

void print_list(struct song *root)
{
    printf("[");
    while (root)
    {
        printf("%s (%s)", root->name, root->artist);
        if (root->next)
        {
            printf(", ");
        }
        root = root->next;
    }
    printf("]\n");
}
void print_song(struct song *song)
{
    printf("Song {Name: %s, Artist: %s}\n", song->name, song->artist);
}

struct song *insert_front(struct song *root, struct song *new_song)
{
    new_song->next = root;
    return new_song;
}

struct song *insert_ordered(struct song *root, struct song *new_song)
{
    struct song *prev = NULL;
    struct song *cur = root;
    while (cur)
    {
        int cmp = strcmp(new_song->artist, cur->artist);
        if (cmp < 0)
        {
            new_song->next = cur;
            if (prev)
            {
                prev->next = new_song;
                return root;
            }
            else
            {
                return new_song;
            }
        }
        else if (cmp == 0)
        {
            if (strcmp(new_song->name, cur->name) < 0)
            {
                new_song->next = cur;
                if (prev)
                {
                    prev->next = new_song;
                    return root;
                }
                else
                {
                    return new_song;
                }
            }
        }
        prev = cur;
        cur = cur->next;
    }
    //Only happens when the song is alphabetically the last in the entire list.
    prev->next = new_song;
    return root;
}

struct song *search_songs(struct song *root, char n[], char a[])
{
    while (root)
    {
        if (strcmp(root->name, n) == 0 && strcmp(root->artist, a) == 0)
        {
            return root;
        }
        root = root->next;
    }
    printf("song not found\n"); //Perhaps we don't NEED this.
    return NULL;
}

struct song *search_first_song(struct song *root, char a[])
{
    while (root)
    {
        if (strcmp(root->artist, a) == 0)
        {
            return root;
        }
        root = root->next;
    }
    printf("song not found");
    return NULL;
}

struct song *random_song(struct song *root)
{
    srand(time(NULL));
    int i = len_list(root);
    struct song *cur = root;
    int n = rand() % (i - 1);
    int j = 0;
    cur = root;
    while (cur)
    {
        if (j == n)
        {
            return cur;
        }
        ++j;
        cur = cur->next;
    }
}

struct song *remove_song(struct song *root, struct song *to_remove)
{
    struct song *prev = NULL;
    struct song *cur = root;
    while (cur)
    {
        if (cur == to_remove)
        {
            if (prev)
            {
                prev->next = cur->next;
                free(cur);
                return root;
            }
            else
            {
                // Node to remove is the first in the list, check to see if it has anything following it.
                struct song *next = cur->next;
                free(cur);
                if (next)
                    return next;
                return NULL;
            }
        }
        cur = cur->next;
    }
    return NULL;
}

void free_list(struct song *root)
{
    while (root)
    {
        struct song *tmp = root->next;
        free(root);
        root = tmp;
    }
}


int len_list(struct song *root){
    int i = 0;
    struct song *cur = root;
    while (cur)
    {
        ++i;
        cur = cur->next;
    }
    return i;
}