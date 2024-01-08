int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}


int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
	
	{
		i++;
	}
	if (i == n) 
		return 0;
	return (s1[i] - s2[i]);
}



