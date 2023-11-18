#ifndef READXLSX_H
#define READXLSX_H
#include <QVariant>

class ReadXlsx
{
public:
    ReadXlsx() = default;
   // QString fail;
//Document xlsxR(fail);
//ReadXlsx();
    // {
//Document xlsxR(fail);
 //   }
static QVariant Get_value(int row, int col);
static bool proverka(int row, int col);
        //  Cell *plmn_value = xlsxR.cellAt(row, 3);
//  ReadXlsx();

};


#endif // READXLSX_H
