/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:12:50 by cduverge          #+#    #+#             */
/*   Updated: 2019/12/04 13:29:36 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Doom_Nukem.h"

int		hook_keydown(t_sdl *sdl)
{
	int		y;

	y = 0;
	//SDL_FreeSurface(sdl->mes);
	SDL_FreeSurface(sdl->ren);
	SDL_DestroyWindow(sdl->win);
	TTF_CloseFont(sdl->font);
	TTF_Quit();
	SDL_Quit();
	/*while (y < sdl->y_max)
	{
		free(sdl->map[y]);
		++y;
	}
	free(sdl->map);
	sdl->map = NULL;*/
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_init(t_sdl *sdl) // fonction d'init de SDL avec protection
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		ft_putstr(SDL_GetError());
		ft_putstr("\n\n");
	}
	sdl->win = SDL_CreateWindow("Doom-Nukem", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGTH, 0);
	if (!sdl->win)
	{
		ft_putstr(SDL_GetError());
		ft_putstr("\n\n");
	}
	if ((sdl->ren = SDL_GetWindowSurface(sdl->win)) == NULL)
	{
		ft_putstr(SDL_GetError());
		ft_putstr("Surface error.\n");
	}
	if ((sdl->mes = SDL_GetWindowSurface(sdl->win)) == NULL)
	{
		ft_putstr(SDL_GetError());
		ft_putstr("Surface error.\n");
	}
	sdl->k.state = SDL_GetKeyboardState(NULL);
	if (TTF_Init() == -1)
	{
		ft_putstr(SDL_GetError());
		ft_putstr("TTF Error.\n");
	}
	sdl->font = TTF_OpenFont("./font/tf2build.ttf", 31);
	if (!sdl->font)
		printf("TTF_OpenFont : %s\n", TTF_GetError());
}

void	Doom_Nukem(t_sdl *sdl)
{
	ft_init(sdl); // modification possible si non-necessaire
	while (1)
	{
		sdl->f.last = sdl->f.current;
		sdl->f.current = SDL_GetTicks();
		sdl->f.delta = sdl->f.current - sdl->f.last;
		sdl->f.count += sdl->f.delta;
		while (sdl->f.count >= sdl->f.step)
		{
			while (SDL_PollEvent(&sdl->e))
			{
				if (sdl->e.key.keysym.sym == SDLK_ESCAPE)
					hook_keydown(sdl);
			}
			editdraw(sdl);
			SDL_UpdateWindowSurface(sdl->win);
			sdl->f.count -= sdl->f.step;
		}
	}
}

void	apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
	SDL_Rect offset;

	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(source, NULL, destination, &offset);
}

void	pixel(t_sdl *sdl, int x, int y)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGTH)
		return ;
	*((int *)sdl->ren->pixels + (y * WIDTH + x)) = sdl->color;
}

int	main(void)
{
	t_sdl	sdl;

	/*if (ac != 2)
	{
		ft_putendl_fd("Erreur de map", 2);
		return (-1);
	}*/
	Doom_Nukem(&sdl);
	return (0);
}
