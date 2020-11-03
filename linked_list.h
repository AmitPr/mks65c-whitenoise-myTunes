#ifndef _LINKEDLISTH_
#define _LINKEDLISTH_
struct song
{
    char name[100];
    char artist[100];
    struct song *next;
};
struct song* new_song(char n[], char a[]);
void print_song(struct song*);
#endif