
#include<gtk/gtk.h>
 
GtkWidget *win;
 
int main(int argc, char **argv)
{
  gtk_init(&argc, &argv);
  
  win =gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (win), "Window");
  gtk_window_set_default_size (GTK_WINDOW (win), 300, 300);
  
  gtk_widget_show(win);
 
  // connect signal to quit window
  g_signal_connect(win,"destroy",G_CALLBACK(gtk_main_quit),NULL);
 
  gtk_main();
  return 0;
}