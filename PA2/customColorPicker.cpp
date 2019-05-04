#include "customColorPicker.h"

customColorPicker::customColorPicker(HSLAPixel fillColor)
{
/* Your code here! */
    color = fillColor;
}

HSLAPixel customColorPicker::operator()(int x, int y)
{
    return color;
}
