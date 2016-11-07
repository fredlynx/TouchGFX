/******************************************************************************
*
* @brief     This file is a Box widget for TouchGFX.
*
* @author    Fredlynx
*
******************************************************************************/

#include <gui\common\BoxWithBorder.hpp>


/**
 * @fn touchgfx::Rect BoxWithBorder::getSolidRect() const;
 *
 * @brief Get the solid state of the box.
 *
 *        Get the solid state of the box.
 */
touchgfx::Rect touchgfx::BoxWithBorder::getSolidRect() const
{
	return (alpha != 255) ? touchgfx::Rect() : touchgfx::Rect(0, 0, getWidth(), getHeight());
}

/**
 * @fn void BoxWithBorder::draw(const Rect& area) const;
 *
 * @brief Draws the box.
 *
 *        Draws the Box.
 *
 * @param area The rectangle to draw, with coordinates relative to the containing layer.
 */
void touchgfx::BoxWithBorder::draw(const touchgfx::Rect& invalidatedArea) const
{
	touchgfx::Rect absolute = getAbsoluteRect();
	touchgfx::colortype newColor;
	touchgfx::colortype backColor;
	bool inBorder;
	uint8_t out_r, out_g, out_b;
	uint16_t *framebuffer = touchgfx::HAL::getInstance()->lockFrameBuffer();

	for (int y = invalidatedArea.y; y < invalidatedArea.bottom(); y++)
	{
		for (int x = invalidatedArea.x; x < invalidatedArea.right(); x++)
		{
			inBorder = false;
			newColor = color;
			// Manage border color
			if (border != 0)
			{
				if ((y < (invalidatedArea.y+ border)) || \
					(y >= (invalidatedArea.bottom() - border)) || \
					(x < (invalidatedArea.x + border)) || \
					(x >= (invalidatedArea.right() - border)))
				{
					inBorder = true;
					newColor = borderColor;
				}
			}
			// Gradient compute color if out of border and fill gradient active
			if ((fillMode != GRADIENT_NONE) && (!inBorder))
			{
				if (fillMode != GRADIENT_H)
				{
					out_r = ((color >> 11)  * (x - invalidatedArea.x) + (endColor >> 11) * (invalidatedArea.right() - x)) / (invalidatedArea.right() - invalidatedArea.x);
					out_g = (((color >> 5) & ((1u << 6) - 1))  * (x - invalidatedArea.x) + ((endColor >> 5) & ((1u << 6) - 1)) * (invalidatedArea.right() - x)) / (invalidatedArea.right() - invalidatedArea.x);
					out_b = ((color & ((1u << 5) - 1))  * (x - invalidatedArea.x) + (endColor & ((1u << 5) - 1)) * (invalidatedArea.right() - x)) / (invalidatedArea.right() - invalidatedArea.x);
				}
				else
				{
					out_r = ((color >> 11)  * (y - invalidatedArea.y) + (endColor >> 11) * (invalidatedArea.bottom() - y)) / (invalidatedArea.bottom() - invalidatedArea.y);
					out_g = (((color >> 5) & ((1u << 6) - 1))  * (y - invalidatedArea.y) + ((endColor >> 5) & ((1u << 6) - 1)) * (invalidatedArea.bottom() - y)) / (invalidatedArea.bottom() - invalidatedArea.y);
					out_b = ((color & ((1u << 5) - 1))  * (y - invalidatedArea.y) + (endColor & ((1u << 5) - 1)) * (invalidatedArea.bottom() - y)) / (invalidatedArea.bottom() - invalidatedArea.y);
				}
				newColor = ((out_r << 11) | (out_g << 5) | out_b);
			}
			// Alpha compute color if alpha mode active 
			if (alpha != 255)
			{
				backColor = framebuffer[absolute.x + x + (absolute.y + y) * touchgfx::HAL::DISPLAY_WIDTH];
				out_r = ((newColor >> 11) * alpha + (backColor >> 11) * (255 - alpha)) / 255;
				out_g = (((newColor >> 5) & ((1u << 6) - 1)) * alpha + ((backColor >> 5) & ((1u << 6) - 1)) * (255 - alpha)) / 255;
				out_b = ((newColor & ((1u << 5) - 1)) * alpha + (backColor & ((1u << 5) - 1)) * (255 - alpha)) / 255;
				newColor = ((out_r << 11) | (out_g << 5) | out_b);
			}
			framebuffer[absolute.x + x + (absolute.y + y) * touchgfx::HAL::DISPLAY_WIDTH] = newColor;
		}
	}
	touchgfx::HAL::getInstance()->unlockFrameBuffer();
}
