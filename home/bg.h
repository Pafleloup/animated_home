
#ifndef BGrp
#define BGrp

#include <ion.h>

namespace Home {

class background 
{
public:
  void drac(char * liste[240]);
  int b62(char x);
  void load_img_lite(char* img, int x, int y, int s);
};

}

#endif

/** 
 * This is the controller. It allows you to add some logic when there are events like keys pressed... 
 * It follow an MVC pattern -> Model-View-Controller. The controller allows you to show some changes on the view like colors, results...
 * This file is linked to the C controller (sample_controler.cpp here). All files are linked -> app files.
**/