#include "selectable_table_view_with_background.h"
#include "app.h"
#include <apps/i18n.h>

#include <ion/timing.h>

#include "bg4.cpp"
#include "bg3.cpp"



SelectableTableViewWithBackground::SelectableTableViewWithBackground(Responder * parentResponder, TableViewDataSource * dataSource, BackgroundView * backgroundView, SelectableTableViewDataSource * selectionDataSource, SelectableTableViewDelegate * delegate) :
  SelectableTableView(parentResponder, dataSource, selectionDataSource, delegate),
  m_backgroundInnerView(this, backgroundView)
{

}
void SelectableTableViewWithBackground::drawRect( KDRect rect) const {
    load_img_lite2(bacgroind, 0, 0, 1,KDRect(0,0,320,240));
} 

void SelectableTableViewWithBackground::BackgroundInnerView::drawRect(KDContext * ctx, KDRect rect) const {
    load_img_lite2(bacgroind, 0, 0, 1,rect);
    //m_backgroundView->drawRect(ctx, rect);
}

void SelectableTableViewWithBackground::BackgroundInnerView::setBackgroundView(const uint8_t * data) {
    m_backgroundView->setBackgroundImage(data);
}