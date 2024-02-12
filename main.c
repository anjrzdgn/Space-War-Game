/* *********************************************IN THE NAME OF GOD******************************************************
 * SPACE WAR CODE
 * MADE WITH ❤️ IN IRAN
 * WRITTEN BY ALI NAJJARZADEGAN; IRANIAN MUSLIM IUT CE STUDENT
 * TAKEN 222 HOURS TILL NOW
 * FREE TO LEARN
 */

/*
 ***************************************************REMEMBER************************************************************
 */
//TODO important:
// correction of GitHub
// correction of commenting and code readability
// test the game from first to end of two rounds

//TODO
// making an installable file for the game
// write more description in game loadings at the moment of projection
// getting the best score

/*
 ***************************************************HEADERS*************************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <wchar.h>
#include <time.h>
#include <unistd.h>
#include <mmsystem.h>
#include <conio.h>
#include <fcntl.h>
#include <io.h>

/*
 **************************************************DEFINITIONS**********************************************************
 */
#pragma execution-charector-set("utf-8");

/*
 ***************************************************PROTOTYPES**********************************************************
 */
/*
 *----------------------------------------------LOGIN PAGE FUNCTIONS----------------------------------------------------
 */
void welcome();
void play_start_video();
void menu();
void back_to_menu();

void sign_in_first_player();
void getting_user_name_sign_in_first_player();
void getting_password_sign_in_first_player();
void welcome_sign_in_st();
void menu_first_player();
void edit_first_player();
void updating_first_player_user_name();
void updating_first_player_password();
void updating_first_player_email();

void sign_in_second_player();
void getting_user_name_sign_in_second_player();
void getting_password_sign_in_second_player();
void welcome_sign_in_nd();
void menu_second_player();
void edit_second_player();
void updating_second_player_user_name();
void updating_second_player_password();
void updating_second_player_email();

void sing_up();
void getting_user_name_sign_up();
void getting_email_sign_up();
void getting_password_sign_up();

void player_info_resetor();
void forgot_password();
void history_resetor();
void display_history();
void help();
void about_us();
void thanos_mode();
/*
 *-------------------------------------------------GAME'S FUNCTIONS-----------------------------------------------------
 */
void start_the_game();
void ready_to_play();
void in321();
int  key_pressed(int);

void loading_round1();
void game_round_1();
void update_player1_position_board1(wchar_t board[][86], COORD oldPos, COORD newPos);
void update_player2_position_board1(wchar_t board[][86], COORD oldPos, COORD newPos);

void loading_round2();
void game_round_2();
void update_player1_position_board2(wchar_t board[][86], COORD oldPos, COORD newPos);
void update_player2_position_board2(wchar_t board[][86], COORD oldPos, COORD newPos);

void audit();
void play_winning_video();
void play_draw_video();
void show_audit();
void save_the_history();
/*
 *-------------------------------------------------HELPER FUNCTIONS-----------------------------------------------------
 */
void RED();
void GREEN();
void YELLOW();
void CYAN();
void PURPLE();
void BLUE();
void WHITE();
void cursor_on();
void cursor_off();
void type_writer_printer(char must_be_printed[]);
void faster_type_writer_printer(char must_be_printed[]);

/*
 ****************************************************STRUCTURES*********************************************************
 */
typedef struct
{
    char date_of_play[25];
    char winner[25];
    int score_of_winner;
    char loser[25];
    int score_of_loser;
}history;

typedef struct
{
    char user_name[25];
    char password[25];
    char email[50];
}info;

/*
 *************************************************GLOBAL VARIABLES******************************************************
 */
info player_info;
info first_online_player;
info second_online_player;
history game_history;
int sign_in_done_by_first_player = 0;
int sign_in_done_by_second_player = 0;
int first_player_score = 0;
int second_player_score = 0;
int starting_health = 10;

/*
 *****************************************************FUNCTIONS*********************************************************
 */

/*
 *----------------------------------------------LOGIN PAGE FUNCTIONS----------------------------------------------------
 */
void welcome()
{
    play_start_video();

    PlaySoundA("musics\\welcome.wav", NULL, SND_FILENAME | SND_ASYNC);

    RED();
    wprintf(L"%*s _____                        _    _            \n", 20, "");
    wprintf(L"%*s/  ___|                      | |  | |           \n", 20, "");
    wprintf(L"%*s\\ `--. _ __   __ _  ___ ___  | |  | | __ _ _ __ \n", 20, "");
    wprintf(L"%*s `--. \\ '_ \\ / _` |/ __/ _ \\ | |/\\| |/ _` | '__|\n", 20, "");
    wprintf(L"%*s/\\__/ / |_) | (_| | (_|  __/ \\  /\\  / (_| | |   \n", 20, "");
    wprintf(L"%*s\\____/| .__/ \\__,_|\\___\\___|  \\/  \\/ \\__,_|_|   \n", 20, "");
    wprintf(L"%*s      | |                                       \n", 20, "");
    wprintf(L"%*s      |_|                                       \n", 20, "");

    BLUE();
    wprintf(L"\t\t    ");
    for (int i = 0; i < 23; i++)
    {
        wprintf(L"\x25A9");
        Sleep(500);
    }
    for (int i = 0; i < 24; i++)
    {
        wprintf(L"\x25A9");
        Sleep(200);
    }

    Sleep(1500);
    system("cls");
    WHITE();

}

