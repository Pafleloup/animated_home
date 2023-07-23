#include "app.h"
#include <apps/i18n.h>
#include "bg.h"
#include <ion/timing.h>
#include "bg2.cpp"


extern "C" {
#include <assert.h>
}

namespace Home {

I18n::Message App::Descriptor::name() {
  return I18n::Message::Apps;
}

I18n::Message App::Descriptor::upperName() {
  return I18n::Message::AppsCapital;
}

App * App::Snapshot::unpack(Container * container) {
  return new (container->currentAppBuffer()) App(this);
}

App::Descriptor * App::Snapshot::descriptor() {
  static Descriptor descriptor;
  return &descriptor;
}

void App::didBecomeActive(Window * window) {
  ::App::didBecomeActive(window);
  m_window = window;
  Ion::Timing::msleep(400);
  background c;
  for(int i=0;i<13;i++){
    c.load_img_lite(liste[i],0,0,1);
    Ion::Timing::msleep(40);
  }
  Ion::Timing::msleep(40);
  Ion::Timing::msleep(40);
  m_window->redraw(true);
  
}

void App::leave(){
  background c;
  
  Ion::Timing::msleep(40);
  Ion::Timing::msleep(40);
}

void App::redraw() {
  m_window->redraw(true);
}

App::App(Snapshot * snapshot) :
  ::App(snapshot, &m_controller, I18n::Message::Warning),
  m_controller(&m_modalViewController, snapshot, this)
{
  //AppsContainer::sharedAppsContainer()->addTimer(&m_Controller);
}

}
