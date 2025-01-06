/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:35:13 by juduchar          #+#    #+#             */
/*   Updated: 2025/01/06 14:36:12 by sakamoto-42      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct Node {
	int		value;
	struct	Node *next;
} Node;

Node	*create_node(int value)
{
	Node *new_node = malloc(sizeof(Node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	add_node(Node **head, int value)
{
	Node	*new_node;
	Node	*current;

	new_node = create_node(value);
	if (!*head)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

// libft
int	ft_is_space(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

// libft

int	ft_is_digit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_is_nbr(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

long long	ft_strtoll(const char *str)
{
	long long	result;
	int			sign;
	int			digit;

	result = 0;
	sign = 1;

	while (ft_is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		if (result > (LLONG_MAX - digit) / 10)
		{
			if (sign == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		result = result * 10 + digit;
		str++;
	}
	return (result * sign);
}

int	ft_is_int(const char *str)
{
	long long	n;

	n = ft_strtoll(str);
	return (n >= INT_MIN && n <= INT_MAX);
}

int	ft_is_unique(Node *head, int value)
{
	Node	*current;

	current = head;
	while (current)
	{
		if (current->value == value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_free_list(Node *head)
{
	Node	*current;
	Node	*temp;

	current = head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (ft_is_space((int)*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_is_digit((int)*nptr))
	{
		result = (result * 10) + ((int)(*nptr) - 48);
		nptr++;
	}
	return (sign * result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strdup(const char *s)
{
	size_t	str_len;
	char	*dup;

	str_len = ft_strlen(s);
	dup = (char *) malloc((str_len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, str_len + 1);
	return (dup);
}

size_t	ft_count_words(char const *s, char c)
{
	size_t	word_count;

	word_count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			word_count++;
		s++;
	}
	return (word_count);
}

const char	*ft_get_word_end(const char *s, char c)
{
	while (*s && *s != c)
		s++;
	return (s);
}

char	*ft_extract_word(const char *start, const char *end)
{
	char	*word;
	char	*dest;

	word = (char *) malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	dest = word;
	while (start < end)
		*dest++ = *start++;
	*dest = '\0';
	return (word);
}

char	**ft_free_strs(char **strs, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t		word_count;
	char		**splitted_strs;
	size_t		i;
	const char	*word_end;

	word_count = ft_count_words(s, c);
	splitted_strs = (char **) malloc((word_count + 1) * sizeof(char *));
	if (!splitted_strs)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		word_end = ft_get_word_end(s, c);
		splitted_strs[i] = ft_extract_word(s, word_end);
		if (!splitted_strs[i])
			return (ft_free_strs(splitted_strs, i));
		s = word_end;
		i++;
	}
	splitted_strs[i] = NULL;
	return (splitted_strs);
}

void	ft_free_splitted(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**concat_strs(char **strs1, char **strs2)
{
	size_t		strs1_len;
	size_t		strs2_len;
	char		**strs;
	size_t		i;
	size_t		j;

	strs1_len = 0;
	strs2_len = 0;
	while (strs1[strs1_len])
		strs1_len++;
	while (strs2[strs2_len])
		strs2_len++;
	strs = malloc((strs1_len + strs2_len + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (i < strs1_len)
	{
		strs[i] = ft_strdup(strs1[i]);
		if (!strs[i])
		{
			ft_free_strs(strs, i);
			return (NULL);
		}
		i++;
	}
	j = 0;
	while (j < strs2_len)
	{
		strs[i + j] = ft_strdup(strs2[j]);
		if (!strs[i + j])
		{
			ft_free_strs(strs, i + j);
			return (NULL);
		}
		j++;
	}
	strs[i + j] = NULL;
	return (strs);
}

int	main(int argc, char **argv)
{
	char	**strs;
	char	**current_strs;
	char	**temp_strs;
	int		i;
	int		j;
	int		k;
	int		l;
	Node	*head;
	int		value;
	Node	*current;

	if (argc - 1 == 0)
		return (1);
	i = 1;
	strs = NULL;
	while (i < argc)
	{
		current_strs = ft_split(argv[i], ' ');
		j = 0;
		while (current_strs[j])
		{
			if (!ft_is_nbr(current_strs[j]) || !ft_is_int(current_strs[j]))
			{
				write(2, "Error\n", 6);
				ft_free_splitted(current_strs);
				if (strs)
					ft_free_splitted(strs);
				return (1);
			}
			j++;
		}
		if (!strs)
			strs = current_strs;
		else
		{
			temp_strs = strs;
			strs = concat_strs(strs, current_strs);
			ft_free_splitted(temp_strs);
			ft_free_splitted(current_strs);
		}
		i++;
	}

	k = 0;
	while (strs[k])
	{
		printf("%s\n", strs[k]);
		k++;
	}

	head = NULL;
	l = 0;
	while (strs[l])
	{
		value = ft_atoi(strs[l]);
		if (!ft_is_unique(head, value))
		{
			printf("Doublon detecte : %d\n", value);
			ft_free_list(head);
			return (1);
		}
		add_node(&head, value);
		l++;
	}
	ft_free_splitted(strs);
	printf("------------------------------------\n");
	current = head;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	return (1);
	
}
