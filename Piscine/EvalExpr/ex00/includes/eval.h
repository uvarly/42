/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 11:29:58 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/04 14:17:05 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_H
# define EVAL_H

int		eval_expr(char *expr);
int		parse_summands(char **expr);
int		parse_factors(char **expr);
int		parse_atom(char **expr);
int		ft_strtoi(char **expr);

#endif
