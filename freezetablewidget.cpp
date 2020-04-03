#include "freezetablewidget.h"



FreezeTableWidget::FreezeTableWidget(QAbstractItemModel * model)
{
      setModel(model);
      frozenTableView = new QTableView(this);

      init();

      //connect the headers and scrollbars of both tableviews together
      connect(horizontalHeader(),&QHeaderView::sectionResized, this,
              &FreezeTableWidget::updateSectionWidth);
      connect(verticalHeader(),&QHeaderView::sectionResized, this,
              &FreezeTableWidget::updateSectionHeight);

      connect(frozenTableView->verticalScrollBar(), &QAbstractSlider::valueChanged,
              verticalScrollBar(), &QAbstractSlider::setValue);
      connect(verticalScrollBar(), &QAbstractSlider::valueChanged,
              frozenTableView->verticalScrollBar(), &QAbstractSlider::setValue);

}


void FreezeTableWidget::init()
{
      frozenTableView->setModel(model());
      frozenTableView->setFocusPolicy(Qt::NoFocus);
      frozenTableView->verticalHeader()->hide();
      frozenTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

      viewport()->stackUnder(frozenTableView);
      frozenTableView->setStyleSheet("QTableView { border: none;"
                                        "background-color: #8EDE21;"
                                        "selection-background-color: #999}"); //for demo purposes
         frozenTableView->setSelectionModel(selectionModel());
         for (int col = 1; col < model()->columnCount(); ++col)
               frozenTableView->setColumnHidden(col, true);

         frozenTableView->setColumnWidth(0, columnWidth(0) );

         frozenTableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
         frozenTableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
         frozenTableView->show();

         updateFrozenTableGeometry();

         setHorizontalScrollMode(ScrollPerPixel);
         setVerticalScrollMode(ScrollPerPixel);
         frozenTableView->setVerticalScrollMode(ScrollPerPixel);
   }
void FreezeTableWidget::updateSectionWidth(int logicalIndex, int /* oldSize */, int newSize)
{
      if (logicalIndex == 0){
            frozenTableView->setColumnWidth(0, newSize);
            updateFrozenTableGeometry();
      }
}

void FreezeTableWidget::updateSectionHeight(int logicalIndex, int /* oldSize */, int newSize)
{
      frozenTableView->setRowHeight(logicalIndex, newSize);
}
void FreezeTableWidget::resizeEvent(QResizeEvent * event)
{
      QTableView::resizeEvent(event);
      updateFrozenTableGeometry();
 }
QModelIndex FreezeTableWidget::moveCursor(CursorAction cursorAction,
                                          Qt::KeyboardModifiers modifiers)
{
      QModelIndex current = QTableView::moveCursor(cursorAction, modifiers);

      if (cursorAction == MoveLeft && current.column() > 0
              && visualRect(current).topLeft().x() < frozenTableView->columnWidth(0) ){
            const int newValue = horizontalScrollBar()->value() + visualRect(current).topLeft().x()
                                 - frozenTableView->columnWidth(0);
            horizontalScrollBar()->setValue(newValue);
      }
      return current;
}
void FreezeTableWidget::updateFrozenTableGeometry()
{
      frozenTableView->setGeometry(verticalHeader()->width() + frameWidth(),
                                   frameWidth(), columnWidth(0),
                                   viewport()->height()+horizontalHeader()->height());
}

FreezeTableWidget::~FreezeTableWidget()
{

}
