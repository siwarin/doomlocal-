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

void	drawsquare(t_sdl *sdl)
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
	drawsquare(sdl);
	sdl->fc.r = 0xFF;
	sdl->fc.g = 0xA5;
	sdl->fc.b = 0x00;
	sdl->fc.a = 0xFF;
	sdl->mes = TTF_RenderText_Solid(sdl->font, "Test", sdl->fc);
	if (sdl->mes == NULL)
		return ;
	apply_surface((WIDTH / 1.25) , 20, sdl->mes, sdl->ren);
}
