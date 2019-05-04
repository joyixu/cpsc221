#include "borderColorPicker.h"
#include <cmath>

borderColorPicker::borderColorPicker(HSLAPixel fillColor, PNG & img, double tolerance,HSLAPixel center)
{
/* Your code here! */
    color = fillColor;
    im = img;
    tol = tolerance;
    ctr = center;
}

HSLAPixel borderColorPicker::operator()(int x, int y)
{

/* Your code here! 
     * Picks the color for pixel (x, y). If the x or y coordinate is 
     * near the border of the fill, or the border of the image, 
     * the fillColor will be returned.
     * Otherwise, the current color of (x,y) will be returned.
     *
     * @param x The x coordinate to pick a color for.
     * @param y The y coordinat to pick a color for.
     * @return The color chosen for (x, y).
     */
    for (int a = x-3; a <= x+3; a++) {
        for (int b = y-3; b <= y+3; b++) {
            HSLAPixel pixel = *im.getPixel(a, b);
            if(pixel.dist(ctr) > tol || a>im.width() || a<0 || b>im.height() || b<0)
                return color;
                else
                return pixel;
        }
    }
}

/* 
    for (int a = 0; a <= (int)im.width(); a++) {
        for (int b = 0; b <= (int)im.height(); b++){
            HSLAPixel *curr = im.getPixel(a,b);
            if (center->dist(*curr) <= tol)
            {
                if (pow(x-a, 2) + pow(y-b, 2) <= pow(3, 2)
            }
                return color;
            else {
                HSLAPixel original = *curr;
//                cout << "4";
                return original;
            }
        }
    }
}
 */