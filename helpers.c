#include <math.h>
#include <stdio.h>
#include <cs50.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            float average = (round(red) + round(green) + round(blue)) / 3;
            average = round(average);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);

            {
                {
                    if(sepiaRed > 255)
                    {
                        image[i][j].rgbtRed = 255;
                    }
                    else
                    {
                        image[i][j].rgbtRed = sepiaRed;
                    }

                }
                {
                    if(sepiaGreen > 255)
                    {
                        image[i][j].rgbtGreen = 255;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = sepiaGreen;
                    }

                }
                {
                    if(sepiaBlue > 255)
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                    else
                    {
                        image[i][j].rgbtBlue = sepiaBlue;
                    }
                }
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width/2; j++)
        {
            temp[0] = image[i][j].rgbtRed;
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = temp[0];
            image[i][width - j - 1].rgbtGreen = temp[1];
            image[i][width - j - 1].rgbtBlue = temp[2];

        }
    }
    return;
}

// Blur image

bool valid_pixel(int i, int j, int height, int width)
{
    return i >= 0 && i < height && j >= 0 && j < width;
}

RGBTRIPLE get_blurred_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int redValue, greenValue, blueValue; redValue = greenValue = blueValue = 0;
    int numValidPixels = 0;
    for(int ni = -1; ni <= 1; ni++)
    {
       for(int nj = -1; nj <= 1; nj++)
       {
           int new_i = i + ni;
           int new_j = j + nj;
           if(valid_pixel(new_i, new_j, height, width))
           {
               numValidPixels++;
               redValue += image[new_i][new_j].rgbtRed;
               greenValue += image[new_i][new_j].rgbtGreen;
               blueValue += image[new_i][new_j].rgbtBlue;
           }
       }
    }
    RGBTRIPLE blurred_pixel;
    blurred_pixel.rgbtRed = round((float)redValue / numValidPixels);
    blurred_pixel.rgbtGreen = round((float)greenValue / numValidPixels);
    blurred_pixel.rgbtBlue = round((float)blueValue / numValidPixels);
    return blurred_pixel;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            new_image[i][j] = get_blurred_pixel(i, j, height, width, image);
        }
    }
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
        image[i][j] = new_image[i][j];
}
