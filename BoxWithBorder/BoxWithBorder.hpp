/******************************************************************************
 *
 * @brief     This file is a Box widget for TouchGFX.
 *
 * @author    Fredlynx
 *
 ******************************************************************************/
#ifndef BOX_WITH_BORDER_HPP
#define BOX_WITH_BORDER_HPP

#include <touchgfx/hal/Types.hpp>
#include <touchgfx/widgets/Widget.hpp>
#include <touchgfx/Bitmap.hpp>
#include <touchgfx/lcd/LCD.hpp>

namespace touchgfx
{
/**
 * @class BoxWithBorder BoxWithBorder.hpp
 *
 * @brief Widget capable of showing a rectangle of a specific color/gradient with border and optional alpha.
 *
 *        Widget capable of showing a rectangle of a specific color/gradient with border
 *         and optional alpha.
 *
 */
class BoxWithBorder : public Widget
{
public:

	typedef enum
	{
		GRADIENT_NONE,   	///< An enum constant representing no gradient
		GRADIENT_H,			///< An enum constant representing gradient oriantation horizontal
		GRADIENT_V			///< An enum constant representing gradient oriantation vertical
	} gradient;
	
	/**
     * @fn BoxWithBorder::BoxWithBorder()
     *
     * @brief Constructor.
     *
     *        Constructs a new BoxWithBorder with a default alpha value of 255 (solid),
	 *		  white background, white border, border size 0 (no border) and fixe backgound.
     */
	BoxWithBorder() : Widget(), alpha(255), color(0), borderColor(0), border(0), fillMode(GRADIENT_NONE)
    {
    }

    /**
     * @fn BoxWithBorder::BoxWithBorder(uint16_t width, uint16_t height, colortype color, uint8_t alpha = 255)
     *
     * @brief Constructor.
     *
     *        Construct a BoxWithBorder.
     *
     * @param width  The width of the box.
     * @param height The height of the box.
     * @param color  The color of the box.
     * @param alpha  The alpha of the box. Default is 255 (solid).
     */
    BoxWithBorder(uint16_t width, uint16_t height, colortype color, uint8_t alpha = 255, uint8_t border = 0, gradient mode = GRADIENT_NONE) : Widget(),
        alpha(alpha), color(color), borderColor(color), border(border), fillMode(mode)
    {
        rect.width = width;
        rect.height = height;
    }

    /**
     * @fn virtual BoxWithBorder::~BoxWithBorder()
     *
     * @brief Destructor.
     *
     *        Destructor.
     */
    virtual ~BoxWithBorder() {}

    /**
     * @fn virtual touchgfx::Rect BoxWithBorder::getSolidRect() const;
     *
     * @brief Get the solid state of the box.
     *
     *        Get the solid state of the box.
     */
    virtual touchgfx::Rect BoxWithBorder::getSolidRect() const;

    /**
     * @fn void BoxWithBorder::setColor(colortype color)
     *
     * @brief Sets the background color of the rectangle.
     *
     *        Sets the background color of the rectangle.
     *
     * @param color The background color.
     */
    void setColor(colortype color)
    {
        this->color = color;
    }

    /**
     * @fn inline colortype BoxWithBorder::getColor() const
     *
     * @brief Gets the current color of the background.
     *
     *        Gets the current color of the background.
     *
     * @return The background current color.
     */
    inline colortype getColor() const
    {
        return color;
    }

	/**
	* @fn void BoxWithBorder::setEndColor(colortype color)
	*
	* @brief Sets the background End color of the rectangle in gradient mode.
	*
	*        Sets the background End color of the rectangle in gradient mode.
	*
	* @param color The End background color.
	*/
	void setEndColor(colortype color)
	{
		this->endColor = color;
	}

	/**
	* @fn inline colortype BoxWithBorder::getEndColor() const
	*
	* @brief Gets the background End color of the rectangle in gradient mode.
	*
	*        Gets the background End color of the rectangle in gradient mode.
	*
	* @return The End background current color.
	*/
	inline colortype getEndColor() const
	{
		return endColor;
	}

	/**
	* @fn void BoxWithBorder::setborderColor(colortype color)
	*
	* @brief Sets the border color of the rectangle.
	*
	*        Sets the border color of the rectangle.
	*
	* @param color The border color of the box.
	*/
	void setBorderColor(colortype color)
	{
		this->borderColor = color;
	}

	/**
	* @fn inline colortype BoxWithBorder::getBorderColor() const
	*
	* @brief Gets the current border color of the Box.
	*
	*        Gets the current border color of the Box.
	*
	* @return The current border color.
	*/
	inline colortype getBorderColor() const
	{
		return borderColor;
	}
	
	/**
	* @fn void BoxWithBorder::setFillMode(gradient mode)
	*
	* @brief Sets the background fill mode for this Box.
	*
	*        Sets background fill mode value for this Box.
	*
	* @param mode The background fill mode value. 0 = no gradient.
	*/
	void setFillMode(gradient mode)
	{
		this->fillMode = mode;
	}

	/**
	* @fn inline uint8_t BoxWithBorder::getFillMode() const
	*
	* @brief Returns the current background fill mode value.
	*
	* @return Gets the current fill mode value of the Box.
	*/
	inline gradient getFillMode() const
	{
		return fillMode;
	}

	/**
	* @fn void BoxWithBorder::setBorder(uint8_t border)
	*
	* @brief Sets the border value for this Box.
	*
	*        Sets the border value for this Box.
	*
	* @param border The border with value. 0 = no border.
	*/
	void setBorder(uint8_t border)
	{
		this->border = border;
	}

	/**
	* @fn inline uint8_t BoxWithBorder::getBorder() const
	*
	* @brief Returns the current border value.
	*
	* @return Gets the current border value of the Box.
	*/
	inline uint8_t getBorder() const
	{
		return border;
	}

	/**
     * @fn void BoxWithBorder::setAlpha(uint8_t alpha)
     *
     * @brief Sets the alpha value for this Box.
     *
     *        Sets the alpha value for this Box.
     *
     * @param alpha The alpha value. 255 = completely solid.
     */
    void setAlpha(uint8_t alpha)
    {
        this->alpha = alpha;
    }

    /**
     * @fn inline uint8_t BoxWithBorder::getAlpha() const
     *
     * @brief Returns the current alpha value.
     *
     * @return Gets the current alpha value of the Box.
     */
    inline uint8_t getAlpha() const
    {
        return alpha;
    }

    /**
     * @fn virtual void BoxWithBorder::draw(const Rect& area) const;
     *
     * @brief Draws the box.
     *
     *        Draws the Box.
     *
     * @param area The rectangle to draw, with coordinates relative to the containing layer.
     */
    virtual void draw(const Rect& area) const;

protected:
	uint8_t  border;        ///< The border with of the Box.
	uint8_t  alpha;         ///< The alpha value of the Box.
	gradient fillMode;		///< The fill method of the Box.
	colortype color;        ///< The fill color of the Box
	colortype endColor;     ///< The end fill color of the Box in gradiant mode
	colortype borderColor;  ///< The border color of the Box
};

} // namespace touchgfx

#endif // BOX_WITH_BORDER_HPP
