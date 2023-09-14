/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyun2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:47:54 by taehyun2          #+#    #+#             */
/*   Updated: 2023/09/13 14:50:52 by taehyun2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}

int	is_possible(int *board, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (board[j] == board[i])
			return (0);
		else if (ft_abs(i - j) == ft_abs(board[i] - board[j]))
			return (0);
		j++;
	}
	return (1);
}

void	p_queen(int *board)
{
	int		i;
	char	index;

	i = 0;
	while (i < 10)
	{
		index = board[i] + '0';
		write(1, &index, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ten_queens(int *board, int row, int column, int *result)
{
	if (row == 10)
	{
		p_queen(board);
		(*result)++;
		return ;
	}
	while (column < 10)
	{
		board[row] = column;
		if (is_possible(board, row))
			ten_queens(board, row + 1, 0, result);
		column++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	result;

	result = 0;
	ten_queens(board, 0, 0, &result);
	return (result);
}
