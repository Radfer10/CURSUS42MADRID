/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mains.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 05:41:02 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/21 12:47:42 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ft_atoi*/
/*int main()
{
	const char *str = "   -123-45";

	int result;

	result = ft_atoi(str);
	printf("%d\n", result);
	return (0);
}*/

/*ft_bzero*/
/*int main()
{
    char buffer[50] = "Hola que tal";
    printf("Antes de ft_bzero: %s\n", buffer);
    ft_bzero(buffer,  10);
    printf("Después de ft_bzero: %s\n", buffer);
    return  0;
}*/ 

/*ft_isalnum*/
/*int main(void)
{
	int	result;

	result = ft_isalnum('a');
	printf("%d\n", result);
	return (0);
}*/

/*ft_isalpha*/
/*int main(void)
{
	int	result;

	result = ft_isalpha('a');
	printf("%d\n", result);
	return (0);
}*/

/*ft_isascii*/
/*int main(void)
{
	int	result;

	result = ft_isascii('60');
	printf("%d\n", result);
	return (0);
}*/

/*ft_isdigit*/
/*int main(void)
{
	int	result;

	result = ft_isdigit('6');
	printf("%d\n", result);
	return (0);
}*/

/*ft_isprint*/
/*int main(void)
{
	int	result;

	result = ft_isprint('33');
	printf("%d\n", result);
	return (0);
}*/

/*ft_itoa*/
/*int main(void)
{
    int number = 12345;
    char *result = ft_itoa(number);

    if (result)
    {
        printf("%s\n", result);
        free(result);
    }
    else
    {
        printf("Error\n");
    }

    return 0;
}*/

/*ft_memchr*/
/*int	main(void)
{
	char	str[] = "Hola Mundo";
	char	ch = 'W';
	size_t n = strlen(str);

	void *result = ft_memchr(str, ch, n);

	if (result != NULL)
		printf("Se encontro 'M' en la posicion: %ld\n", (char *)result - str);
	else
		printf(" 'M' no se encontro en la cadena\n");
	return (0);
}*/

/*ft_memcmp*/
/*int main()
{
	char	bloque1[] = "Hello";
	char	bloque1[] = "Hellp";

	size_t len = 5;

	int result = ft_memcmp(bloque1, bloque2, len);

	if (result < 0)
	{
		printf("1\n");
	} else if (result > 0)
	{
		printf("2\n");
	} else {
		printf("0\n");
	}
	return (0);
}*/

/*ft_memcpy*/
/*int main()
{
    char s[] = "abcdefghijklmnopqrstuvwxyz";
    char d[27];
    ft_memcpy(d, s, sizeof(char) * 27);
    printf("d: %s\n", d);
    char e [10];
    ft_memcpy(e, s+8, sizeof(char) * 9);
    e  [9] = '\0';
    printf("e: %s\n", e);
    return 0;
}
*/

/*ft_memmove*/
/*
int main()
{
    int source[] = {1,2,3,4,5,6,7,8,9,10};
    int destination[10];
    ft_memmove (destination, source, sizeof(int) * 10);
    int i = 0;
    while(i < 10)
    {
    printf("destination[%d]=%d\n", i, destination[i]);
    i++;
    }
}
*/

/*ft_memset*/
/*
int main(void)
{int main()
{
	char	str[20];
	size_t	i = 0;
	ft_memset(str, '1', 10);
	printf("%s", str);
	return (0);
}
*/

/*ft_putchar_fd*/
/*int main()
{
	ft_putchar_fd('H', 1);
	ft_putchar_fd('O', 1);
	ft_putchar_fd('L', 1);
	ft_putchar_fd('A', 1);

	return (0);

}*/

/*ft_putendl_fd*/
/*int main()
{
	char *str = "Hola mundo";
	int	fd = 1;

	ft_putendl_fd(str, fd);
	return (0);
}*/

/*ft_putnbr_fd*/
/*int main()
{
	int	num1 = 12345;
	int	num2 = -6789;

	ft_putnbr_fd(12345, 1);
	write(1, "\n", 1);

	ft_putnbr_fd(-6789, 1);
	write(1, "\n", 1);
	return (0);
}*/

/*ft_pustr_fd*/
/*int main()
{
	char	str[] = "Hola mundo";
	ft_putstr_fd(str, 1);
	return (0);
}*/

/*ft_split*/
/*int main()
{
    const char *str = "Hola, soy, radfer";
    char c = ' ';
    char **result = ft_split(str, c);

    int i =  0;
    while (result[i] != NULL)
    {
        printf("%s\n", result[i]);
        free(result[i]);
        i++;
    }
    free(result);

    return  0;
}*/

/*ft_strchr*/
/*int main() {
	const char *str = "Hello, World!";
	char target = 'H';

	char *result = custom_strchr(str, target);

	if (result != NULL) {
		printf("posición %ld de la cadena.\n", result - str);
	}
	return (0);
}*/

/*ft_strdup*/
/*
int main()
{
    char source [] = "Michitos ronroneando";
    char *target = strdup(source);
    printf("%s\n", target);
    free(target);
    return 0;
}
*/

