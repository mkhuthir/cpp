/*
 ============================================================================
 Name        : HelloWorld_GTK2_Linux.c
 Author      : Muthanna A. Attyah
 Version     :
 Copyright   : (c) Muthanna 2017
 Description : Hello World in GTK+
 ============================================================================
 */

 #include <gtk/gtk.h>

 int main (int argc, char *argv[])
 {
    GtkWidget *window;
    GtkWidget *label;

    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL); 					/* create the main, top level, window */
    gtk_window_set_title (GTK_WINDOW (window), "Hello World");     	/* give it the title */

    /* Connect the destroy signal of the window to gtk_main_quit
     * When the window is about to be destroyed we get a notification and
     * stop the main GTK+ loop
     */

    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    label = gtk_label_new ("Hello, World");  						/* Create the "Hello, World" label  */
    gtk_container_add (GTK_CONTAINER (window), label);     			/* and insert it into the main window  */
    gtk_widget_show_all (window);     								/* make sure that everything, window and label, are visible */
    gtk_main ();     												/* start the main loop, and let it rest there until the application is closed */

    return 0;
 }
