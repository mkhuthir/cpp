#include <gtk/gtk.h>


static void printButton1 (GtkWidget *widget, gpointer data)
{
  g_print ("Clicked Button 1\n");
}

//-------------------------------------------------------------------------------

static void printButton2 (GtkWidget *widget, gpointer data)
{
  g_print ("Clicked Button 2\n");
}

//-------------------------------------------------------------------------------

int main (int argc, char *argv[])
{
  GtkBuilder *builder;
  GObject *window;
  GObject *button;

  gtk_init (&argc, &argv);

  /* Construct a GtkBuilder instance and load our UI description */
  builder = gtk_builder_new ();
  gtk_builder_add_from_file (builder, "res/builder.ui", NULL);

  /* Connect signal handlers to the constructed widgets. */
  window = gtk_builder_get_object (builder, "window");
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  button = gtk_builder_get_object (builder, "button1");
  g_signal_connect (button, "clicked", G_CALLBACK (printButton1), NULL);

  button = gtk_builder_get_object (builder, "button2");
  g_signal_connect (button, "clicked", G_CALLBACK (printButton2), NULL);

  button = gtk_builder_get_object (builder, "quit");
  g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);

  gtk_main ();

  return 0;
}

//-------------------------------------------------------------------------------
