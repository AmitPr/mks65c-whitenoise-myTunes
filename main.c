#include <stdio.h>
#include <stdlib.h>
#include "song.h"

int main()
{
    printf("linked list test\n");
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

    // to test: free list

    printf("remove song:\n");
    print_list(sample_songs);
    sample_songs = remove_song(sample_songs,sample_songs);
    print_list(sample_songs);
    printf("\n");

    printf("freeing list...");
    free_list(sample_songs);
    printf(" done.\n");
    return 0;
}
