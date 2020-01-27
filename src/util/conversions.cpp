#include "conversions.hpp"

FloatColour RGBtoFloats(int rgbColour) {
	// Get the ARGB colour channels out from the colour integer
	int a = rgbColour >> 24 & 0xff;
	int r = rgbColour >> 16 & 0xff;
	int g = rgbColour >> 8 & 0xff;
	int b = rgbColour & 0xff;

	FloatColour result;

	result.r = r / 255.0f;
	result.g = g / 255.0f;
	result.b = b / 255.0f;
	result.a = a / 255.0f;

	return result;
}