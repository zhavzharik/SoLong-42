/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:12:54 by abridger          #+#    #+#             */
/*   Updated: 2021/10/15 22:38:07 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

# define BUFFER_SIZE 300

typedef struct s_stack
{
	int				nb;
	int				indx;
	int				flag;
	struct s_stack	*next;
}					t_stack;

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
void	ft_puterror(void);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(char *s1);
void	ft_lstadd_front(t_stack **a, int number, int index);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstclear(t_stack **lst);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dest, char const *src);
char	*ft_strjoin(char *s1, char const *s2);

char	*check_rest(char *rest, char **line);
int		check_lesen(int lesen, char **buf, char **line);
int		get_rest_and_line(char **n_point, char **buf, char **rest, char **line);
int		get_return(char **buf, int lesen, char **rest, char **line);
int		get_next_line(int fd, char **line);

#endif
