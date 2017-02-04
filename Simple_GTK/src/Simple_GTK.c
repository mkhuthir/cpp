/*
 ============================================================================
 Name        : Simple_GTK.c
 Author      : Muthanna A. Attyah
 Version     : 1.0
 Copyright   : (c) Muthanna 2017
 Description : Simple GTK window in C, Ansi-style
 ============================================================================
 */
#include <gtk/gtk.h>

int main( int   argc,
          char *argv[] )
{

	GtkWidget *window;

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    gtk_widget_show  (window);

    gtk_main ();

    return 0;

}

