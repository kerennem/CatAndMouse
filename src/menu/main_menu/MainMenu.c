#include "MainMenu.h"
#include <stdio.h>
#include <stdbool.h>

// TODO what is going in here?

void perform_single_menu_run();

int receive_user_input();

void respond_to_user_input(int input);

void start_menu() {
    bool continue_playing = true;
    while (continue_playing) {
        perform_single_menu_run();
    }
}

void perform_single_menu_run() {
    print_start_menu();
    int user_input = receive_user_input();
    respond_to_user_input(user_input);
}

void respond_to_user_input(int user_input) {
    
}

int receive_user_input() {
    return 0;
}

// TODO is this for debug?
void print_start_menu(){
    printf("CAT AND MOUSE\n\n");
    printf("choose one of the folowing:\n\n");
    printf("new_game\n");
    printf("load_game\n");
    printf("create_game\n");
    printf("edit_game\n");
    printf("quit\n");
}