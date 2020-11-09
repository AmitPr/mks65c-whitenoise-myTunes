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
    print_list(search_result); // to fix: prints whole list instead of one song
    printf("\n");

    printf("searching for first song by an artist: \n");
    search_result = search_first_song(sample_songs, "Mitski");
    print_list(search_result); // to fix: prints first song + everything after it
    printf("\n");

    printf("random song:\n");
    search_result = random_song(sample_songs);
    print_list(search_result); // to fix: prints random song + everything after it
    printf("\n");

    // to test: remove song, free list

    return 0;
}
