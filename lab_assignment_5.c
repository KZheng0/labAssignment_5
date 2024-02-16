#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	node * tmp = head;
	int count = 0;
	while(tmp != NULL){
		tmp = tmp->next;
		count++;
	}
	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int size, i = 0;
	size = length(head);
	char * arr = (char*) malloc((size+1) * sizeof(char));
	node * tmp = head;
	if(arr != NULL){
		while (tmp != NULL){
			arr[i] = tmp->letter;
			tmp = tmp->next;
			i++;
		}	
	}
	arr[i] = '\0';
	return arr;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node * newNode = (node*) malloc(sizeof(node));	
	if (newNode != NULL){
		newNode->letter = c;
		newNode->next = NULL;
	}

	if( *pHead == NULL){
		*pHead = newNode;
	}
	else 
	{
		node * tmp = *pHead;
		while (tmp != NULL && tmp->next != NULL){
			tmp = tmp->next;
		}
		if (tmp != NULL && tmp->next == NULL){
			tmp->next = newNode;
		}
	}	
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node * tmp = *pHead;
	while (tmp != NULL){
		*pHead = tmp->next;
		free(tmp);
		tmp = *pHead;
	}
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}