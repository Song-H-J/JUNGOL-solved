// 2024. 07. 28.
// 송현준
// C stack

#include<stdio.h>
#include<stdlib.h>

#pragma pack(push, 4)
typedef struct node_t{
	int v;
	struct node_t* addr;
} node_t;

typedef struct stack_t
{
	struct stack_t* this;
	int size;
	node_t* top;

	int(*is_empty) (struct stack_t*);
	int(*pop) (struct stack_t*);
	void(*push) (struct stack_t*, int);
	void(*stack_size) (struct stack_t*);
	void(*spread) (struct stack_t*);
} stack_t;
#pragma pack(pop)

stack_t* init_stack();
int _is_empty(stack_t*);
int _pop(stack_t*);
void _push(stack_t*, int);
void _stack_size(stack_t*);
void _spread(stack_t*);

int main()
{
	int n;
	int tmp = 0;
	int v = 0;
	char ch, edl;
	stack_t* sss = init_stack();

	scanf("%d", &n);

	for(int i = 0; i<n; i++){
		scanf(" %c", &ch);
		if(ch=='i'){
			scanf(" %d", &v);
		}
		// printf("check %c\n", ch);
		// printf("check %d\n", v);

		switch(ch){
			case 'i':
				sss->push(sss->this, v);
				break;
			case 'o':
				tmp = sss->pop(sss->this);
				if(tmp!=(-1)){
					printf("%d\n", tmp);
				}
				break;
			case 'c':
				sss->stack_size(sss->this);
				break;
		}
	}
	return 0;
}

stack_t* init_stack(){

	stack_t* tmp = (stack_t*)malloc(sizeof(stack_t));

	tmp->this = tmp;
	tmp->top = NULL;
	tmp->size = 0;
	tmp->is_empty = _is_empty;
	tmp->pop = _pop;
	tmp->push = _push;
	tmp->spread = _spread;
	tmp->stack_size = _stack_size;
	return tmp;
}

int _is_empty(stack_t* this){
	return (this->top == NULL);
}


int _pop(stack_t* this){
	if(this->is_empty(this)){
		printf("empty\n");
		return -1;
	}

	else{
		node_t* tmp = this->top;
		int return_data = tmp->v;
		this->top = this->top->addr;
		free(tmp);
		this->size--;
		return return_data;
	}
}

void _push(stack_t* this, int value){
	node_t *tmp = (node_t*) malloc(sizeof(node_t));
	tmp->addr = this->top;
	tmp->v = value;
	this->top = tmp;
	this->size++;
}

void _spread(stack_t* this){
	node_t* i;
	printf("Top ");
	for(i = this->top; i != NULL; i = i->addr){
		printf("-> %d ", i->v);
	}
	printf(" Bottom\n");
}

void _stack_size(stack_t* this){
	printf("%d\n", (this->size));
}