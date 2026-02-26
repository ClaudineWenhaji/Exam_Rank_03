/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:22:12 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/26 18:24:05 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERMUTATIONS_H
# define PERMUTATIONS_H

int	ft_strlen(char *str);
void	sort_string(char *str);
int	ft_strchr(char *str, char c);
void	permutations(char *src, char *res, int pos, int src_len);

#endif
