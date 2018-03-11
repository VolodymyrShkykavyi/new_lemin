/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:15:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/05 19:15:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static unsigned int	get_edges_num(t_room *room)
{
	t_edge			*tmp;
	unsigned int	num;

	tmp = room->edges;
	num = 0;
	while (tmp)
	{
		num++;
		tmp = tmp->next;
	}
	return (num);
}
/*
void				copy_way(t_way **head, t_way *way)
{
	t_way	*tmp;
	t_way	*new;

	tmp = *head;
	while (tmp && tmp->next)
		tmp = tmp->next;
	MALL_CHECK(new = (t_way *)malloc(sizeof(t_way)));
	//tmp->next
}
*/
void				add_way_edge(t_way *way, t_room *room)
{
	t_edge	*last;

	if (!way->edges)
	{
		MALL_CHECK(way->edges = (t_edge *) malloc(sizeof(t_edge)));
		last = way->edges;
	}
	else
	{
		last = way->edges;
		while (last && last->next)
			last = last->next;
		MALL_CHECK(last->next = (t_edge *) malloc(sizeof(t_edge)));
		last = last->next;
	}
	last->next = NULL;
	last->room = room;
}

void				init_ways(t_info *info)
{
	t_edge	*edge;
	t_way	*tmp;

	edge = info->end->edges;
	while (edge)
	{
		MALL_CHECK(tmp = (t_way *)malloc(sizeof(t_way)));
		tmp->len = 1;
		tmp->next = info->ways;
		tmp->edges = NULL;
		add_way_edge(tmp, info->end);
		add_way_edge(tmp, edge->room);
		info->ways = tmp;
		edge = edge->next;
	}
}

void				copy_way_exept_ledge(t_info *info, t_way *way)
{
	t_way	*new;
	t_edge	*edge;

	MALL_CHECK(new = (t_way *)malloc(sizeof(t_way)));
	new->edges = NULL;
	new->next = way->next;
	way->next = new;
	edge = way->edges;
	while (edge && edge->next)
	{
		add_way_edge(new, edge->room);
		edge = edge->next;
	}
}

int					get_shortest_ways(t_info *info, int max)
{
	t_way	*tmp_w;
	t_edge	*edge;
	t_edge	*tmp_e;
	int 	step;
	int		added;

	//room = info->end->edges;
	init_ways(info);
	step = info->end->weight;
	while (--step > 0)
	{
		tmp_w = info->ways;
		while (tmp_w)
		{
			edge = tmp_w->edges;
			while (edge && edge->next)
				edge = edge->next;
			tmp_e = edge->room->edges;
			added = 0;
			while (tmp_e)
			{
				if (!added && tmp_e->room->weight == step)
				{
					add_way_edge(tmp_w, tmp_e->room);
					added = 1;
				}
				else if (added && tmp_e->room->weight == step)
				{
					//copy_way_exept_ledge(info, tmp_w);
				//	add_way_edge(tmp_w->next, tmp_e->room);
				}
				tmp_e = tmp_e->next;
			}
			tmp_w = tmp_w->next;
		}
	}
	return (0);
}
/*

void				find_ways(t_info *info)
{
	unsigned int	max_ways;
	t_way			*shortest;

	if (get_edges_num(info->start) < get_edges_num(info->end))
		max_ways = get_edges_num(info->start);
	else
		max_ways = get_edges_num(info->end);
	get_shortest_ways(info, max_ways);
}
*/
/*
 * new
 */

t_edge				*get_minweight_edge(t_edge *end_edges)
{
	t_edge	*edge;
	t_edge	*best_edge;
	t_edge	*new_edge;

	edge = end_edges;
	best_edge = NULL;
	while (edge)
	{
		if (!edge->room->visited)
		{
			if (!best_edge || edge->room->weight < best_edge->room->weight)
				best_edge = edge;
			else if (edge->room->weight == best_edge->room->weight &&
					edge->room->num_edges == 2)
				best_edge = edge;
		}
		edge = edge->next;
	}
	if (!best_edge)
		return (NULL);
	MALL_CHECK(new_edge = (t_edge *)malloc(sizeof(t_edge)));
	new_edge->room = best_edge->room;
	new_edge->next = NULL;
	return (new_edge);
}

t_edge				*get_last_edge(t_edge *edges)
{
	t_edge	*edge;
	edge = edges;
	while (edge && edge->next)
		edge = edge->next;
	return (edge);
}

void				delete_way(t_way *way)
{
	t_edge	*edge;
	t_edge	*prev;

	way->len = 0;

	edge = way->edges->next;
	while (edge && edge->next)
	{
		prev = edge;
		edge = edge->next;
		prev->room->visited = 0;
		free(prev);
	}
	if (edge)
		free(edge);
	way->edges->next = NULL;
}

void				get_new_way(t_way *way, t_info *info)
{
	t_edge	*last_e;
	t_edge	*min_edge;

	//ft_putstr_fd("buid new way\n", 2);
	last_e = get_last_edge(way->edges);
	last_e->room->visited = 1;
	while (1)
	{
		min_edge = get_minweight_edge(last_e->room->edges);
		//ft_putstr_fd("\tnew way edge\n", 2);
		if (!min_edge)
		{
			delete_way(way);
			return ;
		}
		last_e->next = min_edge;
		last_e = min_edge;
		way->len++;
		if (min_edge->room == info->start)
			return ;
		min_edge->room->visited = 1;
	}
}

void				find_ways(t_info *info)
{
	unsigned int	num_way;
	unsigned int	max_ways;
	unsigned int	find_ways;
	t_way			way_arr[info->end->num_edges];

	max_ways = (info->end->num_edges > info->start->num_edges) ?
			   info->start->num_edges : info->end->num_edges;
	find_ways = 0;
	num_way = 0;
	info->end->visited = 1;
	ft_putstr_fd("start finding\n", 2);
	while (find_ways < max_ways && num_way < max_ways)
	{
		way_arr[num_way].edges = get_minweight_edge(info->end->edges);
		way_arr[num_way].len = 0;
		if (way_arr[num_way].edges)
			get_new_way(&(way_arr[num_way]), info);
		if (way_arr[num_way].len)
		{
			find_ways++;
			way_arr[num_way].next = NULL;
			info->ways = &(way_arr[num_way]);
		}
		num_way++;
	}
//	way_arr[0].next = NULL;

	find_ways = 0;
	while (find_ways < num_way)
	{
		if (!way_arr[find_ways++].len)
			get_new_way(&(way_arr[num_way - 1]), info);
	}



	while (--num_way)
		if (way_arr[num_way].len)
			print_ways(&way_arr[num_way]);
	//print_ways(&way_arr[num_way]);
}

