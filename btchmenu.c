/* btchMenu.c

   By Michael W. Maher

   Started: 10/4/90

   The following program will create a user menu.  The menu will allow
   the launching of batchfile by use of the 10 function keys.  The
   batch file can be launched without the menu program being removed
   from memory; Therefore, any program that is run from this menu will
   return to the menu after execution.

   128 characters are allowed for the path+filename of the process.
    40 characters are allowed for the menu label.
   F1 -> F10 are the valid function keys.
*/
#include<process.h>
#include<bios.h>
#include<enhdkeys.h>
#include<graph.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"btch_c.h"

menu_item_rec items[10];

void main(int argc, char **argv);

int num_func;
char menu_label[41];

void main(int argc, char **argv)
  {
  char i;

  if ((argc > 1) &&
      (load_setup(items, argv[1], &num_func, menu_label) == TRUE))
    {
    create_menu(items, menu_label);
    do
      {
      i = do_menu_calls(items);
      if ((i > -1) && (i < 99))
	{
	system(items[i].path_file);
	create_menu(items, menu_label);
	}
      }
    while(i != 99);
    }
  else if (argc <= 1)
    printf("Michael W. Maher 1991\nuseage: BTCHMENU [setup-filespec]\n");
  return;
  }




