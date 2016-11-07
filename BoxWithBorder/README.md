Purpose
========

![Box with Border and gradient Backgound](BoxWithBorder.png "Box with Border and gradient Backgound")

The purpose of the Box widget, is to add options for Border and fill backgound gradient

TouchGFX Version
=================

This widget was created and tested using TouchGFX version 4.6.1

Functional description exemple
==============================

    // Set the Box position and size
	  Bbox.setPosition(10, 10, 300, 48);    
    // Set the Box border with ( 0 = No border )
	  Bbox.setBorder(1);    
    // Set the Box border color
	  Bbox.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    // Set the Box background start color for gradient fill mode
	  Bbox.setColor(touchgfx::Color::getColorFrom24BitRGB(3, 74, 114));
    // Set the Box background end color for gradient fill mode
          Bbox.setEndColor(touchgfx::Color::getColorFrom24BitRGB(2, 121, 180));
    // Set the Box background gradient fill mode as horizontaly
	  Bbox.setFillMode(BoxWithBorder::GRADIENT_H);
    // Add widget
	 add(Bbox);
