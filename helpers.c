#include "helpers.h"
#include <math.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //get average
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

int cap(int value)
{
    return value > 255 ? 255 : value;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //used given formula
            int sepiaRed = cap(round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue));
            int sepiaGreen = cap(round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue));
            int sepiaBlue = cap(round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue));
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

void swap(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        //mid point is width / 2
        for (int j = 0; j < width / 2; j++)
        {
            //swap is a helper
            swap(&image[i][j], &image[i][width - 1 - j]);
        }
    }
    return;
}


RGBTRIPLE get_blurred_image(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int red, green, blue; 
    red = green = blue = 0;
    
    int numPixel = 0;
    
    //blur box
    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int new_i = i + di;
            int new_j = j + dj;
                    
            
            //checks if pixel is valid
            if (new_i >= 0 && new_i < height && new_j >= 0 && new_j < width)
            {
                numPixel++;
                red += image[new_i][new_j].rgbtRed;
                green += image[new_i][new_j].rgbtGreen;
                blue += image [new_i][new_j].rgbtBlue;
            }
        }
    }
    RGBTRIPLE blurred_pixel;
    //get the average within the blur box
    blurred_pixel.rgbtRed = round((float) red / numPixel);
    blurred_pixel.rgbtGreen = round((float) green / numPixel);
    blurred_pixel.rgbtBlue = round((float) blue / numPixel);
    return blurred_pixel;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //get_blurred_image is a helper
            new_image[i][j] = get_blurred_image(i, j, height, width, image);
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //replaces original pixels with blurred ones
            image[i][j] = new_image[i][j];
        }
    }
}
