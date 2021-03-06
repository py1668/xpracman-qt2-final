/***************************************************************************
              mreportsection.h  -  Kugar report section
              -------------------
    begin     : Mon Aug 23 1999                                           
    copyright : (C) 1999 by Mutiny Bay Software                         
    email     : info@mutinybaysoftware.com                                     
 ***************************************************************************/

#ifndef MREPORTSECTION_H
#define MREPORTSECTION_H

#include <qlist.h>
#include <qobject.h>

#include "mlineobject.h"
#include "mlabelobject.h"
#include "mspecialobject.h"
#include "mcalcobject.h"

/**Kugar report section
  *@author Mutiny Bay Software
  */

class MReportSection : public QObject  {

public:
  /** Section print frequency constants */
  enum PrintFrequency { FirstPage = 0, EveryPage, LastPage };

  /** Constructor */
	MReportSection();
  /** Copy constructor */
  MReportSection(const MReportSection& mReportSection);
  /** Assignment operator */
  MReportSection operator=(const MReportSection& mReportSection);
  /** Destructor */
	virtual ~MReportSection();

protected:
  /** Sections's height */
  int height;
  /** Section print frequency */
  int frequency;
  /** Page number - used by special fields */
  int pageNumber;
  /** Report date - used by special fields */
  QDate reportDate;

	/** Section's line collection */
  QList<MLineObject> lines;
  /** Section's label collection */
  QList<MLabelObject> labels;
  /** Section's special field collection */
  QList<MSpecialObject> specialFields;
  /** Section's calculated field collection */
  QList<MCalcObject> calculatedFields;

public:
	/** Adds a new line object to the section's line collection */
  void addLine(MLineObject* line);
  /** Adds a new label object to the section's label collection */
  void addLabel(MLabelObject* label);
  /** Adds a new special field object to the section's special field collection */
  void addSpecialField(MSpecialObject* special);
  /** Adds a new calculated field object to the section's calculated field collection */
  void addCalculatedField(MCalcObject* calc);
  /** Sets the height of the section */
  void setHeight(int h);
  /** Gets the height of the section */
  int getHeight();
  /** Set the current page number - used by special fields */
  void setPageNumber(int page);
  /** Set the current date - used by special fields */
  void setReportDate(QDate date);
  /** Sets the print frequency of the section */
  void setPrintFrequency(int printFrequency);
  /** Returns the print frequency of the section */
  int printFrequency();
  /** Returns the name of the bound field for the calculated field object at the given index */
  QString getCalcFieldName(int idx);
  /** Returns the index of the calculated field object for the given bound field */
  int getCalcFieldIndex(QString field);
  /** Sets the data for the specified calculated field */
  void setCalcFieldData(int idx, QString data);
  /** Sets the data for the all calculated fields - list size must match number of calculated fields */
  void setCalcFieldData(QList<QArray<double> >* values);
  /** Returns the number of calculated fields in the section */
  int getCalcFieldCount();
  /** Draws the section to the specified painter & x/y-offsets */
  virtual void draw(QPainter* p, int xoffset, int yoffset);
  /** Frees all resources allocated by the report section */
  virtual void clear();

protected:
  /** Frees base resources allocated by the report section */
  void clearBase();
  /** Draws the section base objects to the specified painter & x/y offsets */
  void drawObjects(QPainter* p, int xoffset, int yoffset);

private:
  /** Copies member data from one object to another.
    * Used by the copy constructor and assignment operator
    */
  void copy(const MReportSection* mReportSection);

};

#endif






























































