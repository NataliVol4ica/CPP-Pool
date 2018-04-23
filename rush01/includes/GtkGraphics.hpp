
#ifndef GTKGRAPHICS_HPP
# define GTKGRAPHICS_HPP

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "UserInfoM.hpp"
#include "OSInfoM.hpp"
#include "TimeInfoM.hpp"
#include "CPUInfoM.hpp"
#include "RAMInfoM.hpp"
#include "NETInfoM.hpp"
#include "UnicornM.hpp"

#include <iostream>
#include <ctime>

#include <gtk/gtk.h>
#include <vector>

#define NUMOFMODULES 7

class GtkGraphics : public IMonitorDisplay
{
public:
	GtkGraphics(int ac, char **av);
	~GtkGraphics(void);
	
	void		setNoExit(bool val);
	GtkWidget**	getModules(void) const;
	std::string	getModuleName(unsigned int i) const;

	void	displayAll();
	void	switchModeEvent();
	void	onHiButtonClick(void);

private:
	std::string *moduleNames;
	std::vector<IMonitorModule*> moduleInst;
	std::vector<std::vector<GtkWidget*> > labels;
	bool	mod2; //if quited hi window
	bool	isSilly; //silly random mode
	bool	notExit; // if i want to switch to console mod
	GtkWidget* window;
	GtkWidget *templ; //temp label
    GtkCssProvider *provider;
	/* window elements */
	GtkWidget* 	panel;
	
	GtkWidget*		leftGrid;
	GtkWidget*			toggleFrame;
	GtkWidget*			toggleContainer;
	GtkWidget**			toggles;
	//GtkWidget*		backButton;
	
	GtkWidget*		rightGrid;
	GtkWidget*			moduleFrame;
	GtkWidget*			moduleContainer;
	GtkWidget**			modules;
	GtkWidget**				moduleStrings;

	GtkGraphics(void);
	GtkGraphics(GtkGraphics const &ref);
	GtkGraphics &operator=(GtkGraphics const &ref);
	
	void	update_labels(void);
	void	deleteHiWindowChildren(void);

	void	cleanAfterHi(void);
	void	setMainPanel(void);
	void	setToggleContainer(void);
	void	setModuleContainer(void);

};

/* SIGNAL FUNCS */

void	timeToExit(GtkWidget *widget, GtkGraphics* data);
void	onHiButtonClickCostil(GtkWidget *widget, GtkGraphics *data);
void	onToggleModule(GtkToggleButton *widget, GtkGraphics *data);

#endif
