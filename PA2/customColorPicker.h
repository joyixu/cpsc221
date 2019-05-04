/**
 * @file customColorPicker.h
 * Definition of a custom color picker.
 *
 */
#ifndef customCOLORPICKER_H
#define customCOLORPICKER_H

#include "colorPicker.h"

/**
 * customColorPicker: a functor that determines the color that should be used
 * given an x and a y coordinate. 
 **/
class customColorPicker : public colorPicker
{
  public:
    /**
     * Constructs a new customColorPicker.
     *
     * @param fillColor Color for the fill.
     */

    customColorPicker(HSLAPixel fillColor);

    /**
     * @param x The x coordinate to pick a color for.
     * @param y The y coordinat to pick a color for.
     * @return The color chosen for (x, y).
     */
    virtual HSLAPixel operator()(int x, int y);

  private:
    HSLAPixel color; 
};

#endif