/*ft_striteri*/
/*int main()
{
	char str[] = "Hello, World";

	ft_striteri(str, printchari);
	return (0);
}*/

/*ft_strjoin*/
/*int	main(void)
{
 char    *s1 = "Hola";
    char    *s2 = "mundo!";
    char    *result;

    result = ft_strjoin(s1,s2);

    if (result)
    {
        printf("%s\n", result);
        free(result);
    }
    else
    {
        printf("Error\n");
    }
    return (0);
}
	*/

/*ft_strlcat*/
/*
int main()
{
	 char	dst[20] = "Hola";
	const char	*src = "Mundo";
	size_t	result = ft_strlcat(dst, src, sizeof(dst));
	printf("%s\n", dst);
	printf("%zu\n", result);
	return (0);
}*/

/*ft_strlcpy*/

/*int main() {
    char src[] = "Hello, World!";
    char dst[20];
    size_t dstsize = sizeof(dst);
    size_t copied_length;

    copied_length = ft_strlcpy(dst, src, dstsize);

    printf("Longitud copiada: %zu\n", copied_length);
    printf("Destino: %s\n", dst);

    return  0;
}*/

/*ft_strlen*/
/*
int main ();
{
    char dest[20] = "Michis peluditos";
    char src [] = "Ronroneando";
    ft_strlcat(dest, src, sizeof(dest));
    return 0;
}
*/

/*ft_strmapi*/
/*int main()
{
	const char *input;
	char *result;

	input = "HelloWorld";
	result = ft_strmapi((char *)input, map_function);

	printf("%s\n", input);
	printf("%s\n", result);
	return (0);
}*/

/*ft_strncmp*/
/*
int main ()
{
    const char *s1 = "Perritos";
    const char *s2 = "Perrito!";
    size_t n = 8;
    printf("%ld\n", ft_strncmp(s1, s2, n));
    return (0);
}
*/

/*ft_strnstr*/
/*int main()
{
	const char	*haystack = "Hello, world";
	const char	*needle = "rl";
	const char	*result;
	const char	*resultoriginal;

	result = ft_strnstr(haystack, needle, 5);
	resultoriginal = strnstr(haystack, needle, 5);

	printf("%s", resultoriginal);
	printf("%s", result);

	return (0);
}*/

/*ft_strrchr*/
/*int main() {
	const char *str = "Hello, World!";
	char target = 'H';

	char *result = custom_strchr(str, target);

	if (result != NULL) {
		printf("posición %ld de la cadena.\n", result - str);
	}
	return (0);
}*/

/*ft_strtrim*/
/*int main(void)
{
	const char *str1 = "delen";
	const char *str2 = "e";

	char result = *ft_strtrim(str1, str2);

		printf("%c", result);
	return (0);
	}*/
/*ft_substr*/
/*int main()
{
	const char *original = "Hello, World!";
	char	*substring = ft_substr(original, 7, 5);


	printf("%s\n", original);
	printf("%s\n", substring);

	free(substring);

	return (0);
}*/

/*ft_tolower*/
/*int main() {
   char ch = 'g';
   printf("%c",ft_tolower(ch));
   return (0);
}*/

/*ft_toupper*/
/*int main() {
   char ch = 'g';
   printf("%c",ft_toupper(ch));
   return (0);
}*/

/*ft_lstadd_back*/
/*
void ft_lstadd_back(t_list **lst, t_list *new) {
    t_list *last;
    last = *lst;
    if (!*lst) {
        *lst = new;
        return;
    }
    while (last->next)
        last = last->next;
    last->next = new;
}
int main()
{
    t_list *node1 = malloc(sizeof(t_list));
    node1->content = "Primero";
    node1->next = NULL;

    t_list *node2 = malloc(sizeof(t_list));
    node2->content = "Segundo";
    node2->next = NULL;

    ft_lstadd_back(&node1, node2);

    t_list *current = node1;
    while (current != NULL) {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }

    t_list *tmp;
    while (node1 != NULL) {
        tmp = node1;
        node1 = node1->next;
        free(tmp);
    }
}*/

/*ft_lstadd_front*/
/*void ft_lstadd_front(t_list **list, t_list *new) {
    if (list && new) {
        new->next = *list;
        *list = new;
    }
}

int main() {
    t_list *node1 = malloc(sizeof(t_list));
    node1->content = "Primer";
    node1->next = NULL;

    t_list *node2 = malloc(sizeof(t_list));
    node2->content = "Segundo";
    node2->next = NULL;

    ft_lstadd_front(&node1, node2);

    t_list *current = node1;
    while (current != NULL) {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }

    t_list *tmp;
    while (node1 != NULL) {
        tmp = node1;
        node1 = node1->next;
        free(tmp);
    }

    return   0;
}*/

/*ft_lstclear_bonus*/
/*void	ft_lstclear(t_list **lst, void (*del) (void *)) {
    t_list	*current;
    t_list	*next;

    if (lst && del) {
        current = *lst;
        while (current) {
            next = current->next;
            del(current->content);
            free(current);
            current = next;
        }
        *lst = NULL;
    }
}
void	del(void *content) {
    free(content);
}

int main() {
    t_list *head = malloc(sizeof(t_list));
    head->content = strdup("Contenido");
    head->next = NULL;

    ft_lstclear(&head, &del);

    return  0;
}*/

