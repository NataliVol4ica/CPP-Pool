
#include "GtkGraphics.hpp"

IMonitorDisplay::~IMonitorDisplay() {}

GtkGraphics::GtkGraphics(int ac, char **av)
{
	mod2 = false;
	isSilly = false;
	srand(time(NULL));
	if ((ac == 3 && static_cast<std::string>(av[2]) == "-silly") ||
		(ac == 2 && static_cast<std::string>(av[1]) == "-silly"))
		isSilly = true;
	moduleInst.push_back(new UserInfoM());
	moduleInst.push_back(new OSInfoM());
	moduleInst.push_back(new TimeInfoM());
	moduleInst.push_back(new CPUInfoM());
	moduleInst.push_back(new RAMInfoM());
	moduleInst.push_back(new NETInfoM());
	moduleInst.push_back(new UnicornM());
	moduleNames = new std::string[moduleInst.size()];
	for (unsigned int i = 0; i < moduleInst.size(); i++)
		moduleNames[i] = moduleInst[i]->getName();
	gtk_init(&ac, &av);
	GtkWidget* label;
	GtkWidget* hiButton;
	GtkWidget* vbox;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL); //GTK_WINDOW_TOPLEVEL GTK_WINDOW_POPUP
	label = gtk_label_new("Hello");
	hiButton = gtk_button_new_with_label("Hi");
	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,  10); // spacing

	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(window), "Say hi");
	gtk_window_set_resizable(GTK_WINDOW(window), false);
	gtk_container_set_border_width(GTK_CONTAINER(window), 25);
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 150);

	g_signal_connect(window, "delete-event", G_CALLBACK(exit), NULL);
	g_signal_connect(hiButton, "clicked", G_CALLBACK(onHiButtonClickCostil), this);

	gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 5); //push from beginning .., expand, fill width, extra spacing
	gtk_box_pack_start(GTK_BOX(vbox), hiButton, 0, 0, 5);

	gtk_container_add(GTK_CONTAINER(window), vbox);

	provider = gtk_css_provider_new ();
}

GtkGraphics::~GtkGraphics(void){}

void		GtkGraphics::setNoExit(bool val) { this->notExit = val; }
GtkWidget**	GtkGraphics::getModules(void) const { return this->modules; }
std::string	GtkGraphics::getModuleName(unsigned int i) const { return this->moduleNames[i]; }

void	GtkGraphics::displayAll()
{
	setNoExit(true);
	gtk_widget_show_all(window);
	while (notExit)
	{
		gtk_main_iteration();
		if (mod2)
			update_labels();
	}
	gtk_window_close(GTK_WINDOW(window));
}

void	GtkGraphics::switchModeEvent() { this->notExit = !this->notExit; }

void	GtkGraphics::onHiButtonClick(void)
{
	cleanAfterHi();
	setMainPanel();
	setToggleContainer();
	setModuleContainer();

	/* FINAL */
	gtk_widget_show_all(window);
	for (int i = 0; i < NUMOFMODULES; i++)
		gtk_widget_hide(modules[i]);
	mod2 = true;
}
void	GtkGraphics::cleanAfterHi(void)
{
	toggles = new GtkWidget*[NUMOFMODULES];
	modules = new GtkWidget*[NUMOFMODULES];
	moduleStrings = new GtkWidget*[NUMOFMODULES];

	deleteHiWindowChildren();

	gtk_window_set_title(GTK_WINDOW(window), "I Forgot the Prog Name. It's too stupid to display anyway");
	gtk_widget_set_size_request(window, 500, 100 + 75 * NUMOFMODULES);

}

