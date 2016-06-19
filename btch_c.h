/* btch_c.h

   By Michael W. Maher
   Ver 1.0 7/17/91
*/
/* include files */
#include<process.h>
#include<bios.h>
#include<enhdkeys.h>
#include<graph.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/* macros */
#define TRUE 1
#define FALSE 0
#define YELLOW 14
#define BRIGHTWHITE 15
#define MAXFUNCTIONS 10

typedef struct menu_item_rec
	   {
	   char *path_file;
	   char *batch_label;
	   } menu_item_rec;

/* function prototypes */
void set_items(menu_item_rec *items);
void create_menu(menu_item_rec *items, char *menu_label);
char do_menu_calls(menu_item_rec *items);
char load_setup(menu_item_rec *setup, char *setupfilename,
		int *num_func, char *menu_label);
char open_file_handler(char *filename, FILE **fileptr, char *typestring);
void highlight(char *textline, int x, int y, unsigned highlightcolor);

