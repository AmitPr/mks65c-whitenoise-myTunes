#ifndef _LINKEDLISTH_
#define _LINKEDLISTH_
struct song
{
    char name[100];
    char artist[100];
    struct song *next;
};
struct song *new_song(char n[], char a[]);

struct song *insert_front(struct song *root, struct song *new_song);
struct song *insert_ordered(struct song *root, struct song *new_song);

struct song *search_songs(struct song *root, char n[], char a[]);
struct song *search_first_song(struct song *root, char a[]);
struct song *random_song(struct song *root);

struct song *remove_song(struct song *root, struct song *to_remove);
void free_list(struct song *root);

void print_list(struct song *root);
void print_song(struct song *song);

int len_list(struct song *root);
#endif
