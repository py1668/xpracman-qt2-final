/***************************************************************************
              mlabelobject.cpp  -  Kugar report label object
              -------------------
    begin     : Wed Aug 11 1999
    copyright : (C) 1999 by Mutiny Bay Software
    email     : info@mutinybaysoftware.com
 ***************************************************************************/

#include <qregexp.h>
#include "mlabelobject.h"

/** Constructor */
MLabelObject::MLabelObject() : MReportObject(), xMargin(0), yMargin(0){
  // Set the default label text
  text = "";

  // Set the default font
  fontFamily = "times";
  fontSize = 10;
  fontWeight = MLabelObject::Normal;
  fontItalic = false;

  // Set the default alignment
  hAlignment = MLabelObject::Left;
  vAlignment = MLabelObject::Top;
  wordWrap = false;
}

/** Copy constructor */
MLabelObject::MLabelObject(const MLabelObject& mLabelObject): MReportObject((MReportObject &) mLabelObject), xMargin(0), yMargin(0) {
  copy(&mLabelObject);	
}

/** Assignment operator */
MLabelObject MLabelObject::operator=(const MLabelObject& mLabelObject){
  if(&mLabelObject == this) return *this;

  // Copy the derived class's data
  copy(&mLabelObject);

  // Copy the base class's data
  ((MReportObject &) *this) = mLabelObject;

	return *this;
}

/** Destructor */
MLabelObject::~MLabelObject(){
}

/** Sets the label's text string */
void MLabelObject::setText(const QString txt){
  text = txt;
}

/** Sets the label's text font */
void MLabelObject::setFont(const QString family, int size, int weight, bool italic){
  fontFamily = family;
  fontSize = size;
  fontWeight = weight;
  fontItalic = italic;
}

/** Sets the label's horizontal alignment */
void MLabelObject::setHorizontalAlignment(int a){
  hAlignment = a;
}

/** Sets the label's vertical alignment */
void MLabelObject::setVerticalAlignment(int a){
  vAlignment = a;
}

/** Sets the label's word wrap flag */
void MLabelObject::setWordWrap(bool state){
  wordWrap = state;
}

/** Draws the label using the specificed painter & x/y-offsets */
void MLabelObject::draw(QPainter* p, int xoffset, int yoffset){
    QFont font(fontFamily, fontSize, fontWeight, fontItalic);
    QPen textPen(foregroundColor, 0, QPen::NoPen);

    int tf;

        // Set the offsets
    int xcalc = xpos + xoffset;
    int ycalc = ypos + yoffset;

        // Draw the base
    drawBase(p, xoffset, yoffset);

        // Set the font
    p->setFont(font);
    QFontMetrics fm = p->fontMetrics();

        // Set the text alignment flags

        // Horizontal
    switch(hAlignment){
        case MLabelObject::Left:
            tf = QPainter::AlignLeft;
            break;
        case MLabelObject::Center:
            tf = QPainter::AlignHCenter;
            break;
        case MLabelObject::Right:
	    tf = QPainter::AlignRight;
    }

        // Vertical
    switch(vAlignment){
        case MLabelObject::Top:
            tf = tf | QPainter::AlignTop;
            break;
        case MLabelObject::Bottom:
            tf = tf | QPainter::AlignBottom;
            break;
        case MLabelObject::Middle:
	    tf = tf | QPainter::AlignVCenter;
    }

        // Word wrap
    if(wordWrap) tf = tf | QPainter::WordBreak;

        // Draw the text
    p->setPen(textPen);
    QString newtext = text;
    newtext.replace( QRegExp( "<br>", false ), QString( "\n" ) );
    p->drawText(xcalc + xMargin, ycalc + yMargin,
                width - xMargin, height - yMargin,
                tf, newtext);

        // leave this in place - possible use for other tags
        //
//          // ----------------------------------------
//          // look for line breaks (<br>)
//          // ----------------------------------------

//      int idx = 0;
//      int ysub = ycalc;
//      int line_height = height;
//      int len = text.length();
//      int line_len = len;
//      QString sep = "<br>";
//      int len_sep = sep.length();
//      while ( idx < len )
//      {
//          int eol = text.find( sep, idx, FALSE );
//          if ( eol < 0 )
//              eol = len;
        
//          line_len = eol - idx;

//              // draw the line and determine the space used.
//          QRect brect = p->boundingRect(xcalc + xMargin, ysub + yMargin,
//                                        width - xMargin, line_height - yMargin,
//                                        tf, text.mid( idx, line_len ), line_len);
//          p->drawText( xcalc + xMargin, ysub + yMargin,
//                       width - xMargin, line_height - yMargin,
//                       tf, text.mid( idx, line_len ), line_len );

//              // substract the vert space used.
//          ysub += brect.height();
//          line_height -= brect.height();
        
//              // nothing more
//          if ( eol == len )
//              break;
//          else
//              idx = eol + len_sep;
//      }
}

/** Copies member data from one object to another.
      Used by the copy constructor and assignment operator */
void MLabelObject::copy(const MLabelObject* mLabelObject){
  // Copy the label's text
	text = mLabelObject->text;

  // Copy the label's font data
  fontFamily =  mLabelObject->fontFamily;
  fontSize = mLabelObject->fontSize;
  fontWeight = mLabelObject->fontWeight;
  fontItalic = mLabelObject->fontItalic;

  // Copy the label's alignment data
  vAlignment = mLabelObject->vAlignment;
  hAlignment = mLabelObject->hAlignment;
  wordWrap = mLabelObject->wordWrap;
}











































