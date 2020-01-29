#pragma once

#include <string>

class Image {
public:
    Image(const std::string& path);
    ~Image();
private:
    void loadImage(const std::string& fileBuffer);
public:
    unsigned char* getPixels() const { return m_Image; }
    int getWidth() const { return m_Width; }
    int getHeight() const { return m_Height; }
    int getBitDepth() const { return m_BitDepth; }
private:
    unsigned char* m_Image;
    int m_Width;
    int m_Height;
    int m_BitDepth;
};