void	GtkGraphics::setMainPanel(void)
{
	/* MAIN PANEL */

	panel = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
	gtk_paned_set_position(GTK_PANED(panel), 50);
	gtk_paned_set_wide_handle(GTK_PANED(panel), true);
	gtk_container_add(GTK_CONTAINER(window), panel);
	//gtk_container_set_border_width(GTK_CONTAINER(panel), 10);

	/* LEFT GRID */
	leftGrid = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_paned_pack1(GTK_PANED(panel), leftGrid, false, false);

	/* RIGHT GRID */
	rightGrid = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_paned_pack2(GTK_PANED(panel), rightGrid, false, false);

	//backButton = gtk_button_new_with_label("Authors");
	//g_signal_connect(backButton, "clicked", G_CALLBACK(timeToExit), this);
}
void	GtkGraphics::setToggleContainer(void)
{
	/* TOGGLE CONTAINER */
	toggleFrame = gtk_frame_new(NULL);	
	templ = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(templ), "<span size=\"x-large\" foreground=\"#CC3300\"><b>    Modules: </b></span>");
	gtk_frame_set_label_widget(GTK_FRAME(toggleFrame), templ);

	gtk_frame_set_shadow_type(GTK_FRAME(toggleFrame), GTK_SHADOW_NONE);
	//gtk_widget_set_size_request(toggleFrame, 150, 300);
	gtk_box_pack_start(GTK_BOX(leftGrid), toggleFrame, 10, 10, 5);
	//gtk_box_pack_start(GTK_BOX(leftGrid), backButton, 10, 10, 5);
	toggleContainer = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
	gtk_container_add(GTK_CONTAINER(toggleFrame), toggleContainer);

	/* TOGGLE BUTTONS (LEFT) */
	for (int i = 0; i < NUMOFMODULES; i++)
	{
		toggles[i] = gtk_toggle_button_new_with_label(static_cast<const char*>(moduleNames[i].c_str()));
		gtk_box_pack_start(GTK_BOX(toggleContainer), toggles[i], 10, 10, 5);
		g_signal_connect(toggles[i], "clicked", G_CALLBACK(onToggleModule), this);
	}
}
void	GtkGraphics::setModuleContainer(void)
{
	/* MODULE CONTAINER */
	moduleFrame = gtk_frame_new(NULL);
	templ = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(templ), "<span size=\"x-large\" foreground=\"#CC3300\"><b>     Active Modules: </b></span>");
	gtk_frame_set_label_widget(GTK_FRAME(moduleFrame), templ);

	gtk_frame_set_shadow_type(GTK_FRAME(moduleFrame), GTK_SHADOW_NONE);
	gtk_box_pack_start(GTK_BOX(rightGrid), moduleFrame, 10, 10, 5);
	moduleContainer = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
	gtk_container_add(GTK_CONTAINER(moduleFrame), moduleContainer);

	/* MODULES */
	for (int i = 0; i < NUMOFMODULES; i++)
	{
		GtkWidget *templ = gtk_label_new(NULL);
		std::vector<GtkWidget*> temp;
		std::vector<std::string> info = moduleInst[i]->getInfo();

		modules[i] = gtk_frame_new(NULL);
		gtk_label_set_markup(GTK_LABEL(templ), static_cast<const char*>(("<span size=\"large\"foreground=\"#006622\"><b>" + moduleNames[i] + "</b></span>").c_str()));
		gtk_frame_set_label_widget(GTK_FRAME(modules[i]), templ);
		gtk_box_pack_start(GTK_BOX(moduleContainer), modules[i], 0, 0, 5);

		moduleStrings[i] = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
		gtk_container_add(GTK_CONTAINER(modules[i]), moduleStrings[i]);

		gtk_widget_hide(modules[i]);
		for (unsigned int j = 0; j < info.size(); j++)
		{
			GtkWidget *l;
			l = gtk_label_new(info[j].c_str());
			gtk_label_set_xalign (GTK_LABEL(l), 0.0);
			if (isSilly)
				gtk_label_set_angle(GTK_LABEL(l), rand()%360);
			temp.push_back(l);
			gtk_container_add(GTK_CONTAINER(moduleStrings[i]),l);
		}
		labels.push_back(temp);
	}
}

void	GtkGraphics::update_labels(void)
{
	for (unsigned int i = 0; i < moduleInst.size(); i++)
	{
		std::vector<std::string> info = moduleInst[i]->getInfo();
		for (unsigned int j = 0; j < info.size(); j++)
			gtk_label_set_text(GTK_LABEL(labels[i][j]), info[j].c_str());
	}
}

void	GtkGraphics::deleteHiWindowChildren(void)
{
	GList *children, *iter;
	children = gtk_container_get_children(GTK_CONTAINER(window));
	for(iter = children; iter != NULL; iter = g_list_next(iter))
		gtk_widget_destroy(GTK_WIDGET(iter->data));
	g_list_free(children);
}

/* SIGNAL FUNCS */

void	timeToExit(GtkWidget *widget, GtkGraphics* data)
{
	(void)widget;
	data->switchModeEvent();
}

void	onHiButtonClickCostil(GtkWidget *widget, GtkGraphics *data)
{
	(void)widget;
	data->onHiButtonClick();
}

void	onToggleModule(GtkToggleButton *widget, GtkGraphics *data){
	std::string label;
	GtkWidget**	modules = data->getModules();
	label = gtk_button_get_label(GTK_BUTTON(widget));
	for (int i = 0; i < NUMOFMODULES; i++)
		if (label == data->getModuleName(i))
		{
			if (gtk_toggle_button_get_active(widget))
				gtk_widget_show(modules[i]);
			else
				gtk_widget_hide(modules[i]);
		}
}
