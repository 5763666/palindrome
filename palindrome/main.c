#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
typedef struct stacktype { 
	char stack[MAX];
	int top;
}stacktype;
void init(stacktype* s) { 
	s->top = -1;
}
int is_full(stacktype* s) { 
	return (s->top == MAX - 1);
}
int is_empty(stacktype* s) {
	return (s->top == -1);
}
char pop(stacktype* s) { 
	char out; 
	out = s->stack[(s->top)--]; 
	return out; 
}
void push(stacktype* s, char item) { 
	s->stack[++(s->top)] = item; 
}
int check_matching(char input_string[]) { 
	stacktype s;
	int i = 0; 
	init(&s);
	while (input_string[i] != NULL) { 
		if ('a' <= input_string[i] && input_string[i] <= 'z') { 
			if (is_full(&s)) { 
				printf("스택이 가득 찼습니다.");
				return 0;
			}
			push(&s, input_string[i]);  
		}
		else if ('A' <= input_string[i] && input_string[i] <= 'Z') { 
			if (is_full(&s)) { 
				printf("스택이 가득 찼습니다.");
				return 0;
			}
			char c = input_string[i] + ('a' - 'A'); 
			push(&s, c); 
		}
		i++; 
	}
	i = 0;
	int j = 0; 
	while (input_string[i + j] != NULL) { 
		if (isalpha(input_string[i + j]) != 0) { 
			if ('a' <= input_string[i + j] && input_string[i + j] <= 'z') { 
				if (pop(&s) != input_string[i + j]) return 0; 
			}
			else if ('A' <= input_string[i + j] && input_string[i + j] <= 'Z') { 
				char a = input_string[i] + ('a' - 'A'); 
				if (pop(&s) != a) return 0;  
			}
			i++; 
		}
		else j++; 
	}
	return 1; 
}
int main() {
	char input_string[MAX] = { NULL };
	char ans;
	while (1) {
		printf("문자열을 입력하시오: ");
		gets_s(input_string, sizeof(input_string)); 
		if (check_matching(input_string) == 1) printf("회문입니다."); 
		else printf("회문이 아닙니다.");
		
		printf("\n계속 입력하시겠습니까?(Yes/No): ");
		scanf_s("%c", &ans);
		if (ans == 'Yes') continue;
		else break; 
	}
	return 0;
}       