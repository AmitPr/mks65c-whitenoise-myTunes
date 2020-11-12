#ifndef _LIBRARYH_
#define _LIBRARYH_
#include "song.h"
struct library
{
    struct song *library_data[27];
};

struct library *create_library();
void clear_library(struct library *lib);
void free_library(struct library *lib);

void add_song(struct library *lib, struct song *s);
void delete_song(struct library *lib, struct song *s);

struct song *search(struct library *lib, char n[], char a[]);
struct song *search_artist(struct library *lib, char a[]);

void print_letter(struct library *lib, char letter);
void print_library(struct library *lib);
void print_artist(struct library *lib, char a[]);
void shuffle(struct library *lib, int num);

#endif