void play_start_video()
{
    char* video_path = "videos\\space war.mp4";
    char* vlc_path = "C:\\Program Files\\VideoLAN\\VLC\\vlc.exe";

    char command[256];
    sprintf(command, "\"%s\" \"%s\" --play-and-exit", vlc_path, video_path);

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcess(NULL, command, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) {
        fprintf(stderr, "Error creating process: %d\n", GetLastError());
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

void menu()
{
    system("cls");

    DWORD bytes_written;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int j = 1;
    int menu;
    while (1)
    {
        COORD origin = {0, 0};
        SetConsoleCursorPosition(hStdout, origin);

        YELLOW();
        wprintf(L"-------------Main Manu-------------\n\n");
        WHITE();
        (j == 1) ? (wprintf(L"\033[1;31mSign In\033[33m\n")) : wprintf(L"Sign In\n");
        (j == 2) ? (wprintf(L"\033[1;31mSign Up\033[33m\n")) : wprintf(L"Sign Up\n");
        (j == 3) ? (wprintf(L"\033[1;31mHelp\033[33m\n")) : wprintf(L"Help\n");
        (j == 4) ? (wprintf(L"\033[1;31mGame History\033[33m\n")) : wprintf(L"Game History\n");
        (j == 5) ? (wprintf(L"\033[1;31mAbout Us\033[33m\n")) : wprintf(L"About Us\n");
        (j == 6) ? (wprintf(L"\033[1;31mExit Game\033[33m\n")) : wprintf(L"Exit Game\n");

        menu = _getch();
        //PlaySoundA("musics\\menu movement.wav", NULL, SND_FILENAME | SND_ASYNC);
        if (menu == 80)
        {
            if (j < 6)
            {
                j++;
            }
        }
        if (menu == 72)
        {
            if (j != 1)
            {
                j--;
            }
        }
        if (menu == 13)
        {
            if (j == 1)
            {
                PlaySoundA("musics\\sign in.wav", NULL, SND_FILENAME | SND_ASYNC);
                if (sign_in_done_by_first_player == 0) sign_in_first_player();
                if (sign_in_done_by_second_player == 0)sign_in_second_player();
                else start_the_game();
            }
            if (j == 2)
            {
                PlaySoundA("musics\\sign up.wav", NULL, SND_FILENAME | SND_ASYNC);
                sing_up();
            }
            if (j == 3) help();
            if (j == 4) display_history();
            if (j == 5) about_us();
            if (j == 6) exit(EXIT_SUCCESS);
        }
    }
}

void back_to_menu()
{
    int back = _getch();
    if (back == 27) menu();
    else back = 0;
}

void sign_in_first_player()
{
    system("cls");

    YELLOW();
    faster_type_writer_printer("-------------First Player Sign In-------------\n\n");
    WHITE();

    player_info_resetor();

    getting_user_name_sign_in_first_player();
    getting_password_sign_in_first_player();

    welcome_sign_in_st();
    sign_in_done_by_first_player = 1;
    menu_first_player();
}

void getting_user_name_sign_in_first_player()
{

    YELLOW();
    wprintf(L"\nEnter your user name:\n");
    WHITE();

    PURPLE();
    cursor_on();
    char temp_user_name[25];
    fgets(temp_user_name, 25, stdin);
    temp_user_name[strcspn(temp_user_name, "\n")] = '\0';
    cursor_off();
    WHITE();

    FILE *fp3;
    fp3 = fopen("player's information.txt","r");
    int user_found_flag = 0;
    while (fread(&player_info, sizeof(player_info), 1, fp3))
    {
        if(strcmp(temp_user_name, player_info.user_name) == 0)
        {
            user_found_flag = 1;
            strcpy(first_online_player.user_name, player_info.user_name);
            strcpy(first_online_player.email,     player_info.email);
            strcpy(first_online_player.password,  player_info.password);
        }
    }

    if (user_found_flag == 0)
    {
        PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
        RED();
        type_writer_printer("No account found with this user name!\n");
        WHITE();

        Sleep(1000);

        system("cls");

        int j = 1;
        int menu_failed_sign_in;

        DWORD bytes_written;
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        while (1)
        {
            COORD origin = {0, 0};
            SetConsoleCursorPosition(hStdout, origin);

            (j == 1) ? (wprintf(L"\033[1;31mSign In Again\033[33m\n")) : wprintf(L"Sign In Again\n");
            (j == 2) ? (wprintf(L"\033[1;31mCreat A Account\033[33m\n")) : wprintf(L"Creat A Account\n");
            (j == 3) ? (wprintf(L"\033[1;31mBack To Menu\033[33m\n")) : wprintf(L"Back To Menu\n");

            menu_failed_sign_in = _getch();
            PlaySoundA("musics\\menu movement.wav", NULL, SND_FILENAME | SND_ASYNC);
            if (menu_failed_sign_in == 80)
            {
                if (j < 3)
                {
                    j++;
                }
            }
            if (menu_failed_sign_in == 72)
            {
                if (j != 1)
                {
                    j--;
                }
            }

            if (menu_failed_sign_in == 13)
            {
                if (j == 1)
                {
                    PlaySoundA("musics\\sign in.wav", NULL, SND_FILENAME | SND_ASYNC);
                    sign_in_first_player();
                }
                if (j == 2)
                {
                    PlaySoundA("musics\\sign up.wav", NULL, SND_FILENAME | SND_ASYNC);
                    sing_up();
                }
                if (j == 3)
                {
                    menu();
                }
            }
        }
    }
    fclose(fp3);
}

void getting_password_sign_in_first_player()
{
    YELLOW();
    wprintf(L"\nEnter %s's password:\n", first_online_player.user_name);

    PURPLE();
    cursor_on();
    char temp_password[25];
    int i = 0;
    while (1)
    {
        temp_password[i] = getch();

        if (temp_password[i] == '\r')
        {
            temp_password[i] = '\0';
            break;
        }
        else if (temp_password[i] == '\b' && i > 0)
        {
            wprintf(L"\b \b");
            i--;
        }
        else
        {
            wprintf(L"*");
            i++;
        }
    }
    cursor_off();
    WHITE();

    if (strcmp(temp_password, first_online_player.password) != 0)
    {
        PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
        RED();
        type_writer_printer("\nWrong password!\n");
        WHITE();
        Sleep(1000);

        system("cls");
        int j = 1;
        int menu_failed_sign_in;

        DWORD bytes_written;
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        while (1)
        {
            COORD origin = {0, 0};
            SetConsoleCursorPosition(hStdout, origin);

            (j == 1) ? (wprintf(L"\033[1;31mForgot Password?\033[33m\n")) : wprintf(L"Forgot Password?\n");
            (j == 2) ? (wprintf(L"\033[1;31mCreat A Account\033[33m\n")) : wprintf(L"Creat A Account\n");
            (j == 3) ? (wprintf(L"\033[1;31mBack To Menu\033[33m\n")) : wprintf(L"Back To Menu\n");

            menu_failed_sign_in = _getch();
            PlaySoundA("musics\\menu movement.wav", NULL, SND_FILENAME | SND_ASYNC);
            if (menu_failed_sign_in == 80)
            {
                if (j < 3)
                {
                    j++;
                }
            }
            if (menu_failed_sign_in == 72)
            {
                if (j != 1)
                {
                    j--;
                }
            }
            if (menu_failed_sign_in == 13)
            {
                if (j == 1)
                {
                    forgot_password();
                }
                if (j == 2)
                {
                    PlaySoundA("musics\\sign up.wav", NULL, SND_FILENAME | SND_ASYNC);
                    sing_up();
                }
                if (j == 3)
                {
                    menu();
                }
            }
        }
    }
}

void welcome_sign_in_st()
{
    system("cls");

    PlaySoundA("musics\\welcome sign in first player.wav", NULL, SND_FILENAME | SND_ASYNC);
    WHITE();
    wprintf(L"%*s __      __       .__                               \n", 7, "");
    wprintf(L"%*s/  \\    /  \\ ____ |  |   ____  ____   _____   ____  \n", 7, "");
    wprintf(L"%*s\\   \\/\\/   // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\ \n", 7, "");
    wprintf(L"%*s \\        /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/ \n", 7, "");
    wprintf(L"%*s  \\__/\\  /  \\___  >____/\\___  >____/|__|_|  /\\___  >\n", 7, "");
    wprintf(L"%*s       \\/       \\/          \\/            \\/     \\/ \n", 7, "");

    RED();
    wprintf(L"\n\tWe hope you enjoy dear %s", first_online_player.user_name);
    WHITE();
    Sleep(3000);
    system("color 07");
}

void menu_first_player()
{
    system("cls");

    DWORD bytes_written;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int j = 1;
    int menu_first_player;
    while (1)
    {
        COORD origin = {0, 0};
        SetConsoleCursorPosition(hStdout, origin);

        PlaySoundA("musics\\player menu.wav", NULL, SND_FILENAME | SND_ASYNC);

        YELLOW();
        wprintf(L"-------------First Player Menu-------------\n\n");
        WHITE();
        (j == 1) ? (wprintf(L"\033[1;31mOpponent Sign In\033[33m\n")) : wprintf(L"Opponent Sign In\n");
        (j == 2) ? (wprintf(L"\033[1;31mEdit Your Profile\033[33m\n")) : wprintf(L"Edit Your Profile\n");
        (j == 3) ? (wprintf(L"\033[1;31mBack To Main Menu\033[33m\n")) : wprintf(L"Back To Main Menu\n");

        menu_first_player = _getch();
        PlaySoundA("musics\\menu movement.wav", NULL, SND_FILENAME | SND_ASYNC);
        if (menu_first_player == 80)
        {
            if (j < 3)
            {
                j++;
            }
        }
        if (menu_first_player == 72)
        {
            if (j != 1)
            {
                j--;
            }
        }
        if (menu_first_player == 13)
        {
            if (j == 1)
            {
                PlaySoundA("musics\\sign in.wav", NULL, SND_FILENAME | SND_ASYNC);
                sign_in_second_player();
            }
            if (j == 2)
            {
                edit_first_player();
            }
            if (j == 3)
            {
                menu();
            }
        }
        if (menu_first_player == 27)
        {
            sign_in_first_player();
        }
    }
}

void edit_first_player()
{
    system("cls");

    player_info_resetor();

    FILE *fpt;
    FILE *fpo;

    char temp_search_user_name[25];

    fpo = fopen("player's information.txt", "r");
    fpt = fopen("TempFile.txt", "w");

    while (fread(&player_info, sizeof(player_info), 1, fpo))
    {
        strcpy(temp_search_user_name, player_info.user_name);

        if (strcmp(first_online_player.user_name, temp_search_user_name) != 0)
        {
            fwrite(&player_info, sizeof(player_info), 1, fpt);
        }
        else
        {
            player_info_resetor();

            strcpy(player_info.user_name, first_online_player.user_name);
            strcpy(player_info.password, first_online_player.password);
            strcpy(player_info.email, first_online_player.email);

            int j = 1;
            int edit;

            DWORD bytes_written;
            HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

            while (1)
            {
                COORD origin = {0, 0};
                SetConsoleCursorPosition(hStdout, origin);

                YELLOW();
                wprintf(L"-------------First Player's Profile Editor-------------\n\n");
                wprintf(L"Which one would you like to update?\n\n");
                WHITE();
                (j == 1) ? (wprintf(L"\033[1;31mUser Name\033[33m\n")) : wprintf(L"User Name\n");
                (j == 2) ? (wprintf(L"\033[1;31mEmail\033[33m\n")) : wprintf(L"Email\n");
                (j == 3) ? (wprintf(L"\033[1;31mPassword\033[33m\n")) : wprintf(L"Password\n");

                edit = _getch();
                if (edit == 80)
                {
                    if (j < 3)
                    {
                        j++;
                    }
                }
                if (edit == 72)
                {
                    if (j != 1)
                    {
                        j--;
                    }
                }
                if (edit == 13)
                {
                    if (j == 1)
                    {
                        updating_first_player_user_name();
                    }
                    else if (j == 2)
                    {
                        updating_first_player_email();
                    }
                    else if (j == 3)
                    {
                        updating_first_player_password();
                    }
                    break;
                }
                if (edit == 27)
                {
                    menu_first_player();
                }
            }

            fwrite(&player_info, sizeof(player_info), 1, fpt);

            strcpy(first_online_player.user_name, player_info.user_name);
            strcpy(first_online_player.password, player_info.password);
            strcpy(first_online_player.email, player_info.email);
        }
    }
    fclose(fpo);
    fclose(fpt);

    fpo = fopen("player's information.txt", "w");
    fpt = fopen("TempFile.txt", "r");
    while (fread(&player_info, sizeof(player_info), 1, fpt))
    {
        fwrite(&player_info, sizeof(player_info), 1, fpo);
    }
    fclose(fpo);
    fclose(fpt);

    PlaySoundA("musics\\add was successful bell.wav", NULL, SND_FILENAME | SND_ASYNC);
    GREEN();
    type_writer_printer("\n\t\tChange Has Been Done!");
    WHITE();
    Sleep(2000);

    menu_first_player();
}

void updating_first_player_user_name()
{
    FILE *fp;
    fp = fopen("player's information.txt", "r+");

    CYAN();
    type_writer_printer("\nEnter your NEW user name:\n");
    WHITE();
    char temp_user_name[25];
    PURPLE();
    cursor_on();
    fgets(temp_user_name, 25, stdin);
    cursor_off();
    WHITE();
    temp_user_name[strcspn(temp_user_name, "\n")] = '\0';

    char check_user_name[25];
    while (fread(&player_info, sizeof(player_info), 1, fp))
    {
        strcpy(check_user_name, player_info.user_name);
        if (strcmp(check_user_name, temp_user_name) == 0)
        {
            PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
            RED();
            type_writer_printer("Sorry pal, This user name is taken!\n");
            WHITE();
            Sleep(1000);
            fclose(fp);
            return;
        }
    }

    rewind(fp);
    while (fread(&player_info, sizeof(player_info), 1, fp))
    {
        strcpy(player_info.user_name, temp_user_name);
        fwrite(&player_info, sizeof(player_info), 1, fp);
        break;
    }

    fclose(fp);
}

void updating_first_player_password()
{
    CYAN();
    type_writer_printer("\nEnter your NEW password:\n");
    WHITE();
    char temp_password[25];
    char temp_again_password[25];
    PURPLE();
    cursor_on();
    fgets(temp_password, 25, stdin);
    cursor_off();
    WHITE();
    temp_password[strcspn(temp_password, "\n")] = '\0';

    if (strlen(temp_password) < 8)
    {
        PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
        RED();
        type_writer_printer("Too small password!\n");
        WHITE();
        Sleep(1000);
        return;
    }
    CYAN();
    type_writer_printer("Please enter your password AGAIN:\n");
    WHITE();
    PURPLE();
    cursor_on();
    fgets(temp_again_password, 25, stdin);
    cursor_off();
    WHITE();
    temp_again_password[strcspn(temp_again_password, "\n")] = '\0';


    if (strcmp(temp_again_password, temp_password) != 0)
    {
        PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
        RED();
        type_writer_printer("Passwords aren't match!\n");
        WHITE();
        Sleep(1000);
        return;
    }
    else
    {
        strcpy(player_info.password, temp_password);
    }
}

void updating_first_player_email()
{
    CYAN();
    type_writer_printer("\nEnter your NEW Email address:\n");
    WHITE();
    char temp_email[50];
    char gmail[] = "@gmail.com";
    char yahoo[] = "@yahoo.com";
    PURPLE();
    cursor_on();
    fgets(temp_email, 50, stdin);
    cursor_off();
    WHITE();
    temp_email[strcspn(temp_email, "\n")] = '\0';

    char *temp_email_ptr = temp_email;
    int check_at_sign = strcspn(temp_email, "@");
    temp_email_ptr += check_at_sign;

    if (strcmp(gmail, temp_email_ptr) != 0 && strcmp(yahoo, temp_email_ptr) != 0)
    {
        PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
        RED();
        type_writer_printer("Invalid Email type!\n");
        WHITE();
        Sleep(1000);
        return;
    }
    else
    {
        strcpy(player_info.email, temp_email);
    }
}

void sign_in_second_player()
{
    system("cls");

    YELLOW();
    faster_type_writer_printer("-------------Second Player Sign In-------------\n");
    WHITE();

    player_info_resetor();

    getting_user_name_sign_in_second_player();
    getting_password_sign_in_second_player();

    welcome_sign_in_nd();
    sign_in_done_by_second_player = 1;
    menu_second_player();
}

void getting_user_name_sign_in_second_player()
{

    YELLOW();
    faster_type_writer_printer("\nEnter your user name:\n");
    WHITE();

    PURPLE();
    cursor_on();
    char temp_user_name[25];
    temp_user_name[0] = '\0';
    fgets(temp_user_name, 25, stdin);
    temp_user_name[strcspn(temp_user_name, "\n")] = '\0';
    cursor_off();
    WHITE();

    if(strcmp(temp_user_name, first_online_player.user_name) == 0)
    {
        PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
        RED();
        type_writer_printer("You can not play with yourself!\n");
        WHITE();

        Sleep(1000);

        PlaySoundA("musics\\sign in.wav", NULL, SND_FILENAME | SND_ASYNC);

        sign_in_second_player();
    }

    player_info_resetor();

    FILE *fp3;
    fp3 = fopen("player's information.txt","r");
    int user_found_flag = 0;
    while (fread(&player_info, sizeof(player_info), 1, fp3))
    {

        if(strcmp(temp_user_name, player_info.user_name) == 0)
        {
            user_found_flag = 1;
            strcpy(second_online_player.user_name, player_info.user_name);
            strcpy(second_online_player.email,     player_info.email);
            strcpy(second_online_player.password,  player_info.password);
        }
    }

    if (user_found_flag == 0)
    {
        PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
        RED();
        type_writer_printer("No account found with this user name!\n");
        WHITE();

        Sleep(1000);

        system("cls");

        int j = 1;
        int menu_failed_sign_in;

        DWORD bytes_written;
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        while (1)
        {
            COORD origin = {0, 0};
            SetConsoleCursorPosition(hStdout, origin);

            (j == 1) ? (wprintf(L"\033[1;31mSign In Again\033[33m\n")) : wprintf(L"Sign In Again\n");
            (j == 2) ? (wprintf(L"\033[1;31mCreat A Account\033[33m\n")) : wprintf(L"Creat A Account\n");
            (j == 3) ? (wprintf(L"\033[1;31mBack To Menu\033[33m\n")) : wprintf(L"Back To Menu\n");

            menu_failed_sign_in = _getch();
            PlaySoundA("musics\\menu movement.wav", NULL, SND_FILENAME | SND_ASYNC);
            if (menu_failed_sign_in == 80)
            {
                if (j < 3)
                {
                    j++;
                }
            }
            if (menu_failed_sign_in == 72)
            {
                if (j != 1)
                {
                    j--;
                }
            }
            if (menu_failed_sign_in == 13)
            {
                if (j == 1)
                {
                    PlaySoundA("musics\\sign in.wav", NULL, SND_FILENAME | SND_ASYNC);
                    sign_in_second_player();
                }
                if (j == 2)
                {
                    PlaySoundA("musics\\sign up.wav", NULL, SND_FILENAME | SND_ASYNC);
                    sing_up();
                }
                if (j == 3)
                {
                    menu();
                }
            }
        }
    }
    fclose(fp3);
}

void getting_password_sign_in_second_player()
{
    YELLOW();
    wprintf(L"\nEnter %s's password:\n", second_online_player.user_name);

    PURPLE();
    cursor_on();
    char temp_password[25];
    int i = 0;
    while (1)
    {
        temp_password[i] = getch();

        if (temp_password[i] == '\r')
        {
            temp_password[i] = '\0';
            break;
        }
        else if (temp_password[i] == '\b' && i > 0)
        {
            wprintf(L"\b \b");
            i--;
        }
        else
        {
            wprintf(L"*");
            i++;
        }
    }
    cursor_off();
    WHITE();

    if (strcmp(temp_password, second_online_player.password) != 0)
    {
        PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
        RED();
        type_writer_printer("\nWrong password!\n");
        WHITE();
        Sleep(1000);

        system("cls");
        int j = 1;
        int menu_failed_sign_in;

        DWORD bytes_written;
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        while (1)
        {
            COORD origin = {0, 0};
            SetConsoleCursorPosition(hStdout, origin);

            (j == 1) ? (wprintf(L"\033[1;31mForgot Password?\033[33m\n")) : wprintf(L"Forgot Password?\n");
            (j == 2) ? (wprintf(L"\033[1;31mCreat A Account\033[33m\n")) : wprintf(L"Creat A Account\n");
            (j == 3) ? (wprintf(L"\033[1;31mBack To Menu\033[33m\n")) : wprintf(L"Back To Menu\n");

            menu_failed_sign_in = _getch();
            PlaySoundA("musics\\menu movement.wav", NULL, SND_FILENAME | SND_ASYNC);
            if (menu_failed_sign_in == 80)
            {
                if (j < 3)
                {
                    j++;
                }
            }
            if (menu_failed_sign_in == 72)
            {
                if (j != 1)
                {
                    j--;
                }
            }
            if (menu_failed_sign_in == 13)
            {
                if (j == 1)
                {
                    forgot_password();
                }
                if (j == 2)
                {
                    PlaySoundA("musics\\sign up.wav", NULL, SND_FILENAME | SND_ASYNC);
                    sing_up();
                }
                if (j == 3)
                {
                    menu();
                }
            }
        }
    }
}

void welcome_sign_in_nd()
{
    system("cls");


    PlaySoundA("musics\\welcome sign in second player.wav", NULL, SND_FILENAME | SND_ASYNC);
    WHITE();
    wprintf(L"%*s __      __       .__                               \n", 7, "");
    wprintf(L"%*s/  \\    /  \\ ____ |  |   ____  ____   _____   ____  \n", 7, "");
    wprintf(L"%*s\\   \\/\\/   // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\ \n", 7, "");
    wprintf(L"%*s \\        /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/ \n", 7, "");
    wprintf(L"%*s  \\__/\\  /  \\___  >____/\\___  >____/|__|_|  /\\___  >\n", 7, "");
    wprintf(L"%*s       \\/       \\/          \\/            \\/     \\/ \n", 7, "");

    BLUE();
    wprintf(L"\n\tWe hope you enjoy dear %s", second_online_player.user_name);
    WHITE();
    Sleep(3000);
    system("color 07");
}

void menu_second_player()
{
    system("cls");

    PlaySoundA("musics\\player menu.wav", NULL, SND_FILENAME | SND_ASYNC);

    int j = 1;
    int menu_second_player;

    DWORD bytes_written;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    while (1)
    {
        COORD origin = {0, 0};
        SetConsoleCursorPosition(hStdout, origin);

        YELLOW();
        wprintf(L"-------------Second Player Menu-------------\n\n");
        WHITE();
        (j == 1) ? (wprintf(L"\033[1;31mStart The Game\033[33m\n")) : wprintf(L"Start The Game\n");
        (j == 2) ? (wprintf(L"\033[1;31mEdit Your Profile\033[33m\n")) : wprintf(L"Edit Your Profile\n");
        (j == 3) ? (wprintf(L"\033[1;31mBack To Main Menu\033[33m\n")) : wprintf(L"Back To Main Menu\n");

        menu_second_player = _getch();
        PlaySoundA("musics\\menu movement.wav", NULL, SND_FILENAME | SND_ASYNC);
        if (menu_second_player == 80)
        {
            if (j < 3)
            {
                j++;
            }
        }
        if (menu_second_player == 72)
        {
            if (j != 1)
            {
                j--;
            }
        }
        if (menu_second_player == 13)
        {
            if (j == 1)
            {
                start_the_game();
            }
            if (j == 2)
            {
                edit_second_player();
            }
            if (j == 3)
            {
                menu();
            }
        }
        if (menu_second_player == 27)
        {
            sign_in_second_player();
        }
    }
}

void edit_second_player()
{
    system("cls");

    player_info_resetor();

    FILE *fpt;
    FILE *fpo;

    char temp_search_user_name[25];

    fpo = fopen("player's information.txt", "r");
    fpt = fopen("TempFile.txt", "w");

    while (fread(&player_info, sizeof(player_info), 1, fpo))
    {
        strcpy(temp_search_user_name, player_info.user_name);

        if (strcmp(second_online_player.user_name, temp_search_user_name) != 0)
        {
            fwrite(&player_info, sizeof(player_info), 1, fpt);
        }
        else
        {
            player_info_resetor();

            strcpy(player_info.user_name, second_online_player.user_name);
            strcpy(player_info.password, second_online_player.password);
            strcpy(player_info.email, second_online_player.email);

            int j = 1;
            int edit;
            while (1)
            {
                system("cls");
                YELLOW();
                wprintf(L"-------------Second Player's Profile Editor-------------\n\n");
                wprintf(L"Which one would you like to update?\n\n");
                WHITE();
                (j == 1) ? (wprintf(L"\033[1;31mUser Name\033[33m\n")) : wprintf(L"User Name\n");
                (j == 2) ? (wprintf(L"\033[1;31mEmail\033[33m\n")) : wprintf(L"Email\n");
                (j == 3) ? (wprintf(L"\033[1;31mPassword\033[33m\n")) : wprintf(L"Password\n");

                edit = _getch();
                if (edit == 80)
                {
                    if (j < 3)
                    {
                        j++;
                    }
                }
                if (edit == 72)
                {
                    if (j != 1)
                    {
                        j--;
                    }
                }
                if (edit == 13)
                {
                    if (j == 1)
                    {
                        updating_second_player_user_name();
                    }
                    else if (j == 2)
                    {
                        updating_second_player_email();
                    }
                    else if (j == 3)
                    {
                        updating_second_player_password();
                    }
                    break;
                }
                if (edit == 27)
                {
                    menu_second_player();
                }
            }

            fwrite(&player_info, sizeof(player_info), 1, fpt);

            strcpy(second_online_player.user_name, player_info.user_name);
            strcpy(second_online_player.password, player_info.password);
            strcpy(second_online_player.email, player_info.email);
        }
    }
    fclose(fpo);
    fclose(fpt);

    fpo = fopen("player's information.txt", "w");
    fpt = fopen("TempFile.txt", "r");
    while (fread(&player_info, sizeof(player_info), 1, fpt))
    {
        fwrite(&player_info, sizeof(player_info), 1, fpo);
    }
    fclose(fpo);
    fclose(fpt);

    PlaySoundA("musics\\add was successful bell.wav", NULL, SND_FILENAME | SND_ASYNC);
    GREEN();
    type_writer_printer("\n\t\tChange Has Been Done!");
    WHITE();
    Sleep(2000);

    menu_second_player();
}

void updating_second_player_user_name()
{
    FILE *fp;
    fp = fopen("player's information.txt", "r+");

    CYAN();
    type_writer_printer("\nEnter your NEW user name:\n");
    WHITE();
    char temp_user_name[25];
    PURPLE();
    cursor_on();
    fgets(temp_user_name, 25, stdin);
    cursor_off();
    WHITE();
    temp_user_name[strcspn(temp_user_name, "\n")] = '\0';

    char check_user_name[25];
    while (fread(&player_info, sizeof(player_info), 1, fp))
    {
        strcpy(check_user_name, player_info.user_name);
        if (strcmp(check_user_name, temp_user_name) == 0)
        {
            PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
            RED();
            type_writer_printer("Sorry pal, This user name is taken!\n");
            WHITE();
            Sleep(1000);
            fclose(fp);
            return;
        }
    }

    rewind(fp);
    while (fread(&player_info, sizeof(player_info), 1, fp))
    {
        strcpy(player_info.user_name, temp_user_name);
        fwrite(&player_info, sizeof(player_info), 1, fp);
        break;
    }

    fclose(fp);
}

void updating_second_player_password()
{
    CYAN();
    type_writer_printer("\nEnter your NEW password:\n");
    WHITE();
    char temp_password[25];
    char temp_again_password[25];
    PURPLE();
    cursor_on();
    fgets(temp_password, 25, stdin);
    cursor_off();
    WHITE();
    temp_password[strcspn(temp_password, "\n")] = '\0';

    if (strlen(temp_password) < 8)
    {
        PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
        RED();
        type_writer_printer("Too small password!\n");
        WHITE();
        Sleep(1000);
        return;
    }

    CYAN();
    type_writer_printer("Please enter your password AGAIN:\n");
    WHITE();
    PURPLE();
    cursor_on();
    fgets(temp_again_password, 25, stdin);
    cursor_off();
    WHITE();
    temp_again_password[strcspn(temp_again_password, "\n")] = '\0';


    if (strcmp(temp_again_password, temp_password) != 0)
    {
        PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
        RED();
        type_writer_printer("Passwords aren't match!\n");
        WHITE();
        Sleep(1000);
        return;
    }
    else
    {
        strcpy(player_info.password, temp_password);
    }
}

void updating_second_player_email()
{
    CYAN();
    type_writer_printer("\nEnter your NEW Email address:\n");
    WHITE();
    char temp_email[50];
    char gmail[] = "@gmail.com";
    char yahoo[] = "@yahoo.com";
    PURPLE();
    cursor_on();
    fgets(temp_email, 50, stdin);
    cursor_off();
    WHITE();
    temp_email[strcspn(temp_email, "\n")] = '\0';

    char *temp_email_ptr = temp_email;
    int check_at_sign = strcspn(temp_email, "@");
    temp_email_ptr += check_at_sign;

    if (strcmp(gmail, temp_email_ptr) != 0 && strcmp(yahoo, temp_email_ptr) != 0)
    {
        PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
        RED();
        type_writer_printer("Invalid Email type!\n");
        WHITE();
        Sleep(1000);
        return;
    }
    else
    {
        strcpy(player_info.email, temp_email);
    }
}

void forgot_password()
{
    system("cls");

    PlaySoundA("musics\\forgot password.wav", NULL, SND_FILENAME | SND_ASYNC);
    YELLOW();
    faster_type_writer_printer("-------------Forgotten Password System-------------\n\n");
    type_writer_printer("Enter your user name:\n");
    WHITE();

    char temp_user_name[25];
    PURPLE();
    cursor_on();
    fgets(temp_user_name, 25, stdin);
    cursor_off();
    WHITE();
    temp_user_name[strcspn(temp_user_name, "\n")] = '\0';

    char shown_password_forgot[25];
    char temp_checking_email_from_file[50];

    FILE *fp3;
    fp3 = fopen("player's information.txt", "r");
    int user_found_flag = 0;
    while (fread(&player_info, sizeof(player_info), 1, fp3))
    {
        if (strcmp(temp_user_name, player_info.user_name) == 0)
        {
            user_found_flag = 1;
            strcpy(shown_password_forgot, player_info.password);
            strcpy(temp_checking_email_from_file, player_info.email);
        }
    }
    if (user_found_flag == 0)
    {
        PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
        RED();
        type_writer_printer("No account found with this user name!\n");
        WHITE();
        Sleep(1000);
        menu();
    }
    fclose(fp3);

    YELLOW();
    type_writer_printer("Enter your Email address:\n");
    char temp_email[50];
    char gmail[] = "@gmail.com";
    char yahoo[] = "@yahoo.com";
    WHITE();

    PURPLE();
    cursor_on();
    fgets(temp_email, 50, stdin);
    cursor_off();
    WHITE();
    temp_email[strcspn(temp_email, "\n")] = '\0';

    char *temp_email_ptr = temp_email;
    int check_at_sign = strcspn(temp_email, "@");
    temp_email_ptr += check_at_sign;

    if (strcmp(gmail, temp_email_ptr) != 0 && strcmp(yahoo, temp_email_ptr) != 0)
    {
        PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
        RED();
        type_writer_printer("Invalid Email type!\n");
        WHITE();
        Sleep(1000);
        forgot_password();
    }

    int email_found_flag = 0;

    if (strcmp(temp_checking_email_from_file, temp_email) == 0) email_found_flag = 1;

    if (email_found_flag == 0)
    {
        PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
        RED();
        type_writer_printer("No account found with this Email address!\n");
        WHITE();
        Sleep(1000);
        if (sign_in_done_by_first_player == 0) sign_in_first_player();
        if (sign_in_done_by_second_player == 0) sign_in_second_player();
    }

    RED();
    PlaySoundA("musics\\type 2s.wav", NULL, SND_FILENAME | SND_ASYNC);
    faster_type_writer_printer("Your password will be shown by now.\n");
    faster_type_writer_printer("You can change it in your account later.\n");
    faster_type_writer_printer("Memorize it.\tCause only 10s you have...\n");

    Sleep(3000);

    PlaySoundA("musics\\10s down counting.wav", NULL, SND_FILENAME | SND_ASYNC);

    WHITE();

    for (int i = 10; i > 0; --i)
    {
        system("cls");

        YELLOW();
        wprintf(L"\tThe password of %s is:\n", temp_user_name);
        CYAN();
        wprintf(L"\t%s\n", shown_password_forgot);
        RED();
        wprintf(L"\t%d remain(s)\n", i);
        WHITE();
        Sleep(1000);
    }
    if (sign_in_done_by_first_player == 0) sign_in_first_player();
    if (sign_in_done_by_second_player == 0) sign_in_second_player();
}

void sing_up()
{
    system("cls");

    YELLOW();
    faster_type_writer_printer("-------------Sign Up-------------\n");
    WHITE();

    player_info_resetor();

    getting_user_name_sign_up();
    getting_email_sign_up();
    getting_password_sign_up();

    FILE *fp;
    fp = fopen("player's information.txt", "a+");

    fseek(fp, 0, SEEK_END);

    fwrite(&player_info, sizeof(player_info), 1, fp);

    fclose(fp);

    PlaySoundA("musics\\add was successful bell.wav", NULL, SND_FILENAME | SND_ASYNC);
    GREEN();
    type_writer_printer("\n\t\tNew account added successfully!");
    WHITE();
    Sleep(2000);

    menu();
}

void getting_user_name_sign_up()
{
    FILE *fp;
    fp = fopen("player's information.txt", "r");

    YELLOW();
    type_writer_printer("\nEnter your user name:\n");
    WHITE();

    char temp_user_name[25];
    PURPLE();
    cursor_on();
    fgets(temp_user_name, 25, stdin);
    cursor_off();
    WHITE();
    temp_user_name[strcspn(temp_user_name, "\n")] = '\0';

    char check_user_name[25];
    int found = 0;

    while (fread(&player_info, sizeof(player_info), 1, fp))
    {
        strcpy(check_user_name, player_info.user_name);
        if (strcmp(check_user_name, temp_user_name) == 0)
        {
            found = 1;
            PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
            RED();
            type_writer_printer("Sorry pal, This user name is taken!\n");
            WHITE();
            Sleep(1);
            break;
        }
    }

    fclose(fp);

    if (!found)
    {
        strcpy(player_info.user_name, temp_user_name);
    }
    else
    {
        getting_user_name_sign_up();
    }
}

void getting_password_sign_up()
{
    YELLOW();
    type_writer_printer("\nEnter your password:\n");
    WHITE();
    char temp_password[25];
    char temp_again_password[25];
    PURPLE();
    cursor_on();
    fgets(temp_password, 25, stdin);
    cursor_off();
    WHITE();
    temp_password[strcspn(temp_password, "\n")] = '\0';

    int long_password = 0;
    if (strlen(temp_password) < 8)
    {
        PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
        RED();
        type_writer_printer("Too small password!\n");
        WHITE();
        Sleep(1000);
        //getting_password_sign_up();
    }
    YELLOW();
    type_writer_printer("Please enter your password AGAIN:\n");
    WHITE();
    PURPLE();
    cursor_on();
    fgets(temp_again_password, 25, stdin);
    cursor_off();
    WHITE();
    temp_again_password[strcspn(temp_again_password, "\n")] = '\0';


    if (strcmp(temp_again_password, temp_password) != 0)
    {
        PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
        RED();
        type_writer_printer("Passwords aren't match!\n");
        WHITE();
        Sleep(1000);
        getting_password_sign_up();
    }
    else
    {
        strcpy(player_info.password, temp_password);
    }
}

void getting_email_sign_up()
{
    YELLOW();
    type_writer_printer("\nEnter your Email address:\n");
    WHITE();
    char temp_email[50];
    char gmail[] = "@gmail.com";
    char yahoo[] = "@yahoo.com";
    PURPLE();
    cursor_on();
    fgets(temp_email, 50, stdin);
    cursor_off();
    WHITE();
    temp_email[strcspn(temp_email, "\n")] = '\0';

    char *temp_email_ptr = temp_email;
    int check_at_sign = strcspn(temp_email, "@");
    temp_email_ptr += check_at_sign;

    if (strcmp(gmail, temp_email_ptr) != 0 && strcmp(yahoo, temp_email_ptr) != 0)
    {
        PlaySoundA("musics\\normal error.wav", NULL, SND_FILENAME | SND_ASYNC);
        RED();
        type_writer_printer("Invalid Email type!\n");
        WHITE();
        Sleep(1000);
        getting_email_sign_up();
    }
    else
    {
        strcpy(player_info.email, temp_email);
    }
}

void player_info_resetor()
{
    memset(player_info.user_name, '\0', sizeof(player_info.user_name));
    memset(player_info.password, '\0', sizeof(player_info.password));
    memset(player_info.email, '\0', sizeof(player_info.email));
}

void history_resetor()
{
    memset(game_history.winner,'\0', sizeof(game_history.date_of_play));
    memset(game_history.winner,'\0', sizeof(game_history.winner));
    game_history.score_of_winner = 0;
    memset(game_history.loser,'\0', sizeof(game_history.loser));
    game_history.score_of_loser = 0;
}

void display_history()
{
    system("cls");

    YELLOW();
    faster_type_writer_printer("-------------Whole Game History-------------\n\n");
    WHITE();

    PlaySoundA("musics\\history.wav", NULL, SND_FILENAME | SND_ASYNC);

    FILE *fp3;
    fp3 = fopen("game history.txt","r");
    while (fread(&game_history, sizeof(game_history), 1, fp3)) {
        CYAN();
        wprintf(L"------------------------------------------------------------------------------------------\n");

        WHITE();
        wprintf(L"Date of play %s\n", game_history.date_of_play);
        if (game_history.score_of_winner == game_history.score_of_loser)
        {
            YELLOW();
            wprintf(L"The game had a draw result\n");
            WHITE();
            wprintf(L"The First  equal player: %s \t\twith\t %d scores\n", game_history.winner, game_history.score_of_winner);
            wprintf(L"The Second equal player: %s \t\twith\t %d scores\n", game_history.loser, game_history.score_of_loser);
        }
        else
        {
            GREEN();
            wprintf(L"The WINNER: %s \t\twith\t %d scores\n", game_history.winner, game_history.score_of_winner);
            RED();
            wprintf(L"The LOSER : %s \t\twith\t %d scores\n", game_history.loser, game_history.score_of_loser);
            WHITE();
        }
    }
    fclose(fp3);
    back_to_menu();
}

void help()
{
    system("cls");

    YELLOW();
    type_writer_printer("Seems you are confused!");
    faster_type_writer_printer("Here's the help");
    PlaySoundA("musics\\help bell.wav", NULL, SND_FILENAME | SND_ASYNC);
    wprintf(L"\x1b[5;33;7m\U0001f447\x1b[m\n");
    sleep(2);

    system("cls");
    GREEN();
    PlaySoundA("musics\\type 5s.wav", NULL, SND_FILENAME | SND_ASYNC);
    faster_type_writer_printer("At the beginning, you have to know this couple game needs both players verification.\n");
    faster_type_writer_printer("Which means if you have no account, make one!\n");

    Sleep(1);
    YELLOW();
    faster_type_writer_printer("First singed-in player movement:\n");
    WHITE();
    faster_type_writer_printer("Up-------->W\n");
    faster_type_writer_printer("Down------>S\n");
    faster_type_writer_printer("Right----->D\n");
    faster_type_writer_printer("Left------>A\n");
    faster_type_writer_printer("Shoot----->C\n");

    YELLOW();
    faster_type_writer_printer("Second singed-in player movement:\n");
    WHITE();
    faster_type_writer_printer("Up-------->I\n");
    faster_type_writer_printer("Down------>K\n");
    faster_type_writer_printer("Right----->L\n");
    faster_type_writer_printer("Left------>J\n");
    faster_type_writer_printer("Shoot----->N\n");

    faster_type_writer_printer("\n");
    faster_type_writer_printer("More decryption in The game!\n");

    back_to_menu();
}

void about_us()
{
    system("cls");
    type_writer_printer("\t\t\tIN THE NAME OF ALMIGHTY\n");

    PlaySoundA("musics\\type 6s.wav", NULL, SND_FILENAME | SND_ASYNC);

    CYAN();
    type_writer_printer("IMTB.co presents:\n");
    WHITE();
    faster_type_writer_printer("Design and Development------------>Ali Najjarzadegan\n");
    faster_type_writer_printer("Main Director--------------------->Ali Najjarzadegan\n");
    faster_type_writer_printer("Producer and Finance-------------->Ali Najjarzadegan\n");
    faster_type_writer_printer("System and BackUp----------------->ALi Najjarzadegan\n\n");
    faster_type_writer_printer("Deepest thanks from who helped us to creat this game:\n");

    faster_type_writer_printer("Copilot, Google, GitHub, ChatGPT, Bard, StackOverFlow, Adobe Audition, Angry Birds Star War II, etc\n");
    RED();
    PlaySoundA("musics\\type 1s.wav", NULL, SND_FILENAME | SND_ASYNC);
    faster_type_writer_printer("\n\n\n\t\tBy playing the game, you are agree with our \"Terms & Policies.\"\n");
    WHITE();
    back_to_menu();
}

void thanos_mode()
{
    //TODO
    // save the information game won and lost for history
    // resetting all data expect files
    player_info_resetor();
    history_resetor();

    sign_in_done_by_first_player = 0;
    sign_in_done_by_second_player = 0;

    first_player_score = 0;
    second_player_score = 0;
}

/*
 *-------------------------------------------------GAME'S FUNCTIONS-----------------------------------------------------
 */
int  key_pressed(int key)
{
    return GetAsyncKeyState(key);
}

void start_the_game()
{
    ready_to_play();
    loading_round1();
    in321();

    game_round_1();

    ready_to_play();
    loading_round2();
    in321();

    game_round_2();

    audit();
    show_audit();

    save_the_history();
    thanos_mode();

    menu();
}

void ready_to_play()
{
    system("cls");

    system("color 02");

    wprintf(L"%*s    ____  _________    ______  __   ___ \n", 20, "");
    wprintf(L"%*s   / __ \\/ ____/   |  / __ \\ \\/ /  /__ \\\n", 20, "");
    wprintf(L"%*s  / /_/ / __/ / /| | / / / /\\  /    / _/\n", 20, "");
    wprintf(L"%*s / _, _/ /___/ ___ |/ /_/ / / /    /_/  \n", 20, "");
    wprintf(L"%*s/_/ |_/_____/_/  |_/_____/ /_/    (_)   \n", 20, "");

    PlaySoundA("musics\\ready to play.wav", NULL, SND_FILENAME | SND_ASYNC);

    WHITE();
    wprintf(L"\n\t\t%s's Score by now: %d\n\n",first_online_player.user_name, first_player_score);
    wprintf(L"\t\t%s's Score by now: %d\n",second_online_player.user_name, second_player_score);

    Sleep(3000);
    system("color 07");
}

void in321()
{
    system("cls");

    PlaySoundA("musics\\in321.wav", NULL, SND_FILENAME | SND_ASYNC);

    RED();
    wprintf(L"%*s 333333333333333   \n", 20, "");
    wprintf(L"%*s3:::::::::::::::33 \n", 20, "");
    wprintf(L"%*s3::::::33333::::::3\n", 20, "");
    wprintf(L"%*s3333333     3:::::3\n", 20, "");
    wprintf(L"%*s            3:::::3\n", 20, "");
    wprintf(L"%*s            3:::::3\n", 20, "");
    wprintf(L"%*s    33333333:::::3 \n", 20, "");
    wprintf(L"%*s    3:::::::::::3  \n", 20, "");
    wprintf(L"%*s    33333333:::::3 \n", 20, "");
    wprintf(L"%*s            3:::::3\n", 20, "");
    wprintf(L"%*s            3:::::3\n", 20, "");
    wprintf(L"%*s3333333     3:::::3\n", 20, "");
    wprintf(L"%*s3::::::33333::::::3\n", 20, "");
    wprintf(L"%*s3:::::::::::::::33 \n", 20, "");
    wprintf(L"%*s 333333333333333   \n", 20, "");

    Sleep(1000);
    system("cls");

    RED();
    wprintf(L"%*s 222222222222222    \n", 20, "");
    wprintf(L"%*s2:::::::::::::::22  \n", 20, "");
    wprintf(L"%*s2::::::222222:::::2 \n", 20, "");
    wprintf(L"%*s2222222     2:::::2 \n", 20, "");
    wprintf(L"%*s            2:::::2 \n", 20, "");
    wprintf(L"%*s            2:::::2 \n", 20, "");
    wprintf(L"%*s         2222::::2  \n", 20, "");
    wprintf(L"%*s    22222::::::22   \n", 20, "");
    wprintf(L"%*s  22::::::::222     \n", 20, "");
    wprintf(L"%*s 2:::::22222        \n", 20, "");
    wprintf(L"%*s2:::::2             \n", 20, "");
    wprintf(L"%*s2:::::2       222222\n", 20, "");
    wprintf(L"%*s2::::::2222222:::::2\n", 20, "");
    wprintf(L"%*s2::::::::::::::::::2\n", 20, "");
    wprintf(L"%*s22222222222222222222\n", 20, "");

    Sleep(1000);
    system("cls");

    RED();
    wprintf(L"%*s  1111111   \n", 20, "");
    wprintf(L"%*s 1::::::1   \n", 20, "");
    wprintf(L"%*s1:::::::1   \n", 20, "");
    wprintf(L"%*s111:::::1   \n", 20, "");
    wprintf(L"%*s   1::::1   \n", 20, "");
    wprintf(L"%*s   1::::1   \n", 20, "");
    wprintf(L"%*s   1::::1   \n", 20, "");
    wprintf(L"%*s   1::::1   \n", 20, "");
    wprintf(L"%*s   1::::1   \n", 20, "");
    wprintf(L"%*s   1::::1   \n", 20, "");
    wprintf(L"%*s   1::::1   \n", 20, "");
    wprintf(L"%*s   1::::1   \n", 20, "");
    wprintf(L"%*s111::::::111\n", 20, "");
    wprintf(L"%*s1::::::::::1\n", 20, "");
    wprintf(L"%*s1::::::::::1\n", 20, "");
    wprintf(L"%*s111111111111\n", 20, "");

    WHITE();
    Sleep(1000);
    system("cls");
}

void loading_round1()
{
    PlaySoundA("musics\\loading the game.wav", NULL, SND_FILENAME | SND_ASYNC);

    faster_type_writer_printer("\nIn this round, you both can plant Bomb on other side\n");
    faster_type_writer_printer("First player by pressing X            Second player by pressing M\n");
    faster_type_writer_printer("Defuse bombs pressing G \n");

    RED();
    type_writer_printer("\n\n\t\t\t\tLOADING FIRST GROUND ...\n");
    wprintf(L"\t\t\t\t");
    BLUE();
    for(int r = 1; r <= 23; r++)
    {
        Sleep(500);
        wprintf(L"\x25A9",177);
    }
    WHITE();
    Sleep(3000);
}

void update_player1_position_board1(wchar_t board[][86], COORD oldPos, COORD newPos)
{
    board[oldPos.Y][oldPos.X] = L' ';
    board[oldPos.Y][oldPos.X + 1] = L' ';

    wchar_t RedShip[] = L"\U0001F7E5"; //red ship
    int lenOfRed = wcsnlen(board[newPos.Y], 86);
    wmemmove(&board[newPos.Y][newPos.X + 1], &board[newPos.Y][newPos.X + 1], lenOfRed - newPos.X);
    wcsncpy(&board[newPos.Y][newPos.X], RedShip, 2);
}

void update_player2_position_board1(wchar_t board[][86], COORD oldPos, COORD newPos)
{
    board[oldPos.Y][oldPos.X] = L' ';
    board[oldPos.Y][oldPos.X + 1] = L' ';

    wchar_t BlueShip[] = L"\U0001F7E6"; //blue ship
    int lenOfBlue = wcsnlen(board[newPos.Y], 86);
    wmemmove(&board[newPos.Y][newPos.X + 1], &board[newPos.Y][newPos.X + 1], lenOfBlue - newPos.X);
    wcsncpy(&board[newPos.Y][newPos.X], BlueShip, 2);
}

void game_round_1()
{
    system("cls");
    Sleep(500);
    fflush(stdin);
    fflush(stdout);

    PlaySoundA("musics\\how much you need.wav", NULL, SND_FILENAME | SND_ASYNC);
    YELLOW();
    type_writer_printer("how much health you both need to start each round?: ");
    cursor_on();
    PURPLE();
    scanf("%d", &starting_health);
    WHITE();
    cursor_off();

    system("cls");

    DWORD bytes_written;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    wchar_t board[21][86] = {
            L"1111111111111111111111111111111111111111111111111111111111111  11111111111111111111",
            L"1                                                           1  1   FIRST GROUND   1",
            L"1                                                           1  11111111111111111111",
            L"1          12                                    1          1",
            L"1          12                                    1          1",
            L"1   1111                                             1111   1  11111111111111111111",
            L"1      12                                           21      1  1    RED SHIP      1",
            L"1      12                    1                      21      1  1                  1",
            L"1      1                     1   1111                1      1  1                  1",
            L"1      1                     1                       1      1  1                  1",
            L"1      1                     2                       1      1  11111111111111111111",
            L"1      1                     1                       1      1",
            L"1      1              1111   1                       1      1",
            L"1      12                    1                      21      1  11111111111111111111",
            L"1      12                                           21      1  1    BLUE SHIP     1",
            L"1   1111                                             1111   1  1                  1",
            L"1          1                                    21          1  1                  1",
            L"1          1                                    21          1  1                  1",
            L"1                                                           1  11111111111111111111",
            L"1                                                           1",
            L"1111111111111111111111111111111111111111111111111111111111111",
    };

    for (int i = 0; i < 21; ++i)
    {
        for (int j = 0; j < 86; ++j)
        {
            if (board[i][j] == '1') board[i][j] = L'\u2588';
            if (board[i][j] == '2') board[i][j] = L'\u2016';
        }
    }

    int health_player_1 = starting_health;
    int health_player_2 = starting_health;
    char user_player1[25];
    strcpy(user_player1, first_online_player.user_name);
    char user_player2[25];
    strcpy(user_player2, second_online_player.user_name);

    COORD first_player1_pos = {4, 10};
    COORD first_player2_pos = {55, 10};
    COORD first_side_bomb = {2 , 10};
    COORD second_side_bomb = {57, 10};
    COORD hole1 = {51, 4};
    COORD hole2 = {9, 16};
    COORD portal1 = {4, 2};
    COORD portal2 = {55, 18};
    COORD player1_pos = first_player1_pos;
    COORD player2_pos = first_player2_pos;
    COORD bullet1_pos = {player1_pos.X, player1_pos.Y};
    COORD bullet2_pos = {player2_pos.X, player2_pos.Y};
    COORD heart = {29, 3};
    int player1_bomb_activision = 0;
    int player2_bomb_activision = 0;
    int player1_bomb_ticket = 1;
    int player2_bomb_ticket = 1;
    int heart_gotten = 0;
    int bullet1_shot = 0;
    int bullet2_shot = 0;
    int checker1 = 1;
    int checker2 = 1;
    float time_of_bomb = 10;
    char last_move_player1 = ' ';
    char last_move_player2 = ' ';
    float time = 60;

    while (time > 0 && health_player_1 > 0 && health_player_2 > 0)
    {
        COORD origin = {0, 0};
        SetConsoleCursorPosition(hStdout, origin);

        if (player1_pos.X == heart.X && player1_pos.Y == heart.Y)
        {
            health_player_1 += 5;
            heart_gotten = 1;
            board[player1_pos.Y][player1_pos.X] = L' ';
            board[player1_pos.Y][player1_pos.X + 1] = L' ';
            PlaySoundA("musics\\health up.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        if (player2_pos.X == heart.X && player2_pos.Y == heart.Y)
        {
            health_player_2 += 5;
            heart_gotten = 1;
            board[player2_pos.Y][player2_pos.X] = L' ';
            board[player2_pos.Y][player2_pos.X + 1] = L' ';
            PlaySoundA("musics\\health up.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        else if (heart_gotten == 0)
        {
            wchar_t Heart[] = L"\U0001F497"; // heart
            int lenOfHeart = wcsnlen(board[3], 86);
            wmemmove(&board[heart.Y][heart.X + 1], &board[heart.Y][heart.X + 1], lenOfHeart - heart.X);
            wcsncpy(&board[heart.Y][heart.X], Heart, 2);
        }
        if (heart_gotten == 1)
        {
            heart.X = rand() % (45 - 13 + 1) + 13;
            heart.Y = rand() % (18 - 2 + 1) + 2;
            heart_gotten = 0;
        }


        if (player1_pos.X == hole1.X && player1_pos.Y == hole1.Y)
        {
            PlaySoundA("musics\\getting in hole.wav", NULL, SND_FILENAME | SND_ASYNC);
            health_player_1 += -1;
            player1_pos.X = first_player1_pos.X;
            player1_pos.Y = first_player1_pos.Y;
        }
        if (player1_pos.X == hole2.X && player1_pos.Y == hole2.Y)
        {
            PlaySoundA("musics\\getting in hole.wav", NULL, SND_FILENAME | SND_ASYNC);
            health_player_1 += -1;
            player1_pos.X = first_player1_pos.X;
            player1_pos.Y = first_player1_pos.Y;
        }
        if (player2_pos.X == hole1.X && player2_pos.Y == hole1.Y)
        {
            PlaySoundA("musics\\getting in hole.wav", NULL, SND_FILENAME | SND_ASYNC);

            Sleep(100);

            health_player_2 += -1;
            player2_pos.X = first_player2_pos.X;
            player2_pos.Y = first_player2_pos.Y;
        }
        if (player2_pos.X == hole2.X && player2_pos.Y == hole2.Y)
        {
            PlaySoundA("musics\\getting in hole.wav", NULL, SND_FILENAME | SND_ASYNC);

            Sleep(100);

            health_player_2 += -1;
            player2_pos.X = first_player2_pos.X;
            player2_pos.Y = first_player2_pos.Y;
        }
        wchar_t Hole[] = L"\U0001F300"; //hole
        int lenOfHole = wcsnlen(board[4], 86);
        wmemmove(&board[hole1.Y][hole1.X + 1], &board[hole1.Y][hole1.X + 1], lenOfHole - hole1.X);
        wcsncpy(&board[hole1.Y][hole1.X], Hole, 2);
        wmemmove(&board[hole2.Y][hole2.X + 1], &board[hole2.Y][hole2.X + 1], lenOfHole - hole2.X);
        wcsncpy(&board[hole2.Y][hole2.X], Hole, 2);


        if (player1_pos.X == portal1.X && player1_pos.Y == portal1.Y)
        {
            PlaySoundA("musics\\portal.wav", NULL, SND_FILENAME | SND_ASYNC);
            player1_pos.X = portal2.X;
            player1_pos.Y = portal2.Y;
        }
        else if (player1_pos.X == portal2.X && player1_pos.Y == portal2.Y)
        {
            PlaySoundA("musics\\portal.wav", NULL, SND_FILENAME | SND_ASYNC);
            player1_pos.X = portal1.X;
            player1_pos.Y = portal1.Y;
        }
        if (player2_pos.X == portal1.X && player2_pos.Y == portal1.Y)
        {
            PlaySoundA("musics\\portal.wav", NULL, SND_FILENAME | SND_ASYNC);
            player2_pos.X = portal2.X;
            player2_pos.Y = portal2.Y;
        }
        else if (player2_pos.X == portal2.X && player2_pos.Y == portal2.Y)
        {
            PlaySoundA("musics\\portal.wav", NULL, SND_FILENAME | SND_ASYNC);
            player2_pos.X = portal1.X;
            player2_pos.Y = portal1.Y;
        }
        board[portal1.Y][portal1.X + 1] = L' ';
        board[portal2.Y][portal2.X + 1] = L' ';
        board[portal1.Y][portal1.X] = L'\u058D'; //portal
        board[portal2.Y][portal2.X] = L'\u058D';


        wchar_t RedShip[] = L"\U0001F7E5"; //red ship
        int lenOfRed = wcsnlen(board[player1_pos.Y], 86);
        wmemmove(&board[player1_pos.Y][player1_pos.X + 1], &board[player1_pos.Y][player1_pos.X + 1], lenOfRed - player1_pos.X);
        wcsncpy(&board[player1_pos.Y][player1_pos.X], RedShip, 2);

        wchar_t BlueShip[] = L"\U0001F7E6"; //blue ship
        int lenOfBlue = wcsnlen(board[player2_pos.Y], 86);
        wmemmove(&board[player2_pos.Y][player2_pos.X + 1], &board[player2_pos.Y][player2_pos.X + 1], lenOfBlue - player2_pos.X);
        wcsncpy(&board[player2_pos.Y][player2_pos.X], BlueShip, 2);


        swprintf(&board[7][64], 25, L"name: %s", user_player1);
        board[7][82] = L' ';
        board[7][83] = L'\u2588';
        swprintf(&board[9][64], 25, L"health: %d", health_player_1);
        board[9][82] = L' ';
        board[9][83] = L'\u2588';
        swprintf(&board[15][64], 25, L"name: %s", user_player2);
        board[15][82] = L' ';
        board[15][83] = L'\u2588';
        swprintf(&board[17][64], 25, L"health: %d", health_player_2);
        board[17][82] = L' ';
        board[17][83] = L'\u2588';
        swprintf(&board[4][64], 19, L"      time: %.1f", time);

        for (short i = 0; i < 21; i++)
        {
            COORD place_of_ground_1;
            place_of_ground_1.X = 0;
            place_of_ground_1.Y = i;
            WriteConsoleOutputCharacterW(hStdout, board[i], 86, place_of_ground_1, &bytes_written);
        }

        COORD old_player1_pos = player1_pos;
        COORD old_player2_pos = player2_pos;

        if (key_pressed('W')&0x8000  && player1_pos.Y > 1 )
        {
            if (bullet1_shot == 0)
            {
                last_move_player1 = 'W';
            }
            if (board[player1_pos.Y - 1][player1_pos.X] != L'\u2588' && board[player1_pos.Y - 1][player1_pos.X] != L'\u2016' && board[player1_pos.Y - 1][player1_pos.X + 1] != L'\u2588' && board[player1_pos.Y - 1][player1_pos.X + 1] != L'\u2016')
            {
                player1_pos.Y -= 1;
            }
            //PlaySoundA("musics\\movement of players.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        if (key_pressed('S')&0x8000  && player1_pos.Y < 19)
        {
            if (bullet1_shot == 0)
            {
                last_move_player1 = 'S';
            }
            if (board[player1_pos.Y + 1][player1_pos.X] != L'\u2588' && board[player1_pos.Y + 1][player1_pos.X] != L'\u2016' && board[player1_pos.Y + 1][player1_pos.X + 1] != L'\u2588' && board[player1_pos.Y + 1][player1_pos.X + 1] != L'\u2016')
            {
                player1_pos.Y += 1;
            }
            //PlaySoundA("musics\\movement of players.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        if (key_pressed('A')&0x8000  && player1_pos.X > 1)
        {
            if (bullet1_shot == 0)
            {
                last_move_player1 = 'A';
            }
            if (board[player1_pos.Y][player1_pos.X - 1] != L'\u2588' && board[player1_pos.Y][player1_pos.X - 1] != L'\u2016')
            {
                player1_pos.X -= 1;
            }
            //PlaySoundA("musics\\movement of players.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        if (key_pressed('D')&0x8000  && player1_pos.X < 58)
        {
            if (bullet1_shot == 0)
            {
                last_move_player1 = 'D';
            }
            if (board[player1_pos.Y][player1_pos.X + 2] != L'\u2588' && board[player1_pos.Y][player1_pos.X + 2] != L'\u2016')
            {
                player1_pos.X += 1;
            }
            //PlaySoundA("musics\\movement of players.wav", NULL, SND_FILENAME | SND_ASYNC );
        }

        if (key_pressed('C')&0x8000 && bullet1_shot == 0)
        {
            bullet1_shot = 1;
            PlaySoundA("musics\\shooting normal bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        if (bullet1_shot == 0)
        {
            bullet1_pos = player1_pos;
        }
        if (bullet1_shot == 1)
        {
            if (last_move_player1 == 'W')
            {
                if (board[bullet1_pos.Y - 1][bullet1_pos.X] != L'\u2588' && board[bullet1_pos.Y - 1][bullet1_pos.X] != L'\u2016')
                {
                    bullet1_pos.Y -= 1;
                    board[bullet1_pos.Y][bullet1_pos.X] = L'\u2022';
                    board[bullet1_pos.Y + 1][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y + 2][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y + 3][bullet1_pos.X] = L' ';
                }
                if (board[bullet1_pos.Y - 1][bullet1_pos.X] == L'\u2588' || board[bullet1_pos.Y - 1][bullet1_pos.X] == L'\u2016')
                {
                    bullet1_shot = 0;
                    board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y + 1][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y + 2][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y + 3][bullet1_pos.X] = L' ';
                }
                if (bullet1_pos.X == player2_pos.X && bullet1_pos.Y == player2_pos.Y)
                {
                    bullet1_shot = 0;
                    board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y + 1][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y + 2][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y + 3][bullet1_pos.X] = L' ';
                    PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                    health_player_2 -= 2;
                }
            }
            if (last_move_player1 == 'S')
            {
                if (board[bullet1_pos.Y + 1][bullet1_pos.X] != L'\u2588' && board[bullet1_pos.Y + 1][bullet1_pos.X] != L'\u2016')
                {
                    bullet1_pos.Y += 1;
                    board[bullet1_pos.Y][bullet1_pos.X] = L'\u2022';
                    board[bullet1_pos.Y - 1][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y - 2][bullet1_pos.X] = L' ';
                }
                if (board[bullet1_pos.Y + 1][bullet1_pos.X] == L'\u2588' || board[bullet1_pos.Y + 1][bullet1_pos.X] == L'\u2016')
                {
                    bullet1_shot = 0;
                    board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y - 1][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y - 2][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y - 3][bullet1_pos.X] = L' ';
                }
                if (bullet1_pos.X == player2_pos.X && bullet1_pos.Y == player2_pos.Y)
                {
                    bullet1_shot = 0;
                    board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y - 1][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y - 2][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y - 3][bullet1_pos.X] = L' ';
                    PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                    health_player_2 -= 2;
                }
            }
            if (last_move_player1 == 'A')
            {
                if (board[bullet1_pos.Y][bullet1_pos.X - 1] != L'\u2588' && board[bullet1_pos.Y][bullet1_pos.X - 1] != L'\u2016')
                {
                    bullet1_pos.X -= 1;
                    board[bullet1_pos.Y][bullet1_pos.X] = L'\u2022';
                    board[bullet1_pos.Y][bullet1_pos.X + 1] = L' ';
                    board[bullet1_pos.Y][bullet1_pos.X + 2] = L' ';
                }
                if (board[bullet1_pos.Y][bullet1_pos.X - 1] == L'\u2588')
                {
                    bullet1_shot = 0;
                    board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y][bullet1_pos.X + 1] = L' ';
                    board[bullet1_pos.Y][bullet1_pos.X + 2] = L' ';
                    board[bullet1_pos.Y][bullet1_pos.X + 3] = L' ';
                }
                if (board[bullet1_pos.Y][bullet1_pos.X - 1] == L'\u2016')
                {
                    last_move_player1 = 'D';
                    board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                    PlaySoundA("musics\\mirror break.wav", NULL, SND_FILENAME | SND_ASYNC);
                }
                if (bullet1_pos.X == player2_pos.X && bullet1_pos.Y == player2_pos.Y)
                {
                    bullet1_shot = 0;
                    board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y][bullet1_pos.X + 1] = L' ';
                    board[bullet1_pos.Y][bullet1_pos.X + 2] = L' ';
                    board[bullet1_pos.Y][bullet1_pos.X + 3] = L' ';
                    PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                    health_player_2 -= 2;
                }
            }
            if (last_move_player1 == 'D')
            {
                if (board[bullet1_pos.Y][bullet1_pos.X + 1] != L'\u2588' && board[bullet1_pos.Y][bullet1_pos.X + 1] != L'\u2016')
                {
                    bullet1_pos.X += 1;
                    board[bullet1_pos.Y][bullet1_pos.X] = L'\u2022';
                    board[bullet1_pos.Y][bullet1_pos.X - 1] = L' ';
                    board[bullet1_pos.Y][bullet1_pos.X - 2] = L' ';
                }
                if (board[bullet1_pos.Y][bullet1_pos.X + 1] == L'\u2588')
                {
                    bullet1_shot = 0;
                    board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y][bullet1_pos.X - 1] = L' ';
                    board[bullet1_pos.Y][bullet1_pos.X - 2] = L' ';
                    board[bullet1_pos.Y][bullet1_pos.X - 3] = L' ';
                }
                if (board[bullet1_pos.Y][bullet1_pos.X + 1] == L'\u2016')
                {
                    last_move_player1 = 'A';
                    board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                    PlaySoundA("musics\\mirror break.wav", NULL, SND_FILENAME | SND_ASYNC);
                }
                if (bullet1_pos.X == player2_pos.X && bullet1_pos.Y == player2_pos.Y)
                {
                    bullet1_shot = 0;
                    board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                    board[bullet1_pos.Y][bullet1_pos.X - 1] = L' ';
                    board[bullet1_pos.Y][bullet1_pos.X - 2] = L' ';
                    board[bullet1_pos.Y][bullet1_pos.X - 3] = L' ';
                    PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                    health_player_2 -= 2;
                }
            }
            board[bullet1_pos.Y][bullet1_pos.X] = L'\u2022';
        }

        if (key_pressed('X')&0x8000 && player1_bomb_activision == 0 && player1_bomb_ticket == 1)
        {
            PlaySoundA("musics\\bomb second side.wav", NULL, SND_FILENAME | SND_SYNC);

            player1_bomb_activision = 1;
            player1_bomb_ticket = 0;
        }
        if (player1_bomb_activision == 1)
        {
            time_of_bomb -= 0.05;
            if (checker1 == 1)
            {
                PlaySoundA("musics\\10s down counting.wav", NULL, SND_FILENAME | SND_ASYNC);
                checker1 += 1;
            }
            swprintf(&board[12][64], 19, L"   remain bomb: %.2f", time_of_bomb);

            wchar_t Bomb[] = L"\U0001F4A3"; //bomb
            int lenOfBomb1 = wcsnlen(board[second_side_bomb.Y], 86);
            wmemmove(&board[second_side_bomb.Y][second_side_bomb.X + 1], &board[second_side_bomb.Y][second_side_bomb.X + 1], lenOfBomb1 - second_side_bomb.X);
            wcsncpy(&board[second_side_bomb.Y][second_side_bomb.X], Bomb, 2);

            if (time_of_bomb > 0 && key_pressed('G')&0x8000 && player2_pos.X == second_side_bomb.X && player2_pos.Y == second_side_bomb.Y)
            {
                health_player_2 += 5;
                PlaySoundA("musics\\bomb defused.wav", NULL, SND_FILENAME | SND_ASYNC);
                wcsncpy(&board[second_side_bomb.Y][second_side_bomb.X], L"  ", 2);
                player1_bomb_activision = 0;
                player1_bomb_ticket = 0;
                time_of_bomb = 10;
                for (int i = 64; i < 85; ++i)
                {
                    board[12][i] = ' ';
                }
            }
            if (time_of_bomb < 1)
            {
                health_player_2 -= 2;
                PlaySoundA("musics\\explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
                wcsncpy(&board[second_side_bomb.Y][second_side_bomb.X], L"  ", 2);
                player1_bomb_activision = 0;
                player1_bomb_ticket = 0;
                time_of_bomb = 10;
                for (int i = 50; i < 58 ; ++i)
                {
                    for (int j = 2; j < 19 ; ++j)
                    {
                        board[j][i] = L' ';
                    }
                }
                for (int i = 64; i < 85; ++i)
                {
                    board[12][i] = ' ';
                }
            }
        }

        if (key_pressed('I')&0x8000 && player1_pos.Y > 1)
        {
            if (bullet2_shot == 0)
            {
                last_move_player2 = 'I';
            }
            if (board[player2_pos.Y - 1][player2_pos.X] != L'\u2588' && board[player2_pos.Y - 1][player2_pos.X] != L'\u2016' && board[player2_pos.Y - 1][player2_pos.X + 1] != L'\u2588' && board[player2_pos.Y - 1][player2_pos.X + 1] != L'\u2016')
            {
                player2_pos.Y -= 1;
            }
            //PlaySoundA("musics\\movement of players.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        if (key_pressed('K')&0x8000  && player2_pos.Y < 19)
        {
            if (bullet2_shot == 0)
            {
                last_move_player2 = 'K';
            }
            if (board[player2_pos.Y + 1][player2_pos.X] != L'\u2588' && board[player2_pos.Y + 1][player2_pos.X] != L'\u2016' && board[player2_pos.Y + 1][player2_pos.X + 1] != L'\u2588' && board[player2_pos.Y + 1][player2_pos.X + 1] != L'\u2016')
            {
                player2_pos.Y += 1;
            }
            //PlaySoundA("musics\\movement of players.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        if (key_pressed('J')&0x8000  && player2_pos.X > 1)
        {
            if (bullet2_shot == 0)
            {
                last_move_player2 = 'J';
            }
            if (board[player2_pos.Y][player2_pos.X - 1] != L'\u2588' && board[player2_pos.Y][player2_pos.X - 1] != L'\u2016')
            {
                player2_pos.X -= 1;
            }
            //PlaySoundA("musics\\movement of players.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        if (key_pressed('L')&0x8000 && player2_pos.X < 58)
        {
            if (bullet2_shot == 0)
            {
                last_move_player2 = 'L';
            }
            if (board[player2_pos.Y][player2_pos.X + 2] != L'\u2588' && board[player2_pos.Y][player2_pos.X + 2] != L'\u2016')
            {
                player2_pos.X += 1;
            }
            //PlaySoundA("musics\\movement of players.wav", NULL, SND_FILENAME | SND_ASYNC);
        }

        if (key_pressed('N')&0x8000 && bullet2_shot == 0)
        {
            bullet2_shot = 1;
            PlaySoundA("musics\\shooting normal bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        if (bullet2_shot == 0)
        {
            bullet2_pos = player2_pos;
        }
        if (bullet2_shot == 1)
        {
            if (last_move_player2 == 'I')
            {
                if (board[bullet2_pos.Y - 1][bullet2_pos.X] != L'\u2588' && board[bullet2_pos.Y - 1][bullet2_pos.X] != L'\u2016')
                {
                    bullet2_pos.Y -= 1;
                    board[bullet2_pos.Y][bullet2_pos.X] = L'\u2022';
                    board[bullet2_pos.Y + 1][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y + 2][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y + 3][bullet2_pos.X] = L' ';
                }
                if (board[bullet2_pos.Y - 1][bullet2_pos.X] == L'\u2588' || board[bullet2_pos.Y - 1][bullet2_pos.X] == L'\u2016')
                {
                    bullet2_shot = 0;
                    board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y + 1][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y + 2][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y + 3][bullet2_pos.X] = L' ';
                }
                if (bullet2_pos.X == player1_pos.X && bullet2_pos.Y == player1_pos.Y)
                {
                    bullet2_shot = 0;
                    board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y + 1][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y + 2][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y + 3][bullet2_pos.X] = L' ';
                    PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                    health_player_1 -= 2;
                }
            }
            if (last_move_player2 == 'K')
            {
                if (board[bullet2_pos.Y + 1][bullet2_pos.X] != L'\u2588' && board[bullet2_pos.Y + 1][bullet2_pos.X] != L'\u2016')
                {
                    bullet2_pos.Y += 1;
                    board[bullet2_pos.Y][bullet2_pos.X] = L'\u2022';
                    board[bullet2_pos.Y - 1][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y - 2][bullet2_pos.X] = L' ';
                }
                if (board[bullet2_pos.Y + 1][bullet2_pos.X] == L'\u2588' || board[bullet2_pos.Y + 1][bullet2_pos.X] == L'\u2016')
                {
                    bullet2_shot = 0;
                    board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y - 1][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y - 2][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y - 3][bullet2_pos.X] = L' ';
                }
                if (bullet2_pos.X == player1_pos.X && bullet2_pos.Y == player1_pos.Y)
                {
                    bullet2_shot = 0;
                    board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y - 1][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y - 2][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y - 3][bullet2_pos.X] = L' ';
                    PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                    health_player_1 -= 2;
                }
            }
            if (last_move_player2 == 'J')
            {
                if (board[bullet2_pos.Y][bullet2_pos.X - 1] != L'\u2588' && board[bullet2_pos.Y][bullet2_pos.X - 1] != L'\u2016')
                {
                    bullet2_pos.X -= 1;
                    board[bullet2_pos.Y][bullet2_pos.X] = L'\u2022';
                    board[bullet2_pos.Y][bullet2_pos.X + 1] = L' ';
                    board[bullet2_pos.Y][bullet2_pos.X + 2] = L' ';
                }
                if (board[bullet2_pos.Y][bullet2_pos.X - 1] == L'\u2588')
                {
                    bullet2_shot = 0;
                    board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y][bullet2_pos.X + 1] = L' ';
                    board[bullet2_pos.Y][bullet2_pos.X + 2] = L' ';
                    board[bullet2_pos.Y][bullet2_pos.X + 3] = L' ';
                }
                if (board[bullet2_pos.Y][bullet2_pos.X - 1] == L'\u2016')
                {
                    last_move_player2 = 'L';
                    board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                    PlaySoundA("musics\\mirror break.wav", NULL, SND_FILENAME | SND_ASYNC);
                }
                if (bullet2_pos.X == player1_pos.X && bullet2_pos.Y == player1_pos.Y)
                {
                    bullet2_shot = 0;
                    board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y][bullet2_pos.X + 1] = L' ';
                    board[bullet2_pos.Y][bullet2_pos.X + 2] = L' ';
                    board[bullet2_pos.Y][bullet2_pos.X + 3] = L' ';
                    PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                    health_player_1 -= 2;
                }
            }
            if (last_move_player2 == 'L')
            {
                if (board[bullet2_pos.Y][bullet2_pos.X + 1] != L'\u2588' && board[bullet2_pos.Y][bullet2_pos.X + 1] != L'\u2016')
                {
                    bullet2_pos.X += 1;
                    board[bullet2_pos.Y][bullet2_pos.X] = L'\u2022';
                    board[bullet2_pos.Y][bullet2_pos.X - 1] = L' ';
                    board[bullet2_pos.Y][bullet2_pos.X - 2] = L' ';
                }
                if (board[bullet2_pos.Y][bullet2_pos.X + 1] == L'\u2588')
                {
                    bullet2_shot = 0;
                    board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y][bullet2_pos.X - 1] = L' ';
                    board[bullet2_pos.Y][bullet2_pos.X - 2] = L' ';
                    board[bullet2_pos.Y][bullet2_pos.X - 3] = L' ';
                }
                if (board[bullet2_pos.Y][bullet2_pos.X + 1] == L'\u2016')
                {
                    last_move_player2 = 'J';
                    board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                    PlaySoundA("musics\\mirror break.wav", NULL, SND_FILENAME | SND_ASYNC);
                }
                if (bullet2_pos.X == player1_pos.X && bullet2_pos.Y == player1_pos.Y)
                {
                    bullet2_shot = 0;
                    board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                    board[bullet2_pos.Y][bullet2_pos.X - 1] = L' ';
                    board[bullet2_pos.Y][bullet2_pos.X - 2] = L' ';
                    board[bullet2_pos.Y][bullet2_pos.X - 3] = L' ';
                    PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                    health_player_1 -= 2;
                }
            }
            board[bullet2_pos.Y][bullet2_pos.X] = L'\u2022';
        }

        if (key_pressed('M')&0x8000 && player2_bomb_activision == 0 && player2_bomb_ticket == 1)
        {
            PlaySoundA("musics\\bomb first side.wav", NULL, SND_FILENAME | SND_SYNC);

            player2_bomb_activision = 1;
            player2_bomb_ticket = 0;
        }
        if (player2_bomb_activision == 1)
        {
            time_of_bomb -= 0.05;
            if (checker2 == 1)
            {
                PlaySoundA("musics\\10s down counting.wav", NULL, SND_FILENAME | SND_ASYNC);
                checker2 += 1;
            }

            swprintf(&board[12][64], 19, L"   remain bomb: %.2f", time_of_bomb);
            wchar_t Bomb[] = L"\U0001F4A3"; //bomb
            int lenOfBomb2 = wcsnlen(board[first_side_bomb.Y], 86);
            wmemmove(&board[first_side_bomb.Y][first_side_bomb.X + 1], &board[first_side_bomb.Y][first_side_bomb.X + 1], lenOfBomb2 - first_side_bomb.X);
            wcsncpy(&board[first_side_bomb.Y][first_side_bomb.X], Bomb, 2);

            if (time_of_bomb > 0 && key_pressed('G')&0x8000 && player1_pos.X == first_side_bomb.X && player1_pos.Y == first_side_bomb.Y)
            {
                health_player_1 += 5;
                PlaySoundA("musics\\bomb defused.wav", NULL, SND_FILENAME | SND_ASYNC);
                wcsncpy(&board[first_side_bomb.Y][first_side_bomb.X], L"  ", 2);
                player2_bomb_activision = 0;
                player2_bomb_ticket = 0;
                time_of_bomb = 10;
            }
            if (time_of_bomb < 1)
            {
                health_player_1 -= 2;
                PlaySoundA("musics\\explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
                wcsncpy(&board[first_side_bomb.Y][first_side_bomb.X], L"  ", 2);
                player2_bomb_activision = 0;
                player2_bomb_ticket = 0;
                time_of_bomb = 10;
                for (int i = 2; i < 11 ; ++i)
                {
                    for (int j = 2; j < 19 ; ++j)
                    {
                        board[j][i] = L' ';
                    }
                }
            }
        }

        update_player1_position_board1(board, old_player1_pos, player1_pos);
        update_player2_position_board1(board, old_player2_pos, player2_pos);
        if (time <= 0 || health_player_1 <= 0 || health_player_2 <= 0)
        {
            break;
        }
        fflush(stdin);
        fflush(stdout);
        Sleep(50);
        time -= 0.05;
    }

    if (health_player_1 > health_player_2)
    {
        first_player_score += health_player_1 + 20;
        second_player_score += health_player_2;
    }
    if (health_player_1 < health_player_2)
    {
        first_player_score += health_player_1;
        second_player_score += health_player_2 + 20;
    }
    if (health_player_1 == health_player_2)
    {
        first_player_score += health_player_1 + 10;
        second_player_score += health_player_2 + 10;
    }
    PlaySoundA("musics\\round done.wav", NULL, SND_FILENAME | SND_ASYNC);

    Sleep(4000);


}

void loading_round2()
{
    PlaySoundA("musics\\loading the game.wav", NULL, SND_FILENAME | SND_ASYNC);

    RED();
    type_writer_printer("\n\n\n\n\t\t\t\tLOADING SECOND GROUND ...\n");
    wprintf(L"\t\t\t\t");
    BLUE();
    for(int r = 1; r <= 24; r++)
    {
        Sleep(500);
        wprintf(L"\x25A9",177);
    }
    WHITE();
}

void game_round_2()
{
    system("cls");

    DWORD bytes_written;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    wchar_t board[21][86] = {
            L"1111111111111111111111111111111111111111111111111111111111111  11111111111111111111",
            L"1                                                           1  1  SECOND GROUND   1",
            L"1                12                       21                1  11111111111111111111",
            L"1                1           111           1                1",
            L"1                                                           1",
            L"1                                                           1  11111111111111111111",
            L"1                             1                             1  1    RED SHIP      1",
            L"1         2                   1                   2         1  1                  1",
            L"1         2           1      1 1      1           2         1  1                  1",
            L"1         2          1      1   1      1          2         1  1                  1",
            L"1         2         1                   1         2         1  11111111111111111111",
            L"1         2          1      1   1      1          2         1",
            L"1         2           1      1 1      1           2         1",
            L"1         2                   1                   2         1  11111111111111111111",
            L"1                             1                             1  1    BLUE SHIP     1",
            L"1                                                           1  1                  1",
            L"1                                                           1  1                  1",
            L"1                1           111           1                1  1                  1",
            L"1                12                       21                1  11111111111111111111",
            L"1                                                           1",
            L"1111111111111111111111111111111111111111111111111111111111111",
    };

    for (int i = 0; i < 21; ++i)
    {
        for (int j = 0; j < 86; ++j)
        {
            if (board[i][j] == '1') board[i][j] = L'\u2588';
            if (board[i][j] == '2') board[i][j] = L'\u2016';
        }
    }

    int health_player_1 = starting_health;
    int health_player_2 = starting_health;

    char user_player1[25];
    strcpy(user_player1, first_online_player.user_name);
    char user_player2[25];
    strcpy(user_player2, second_online_player.user_name);

    COORD first_player1_pos = {4, 10};
    COORD first_player2_pos = {55, 10};
    COORD hole1 = {30, 5};
    COORD hole2 = {30, 15};
    COORD portal1 = {1, 19};
    COORD portal2 = {58, 1};
    COORD multiplier1 = {1, 1};
    COORD multiplier2 = {58, 19};
    COORD grenade = {30 , 16};
    COORD player1_pos = first_player1_pos;
    COORD player2_pos = first_player2_pos;
    COORD bullet1_pos = {player1_pos.X, player1_pos.Y};
    COORD bullet2_pos = {player2_pos.X, player2_pos.Y};
    COORD heart = {30, 10};
    COORD ghost = {30, 4};
    int heart_gotten = 0;
    int ghost_gotten_player1 = 0;
    int ghost_gotten_player2 = 0;
    int multiplier_activated_player1 = 0;
    int multiplier_activated_player2 = 0;
    int multiplier1_gotten = 0;
    int multiplier2_gotten = 0;
    int multiplier_usage_time_player1 = 0;
    int multiplier_usage_time_player2 = 0;
    int grenade_gotten_player1 = 0;
    int grenade_gotten_player2 = 0;
    int bullet1_shot= 0;
    int bullet2_shot= 0;
    char last_move_player1 = ' ';
    char last_move_player2 = ' ';
    float time = 60;
    double being_ghost_time;

    while (time > 0 && health_player_1 > 0 && health_player_2 > 0)
    {
        COORD origin = {0, 0};
        SetConsoleCursorPosition(hStdout, origin);

        //eating heart
        if (player1_pos.X == heart.X && player1_pos.Y == heart.Y)
        {
            health_player_1 += 5;
            heart_gotten = 1;
            board[player1_pos.Y][player1_pos.X] = L' ';
            board[player1_pos.Y][player1_pos.X + 1] = L' ';
            PlaySoundA("musics\\health up.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        if (player2_pos.X == heart.X && player2_pos.Y == heart.Y)
        {
            health_player_2 += 5;
            heart_gotten = 1;
            board[player2_pos.Y][player2_pos.X] = L' ';
            board[player2_pos.Y][player2_pos.X + 1] = L' ';
            PlaySoundA("musics\\health up.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        else if (heart_gotten == 0)
        {
            wchar_t Heart[] = L"\U0001F493"; // heart
            int lenOfHeart = wcsnlen(board[3], 86);
            wmemmove(&board[heart.Y][heart.X + 1], &board[heart.Y][heart.X + 1], lenOfHeart - heart.X);
            wcsncpy(&board[heart.Y][heart.X], Heart, 2);
        }
        if (heart_gotten == 1)
        {
            heart.X = rand() % (40 - 13 + 1) + 8;
            heart.Y = rand() % (13 - 2 + 1) + 7;
            heart_gotten = 0;
        }


        //eating ghost
        if (player1_pos.X == ghost.X && player1_pos.Y == ghost.Y)
        {
            ghost_gotten_player1 = 1;
            being_ghost_time = time;
            board[player1_pos.Y][player1_pos.X] = L' ';
            board[player1_pos.Y][player1_pos.X + 1] = L' ';
            PlaySoundA("musics\\getting ghost.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        if (player2_pos.X == ghost.X && player2_pos.Y == ghost.Y)
        {
            ghost_gotten_player2 = 1;
            being_ghost_time = time;
            board[player2_pos.Y][player2_pos.X] = L' ';
            board[player2_pos.Y][player2_pos.X + 1] = L' ';
            PlaySoundA("musics\\getting ghost.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        else if (ghost_gotten_player1 == 0 && ghost_gotten_player2 == 0)
        {
            wchar_t Ghost[] = L"\U0001F47B"; // ghost
            int lenOfGhost = wcsnlen(board[ghost.Y], 86);
            wmemmove(&board[ghost.Y][ghost.X + 1], &board[ghost.Y][ghost.X + 1], lenOfGhost - ghost.X);
            wcsncpy(&board[ghost.Y][ghost.X], Ghost, 2);
        }
        if(ghost_gotten_player1 == 1 || ghost_gotten_player2 == 1)
        {
            if (being_ghost_time - time > 7)
            {
                ghost_gotten_player1 = 0;
                ghost_gotten_player2 = 0;
            }
        }


        //eating multiplier
        if (player1_pos.X == multiplier1.X && player1_pos.Y == multiplier1.Y)
        {
            PlaySoundA("musics\\multiplier activated.wav", NULL, SND_FILENAME | SND_ASYNC);
            multiplier_activated_player1 = 1;
            board[player1_pos.Y][player1_pos.X] = L' ';
            board[player1_pos.Y][player1_pos.X + 1] = L' ';
            multiplier1_gotten = 1;
            multiplier1.X = -1;
            multiplier1.Y = -1;
        }
        if (player1_pos.X == multiplier2.X && player1_pos.Y == multiplier2.Y)
        {
            PlaySoundA("musics\\multiplier activated.wav", NULL, SND_FILENAME | SND_ASYNC);
            multiplier_activated_player1 = 1;
            board[player1_pos.Y][player1_pos.X] = L' ';
            board[player1_pos.Y][player1_pos.X + 1] = L' ';
            multiplier2_gotten = 1;
            multiplier2.X = -1;
            multiplier2.Y = -1;
        }
        if (player2_pos.X == multiplier1.X && player2_pos.Y == multiplier1.Y)
        {
            PlaySoundA("musics\\multiplier activated.wav", NULL, SND_FILENAME | SND_ASYNC);
            multiplier_activated_player2 = 1;
            board[player2_pos.Y][player2_pos.X] = L' ';
            board[player2_pos.Y][player2_pos.X + 1] = L' ';
            multiplier1_gotten = 1;
            multiplier1.X = -1;
            multiplier1.Y = -1;
        }
        if (player2_pos.X == multiplier2.X && player2_pos.Y == multiplier2.Y)
        {
            PlaySoundA("musics\\multiplier activated.wav", NULL, SND_FILENAME | SND_ASYNC);
            multiplier_activated_player2 = 1;
            board[player2_pos.Y][player2_pos.X] = L' ';
            board[player2_pos.Y][player2_pos.X + 1] = L' ';
            multiplier2_gotten = 1;
            multiplier2.X = -1;
            multiplier2.Y = -1;
        }
        if (multiplier1_gotten == 0)
        {
            wchar_t Multiplier[] = L"\u26A1"; //multiplier
            int lenOfMultiplier = wcsnlen(board[multiplier1.Y], 86);
            wmemmove(&board[multiplier1.Y][multiplier1.X + 1], &board[multiplier1.Y][multiplier1.X + 1], lenOfMultiplier - multiplier1.X);
            wcsncpy(&board[multiplier1.Y][multiplier1.X], Multiplier, 1);
        }
        if (multiplier2_gotten == 0)
        {
            wchar_t Multiplier[] = L"\u26A1"; //multiplier
            int lenOfMultiplier = wcsnlen(board[multiplier2.Y], 86);
            wmemmove(&board[multiplier2.Y][multiplier2.X + 1], &board[multiplier2.Y][multiplier2.X + 1], lenOfMultiplier - multiplier2.X);
            wcsncpy(&board[multiplier2.Y][multiplier2.X], Multiplier, 2);

        }


        //eating grenade
        if (player1_pos.X == grenade.X && player1_pos.Y == grenade.Y)
        {
            grenade_gotten_player1 = 1;
            board[player1_pos.Y][player1_pos.X] = L' ';
            board[player1_pos.Y][player1_pos.X + 1] = L' ';
            grenade.X = -1;
            grenade.Y = -1;
            PlaySoundA("musics\\grenade activated.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        if (player2_pos.X == grenade.X && player2_pos.Y == grenade.Y)
        {
            grenade_gotten_player2 = 1;
            board[player2_pos.Y][player2_pos.X] = L' ';
            board[player2_pos.Y][player2_pos.X + 1] = L' ';
            grenade.X = -1;
            grenade.Y = -1;
            PlaySoundA("musics\\grenade activated", NULL, SND_FILENAME | SND_ASYNC);
        }
        else if (grenade_gotten_player1 == 0 && grenade_gotten_player2 == 0)
        {
            wchar_t Grenade[] = L"\U0001F9E8"; // grenade
            int lenOfGrenade = wcsnlen(board[grenade.Y], 86);
            wmemmove(&board[grenade.Y][grenade.X + 1], &board[grenade.Y][grenade.X + 1], lenOfGrenade - grenade.X);
            wcsncpy(&board[grenade.Y][grenade.X], Grenade, 2);
        }


        //getting into hole
        if (player1_pos.X == hole1.X && player1_pos.Y == hole1.Y)
        {
            PlaySoundA("musics\\getting in hole.wav", NULL, SND_FILENAME | SND_ASYNC);
            health_player_1 += -1;
            player1_pos.X = first_player1_pos.X;
            player1_pos.Y = first_player1_pos.Y;
        }
        if (player1_pos.X == hole2.X && player1_pos.Y == hole2.Y)
        {
            PlaySoundA("musics\\getting in hole.wav", NULL, SND_FILENAME | SND_ASYNC);
            health_player_1 += -1;
            player1_pos.X = first_player1_pos.X;
            player1_pos.Y = first_player1_pos.Y;
        }
        if (player2_pos.X == hole1.X && player2_pos.Y == hole1.Y)
        {
            PlaySoundA("musics\\getting in hole.wav", NULL, SND_FILENAME | SND_ASYNC);
            health_player_2 += -1;
            player2_pos.X = first_player2_pos.X;
            player2_pos.Y = first_player2_pos.Y;
        }
        if (player2_pos.X == hole2.X && player2_pos.Y == hole2.Y)
        {
            PlaySoundA("musics\\getting in hole.wav", NULL, SND_FILENAME | SND_ASYNC);
            health_player_2 += -1;
            player2_pos.X = first_player2_pos.X;
            player2_pos.Y = first_player2_pos.Y;
        }

        wchar_t Hole[] = L"\U0001F300"; //hole
        int lenOfHole = wcsnlen(board[hole1.Y], 86);
        wmemmove(&board[hole1.Y][hole1.X + 1], &board[hole1.Y][hole1.X + 1], lenOfHole - hole1.X);
        wcsncpy(&board[hole1.Y][hole1.X], Hole, 2);
        wmemmove(&board[hole2.Y][hole2.X + 1], &board[hole2.Y][hole2.X + 1], lenOfHole - hole2.X);
        wcsncpy(&board[hole2.Y][hole2.X], Hole, 2);


        //getting into portals
        if (player1_pos.X == portal1.X && player1_pos.Y == portal1.Y)
        {
            PlaySoundA("musics\\portal.wav", NULL, SND_FILENAME | SND_ASYNC);
            player1_pos.X = portal2.X;
            player1_pos.Y = portal2.Y;
        }
        else if (player1_pos.X == portal2.X && player1_pos.Y == portal2.Y)
        {
            PlaySoundA("musics\\portal.wav", NULL, SND_FILENAME | SND_ASYNC);
            player1_pos.X = portal1.X;
            player1_pos.Y = portal1.Y;
        }
        if (player2_pos.X == portal1.X && player2_pos.Y == portal1.Y)
        {
            PlaySoundA("musics\\portal.wav", NULL, SND_FILENAME | SND_ASYNC);
            player2_pos.X = portal2.X;
            player2_pos.Y = portal2.Y;
        }
        else if (player2_pos.X == portal2.X && player2_pos.Y == portal2.Y)
        {
            PlaySoundA("musics\\portal.wav", NULL, SND_FILENAME | SND_ASYNC);
            player2_pos.X = portal1.X;
            player2_pos.Y = portal1.Y;
        }
        board[portal1.Y][portal1.X + 1] = L' ';
        board[portal2.Y][portal2.X + 1] = L' ';
        board[portal1.Y][portal1.X] = L'\u058D'; //portal
        board[portal2.Y][portal2.X] = L'\u058D';


        //about players
        wchar_t RedShip[] = L"\U0001F7E5"; //red ship
        int lenOfRed = wcsnlen(board[player1_pos.Y], 86);
        wmemmove(&board[player1_pos.Y][player1_pos.X + 1], &board[player1_pos.Y][player1_pos.X + 1], lenOfRed - player1_pos.X);
        wcsncpy(&board[player1_pos.Y][player1_pos.X], RedShip, 2);

        wchar_t BlueShip[] = L"\U0001F7E6"; //blue ship
        int lenOfBlue = wcsnlen(board[player2_pos.Y], 86);
        wmemmove(&board[player2_pos.Y][player2_pos.X + 1], &board[player2_pos.Y][player2_pos.X + 1], lenOfBlue - player2_pos.X);
        wcsncpy(&board[player2_pos.Y][player2_pos.X], BlueShip, 2);


        //details
        swprintf(&board[7][64], 25, L"name: %s", user_player1);
        board[7][82] = L' ';
        board[7][83] = L'\u2588';
        swprintf(&board[9][64], 25, L"health: %d", health_player_1);
        board[9][82] = L' ';
        board[9][83] = L'\u2588';
        swprintf(&board[15][64], 25, L"name: %s", user_player2);
        board[15][82] = L' ';
        board[15][83] = L'\u2588';
        swprintf(&board[17][64], 25, L"health: %d", health_player_2);
        board[17][82] = L' ';
        board[17][83] = L'\u2588';
        swprintf(&board[4][64], 19, L"      time: %.1f", time);

        for (short i = 0; i < 21; i++)
        {
            COORD place_of_ground_1;
            place_of_ground_1.X = 0;
            place_of_ground_1.Y = i;
            WriteConsoleOutputCharacterW(hStdout, board[i], 86, place_of_ground_1, &bytes_written);
        }

        COORD old_player1_pos = player1_pos;
        COORD old_player2_pos = player2_pos;


        if (key_pressed('W')&0x8000  && player1_pos.Y > 1)
        {
            if (bullet1_shot == 0)
            {
                last_move_player1 = 'W';
            }
            if (ghost_gotten_player1 == 1 && (board[player1_pos.Y - 1][player1_pos.X] == L'\u2588' || board[player1_pos.Y - 1][player1_pos.X] == L'\u2016' || board[player1_pos.Y - 1][player1_pos.X + 1] == L'\u2588' || board[player1_pos.Y - 1][player1_pos.X + 1] == L'\u2016'))
            {
                for (int i = 1; i < 20; ++i)
                {
                    if (board[player1_pos.Y - i][player1_pos.X] != L'\u2588' && board[player1_pos.Y - i][player1_pos.X] != L'\u2016' && board[player1_pos.Y - i][player1_pos.X + 1] != L'\u2588' && board[player1_pos.Y - i][player1_pos.X + 1] != L'\u2016')
                    {
                        player1_pos.Y = player1_pos.Y - i;
                        break;
                    }
                }
            }
            if (ghost_gotten_player1 == 1 && (board[player1_pos.Y - 1][player1_pos.X] != L'\u2588' && board[player1_pos.Y - 1][player1_pos.X] != L'\u2016' && board[player1_pos.Y - 1][player1_pos.X + 1] != L'\u2588' && board[player1_pos.Y - 1][player1_pos.X + 1] != L'\u2016'))
            {
                player1_pos.Y -= 1;
            }
            if (ghost_gotten_player1 == 0 &&  board[player1_pos.Y - 1][player1_pos.X] != L'\u2588' && board[player1_pos.Y - 1][player1_pos.X] != L'\u2016' && board[player1_pos.Y - 1][player1_pos.X + 1] != L'\u2588' && board[player1_pos.Y - 1][player1_pos.X + 1] != L'\u2016')
            {
                player1_pos.Y -= 1;
            }
            //PlaySoundA("musics\\movement of players.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        if (key_pressed('S')&0x8000  && player1_pos.Y < 19)
        {
            if (bullet1_shot == 0)
            {
                last_move_player1 = 'S';
            }
            if (ghost_gotten_player1 == 1 && (board[player1_pos.Y + 1][player1_pos.X] == L'\u2588' || board[player1_pos.Y + 1][player1_pos.X] == L'\u2016' || board[player1_pos.Y + 1][player1_pos.X + 1] == L'\u2588' || board[player1_pos.Y + 1][player1_pos.X + 1] == L'\u2016'))
            {
                for (int i = 1; i < 20; ++i)
                {
                    if (board[player1_pos.Y + i][player1_pos.X] != L'\u2588' && board[player1_pos.Y + i][player1_pos.X] != L'\u2016' && board[player1_pos.Y + i][player1_pos.X + 1] != L'\u2588' && board[player1_pos.Y + i][player1_pos.X + 1] != L'\u2016')
                    {
                        player1_pos.Y = player1_pos.Y + i;
                        break;
                    }
                }
            }
            if (ghost_gotten_player1 == 1 && (board[player1_pos.Y + 1][player1_pos.X] != L'\u2588' && board[player1_pos.Y + 1][player1_pos.X] != L'\u2016' && board[player1_pos.Y + 1][player1_pos.X + 1] != L'\u2588' && board[player1_pos.Y + 1][player1_pos.X + 1] != L'\u2016'))
            {
                player1_pos.Y += 1;
            }
            if (ghost_gotten_player1 == 0 &&  board[player1_pos.Y + 1][player1_pos.X] != L'\u2588' && board[player1_pos.Y + 1][player1_pos.X] != L'\u2016' && board[player1_pos.Y + 1][player1_pos.X + 1] != L'\u2588' && board[player1_pos.Y + 1][player1_pos.X + 1] != L'\u2016')
            {
                player1_pos.Y += 1;
            }
            //PlaySoundA("musics\\movement of players.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        if (key_pressed('A')&0x8000  && player1_pos.X > 1)
        {
            if (bullet1_shot == 0)
            {
                last_move_player1 = 'A';
            }
            if (ghost_gotten_player1 == 1 && (board[player1_pos.Y][player1_pos.X - 1] == L'\u2588' || board[player1_pos.Y][player1_pos.X - 1] == L'\u2016'))
            {
                for (int i = 1; i < 58; ++i)
                {
                    if (board[player1_pos.Y][player1_pos.X - i] != L'\u2588' && board[player1_pos.Y][player1_pos.X - i] != L'\u2016')
                    {
                        player1_pos.X = player1_pos.X - i;
                        break;
                    }
                }
            }
            if (ghost_gotten_player1 == 1 && (board[player1_pos.Y][player1_pos.X - 1] != L'\u2588' && board[player1_pos.Y][player1_pos.X - 1] != L'\u2016'))
            {
                player1_pos.X -= 1;
            }
            if (ghost_gotten_player1 == 0 && board[player1_pos.Y][player1_pos.X - 1] != L'\u2588' && board[player1_pos.Y][player1_pos.X - 1] != L'\u2016')
            {
                player1_pos.X -= 1;
            }
            //PlaySoundA("musics\\movement of players.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        if (key_pressed('D')&0x8000  && player1_pos.X < 58)
        {
            if (bullet1_shot == 0)
            {
                last_move_player1 = 'D';
            }
            if (ghost_gotten_player1 == 1 && (board[player1_pos.Y][player1_pos.X + 2] == L'\u2588' || board[player1_pos.Y][player1_pos.X + 2] == L'\u2016'))
            {
                for (int i = 1; i < 58; ++i)
                {
                    if (board[player1_pos.Y][player1_pos.X + i + 1] != L'\u2588' && board[player1_pos.Y][player1_pos.X + i + 1] != L'\u2016')
                    {
                        player1_pos.X = player1_pos.X + i;
                        break;
                    }
                }
            }
            if (ghost_gotten_player1 == 1 && (board[player1_pos.Y][player1_pos.X + 2] != L'\u2588' && board[player1_pos.Y][player1_pos.X + 2] != L'\u2016'))
            {
                player1_pos.X += 1;
            }
            if (ghost_gotten_player1 == 0 && board[player1_pos.Y][player1_pos.X + 2] != L'\u2588' && board[player1_pos.Y][player1_pos.X + 2] != L'\u2016')
            {
                player1_pos.X += 1;
            }
            //PlaySoundA("musics\\movement of players.wav", NULL, SND_FILENAME | SND_ASYNC);
        }

        if (key_pressed('C')&0x8000  && bullet1_shot == 0)
        {
            bullet1_shot = 1;
            if (multiplier_activated_player1 == 1)
            {
                multiplier_usage_time_player1 += 1;

                if (multiplier_usage_time_player1 < 5)
                {
                    PlaySoundA("musics\\shoot powered bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                }
                else
                {
                    multiplier_activated_player1 = 0;
                }
            }
            else
            {
                PlaySoundA("musics\\shooting normal bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
            }
        }
        if (bullet1_shot == 0)
        {
            bullet1_pos = player1_pos;
        }
        if (bullet1_shot == 1)
        {
            if (last_move_player1 == 'W')
            {
                if (ghost_gotten_player1 == 0)
                {
                    if (board[bullet1_pos.Y - 1][bullet1_pos.X] != L'\u2588' && board[bullet1_pos.Y - 1][bullet1_pos.X] != L'\u2016')
                    {
                        bullet1_pos.Y -= 1;
                        //board[bullet1_pos.Y][bullet1_pos.X] = L'\u2022';
                        board[bullet1_pos.Y + 1][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y + 2][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y + 1][bullet1_pos.X + 1] = L' ';
                        board[bullet1_pos.Y + 2][bullet1_pos.X + 1] = L' ';
                    }
                    if (board[bullet1_pos.Y - 1][bullet1_pos.X] == L'\u2588' || board[bullet1_pos.Y - 1][bullet1_pos.X] == L'\u2016')
                    {
                        if (grenade_gotten_player1 == 0)
                        {
                            bullet1_shot = 0;
                            board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                            board[bullet1_pos.Y + 1][bullet1_pos.X] = L' ';
                            board[bullet1_pos.Y + 2][bullet1_pos.X] = L' ';
                            board[bullet1_pos.Y + 3][bullet1_pos.X] = L' ';
                        }
                        if (grenade_gotten_player1 == 1)
                        {
                            PlaySoundA("musics\\explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
                            grenade_gotten_player1 = 0;
                            bullet1_shot = 0;
                            board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                            board[bullet1_pos.Y + 1][bullet1_pos.X] = L' ';
                            for (int i = 0; i < 3; ++i)
                            {
                                for (int j = 0; j < 3; ++j)
                                {
                                    if (bullet1_pos.X + j == player1_pos.X && bullet1_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X + j == player2_pos.X && bullet1_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player1_pos.X && bullet1_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player2_pos.X && bullet1_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player1_pos.X && bullet1_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player2_pos.X && bullet1_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet1_pos.X + j == player1_pos.X && bullet1_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X + j == player2_pos.X && bullet1_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                }
                            }
                        }
                    }
                    if (bullet1_pos.X == player2_pos.X && bullet1_pos.Y == player2_pos.Y)
                    {
                        bullet1_shot = 0;
                        board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y + 1][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y + 2][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y + 3][bullet1_pos.X] = L' ';
                        PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                        if (multiplier_activated_player1 == 1)
                        {
                            health_player_2 -= 4;
                        }
                        else
                        {
                            health_player_2 -= 2;
                        }
                    }
                }
                if (ghost_gotten_player1 == 1)
                {
                    if (board[bullet1_pos.Y - 1][bullet1_pos.X] != L'\u2588' && board[bullet1_pos.Y - 1][bullet1_pos.X] != L'\u2016')
                    {
                        bullet1_pos.Y -= 1;
                        //board[bullet1_pos.Y][bullet1_pos.X] = L'\u2022';
                        board[bullet1_pos.Y + 1][bullet1_pos.X] = L' ';
                        //board[bullet1_pos.Y + 2][bullet1_pos.X] = L' ';
                        //board[bullet1_pos.Y + 3][bullet1_pos.X] = L' ';
                    }
                    if (board[bullet1_pos.Y - 1][bullet1_pos.X] == L'\u2588' || board[bullet1_pos.Y - 1][bullet1_pos.X] == L'\u2016')
                    {
                        for (int i = 1; i < 20; ++i)
                        {
                            if (board[bullet1_pos.Y - i][bullet1_pos.X] != L'\u2588' && board[bullet1_pos.Y - i][bullet1_pos.X] != L'\u2016')
                            {
                                if (bullet1_pos.Y - i > 0)
                                {
                                    bullet1_pos.Y = bullet1_pos.Y - i;
                                    break;
                                }
                                else
                                {
                                    bullet1_shot = 0;
                                }
                            }
                        }
                    }
                    if (bullet1_pos.X == player2_pos.X && bullet1_pos.Y == player2_pos.Y)
                    {
                        bullet1_shot = 0;
                        board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y + 1][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y + 2][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y + 3][bullet1_pos.X] = L' ';
                        PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                        if (multiplier_activated_player1 == 1)
                        {
                            health_player_2 -= 4;
                        }
                        else
                        {
                            health_player_2 -= 2;
                        }
                    }
                }
            }
            if (last_move_player1 == 'S')
            {
                if (ghost_gotten_player1 == 0)
                {
                    if (board[bullet1_pos.Y + 1][bullet1_pos.X] != L'\u2588' && board[bullet1_pos.Y + 1][bullet1_pos.X] != L'\u2016')
                    {
                        bullet1_pos.Y += 1;
                        //board[bullet1_pos.Y][bullet1_pos.X] = L'\u2022';
                        board[bullet1_pos.Y - 1][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y - 2][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y - 3][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y - 1][bullet1_pos.X + 1] = L' ';
                        board[bullet1_pos.Y - 2][bullet1_pos.X + 1] = L' ';
                    }
                    if (board[bullet1_pos.Y + 1][bullet1_pos.X] == L'\u2588' || board[bullet1_pos.Y + 1][bullet1_pos.X] == L'\u2016') {
                        if (grenade_gotten_player1 == 0)
                        {
                            bullet1_shot = 0;
                            board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                            board[bullet1_pos.Y - 1][bullet1_pos.X] = L' ';
                            board[bullet1_pos.Y - 2][bullet1_pos.X] = L' ';
                        }
                        if (grenade_gotten_player1 == 1)
                        {
                            PlaySoundA("musics\\explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
                            grenade_gotten_player1 = 0;
                            for (int i = 0; i < 2; ++i)
                            {
                                for (int j = 0; j < 2; ++j)
                                {
                                    if (bullet1_pos.X + j == player1_pos.X && bullet1_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X + j == player2_pos.X && bullet1_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player1_pos.X && bullet1_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player2_pos.X && bullet1_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player1_pos.X && bullet1_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player2_pos.X && bullet1_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet1_pos.X + j == player1_pos.X && bullet1_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X + j == player2_pos.X && bullet1_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                }
                            }
                        }
                    }
                    if (bullet1_pos.X == player2_pos.X && bullet1_pos.Y == player2_pos.Y)
                    {
                        bullet1_shot = 0;
                        board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y - 1][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y - 2][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y - 3][bullet1_pos.X] = L' ';
                        PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                        if (multiplier_activated_player1 == 1)
                        {
                            health_player_2 -= 4;
                        }
                        else
                        {
                            health_player_2 -= 2;
                        }
                    }
                }
                if (ghost_gotten_player1 == 1)
                {
                    if (board[bullet1_pos.Y + 1][bullet1_pos.X] != L'\u2588' && board[bullet1_pos.Y + 1][bullet1_pos.X] != L'\u2016')
                    {
                        bullet1_pos.Y += 1;
                        //board[bullet1_pos.Y][bullet1_pos.X] = L'\u2022';
                        board[bullet1_pos.Y - 1][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y - 2][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y - 3][bullet1_pos.X] = L' ';
                    }
                    if (board[bullet1_pos.Y + 1][bullet1_pos.X] == L'\u2588' || board[bullet1_pos.Y + 1][bullet1_pos.X] == L'\u2016')
                    {
                        for (int i = 1; i < 20; ++i)
                        {
                            if (board[bullet1_pos.Y + i][bullet1_pos.X] != L'\u2588' && board[bullet1_pos.Y + i][bullet1_pos.X] != L'\u2016')
                            {
                                if (bullet1_pos.Y + i < 20)
                                {
                                    bullet1_pos.Y = bullet1_pos.Y + i;
                                    break;
                                }
                                else
                                {
                                    bullet1_shot = 0;
                                }
                            }
                        }
                    }
                    if (bullet1_pos.X == player2_pos.X && bullet1_pos.Y == player2_pos.Y)
                    {
                        bullet1_shot = 0;
                        board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y - 1][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y - 2][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y - 3][bullet1_pos.X] = L' ';
                        PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                        if (multiplier_activated_player1 == 1)
                        {
                            health_player_2 -= 4;
                        }
                        else
                        {
                            health_player_2 -= 2;
                        }
                    }
                }
            }
            if (last_move_player1 == 'A')
            {
                if (ghost_gotten_player1 == 0)
                {
                    if (board[bullet1_pos.Y][bullet1_pos.X - 1] != L'\u2588' && board[bullet1_pos.Y][bullet1_pos.X - 1] != L'\u2016')
                    {
                        bullet1_pos.X -= 1;
                        //board[bullet1_pos.Y][bullet1_pos.X] = L'\u2022';
                        board[bullet1_pos.Y][bullet1_pos.X + 1] = L' ';
                        board[bullet1_pos.Y][bullet1_pos.X + 2] = L' ';
                    }
                    if (board[bullet1_pos.Y][bullet1_pos.X - 1] == L'\u2588')
                    {
                        if (grenade_gotten_player1 == 0)
                        {
                            bullet1_shot = 0;
                            board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                            board[bullet1_pos.Y][bullet1_pos.X + 1] = L' ';
                            board[bullet1_pos.Y][bullet1_pos.X + 2] = L' ';
                            board[bullet1_pos.Y][bullet1_pos.X + 3] = L' ';
                        }
                        if (grenade_gotten_player1 == 1)
                        {
                            PlaySoundA("musics\\explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
                            grenade_gotten_player1 = 0;
                            for (int i = 0; i < 2; ++i)
                            {
                                for (int j = 0; j < 2; ++j)
                                {
                                    if (bullet1_pos.X + j == player1_pos.X && bullet1_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X + j == player2_pos.X && bullet1_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player1_pos.X && bullet1_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player2_pos.X && bullet1_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player1_pos.X && bullet1_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player2_pos.X && bullet1_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet1_pos.X + j == player1_pos.X && bullet1_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X + j == player2_pos.X && bullet1_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                }
                            }
                        }
                    }
                    if (board[bullet1_pos.Y][bullet1_pos.X - 1] == L'\u2016')
                    {
                        if (grenade_gotten_player1 == 0)
                        {
                            last_move_player1 = 'D';
                            board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                            PlaySoundA("musics\\mirror break.wav", NULL, SND_FILENAME | SND_ASYNC);
                        }
                        if (grenade_gotten_player1 == 1)
                        {
                            board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                            PlaySoundA("musics\\explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
                            bullet1_shot = 0;
                            grenade_gotten_player1 = 0;
                            for (int i = 0; i < 2; ++i)
                            {
                                for (int j = 0; j < 2; ++j)
                                {
                                    if (bullet1_pos.X + j == player1_pos.X && bullet1_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X + j == player2_pos.X && bullet1_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player1_pos.X && bullet1_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player2_pos.X && bullet1_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player1_pos.X && bullet1_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player2_pos.X && bullet1_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet1_pos.X + j == player1_pos.X && bullet1_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X + j == player2_pos.X && bullet1_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                }
                            }
                        }
                    }
                    if (bullet1_pos.X == player2_pos.X && bullet1_pos.Y == player2_pos.Y)
                    {
                        bullet1_shot = 0;
                        board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y][bullet1_pos.X + 1] = L' ';
                        board[bullet1_pos.Y][bullet1_pos.X + 2] = L' ';
                        board[bullet1_pos.Y][bullet1_pos.X + 3] = L' ';
                        PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                        if (multiplier_activated_player1 == 1)
                        {
                            health_player_2 -= 4;
                        }
                        else
                        {
                            health_player_2 -= 2;
                        }
                    }
                }
                if (ghost_gotten_player1 == 1)
                {
                    if (board[bullet1_pos.Y][bullet1_pos.X - 1] != L'\u2588' && board[bullet1_pos.Y][bullet1_pos.X - 1] != L'\u2016')
                    {
                        bullet1_pos.X -= 1;
                        //board[bullet1_pos.Y][bullet1_pos.X] = L'\u2022';
                        board[bullet1_pos.Y][bullet1_pos.X + 1] = L' ';
                        board[bullet1_pos.Y][bullet1_pos.X + 2] = L' ';
                    }
                    if (board[bullet1_pos.Y][bullet1_pos.X - 1] == L'\u2588' || board[bullet1_pos.Y][bullet1_pos.X - 1] == L'\u2016')
                    {
                        for (int i = 1; i < 20; ++i)
                        {
                            if (board[bullet1_pos.Y][bullet1_pos.X - i] != L'\u2588' && board[bullet1_pos.Y][bullet1_pos.X - i] != L'\u2016')
                            {
                                if (bullet1_pos.X - i - 1 > 0)
                                {
                                    bullet1_pos.X = bullet1_pos.X - i - 1;
                                    break;
                                }
                                else
                                {
                                    bullet1_shot = 0;
                                }
                            }
                        }
                    }
                    if (bullet1_pos.X == player2_pos.X && bullet1_pos.Y == player2_pos.Y)
                    {
                        bullet1_shot = 0;
                        board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y][bullet1_pos.X + 1] = L' ';
                        board[bullet1_pos.Y][bullet1_pos.X + 2] = L' ';
                        board[bullet1_pos.Y][bullet1_pos.X + 3] = L' ';
                        PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                        if (multiplier_activated_player1 == 1)
                        {
                            health_player_2 -= 4;
                        }
                        else
                        {
                            health_player_2 -= 2;
                        }
                    }
                }
            }
            if (last_move_player1 == 'D')
            {
                if (ghost_gotten_player1 == 0)
                {
                    if (board[bullet1_pos.Y][bullet1_pos.X + 1] != L'\u2588' && board[bullet1_pos.Y][bullet1_pos.X + 1] != L'\u2016')
                    {
                        bullet1_pos.X += 1;
                        //board[bullet1_pos.Y][bullet1_pos.X] = L'\u2022';
                        board[bullet1_pos.Y][bullet1_pos.X - 1] = L' ';
                        board[bullet1_pos.Y][bullet1_pos.X - 2] = L' ';
                    }
                    if (board[bullet1_pos.Y][bullet1_pos.X + 1] == L'\u2588')
                    {
                        if (grenade_gotten_player1 == 0)
                        {
                            bullet1_shot = 0;
                            board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                            board[bullet1_pos.Y][bullet1_pos.X - 1] = L' ';
                            board[bullet1_pos.Y][bullet1_pos.X - 2] = L' ';
                            board[bullet1_pos.Y][bullet1_pos.X - 3] = L' ';
                        }
                        if (grenade_gotten_player1 == 1)
                        {
                            PlaySoundA("musics\\explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
                            grenade_gotten_player1 = 0;
                            bullet1_shot = 0;
                            for (int i = 0; i < 2; ++i)
                            {
                                for (int j = 0; j < 2; ++j)
                                {
                                    if (bullet1_pos.X + j == player1_pos.X && bullet1_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X + j == player2_pos.X && bullet1_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player1_pos.X && bullet1_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player2_pos.X && bullet1_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player1_pos.X && bullet1_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player2_pos.X && bullet1_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet1_pos.X + j == player1_pos.X && bullet1_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X + j == player2_pos.X && bullet1_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                }
                            }
                        }
                    }
                    if (board[bullet1_pos.Y][bullet1_pos.X + 1] == L'\u2016')
                    {
                        if (grenade_gotten_player1 == 0)
                        {
                            last_move_player1 = 'A';
                            board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                            PlaySoundA("musics\\mirror break.wav", NULL, SND_FILENAME | SND_ASYNC);
                        }
                        if (grenade_gotten_player1 == 1)
                        {
                            board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                            PlaySoundA("musics\\explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
                            bullet1_shot = 0;
                            grenade_gotten_player1 = 0;
                            for (int i = 0; i < 2; ++i)
                            {
                                for (int j = 0; j < 2; ++j)
                                {
                                    if (bullet1_pos.X + j == player1_pos.X && bullet1_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X + j == player2_pos.X && bullet1_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player1_pos.X && bullet1_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player2_pos.X && bullet1_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player1_pos.X && bullet1_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X - j == player2_pos.X && bullet1_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet1_pos.X + j == player1_pos.X && bullet1_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet1_pos.X + j == player2_pos.X && bullet1_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                }
                            }
                        }
                    }
                    if (bullet1_pos.X == player2_pos.X && bullet1_pos.Y == player2_pos.Y)
                    {
                        bullet1_shot = 0;
                        board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y][bullet1_pos.X - 1] = L' ';
                        board[bullet1_pos.Y][bullet1_pos.X - 2] = L' ';
                        board[bullet1_pos.Y][bullet1_pos.X - 3] = L' ';
                        PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                        if (multiplier_activated_player1 == 1)
                        {
                            health_player_2 -= 4;
                        }
                        else
                        {
                            health_player_2 -= 2;
                        }
                    }
                }
                if (ghost_gotten_player1 == 1)
                {
                    if (board[bullet1_pos.Y][bullet1_pos.X + 1] != L'\u2588' && board[bullet1_pos.Y][bullet1_pos.X + 1] != L'\u2016')
                    {
                        bullet1_pos.X += 1;
                        //board[bullet1_pos.Y][bullet1_pos.X] = L'\u2022';
                        board[bullet1_pos.Y][bullet1_pos.X - 1] = L' ';
                        board[bullet1_pos.Y][bullet1_pos.X - 2] = L' ';
                    }
                    if (board[bullet1_pos.Y][bullet1_pos.X + 1] == L'\u2588' || board[bullet1_pos.Y][bullet1_pos.X + 1] == L'\u2016')
                    {
                        for (int i = 1; i < 20; ++i)
                        {
                            if (board[bullet1_pos.Y][bullet1_pos.X + i] != L'\u2588' && board[bullet1_pos.Y][bullet1_pos.X + i] != L'\u2016')
                            {
                                if (bullet1_pos.X + i < 58)
                                {
                                    bullet1_pos.X = bullet1_pos.X + i + 1;
                                    break;
                                }
                                else
                                {
                                    bullet1_shot = 0;
                                }
                            }
                        }
                    }
                    if (bullet1_pos.X == player2_pos.X && bullet1_pos.Y == player2_pos.Y)
                    {
                        bullet1_shot = 0;
                        board[bullet1_pos.Y][bullet1_pos.X] = L' ';
                        board[bullet1_pos.Y][bullet1_pos.X - 1] = L' ';
                        board[bullet1_pos.Y][bullet1_pos.X - 2] = L' ';
                        board[bullet1_pos.Y][bullet1_pos.X - 3] = L' ';
                        PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                        if (multiplier_activated_player1 == 1)
                        {
                            health_player_2 -= 4;
                        }
                        else
                        {
                            health_player_2 -= 2;
                        }
                    }
                }
            }

            if (multiplier_activated_player1 == 1 && grenade_gotten_player1 == 0)
            {
                board[bullet1_pos.Y][bullet1_pos.X] = L'\u25CF';
            }
            if (grenade_gotten_player1 == 1)
            {
                wchar_t Grenade[] = L"\U0001F9E8"; // grenade
                int lenOfGrenade = wcsnlen(board[bullet1_pos.Y], 86);
                wmemmove(&board[bullet1_pos.Y][bullet1_pos.X + 1], &board[bullet1_pos.Y][bullet1_pos.X + 1], lenOfGrenade - bullet1_pos.X);
                wcsncpy(&board[bullet1_pos.Y][bullet1_pos.X], Grenade, 2);
            }
            if (multiplier_activated_player1 == 0 && grenade_gotten_player1 == 0)
            {
                board[bullet1_pos.Y][bullet1_pos.X] = L'\u2022';
            }
        }


        if (key_pressed('I')&0x8000  && player2_pos.Y > 1)
        {
            if (bullet2_shot == 0)
            {
                last_move_player2 = 'I';
            }
            if (ghost_gotten_player2 == 1 && (board[player2_pos.Y - 1][player2_pos.X] == L'\u2588' || board[player2_pos.Y - 1][player2_pos.X] == L'\u2016' || board[player2_pos.Y - 1][player2_pos.X + 1] == L'\u2588' || board[player2_pos.Y - 1][player2_pos.X + 1] == L'\u2016'))
            {
                for (int i = 1; i < 20; ++i)
                {
                    if (board[player2_pos.Y - i][player2_pos.X] != L'\u2588' && board[player2_pos.Y - i][player2_pos.X] != L'\u2016' && board[player2_pos.Y - i][player2_pos.X + 1] != L'\u2588' && board[player2_pos.Y - i][player2_pos.X + 1] != L'\u2016')
                    {
                        player2_pos.Y = player2_pos.Y - i;
                        break;
                    }
                }
            }
            if (ghost_gotten_player2 == 1 && (board[player2_pos.Y - 1][player2_pos.X] != L'\u2588' && board[player2_pos.Y - 1][player2_pos.X] != L'\u2016' && board[player2_pos.Y - 1][player2_pos.X + 1] != L'\u2588' && board[player2_pos.Y - 1][player2_pos.X + 1] != L'\u2016'))
            {
                player1_pos.Y -= 1;
            }
            if (ghost_gotten_player2 == 0 &&  board[player2_pos.Y - 1][player2_pos.X] != L'\u2588' && board[player2_pos.Y - 1][player2_pos.X] != L'\u2016' && board[player2_pos.Y - 1][player2_pos.X + 1] != L'\u2588' && board[player2_pos.Y - 1][player2_pos.X + 1] != L'\u2016')
            {
                player2_pos.Y -= 1;
            }
            //PlaySoundA("musics\\movement of players.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        if (key_pressed('K')&0x8000  && player2_pos.Y < 19)
        {
            if (bullet2_shot == 0)
            {
                last_move_player2 = 'K';
            }
            if (ghost_gotten_player2 == 1 && (board[player2_pos.Y + 1][player2_pos.X] == L'\u2588' || board[player2_pos.Y + 1][player2_pos.X] == L'\u2016' || board[player2_pos.Y + 1][player2_pos.X + 1] == L'\u2588' || board[player2_pos.Y + 1][player2_pos.X + 1] == L'\u2016'))
            {
                for (int i = 1; i < 20; ++i)
                {
                    if (board[player2_pos.Y - i][player2_pos.X] != L'\u2588' && board[player2_pos.Y - i][player2_pos.X] != L'\u2016' && board[player2_pos.Y + i][player2_pos.X + 1] != L'\u2588' && board[player2_pos.Y + i][player2_pos.X + 1] != L'\u2016')
                    {
                        player2_pos.Y = player2_pos.Y + i;
                        break;
                    }
                }
            }
            if (ghost_gotten_player2 == 1 && (board[player2_pos.Y + 1][player2_pos.X] != L'\u2588' && board[player2_pos.Y + 1][player2_pos.X] != L'\u2016' && board[player2_pos.Y + 1][player2_pos.X + 1] != L'\u2588' && board[player2_pos.Y + 1][player2_pos.X + 1] != L'\u2016'))
            {
                player1_pos.Y -= 1;
            }
            if (ghost_gotten_player2 == 0 &&  board[player2_pos.Y + 1][player2_pos.X] != L'\u2588' && board[player2_pos.Y + 1][player2_pos.X] != L'\u2016' && board[player2_pos.Y + 1][player2_pos.X + 1] != L'\u2588' && board[player2_pos.Y + 1][player2_pos.X + 1] != L'\u2016')
            {
                player2_pos.Y += 1;
            }
            //PlaySoundA("musics\\movement of players.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        if (key_pressed('J')&0x8000  && player2_pos.X > 1)
        {
            if (bullet2_shot == 0)
            {
                last_move_player2 = 'J';
            }
            if (ghost_gotten_player2 == 1 && (board[player2_pos.Y][player2_pos.X - 1] == L'\u2588' || board[player2_pos.Y][player2_pos.X - 1] == L'\u2016'))
            {
                for (int i = 1; i < 58; ++i)
                {
                    if (board[player2_pos.Y][player2_pos.X - i] != L'\u2588' && board[player2_pos.Y][player2_pos.X - i] != L'\u2016')
                    {
                        player2_pos.X = player2_pos.X - i;
                        break;
                    }
                }
            }
            if (ghost_gotten_player2 == 1 && (board[player2_pos.Y][player2_pos.X - 1] != L'\u2588' && board[player2_pos.Y][player2_pos.X - 1] != L'\u2016'))
            {
                player1_pos.X -= 1;
            }
            if (ghost_gotten_player2 == 0 &&  board[player2_pos.Y][player2_pos.X - 1] != L'\u2588' && board[player2_pos.Y][player2_pos.X - 1] != L'\u2016')
            {
                player2_pos.X -= 1;
            }
            //PlaySoundA("musics\\movement of players.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        if (key_pressed('L')&0x8000  && player2_pos.X < 58)
        {
            if (bullet2_shot == 0)
            {
                last_move_player2 = 'L';
            }
            if (ghost_gotten_player2 == 1 && (board[player2_pos.Y][player2_pos.X + 2] == L'\u2588' || board[player2_pos.Y][player2_pos.X + 2] == L'\u2016'))
            {
                for (int i = 1; i < 58; ++i)
                {
                    if (board[player2_pos.Y][player2_pos.X + i] != L'\u2588' && board[player2_pos.Y][player2_pos.X + i] != L'\u2016')
                    {
                        player2_pos.X = player2_pos.X + i;
                        break;
                    }
                }
            }
            if (ghost_gotten_player2 == 1 && (board[player2_pos.Y][player2_pos.X + 2] != L'\u2588' && board[player2_pos.Y][player2_pos.X + 2] != L'\u2016'))
            {
                player1_pos.X -= 1;
            }
            if (ghost_gotten_player2 == 0 &&  board[player2_pos.Y][player2_pos.X + 2] != L'\u2588' && board[player2_pos.Y][player2_pos.X + 2] != L'\u2016')
            {
                player2_pos.X += 1;
            }
            //PlaySoundA("musics\\movement of players.wav", NULL, SND_FILENAME | SND_ASYNC);
        }

        if (key_pressed('N')&0x8000  && bullet2_shot == 0)
        {
            bullet2_shot = 1;
            if (multiplier_activated_player2 == 1)
            {
                multiplier_usage_time_player2 += 1;

                if (multiplier_usage_time_player2 < 5)
                {
                    PlaySoundA("musics\\shoot powered bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                }
                else
                {
                    multiplier_activated_player2 = 0;
                }
            }
            else
            {
                PlaySoundA("musics\\shooting normal bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
            }
        }
        if (bullet2_shot == 0)
        {
            bullet2_pos = player2_pos;
        }
        if (bullet2_shot == 1)
        {
            if (last_move_player2 == 'I')
            {
                if (ghost_gotten_player2 == 0)
                {
                    if (board[bullet2_pos.Y - 1][bullet2_pos.X] != L'\u2588' && board[bullet2_pos.Y - 1][bullet2_pos.X] != L'\u2016')
                    {
                        bullet2_pos.Y -= 1;
                        board[bullet2_pos.Y][bullet2_pos.X] = L'\u2022';
                        board[bullet2_pos.Y + 1][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y + 2][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y + 1][bullet2_pos.X + 1] = L' ';
                        board[bullet2_pos.Y + 2][bullet2_pos.X + 1] = L' ';
                    }
                    if (board[bullet2_pos.Y - 1][bullet2_pos.X] == L'\u2588' || board[bullet2_pos.Y - 1][bullet2_pos.X] == L'\u2016')
                    {
                        if (grenade_gotten_player2 == 0)
                        {
                            bullet2_shot = 0;
                            board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                            board[bullet2_pos.Y + 1][bullet2_pos.X] = L' ';
                            board[bullet2_pos.Y + 2][bullet2_pos.X] = L' ';
                            board[bullet2_pos.Y + 3][bullet2_pos.X] = L' ';
                        }
                        if (grenade_gotten_player2 == 1)
                        {
                            PlaySoundA("musics\\explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
                            grenade_gotten_player2 = 0;
                            bullet2_shot = 0;
                            for (int i = 0; i < 3; ++i)
                            {
                                for (int j = 0; j < 3; ++j)
                                {
                                    if (bullet2_pos.X + j == player1_pos.X && bullet2_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X + j == player2_pos.X && bullet2_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player1_pos.X && bullet2_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player2_pos.X && bullet2_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player1_pos.X && bullet2_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player2_pos.X && bullet2_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet2_pos.X + j == player1_pos.X && bullet2_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X + j == player2_pos.X && bullet2_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                }
                            }
                        }
                    }
                    if (bullet2_pos.X == player1_pos.X && bullet2_pos.Y == player1_pos.Y)
                    {
                        bullet2_shot = 0;
                        board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y + 1][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y + 2][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y + 3][bullet2_pos.X] = L' ';
                        PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                        if (multiplier_activated_player2 == 1)
                        {
                            health_player_1 -= 4;
                        }
                        else
                        {
                            health_player_1 -= 2;
                        }
                    }
                }
                if (ghost_gotten_player2 == 1)
                {
                    if (board[bullet2_pos.Y - 1][bullet2_pos.X] != L'\u2588' && board[bullet2_pos.Y - 1][bullet2_pos.X] != L'\u2016')
                    {
                        bullet2_pos.Y -= 1;
                        board[bullet2_pos.Y][bullet2_pos.X] = L'\u2022';
                        board[bullet2_pos.Y + 1][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y + 2][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y + 3][bullet2_pos.X] = L' ';
                    }
                    if (board[bullet2_pos.Y - 1][bullet2_pos.X] == L'\u2588' || board[bullet2_pos.Y - 1][bullet2_pos.X] == L'\u2016')
                    {
                        for (int i = 1; i < 20; ++i)
                        {
                            if (board[bullet2_pos.Y - i][bullet2_pos.X] != L'\u2588' && board[bullet2_pos.Y - i][bullet2_pos.X] != L'\u2016')
                            {
                                if (bullet2_pos.Y - i > 0)
                                {
                                    bullet2_pos.Y = bullet2_pos.Y - i;
                                    break;
                                }
                                else
                                {
                                    bullet2_shot = 0;
                                }
                            }
                        }
                    }
                    if (bullet2_pos.X == player1_pos.X && bullet2_pos.Y == player1_pos.Y)
                    {
                        bullet2_shot = 0;
                        board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y + 1][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y + 2][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y + 3][bullet2_pos.X] = L' ';
                        PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                        if (multiplier_activated_player2 == 1)
                        {
                            health_player_1 -= 4;
                        }
                        else
                        {
                            health_player_1 -= 2;
                        }
                    }
                }
            }
            if (last_move_player2 == 'K')
            {
                if (ghost_gotten_player2 == 0)
                {
                    if (board[bullet2_pos.Y + 1][bullet2_pos.X] != L'\u2588' && board[bullet2_pos.Y + 1][bullet2_pos.X] != L'\u2016')
                    {
                        bullet2_pos.Y += 1;
                        board[bullet2_pos.Y][bullet2_pos.X] = L'\u2022';
                        board[bullet2_pos.Y - 1][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y - 2][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y - 1][bullet2_pos.X + 1] = L' ';
                        board[bullet2_pos.Y - 2][bullet2_pos.X + 1] = L' ';
                    }
                    if (board[bullet2_pos.Y + 1][bullet2_pos.X] == L'\u2588' || board[bullet2_pos.Y + 1][bullet2_pos.X] == L'\u2016')
                    {
                        if (grenade_gotten_player2 == 0)
                        {
                            bullet2_shot = 0;
                            board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                            board[bullet2_pos.Y - 1][bullet2_pos.X] = L' ';
                            board[bullet2_pos.Y - 2][bullet2_pos.X] = L' ';
                            board[bullet2_pos.Y - 3][bullet2_pos.X] = L' ';
                        }
                        if (grenade_gotten_player2 == 1)
                        {
                            PlaySoundA("musics\\explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
                            grenade_gotten_player2 = 0;
                            bullet2_shot = 0;
                            for (int i = 0; i < 3; ++i)
                            {
                                for (int j = 0; j < 3; ++j)
                                {
                                    if (bullet2_pos.X + j == player1_pos.X && bullet2_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X + j == player2_pos.X && bullet2_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player1_pos.X && bullet2_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player2_pos.X && bullet2_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player1_pos.X && bullet2_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player2_pos.X && bullet2_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet2_pos.X + j == player1_pos.X && bullet2_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X + j == player2_pos.X && bullet2_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                }
                            }
                        }
                    }
                    if (bullet2_pos.X == player1_pos.X && bullet2_pos.Y == player1_pos.Y)
                    {
                        bullet2_shot = 0;
                        board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y - 1][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y - 2][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y - 3][bullet2_pos.X] = L' ';
                        PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                        if (multiplier_activated_player2 == 1)
                        {
                            health_player_1 -= 4;
                        }
                        else
                        {
                            health_player_1 -= 2;
                        }
                    }
                }
                if (ghost_gotten_player2 == 1)
                {
                    if (board[bullet2_pos.Y + 1][bullet2_pos.X] != L'\u2588' && board[bullet2_pos.Y + 1][bullet2_pos.X] != L'\u2016')
                    {
                        bullet2_pos.Y += 1;
                        board[bullet2_pos.Y][bullet2_pos.X] = L'\u2022';
                        board[bullet2_pos.Y - 1][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y - 2][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y - 3][bullet2_pos.X] = L' ';
                    }
                    if (board[bullet2_pos.Y + 1][bullet2_pos.X] == L'\u2588' || board[bullet2_pos.Y + 1][bullet2_pos.X] == L'\u2016')
                    {
                        for (int i = 1; i < 20; ++i)
                        {
                            if (board[bullet2_pos.Y + i][bullet2_pos.X] != L'\u2588' && board[bullet2_pos.Y + i][bullet2_pos.X] != L'\u2016')
                            {
                                if (bullet2_pos.Y + i < 20)
                                {
                                    bullet2_pos.Y = bullet2_pos.Y + i;
                                    break;
                                }
                                else
                                {
                                    bullet2_shot = 0;
                                }
                            }
                        }
                    }
                    if (bullet2_pos.X == player1_pos.X && bullet2_pos.Y == player1_pos.Y)
                    {
                        bullet2_shot = 0;
                        board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y - 1][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y - 2][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y - 3][bullet2_pos.X] = L' ';
                        PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                        if (multiplier_activated_player2 == 1)
                        {
                            health_player_1 -= 4;
                        }
                        else
                        {
                            health_player_1 -= 2;
                        }
                    }
                }
            }
            if (last_move_player2 == 'J')
            {
                if (ghost_gotten_player2 == 0)
                {
                    if (board[bullet2_pos.Y][bullet2_pos.X - 1] != L'\u2588' && board[bullet2_pos.Y][bullet2_pos.X - 1] != L'\u2016')
                    {
                        bullet2_pos.X -= 1;
                        board[bullet2_pos.Y][bullet2_pos.X] = L'\u2022';
                        board[bullet2_pos.Y][bullet2_pos.X + 1] = L' ';
                        board[bullet2_pos.Y][bullet2_pos.X + 2] = L' ';
                    }
                    if (board[bullet2_pos.Y][bullet2_pos.X - 1] == L'\u2588')
                    {
                        if (grenade_gotten_player2 == 0)
                        {
                            bullet2_shot = 0;
                            board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                            board[bullet2_pos.Y][bullet2_pos.X + 1] = L' ';
                            board[bullet2_pos.Y][bullet2_pos.X + 2] = L' ';
                            board[bullet2_pos.Y][bullet2_pos.X + 3] = L' ';
                        }
                        if (grenade_gotten_player2 == 1)
                        {
                            PlaySoundA("musics\\explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
                            grenade_gotten_player2 = 0;
                            bullet2_shot = 0;
                            for (int i = 0; i < 3; ++i)
                            {
                                for (int j = 0; j < 3; ++j)
                                {
                                    if (bullet2_pos.X + j == player1_pos.X && bullet2_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X + j == player2_pos.X && bullet2_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player1_pos.X && bullet2_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player2_pos.X && bullet2_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player1_pos.X && bullet2_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player2_pos.X && bullet2_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet2_pos.X + j == player1_pos.X && bullet2_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X + j == player2_pos.X && bullet2_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                }
                            }
                        }
                    }
                    if (board[bullet2_pos.Y][bullet2_pos.X - 1] == L'\u2016')
                    {
                        if (grenade_gotten_player2 == 0)
                        {
                            last_move_player2 = 'L';
                            board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                            PlaySoundA("musics\\mirror break.wav", NULL, SND_FILENAME | SND_ASYNC);
                        }
                        if (grenade_gotten_player2 == 1)
                        {
                            board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                            PlaySoundA("musics\\explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
                            bullet2_shot = 0;
                            grenade_gotten_player2 = 0;
                            bullet2_shot = 0;
                            for (int i = 0; i < 3; ++i)
                            {
                                for (int j = 0; j < 3; ++j)
                                {
                                    if (bullet2_pos.X + j == player1_pos.X && bullet2_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X + j == player2_pos.X && bullet2_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player1_pos.X && bullet2_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player2_pos.X && bullet2_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player1_pos.X && bullet2_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player2_pos.X && bullet2_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet2_pos.X + j == player1_pos.X && bullet2_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X + j == player2_pos.X && bullet2_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                }
                            }
                        }
                    }
                    if (bullet2_pos.X == player1_pos.X && bullet2_pos.Y == player1_pos.Y)
                    {
                        bullet2_shot = 0;
                        board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y][bullet2_pos.X + 1] = L' ';
                        board[bullet2_pos.Y][bullet2_pos.X + 2] = L' ';
                        board[bullet2_pos.Y][bullet2_pos.X + 3] = L' ';
                        PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                        if (multiplier_activated_player2 == 1)
                        {
                            health_player_1 -= 4;
                        }
                        else
                        {
                            health_player_1 -= 2;
                        }
                    }
                }
                if (ghost_gotten_player2 == 1)
                {
                    if (board[bullet2_pos.Y][bullet2_pos.X - 1] != L'\u2588' && board[bullet2_pos.Y][bullet2_pos.X - 1] != L'\u2016')
                    {
                        bullet2_pos.X -= 1;
                        board[bullet2_pos.Y][bullet2_pos.X] = L'\u2022';
                        board[bullet2_pos.Y][bullet2_pos.X + 1] = L' ';
                        board[bullet2_pos.Y][bullet2_pos.X + 2] = L' ';
                    }
                    if (board[bullet2_pos.Y][bullet2_pos.X - 1] == L'\u2588' || board[bullet2_pos.Y][bullet2_pos.X - 1] == L'\u2016')
                    {
                        for (int i = 1; i < 20; ++i)
                        {
                            if (board[bullet2_pos.Y][bullet2_pos.X - i] != L'\u2588' && board[bullet2_pos.Y][bullet2_pos.X - i] != L'\u2016')
                            {
                                if (bullet2_pos.X - i - 1 > 0)
                                {
                                    bullet2_pos.X = bullet2_pos.X - i - 1;
                                    break;
                                }
                                else
                                {
                                    bullet2_shot = 0;
                                }
                            }
                        }
                    }
                    if (bullet2_pos.X == player1_pos.X && bullet2_pos.Y == player1_pos.Y)
                    {
                        bullet2_shot = 0;
                        board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y][bullet2_pos.X + 1] = L' ';
                        board[bullet2_pos.Y][bullet2_pos.X + 2] = L' ';
                        board[bullet2_pos.Y][bullet2_pos.X + 3] = L' ';
                        PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                        if (multiplier_activated_player2 == 1)
                        {
                            health_player_1 -= 4;
                        }
                        else
                        {
                            health_player_1 -= 2;
                        }
                    }
                }
            }
            if (last_move_player2 == 'L')
            {
                if (ghost_gotten_player2 == 0)
                {
                    if (board[bullet2_pos.Y][bullet2_pos.X + 1] != L'\u2588' && board[bullet2_pos.Y][bullet2_pos.X + 1] != L'\u2016')
                    {
                        bullet2_pos.X += 1;
                        board[bullet2_pos.Y][bullet2_pos.X] = L'\u2022';
                        board[bullet2_pos.Y][bullet2_pos.X - 1] = L' ';
                        board[bullet2_pos.Y][bullet2_pos.X - 2] = L' ';
                    }
                    if (board[bullet2_pos.Y][bullet2_pos.X + 1] == L'\u2588')
                    {
                        if (grenade_gotten_player2 == 0)
                        {
                            bullet2_shot = 0;
                            board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                            board[bullet2_pos.Y][bullet2_pos.X - 1] = L' ';
                            board[bullet2_pos.Y][bullet2_pos.X - 2] = L' ';
                            board[bullet2_pos.Y][bullet2_pos.X - 3] = L' ';
                        }
                        if (grenade_gotten_player2 == 1)
                        {
                            PlaySoundA("musics\\explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
                            grenade_gotten_player2 = 0;
                            bullet2_shot = 0;
                            for (int i = 0; i < 3; ++i)
                            {
                                for (int j = 0; j < 3; ++j)
                                {
                                    if (bullet2_pos.X + j == player1_pos.X && bullet2_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X + j == player2_pos.X && bullet2_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player1_pos.X && bullet2_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player2_pos.X && bullet2_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player1_pos.X && bullet2_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player2_pos.X && bullet2_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet2_pos.X + j == player1_pos.X && bullet2_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X + j == player2_pos.X && bullet2_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                }
                            }
                        }
                    }
                    if (board[bullet2_pos.Y][bullet2_pos.X + 1] == L'\u2016')
                    {
                        if (grenade_gotten_player2 == 0)
                        {
                            last_move_player2 = 'J';
                            board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                            PlaySoundA("musics\\mirror break.wav", NULL, SND_FILENAME | SND_ASYNC);
                        }
                        if (grenade_gotten_player2 == 1)
                        {
                            board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                            PlaySoundA("musics\\explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
                            bullet2_shot = 0;
                            grenade_gotten_player2 = 0;
                            bullet2_shot = 0;
                            for (int i = 0; i < 3; ++i)
                            {
                                for (int j = 0; j < 3; ++j)
                                {
                                    if (bullet2_pos.X + j == player1_pos.X && bullet2_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X + j == player2_pos.X && bullet2_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player1_pos.X && bullet2_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player2_pos.X && bullet2_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player1_pos.X && bullet2_pos.Y + i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X - j == player2_pos.X && bullet2_pos.Y + i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                    if (bullet2_pos.X + j == player1_pos.X && bullet2_pos.Y - i == player1_pos.Y)
                                    {
                                        health_player_1 -= 2;
                                    }
                                    if (bullet2_pos.X + j == player2_pos.X && bullet2_pos.Y - i == player2_pos.Y)
                                    {
                                        health_player_2 -= 2;
                                    }
                                }
                            }
                        }
                    }
                    if (bullet2_pos.X == player1_pos.X && bullet2_pos.Y == player1_pos.Y)
                    {
                        bullet2_shot = 0;
                        board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y][bullet2_pos.X - 1] = L' ';
                        board[bullet2_pos.Y][bullet2_pos.X - 2] = L' ';
                        board[bullet2_pos.Y][bullet2_pos.X - 3] = L' ';
                        PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                        if (multiplier_activated_player2 == 1)
                        {
                            health_player_1 -= 4;
                        }
                        else
                        {
                            health_player_1 -= 2;
                        }
                    }
                }
                if (ghost_gotten_player2 == 1)
                {
                    if (board[bullet2_pos.Y][bullet2_pos.X + 1] != L'\u2588' && board[bullet2_pos.Y][bullet2_pos.X + 1] != L'\u2016')
                    {
                        bullet2_pos.X += 1;
                        board[bullet2_pos.Y][bullet2_pos.X] = L'\u2022';
                        board[bullet2_pos.Y][bullet2_pos.X - 1] = L' ';
                        board[bullet2_pos.Y][bullet2_pos.X - 2] = L' ';
                    }
                    if (board[bullet2_pos.Y][bullet2_pos.X + 1] == L'\u2588' || board[bullet2_pos.Y][bullet2_pos.X + 1] == L'\u2016')
                    {
                        for (int i = 1; i < 20; ++i)
                        {
                            if (board[bullet2_pos.Y][bullet2_pos.X + i] != L'\u2588' && board[bullet2_pos.Y][bullet2_pos.X + i] != L'\u2016')
                            {
                                if (bullet2_pos.X + i < 58)
                                {
                                    bullet2_pos.X = bullet2_pos.X + i + 1;
                                    break;
                                }
                                else
                                {
                                    bullet2_shot = 0;
                                }
                            }
                        }
                    }
                    if (bullet2_pos.X == player1_pos.X && bullet2_pos.Y == player1_pos.Y)
                    {
                        bullet2_shot = 0;
                        board[bullet2_pos.Y][bullet2_pos.X] = L' ';
                        board[bullet2_pos.Y][bullet2_pos.X - 1] = L' ';
                        board[bullet2_pos.Y][bullet2_pos.X - 2] = L' ';
                        board[bullet2_pos.Y][bullet2_pos.X - 3] = L' ';
                        PlaySoundA("musics\\hit the bullet.wav", NULL, SND_FILENAME | SND_ASYNC);
                        if (multiplier_activated_player2 == 1)
                        {
                            health_player_1 -= 4;
                        }
                        else
                        {
                            health_player_1 -= 2;
                        }
                    }
                }
            }

            if (multiplier_activated_player2 == 1 && grenade_gotten_player2 == 0)
            {
                board[bullet2_pos.Y][bullet2_pos.X] = L'\u25CF';
            }
            if (grenade_gotten_player2 == 1)
            {
                wchar_t Grenade[] = L"\U0001F9E8"; // grenade
                int lenOfGrenade = wcsnlen(board[bullet2_pos.Y], 86);
                wmemmove(&board[bullet2_pos.Y][bullet2_pos.X + 1], &board[bullet2_pos.Y][bullet2_pos.X + 1], lenOfGrenade - bullet2_pos.X);
                wcsncpy(&board[bullet2_pos.Y][bullet2_pos.X], Grenade, 2);
            }
            if (multiplier_activated_player2 == 0 && grenade_gotten_player2 == 0)
            {
                board[bullet2_pos.Y][bullet2_pos.X] = L'\u2022';
            }

        }


        update_player1_position_board2(board, old_player1_pos, player1_pos);
        update_player2_position_board2(board, old_player2_pos, player2_pos);

        Sleep(50);
        time -= 0.05;
    }

    if (health_player_1 > health_player_2)
    {
        first_player_score += health_player_1 + 20;
        second_player_score += health_player_2;
    }
    if (health_player_1 < health_player_2)
    {
        first_player_score += health_player_1;
        second_player_score += health_player_2 + 20;
    }
    if (health_player_1 == health_player_2)
    {
        first_player_score += health_player_1 + 10;
        second_player_score += health_player_2 + 10;
    }

    PlaySoundA("musics\\round done.wav", NULL, SND_FILENAME | SND_ASYNC);
    Sleep(4000);
}

void update_player1_position_board2(wchar_t board[][86], COORD oldPos, COORD newPos)
{
    board[oldPos.Y][oldPos.X] = L' ';
    board[oldPos.Y][oldPos.X + 1] = L' ';

    wchar_t RedShip[] = L"\U0001F7E5"; //red ship
    int lenOfRed = wcsnlen(board[newPos.Y], 86);
    wmemmove(&board[newPos.Y][newPos.X + 1], &board[newPos.Y][newPos.X + 1], lenOfRed - newPos.X);
    wcsncpy(&board[newPos.Y][newPos.X], RedShip, 2);
}

void update_player2_position_board2(wchar_t board[][86], COORD oldPos, COORD newPos)
{
    board[oldPos.Y][oldPos.X] = L' ';
    board[oldPos.Y][oldPos.X + 1] = L' ';

    wchar_t BlueShip[] = L"\U0001F7E6"; //blue ship
    int lenOfBlue = wcsnlen(board[newPos.Y], 86);
    wmemmove(&board[newPos.Y][newPos.X + 1], &board[newPos.Y][newPos.X + 1], lenOfBlue - newPos.X);
    wcsncpy(&board[newPos.Y][newPos.X], BlueShip, 2);
}

void audit()
{
    history_resetor();

    time_t currentTime;
    time(&currentTime);

    strcpy(game_history.date_of_play, ctime(&currentTime));

    if (first_player_score > second_player_score)
    {
        strcpy(game_history.winner, first_online_player.user_name);
        strcpy(game_history.loser, second_online_player.user_name);
        game_history.score_of_loser = second_player_score;
        game_history.score_of_winner = first_player_score;
    }
    if (first_player_score < second_player_score)
    {
        strcpy(game_history.loser, first_online_player.user_name);
        strcpy(game_history.winner, second_online_player.user_name);
        game_history.score_of_winner = second_player_score;
        game_history.score_of_loser = first_player_score;
    }
    if (first_player_score == second_player_score)
    {
        strcpy(game_history.winner, first_online_player.user_name);
        strcpy(game_history.loser, second_online_player.user_name);
        game_history.score_of_loser = second_player_score;
        game_history.score_of_winner = first_player_score;
    }
}

void play_winning_video()
{
    char* video_path = "videos\\commander massage.mp4";
    char* vlc_path = "C:\\Program Files\\VideoLAN\\VLC\\vlc.exe";

    char command[256];
    sprintf(command, "\"%s\" \"%s\" --play-and-exit", vlc_path, video_path);

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcess(NULL, command, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) {
        fprintf(stderr, "Error creating process: %d\n", GetLastError());
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

void play_draw_video()
{
    char* video_path = "videos\\commander massage2.mp4";
    char* vlc_path = "C:\\Program Files\\VideoLAN\\VLC\\vlc.exe";

    char command[256];
    sprintf(command, "\"%s\" \"%s\" --play-and-exit", vlc_path, video_path);

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcess(NULL, command, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) {
        fprintf(stderr, "Error creating process: %d\n", GetLastError());
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

void show_audit()
{
    system("cls");

    if (game_history.score_of_winner == game_history.score_of_loser)
    {
        play_draw_video();
        GREEN();
        wprintf(L"\n\t\t%s & %s\n", game_history.winner, game_history.loser);
        YELLOW();
    }
    else
    {
        play_winning_video();
        GREEN();
        wprintf(L"\n\t\t%s\n", game_history.winner);
        YELLOW();
    }
    wprintf(L"%*s          :;;;;;;;;;;;;;;;;;+:          \n", 5, "");
    wprintf(L"%*s     ;;;;;+:::;;;;;;;;;;;;;+++;;;;;.    \n", 5, "");
    wprintf(L"%*s    .;     :::;;;;;;;;;;;;;++     ;.    \n", 5, "");
    wprintf(L"%*s     ;     :::;;;;;;;;;;;;;+;     ;.    \n", 5, "");
    wprintf(L"%*s     ;.    .:::;;;;;;;;;;;;+:    .;     \n", 5, "");
    wprintf(L"%*s      ;.    :::;;;;;;;;;;;++    .;      \n", 5, "");
    wprintf(L"%*s       ;:    :::;;;;;;;;;;+    :;       \n", 5, "");
    wprintf(L"%*s         :;::;;::;;;;;;;;+;::;:         \n", 5, "");
    wprintf(L"%*s              .:;:;;;;;;:.              \n", 5, "");
    wprintf(L"%*s                 ;;;;;+                 \n", 5, "");
    wprintf(L"%*s                  ;++;                  \n", 5, "");
    wprintf(L"%*s                  :;;+                  \n", 5, "");
    wprintf(L"%*s                 ;:;;;+                 \n", 5, "");
    wprintf(L"%*s               :;:;;;;;;+               \n", 5, "");
    WHITE();
    wprintf(L"%*s             ;X$$$$$$$$$$$+             \n", 5, "");
    wprintf(L"%*s             ;$+:;;;;;;+x$+             \n", 5, "");
    wprintf(L"%*s            .X$$$$$$$$$$$$X:            \n", 5, "");

    PlaySoundA("musics\\congratulation.wav", NULL, SND_FILENAME | SND_ASYNC);

    cursor_off();
    CYAN();
    wprintf(L"%*s                NICE JOB             \n", 5, "");
    WHITE();
    Sleep(9000);
}

void save_the_history()
{
    FILE *fp;
    fp = fopen("game history.txt", "a+");

    fseek(fp, 0, SEEK_END);
    fwrite(&game_history, sizeof(game_history), 1, fp);

    fclose(fp);
}

/*
 *-------------------------------------------------HELPER FUNCTIONS-----------------------------------------------------
 */
void RED()
{
    wprintf(L"\033[1;31m");
}

void GREEN()
{
    wprintf(L"\033[1;32m");
}

void YELLOW()
{
    wprintf(L"\033[1;33m");
}

void CYAN()
{
    wprintf(L"\033[1;36m");
}

void PURPLE()
{
    wprintf(L"\033[1;35m");
}

void BLUE()
{
    wprintf(L"\033[1;34m");
}

void WHITE()
{
    wprintf(L"\033[0m");
}

void type_writer_printer(char must_be_printed[])
{
    for (int h= 0; must_be_printed[h] != '\0'; h++)
    {
        wprintf(L"%c", must_be_printed[h]);
        fflush(stdout);
        usleep(25000);
    }
}

void faster_type_writer_printer(char must_be_printed[])
{
    for (int h= 0; must_be_printed[h] != '\0'; h++)
    {
        wprintf(L"%c", must_be_printed[h]);
        fflush(stdout);
        usleep(5000);
    }
}

void cursor_on()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    int game;
}

void cursor_off()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

/*
 *--------------------------------------------------MAIN FUNCTION-------------------------------------------------------
 */
int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    cursor_off();

    welcome();
    menu();
}