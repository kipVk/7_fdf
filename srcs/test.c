#include "fdf.h"

int main()
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Create Image");

	void *image = mlx_new_image(mlx, 340, 160);

	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);

	int color = 0x00FFFF;

	if (pixel_bits != 32)
		color = mlx_get_color_value(mlx, color);

	for(int y = 50; y < 160; ++y)
	for(int x = 50; x < 340; ++x)
	{
		int pixel = (y * line_bytes) + (x * 4);

		if (endian == 1)        // Most significant (Alpha) byte first
		{
			buffer[pixel + 0] = (color >> 24);
			buffer[pixel + 1] = (color >> 16) & 0xFF;
			buffer[pixel + 2] = (color >> 8) & 0xFF;
			buffer[pixel + 3] = (color) & 0xFF;
		}
		else if (endian == 0)   // Least significant (Blue) byte first
		{
			buffer[pixel + 0] = (color) & 0xFF;
			buffer[pixel + 1] = (color >> 8) & 0xFF;
			buffer[pixel + 2] = (color >> 16) & 0xFF;
			buffer[pixel + 3] = (color >> 24);
		}
	}

	mlx_put_image_to_window(mlx, win, image, 0, 0);
	mlx_loop(mlx);
}