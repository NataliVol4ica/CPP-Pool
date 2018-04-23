#include "GtkGraphics.hpp"

int		gtk_main(int ac, char **av)
{
	static GtkGraphics *gtkDraw = new GtkGraphics(ac, av);
	gtkDraw->displayAll();
	return 0;
}
