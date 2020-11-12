#include <stdio.h>
#include <stdlib.h>
#include "song.h"
#include "library.h"

int main()
{
    printf("linked list test\n----------------\n");
    struct song *sample_songs = new_song("Washing Machine Heart", "Mitski");
    printf("testing print_list:\n");
    print_list(sample_songs);
    printf("\n");

    printf("inserting in front:\n");
    sample_songs = insert_front(sample_songs, new_song("Space Song", "Beach House"));
    print_list(sample_songs);
    printf("\n");

    printf("inserting in order:\n");
    sample_songs = insert_ordered(sample_songs, new_song("Chicago", "Sufjan Stevens"));
    sample_songs = insert_ordered(sample_songs, new_song("I Don't Smoke", "Mitski"));
    print_list(sample_songs);
    printf("\n");

    printf("searching for songs: \n");
    struct song *search_result = search_songs(sample_songs, "Nights", "Frank Ocean");
    print_list(search_result);
    printf("\n");
    sample_songs = insert_ordered(sample_songs, new_song("Nights", "Frank Ocean"));
    search_result = search_songs(sample_songs, "Nights", "Frank Ocean");
    print_song(search_result);
    printf("\n");

    printf("searching for first song by an artist: \n");
    search_result = search_first_song(sample_songs, "Mitski");
    print_song(search_result);
    printf("\n");

    printf("random song:\n");
    search_result = random_song(sample_songs);
    print_song(search_result);
    printf("\n");

    printf("remove song:\n");
    print_list(sample_songs);
    sample_songs = remove_song(sample_songs, sample_songs);
    print_list(sample_songs);
    printf("\n");

    printf("freeing list...");
    free_list(sample_songs);
    printf(" done.\n\n\n");

    printf("library test\n------------\n");
    struct song *songs[] = {
        new_song("washing machine heart", "mitski"),
        new_song("space song", "beach house"),
        new_song("here comes the sun", "the beatles"),
        new_song("yellow submarine", "the beatles"),
        new_song("hey jude", "the beatles"),
        new_song("legend", "the score"),
        new_song("chicago", "sufjan stevens"),
        new_song("i don't smoke", "mitski"),
        new_song("nights", "frank ocean")};
    
    printf("Testing add song & print library:\n");
    struct library *lib = create_library();
    for (int i = 0; i < 8; i++)
    {
        add_song(lib, songs[i]);
    }
    print_library(lib);

    printf("\nTesting print letter:\n");
    print_letter(lib,'t');
    
    printf("\nTesting search:\nSearching for \"space song(beach house)\":\n");
    struct song* ss = search(lib,"space song","beach house");
    printf("Got pointer: %p\n",ss);
    print_song(ss);
    printf("\nSearching for \"nights(frank ocean)\":\n");
    struct song* nights = search(lib,"nights","frank ocean");
    if(nights==NULL){
        printf("NULL returned.\n");
    }else{
        //Should never happen
        printf("ERROR - Should return NULL. Got pointer: %p\n",nights);
        print_song(nights);
    }

    printf("\nTesting search artist (the beatles):\n");
    print_list(search_artist(lib,"the beatles"));

    printf("\nTesting print artist (the beatles):\n");
    print_artist(lib,"the beatles");

    printf("\nTesting shuffle:\n");
    shuffle(lib,5);

    printf("\nTesting delete song:\n");
    delete_song(lib,songs[0]);
    print_library(lib);

    printf("\nTesting clear library:\n");
    clear_library(lib);
    printf("Attempting to print cleared library:\n");
    print_library(lib);

    free_library(lib);
    return 0;
}
