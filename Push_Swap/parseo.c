/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:03:39 by rde-migu          #+#    #+#             */
/*   Updated: 2024/05/28 20:04:03 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit2(char c) {
    return (c >= '0' && c <= '9');
}

long long ft_atoll(const char *str) {
    long long result = 0;
    int sign = 1;
    if (*str == '-') {
        sign = -1;
        str++;
    }
    while (*str && ft_isdigit2(*str)) {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result * sign;
}

int ft_atoi(const char *str) {
    return (int)ft_atoll(str);
}

void display_error(const char *message, int exit_code) {
    fprintf(stderr, "%s\n", message);
    exit(exit_code);
}

char **ft_split(const char *str, char delimiter) {
    char **result;
    int count = 0;
    int i = 0;
    

    // Counting the number of splits
    while (str[i]) {
        if (str[i] == delimiter) count++;
        i++;
    }
    result = (char **)malloc((count + 2) * sizeof(char *));
    if (!result) return NULL;

    i = 0;
    int start = 0;
    int index = 0;
    while (str[i]) {
        if (str[i] == delimiter) {
            result[index] = (char *)malloc(i - start + 1);
            if (!result[index]) return NULL;
            strncpy(result[index], &str[start], i - start);
            result[index][i - start] = '\0';
            index++;
            start = i + 1;
        }
        i++;
    }
    result[index] = (char *)malloc(i - start + 1);
    if (!result[index]) return NULL;
    strncpy(result[index], &str[start], i - start);
    result[index][i - start] = '\0';
    result[index + 1] = NULL;

    return result;
}

void free_2d(char **array) {
    int i = 0;
    while (array[i]) {
        free(array[i]);
        i++;
    }
    free(array);
}

int check_digits(int argc, char **argv) {
    int i, j, count = 0;
    for (i = 1; i < argc; i++) {
        j = 0;
        while (argv[i][j]) {
            if (!ft_isdigit2(argv[i][j]) && argv[i][j] != ' ' && argv[i][j] != '-') {
                return -1;
            }
            if (ft_isdigit2(argv[i][j]) && (argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0')) {
                count++;
            }
            j++;
        }
    }
    return count;
}

int contains_duplicate(t_stack *stack, int value) {
    while (stack) {
        if (stack->content == value) {
            return 1;
        }
        stack = stack->next;
    }
    return 0;
}


void check_range(char **s_numbers, t_stack **stack) {
    int i = 0;
    while (s_numbers[i]) {
        long long num = ft_atoll(s_numbers[i]);
        if (num > INT_MAX || num < INT_MIN || strlen(s_numbers[i]) > 11) {
            free_2d(s_numbers);
            while (*stack) {
                t_stack *temp = (*stack)->next;
                free(*stack);
                *stack = temp;
            }
            display_error("Error", 1);
        }
        i++;
    }
}

void add_to_stack(t_stack **stack, int num) {
    t_stack *new_node = malloc(sizeof(t_stack));
    if (!new_node) display_error("Error", 1);
    new_node->content = num;
    new_node->next = *stack;
    *stack = new_node;
}

void arg_parse(t_push_swap *ps, int argc, char **argv) {
    char **s_numbers;
    for (int i = 1; i < argc; i++) {
        s_numbers = ft_split(argv[i], ' ');
        if (!s_numbers) display_error("Error", 1);
        check_range(s_numbers, &ps->a);
        for (int k = 0; s_numbers[k]; k++) {
            int num = ft_atoi(s_numbers[k]);
            if (contains_duplicate(ps->a, num)) {
                free_2d(s_numbers);
                while (ps->a) {
                    t_stack *temp = ps->a->next;
                    free(ps->a);
                    ps->a = temp;
                }
                display_error("Error: Duplicate number found", 1);
            }
            add_to_stack(&ps->a, num);
            ps->a_size++;
        }
        free_2d(s_numbers);
    }
}