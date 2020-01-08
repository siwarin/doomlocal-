/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editdraw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:23:14 by siwarin           #+#    #+#             */
/*   Updated: 2019/12/05 12:23:38 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Doom_Nukem.h"

void	drawmenu(t_sdl *sdl)
{
	sdl->color = BLACK;
	sdl->cy = 10;
	while (sdl->cy != HEIGTH - 10)
	{
		sdl->cx = 10;
		while (sdl->cx <= WIDTH / 1.5)
		{
			pixel(sdl, sdl->cx, sdl->cy);
			sdl->cx++;
		}
		sdl->cy++;
	}
	sdl->color = DARK_GRAY;
	sdl->cy = 10;
	while (sdl->cy != HEIGTH - 10)
	{
		sdl->cx = (WIDTH / 1.5) + 10;
		while (sdl->cx <= WIDTH - 10)
		{
			pixel(sdl, sdl->cx, sdl->cy);
			sdl->cx++;
		}
		sdl->cy++;
	}
}

void	drawsquare(t_sdl *sdl, int x, int y)
{
	int i;
	int j;

	sdl->color = GRAY;
	j = y;
	while (j != y + 30)
	{
		i = x;
		while (i != x + 30)
		{
			pixel(sdl, i, j);
			i++;
		}
		j++;
	}
}

void	editdraw(t_sdl *sdl)
{
	sdl->color = GRAY;
	sdl->cx = 0;
	while (sdl->cx != WIDTH)
	{
		sdl->cy = 0;
		while (sdl->cy != HEIGTH)
		{
			pixel(sdl, sdl->cx, sdl->cy);
			sdl->cy++;
		}
		sdl->cx++;
	}
	drawmenu(sdl);
	sdl->fc.r = 0xFF;
	sdl->fc.g = 0xA5;
	sdl->fc.b = 0x00;
	sdl->fc.a = 0xFF;
	sdl->mes = TTF_RenderText_Solid(sdl->font, "Map editor", sdl->fc);
	if (sdl->mes == NULL)
		return ;
	apply_surface((WIDTH / 1.45), 20, sdl->mes, sdl->ren);
	sdl->mes = TTF_RenderText_Solid(sdl->font, "Textures", sdl->fc);
	if (sdl->mes == NULL)
		return ;
	apply_surface((WIDTH / 1.45), 65, sdl->mes, sdl->ren);
	sdl->mes = TTF_RenderText_Solid(sdl->font, "Items", sdl->fc);
	if (sdl->mes == NULL)
		return ;
	apply_surface((WIDTH / 1.45), 165, sdl->mes, sdl->ren);
	sdl->mes = TTF_RenderText_Solid(sdl->font, "Ennemies", sdl->fc);
	if (sdl->mes == NULL)
		return ;
	apply_surface((WIDTH / 1.45), 265, sdl->mes, sdl->ren);

	drawsquare(sdl, WIDTH / 1.45, 100);
	drawsquare(sdl, (WIDTH / 1.45) + 86, 100);
	drawsquare(sdl, (WIDTH / 1.45) + 172, 100);
	drawsquare(sdl, (WIDTH / 1.45) + 258, 100);
	drawsquare(sdl, (WIDTH / 1.45) + 344, 100);
	drawsquare(sdl, (WIDTH / 1.45) + 430, 100);
	drawsquare(sdl, (WIDTH / 1.45) + 516, 100);

	drawsquare(sdl, WIDTH / 1.45, 205);
	drawsquare(sdl, (WIDTH / 1.45) + 86, 205);
	drawsquare(sdl, (WIDTH / 1.45) + 172, 205);
	drawsquare(sdl, (WIDTH / 1.45) + 258, 205);
	drawsquare(sdl, (WIDTH / 1.45) + 344, 205);
	drawsquare(sdl, (WIDTH / 1.45) + 430, 205);
	drawsquare(sdl, (WIDTH / 1.45) + 516, 205);

	drawsquare(sdl, WIDTH / 1.45, 310);
	drawsquare(sdl, (WIDTH / 1.45) + 86, 310);
	drawsquare(sdl, (WIDTH / 1.45) + 172, 310);
	drawsquare(sdl, (WIDTH / 1.45) + 258, 310);
	drawsquare(sdl, (WIDTH / 1.45) + 344, 310);
	drawsquare(sdl, (WIDTH / 1.45) + 430, 310);
	drawsquare(sdl, (WIDTH / 1.45) + 516, 310);
}