/*ft_lstdelone_bonus*/
/*void	ft_lstdelone(t_list *list, void (*del)(void *)) {
    if (list && del) {
        del(list->content);
        free(list);
    }
}

void	del(void *content) {
    free(content);
}

int main() {
    t_list *node = malloc(sizeof(t_list));
    node->content = strdup("Contenido");
    node->next = NULL;

    ft_lstdelone(node, &del);

    return   0;
}*/

/*ft_lsiter_bonus*/
/*void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int main() {
	t_list *node1 = malloc(sizeof(t_list));
	node1->content = "Primero";
	node1->next = NULL;

	t_list *node2 = malloc(sizeof(t_list));
	node2->content = "Segundo";
	node2->next = NULL;

	node1->next = node2;

	ft_lstiter(node1, &print_content);

	free(node1);
	free(node2);

	return  0;
}*/

/*ft_lstlast_bonus*/
/*t_list *create_new_node(int data)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d ", lst->data);
        lst = lst->next;
    }
    printf("\n");
}

int main(void)
{
    t_list *lst = NULL;
    t_list *node1 = create_new_node(1);
    t_list *node2 = create_new_node(2);
    t_list *node3 = create_new_node(3);

    lst = node1;
    node1->next = node2;
    node2->next = node3;

    printf("Lista original: ");
    print_list(lst);

    t_list *last_node = ft_lstlast(lst);

    if (last_node)
    {
        printf("El último nodo contiene el valor: %d\n", last_node->data);
    }
    else
    {
        printf("La lista está vacía.\n");
    }

    free(node1);
    free(node2);
    free(node3);

    return 0;
}*/

/*ft_calloc*/
/*int main() {
    size_t num_elements =   5;
    size_t size_element = sizeof(int);
    void *array_pointer = ft_calloc(num_elements, size_element);

    if (array_pointer == NULL) {
        printf("La memoria no pudo ser asignada.\n");
        return   1;
    }

    system("./fillArray.sh");
    printf("Los elementos del array son: ");
    system("./printArrayElements.sh");

    free(array_pointer);

    return   0;
}*/

/*ft_lstmap_bonus*/

/*void *duplicate_and_reverse(void *content) {
    char *str = strdup((char *)content);
    int len = strlen(str);
    for (int i =  0; i < len /  2; i++) {
        char temp = str[i];
        str[i] = str[len - i -  1];
        str[len - i -  1] = temp;
    }
    return (str);
}

void delete_content(void *content) {
    free(content);
}

int main() {
    t_list *original_list = ft_lstnew("Hello");
    original_list->next = ft_lstnew("World");
    original_list->next->next = ft_lstnew("!");

    t_list *mapped_list = ft_lstmap(original_list, duplicate_and_reverse, delete_content);

    t_list *current_node = mapped_list;
    while (current_node) {
        printf("%s\n", (char *)current_node->content);
        current_node = current_node->next;
    }

    ft_lstclear(&mapped_list, delete_content);

    return  0;
}*/

/*ft_lstnew_bonus*/
/*int main()
{
	t_list	*lst = ft_lstnew("Hola");
	while(lst)
	{
		printf("%s\n", (char *) lst ->content);
		lst = lst -> next;
	}
	ft_lstclear(&lst, free);
	return (0);
}
}*/

/*ft_lstsize_bonus*/
/*typedef struct s_list {
    int data;
    struct s_list *next;
} t_list;

int ft_lstsize(t_list *lst);

int main() {
    t_list *head = NULL;
    t_list *second = NULL;
    t_list *third = NULL;

    head = (t_list *)malloc(sizeof(t_list));
    second = (t_list *)malloc(sizeof(t_list));
    third = (t_list *)malloc(sizeof(t_list));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    int size = ft_lstsize(head);

    printf("El tamaño de la lista es: %d\n", size);

    free(head);
    free(second);
    free(third);

    return 0;
}*/

/*int main()
{
	t_list	*lst = ft_lstnew("Hola");
	ft_lstadd_back(&lst, ft_lstnew("Mundo"));
	ft_lstadd_front(&lst, ft_lstnew("Que tal"));
	t_list	*last_node = ft_lstlast(lst);
	t_list	*original_lst = lst;
	while (lst)
	{
		printf("%s\n", (char *) lst ->content);
		lst = lst -> next;
	}
	if (last_node)
	{
		printf("%s\n", (char *) last_node -> content);
	}
	printf("%d\n", ft_lstsize(original_lst));
	ft_lstclear(&lst, free);
	return (0);
}*/

/*Para los putchar y demas con fd.*/

/*#include <fcntl.h>



int main()
{
	int	fd;
	fd = open("text.txt", O_WRONLY | O_CREAT, 0644);
	ft_putchar_fd('A', fd);
	close(fd);
	return (0);
}*/
