#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)    // Loop through each pixel
    {
        for (int j = 0 ; j < width; j++)    // i for height, and j for width
        {
            int b = image[i][j].rgbtBlue;   // Get int for colors
            int g = image[i][j].rgbtGreen;  // from RGBTRIPPLE structure
            int r = image[i][j].rgbtRed;    // members
            int gray = round(((float)b + (float)g + (float)r) / 3);   // Get average of pixel values
            image[i][j].rgbtBlue = gray;     // Set structure members to
            image[i][j].rgbtGreen = gray;    // value of avg
            image[i][j].rgbtRed = gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)    // Loop through each pixel
    {
        for (int j = 0 ; j < width; j++)    // i for height, and j for width
        {
            int b = image[i][j].rgbtBlue;   // Get int for colors
            int g = image[i][j].rgbtGreen;  // from RGBTRIPPLE structure
            int r = image[i][j].rgbtRed;    // members
            int s_r = round((float)(b * .189) + (float)(g * .769) + (float)(r * .393));   // Sepia shift
            if (s_r > 255)
            {
                s_r = 255;
            }
            int s_g = round((float)(b * .168) + (float)(g * .686) + (float)(r * .349));   // for rgb
            if (s_g > 255)
            {
                s_g = 255;
            }
            int s_b = round((float)(b * .131) + (float)(g * .534) + (float)(r * .272));  // colors
            if (s_b > 255)
            {
                s_b = 255;
            }
            image[i][j].rgbtBlue = s_b;     // Set structure members to new value
            image[i][j].rgbtGreen = s_g;
            image[i][j].rgbtRed = s_r;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)    // Loop through each pixel
    {                                   // k keeps the relection from undoing itself once the loop reaches the center
        for (int j = 0, k = width / 2; j < k; j++)    // i for height, and j for width
        {
            int swap_b = image[i][j].rgbtBlue;      // First pixel to swap
            int swap_g = image[i][j].rgbtGreen;
            int swap_r = image[i][j].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue; // last pixel to first stopping before the center
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;;
            image[i][width - j - 1].rgbtBlue = swap_b;    // Swap to last pixel
            image[i][width - j - 1].rgbtGreen = swap_g;
            image[i][width - j - 1].rgbtRed = swap_r;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float count;
    int blr_b;
    int blr_g;
    int blr_r;
    RGBTRIPLE temp_image[height][width];
    for (int i = 0; i < height; i++)        // Loop through each pixel
    {
        for (int j = 0; j < width; j++)
        {
            blr_b = 0;
            blr_g = 0;
            blr_r = 0;
            count = 0;
            for (int k = -1; k <= 1; k++)  // Loop through 3X3 "box" to blur
            {
                for (int n = -1; n <= 1; n++) // centered on the pixel in focus
                {
                    if (i + k < 0 || i + k >= height)   // making sure the surrounding
                    {
                        continue;
                    }
                    if (j + n < 0 || j + n >= width)    // pixels are within the boarders of the picture
                    {
                        continue;
                    }
                    count++;    // For getting the average
                    blr_b += image[i + k][j + n].rgbtBlue;   // Get int for surronding colors
                    blr_g += image[i + k][j + n].rgbtGreen;  // kepping a running total
                    blr_r += image[i + k][j + n].rgbtRed;

                }
            }
            temp_image[i][j].rgbtBlue = round(blr_b / count);   // Write new colors, avg of values
            temp_image[i][j].rgbtGreen = round(blr_g / count);  // to temp image
            temp_image[i][j].rgbtRed = round(blr_r / count);
        }
    }
    for (int i = 0; i < height; i++)    // write temp image to image
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp_image[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp_image[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp_image[i][j].rgbtRed;
        }
    }
    return;
}
