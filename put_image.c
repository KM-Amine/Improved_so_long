/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:29:20 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/04 10:27:44 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <math.h>
#include <mlx.h>
#include <stdio.h>
#include <time.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_window;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
// int	main(void)
// {
// 	t_window	data;
// 	t_data img;
// 	int x = 1;
// 	int y = 1;

// 	// if(fork() == 0)
// 	// 	system("afplay /Users/mkhellou/Downloads/lifelike-126735.mp3");
// 	int i =0;
// 	//int j;
// 	//char	*addr;
// 	data.mlx_ptr = mlx_init();
// 	if (data.mlx_ptr == NULL)
// 		return (MLX_ERROR);
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT,"my window");
			// 	if (data.win_ptr == NULL)
			// 	{
			// 		free(data.win_ptr);
			// 		return (MLX_ERROR);
			// 	}
			// 	//img.img = mlx_new_image(data.mlx_ptr, 1920, 1080);
			// 	img.img = mlx_xpm_file_to_image(data.mlx_ptr,"./images/0.xpm",&x,&y);
			// 	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length,&img.endian);
			// 	while (i<10)
			// 	{
			// 		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img,
							x*i, 0);
							// 		mlx_put_image_to_window(data.mlx_ptr,
											data.win_ptr, img.img,
							0, y*i);
											// 		mlx_put_image_to_window(data.mlx_ptr,
											data.win_ptr, img.img,
							9*x, y*i);
											// 		mlx_put_image_to_window(data.mlx_ptr,
											data.win_ptr, img.img,
							x*i, 9*y);
											// 		i++;
											// 	}

											// 	mlx_loop(data.mlx_ptr);
											// 	free(data.mlx_ptr);
											// }
											// #include <mlx.h>

											// typedef struct	s_data {
											// 	void	*img;
											// 	char	*addr;
											// 	int		bits_per_pixel;
											// 	int		line_length;
											// 	int		endian;
											// }				t_data;
											// void	my_mlx_pixel_put(t_data *data,
														int x, int y,
										int color)
							// {
							// 	char	*dst;

							// 	int i = 0;
							// 	int j = 0;
							// 	while (i<500)
							// 	{
							// 		j = 0;
							// 		while (j<500)
							// 		{
							// 			dst = data->addr + ((y+j)
												* data->line_length + (x+i)
					* (data->bits_per_pixel / 8));
														// 			*(unsigned int*)dst = color;
														// 			j++;
														// 		}
														// 		i++;
														// 	}
														// }
														// 	void	*mlx;
														// 	void	*mlx_win;
														// 	t_data	img;

														// int	render(t_data *data)
														// {
														// 	/* if window has been destroyed,
							we don't want to put the pixel ! */
					// 	static int clock;
					// 	static float i;
					// 	static float j;
					// 	static int count;
					// 	(void)data;
					// 	if (i == 0)
					// 		i = 100;
					// 	if (clock % 3000 == 0)
					// 	{
					// 		if (count == 1)
					// 		{
					// 			//ft_printf("%d\n",count);
					// 			my_mlx_pixel_put(&img, 500, 500, 0x000000FF);
					// 			mlx_put_image_to_window(mlx, mlx_win, img.img,
										0, 0);
							// 			count = 0;
							// 		}
							// 		else if (count == 0)
							// 		{
							// 			//ft_printf("%d\n",count);
							// 			my_mlx_pixel_put(&img, 500, 500,
												0x00FF00FF);
												// 			mlx_put_image_to_window(mlx,
																	mlx_win,
												img.img,
										0, 0);
																	// 			count = 3;
																	// 		}
																	// 		else if (count == 3)
																	// 		{
																	// 			//ft_printf("%d\n",count);
																	// 			my_mlx_pixel_put(&img,
																	500,
															500, 0x00FF000);
																	// 			mlx_put_image_to_window(mlx,
															mlx_win, img.img,
										0, 0);
															// 			count = 1;
															// 		}
															// 	}
															// 	j++;
															// 	clock++;
															// 	//mlx_clear_window(mlx,mlx_win);
															// 	return (0);
															// }

															// int	main(void)
															// {

															// 	mlx = mlx_init();
															// 	mlx_win = mlx_new_window(mlx,
																		1920,
													1080,
								"Hello world!");
																		// 	img.img = mlx_new_image(mlx,
																1920, 1080);
																// 	img.addr = mlx_get_data_addr(img.img,
								&img.bits_per_pixel, &img.line_length,
					// 								&img.endian);
					// 	mlx_loop_hook(mlx, &render, NULL);
					// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
					// 	mlx_loop(mlx);
					// }

					// int	destr(int keycode, void *vars)
					// {
					// 	(void)keycode;
					// 	(void)vars;
					// 	exit(0);
					// 	return (0);
					// }
					//mlx_hook(mlx_win, 17,0, destr, mlx);

					// typedef struct	s_data {
					// 	void	*mlx;
					// 	void	*mlx_win;
					// }				t_data;

					// typedef struct s_data
					// {
					// 	void	*mlx_ptr;
					// 	void	*win_ptr;
					// }	t_data;

					// int	render_next_frame(void *data)
					// {
					// 	t_data *s = (t_data *)data;
					// 	int i = 0;
					// 	while (i < 1000)
					// 	{
					// 		if (i % 5000)
					// 			mlx_string_put(s->mlx,s->mlx_win,i,50,25555,"hello");
					// 		i++;
					// 	}
					// 	return (0);
					// }
					// int	handle_no_event(void *data)
					// {
					// 	static int i;
					// 	t_data *s = (t_data*)data;
					// 	i++;
					// 	mlx_string_put(s->mlx_ptr,s->win_ptr,i,1000,i,"hello");
					// 	return (0);
					// }
					// int main(void)
					// {
					// 	// void	*mlx;
					// 	// void	*mlx_win;
					// 	t_data data;

					// 	//void	*img;
					// 	// int i = 0;
					// 	// int j = 0;
					// 	// int k = 0;
					// 	// if(fork() == 0)
					// 	// 	system("afplay
									/Users/mkhellou/Downloads/lifelike-126735.mp3");

					// 		data.mlx_ptr = mlx_init();
					// 		/*if (!mlx)
					// 			exit(EXIT_FAILURE);*/
					// 		data.win_ptr = mlx_new_window(data.mlx_ptr, 1920,
									1080, "So_long");
								// 		/*if (!mlx_win)
								// 			exit(EXIT_FAILURE);*/
								// 		//i = 0;
								// 		// while(i < 1080)
								// 		// {
								// 		// 	j = 0;
								// 		// 	while (j < 1920)
								// 		// 	{
								// 		// 		mlx_pixel_put(mlx,mlx_win,j,i,k);
								// 		// 		k++;
								// 		// 		j++;
								// 		// 	}
								// 		// 	i++;
								// 		// }
								// 		mlx_loop_hook(data.win_ptr,
												&handle_no_event,
									&data);
												// 		mlx_loop(data.mlx_ptr);
												// }
												// #include <stdlib.h>
												// #include <stdio.h>
												// #include <math.h>

												// #include <mlx.h>

												// #define WINDOW_WIDTH 2560
												// #define WINDOW_HEIGHT 1440

												// #define MLX_ERROR 1

												// #define RED_PIXEL 0xFF0000

												// typedef struct s_data
												// {
												// 	void	*mlx_ptr;
												// 	void	*win_ptr;
												// }	t_data;

												// int	handle_keypress(int keysym,
												t_data *data)
									// {
									// 	if (keysym == 0)
									// 	{
									// 		mlx_destroy_window(data->mlx_ptr,
													data->win_ptr);
												// 		data->win_ptr = NULL;
												// 	}
												// 	return (0);
												// }
												// #include <time.h>
												// int	render(t_data *data)
												// {
												// 	/* if window has been destroyed,
									we don't want to put the pixel ! */
										// 	static int clock;
										// 	static float i;
										// 	static float j;
										// 	static int count;

										// 	if (i == 0)
										// 		i = 100;
										// 	mlx_clear_window(data->mlx_ptr,data->win_ptr);
										// 	if (clock % 30 ==0)
										// 	{
										// 		if (count == 1)
										// 		{
										// 			ft_printf("%d\n",count);
										// 			count = 0;
										// 		}
										// 		else if (count == 0)
										// 		{
										// 			ft_printf("%d\n",count);
										// 			count = 1;
										// 		}
										// 	}
										// 	if (count == 1)
										// 	{
										// 		mlx_string_put(data->mlx_ptr,data->win_ptr,fabs(cos(i)*WINDOW_WIDTH),j,0xFFF0F0,"hello");
										// 	}
										// 	else if (count == 0)
										// 	{
										// 		mlx_string_put(data->mlx_ptr,data->win_ptr,fabs(cos(i)*WINDOW_WIDTH),j,0xFFF0,"hello");
										// 	}
										// 	i+=0.019;
										// 	j++;
										// 	if (j == WINDOW_HEIGHT)
										// 		j = 0;
										// 	if (i == WINDOW_WIDTH)
										// 		i = 0;
										// 	if (cos(i) == WINDOW_HEIGHT)
										// 		i = 0;
										// 	clock++;
										// 	return (0);
										// }

										// int	main(void)
										// {
										// 	t_data	data;

										// 	data.mlx_ptr = mlx_init();
										// 	if (data.mlx_ptr == NULL)
										// 		return (MLX_ERROR);
										// 	data.win_ptr = mlx_new_window(data.mlx_ptr,
										WINDOW_WIDTH,
										WINDOW_HEIGHT,
										// 								"my window");
										// 	if (data.win_ptr == NULL)
										// 	{
										// 		free(data.win_ptr);
										// 		return (MLX_ERROR);
										// 	}

										// 	/* Setup hooks */
										// 	mlx_loop_hook(data.mlx_ptr, &render,
													&data);
									// 	mlx_hook(data.win_ptr, 0, 0,
													&handle_keypress, &data);

													// 	mlx_loop(data.mlx_ptr);

													// 	/* we will exit the loop if there's no window left,
										and execute this code * /
										// 	//mlx_destroy_display(data.mlx_ptr);
										// 	free(data.mlx_ptr);
										// }

										// int	jclose(int keycode,
													all_data *data)
										// {
										// 	(void)data;
										// 	ft_printf("%d",keycode);
										// 	simple_map_printer(data->mlx.mlx,data->mlx.mlx_win,data->img,data->map);
										// 	if (keycode == 53)
										// 	{
										// 		mlx_destroy_window(data->mlx.mlx,data->mlx.mlx_win);
										// 		//exit function
										// 	}
										// 	return (0);
										// }