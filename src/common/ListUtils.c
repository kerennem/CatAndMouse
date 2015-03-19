#include <stdlib.h>
#include "ListUtils.h"
#include <stdio.h>

struct List {
 	void* data; // doesn't support NULL data. If list is empty, holds irrelevant data of int* (int = 2015)
 	ListRef next; 
 	int is_empty; // 1 if list is empty, 0 otherwize
} List;


/**
 * Allocate a new list with the given data pointer at the head.
 * The list does not support NULL data - in this case if the data is NULL then an empty list will be created.
 *
 * May return NULL if malloc fails.
 */
ListRef newList(void* headData) {
	ListRef new_list = (ListRef)malloc (sizeof(List));
 	if (new_list == NULL) {
 		return NULL;
 	}
 	if (headData == NULL) {
 		new_list -> is_empty = 1;
 		int mock_data = 2015; // irrelevant data since list is empty
		int* p = malloc(sizeof(int));
		if (p == NULL) {
			return NULL;
		}
		*p = mock_data;
 		new_list -> data = p;

 	}
 	else {
 		new_list -> is_empty = 0;
 		new_list -> data = headData;
 	}
 	new_list->next = NULL;
 	return new_list;
}


/**
 * Return the data pointer held by the head of the list or NULL if the list is empty.
 */
void* headData(ListRef list) {
	if (isEmpty(list) == 1) {
		return NULL;
	}
	return list -> data;
}

/**
 * Return the tail of the given list or NULL if the list has less than 2 elements.
 * E.g. if the list holds the addresses [1,2,3] then tail(list) will return the sub-list [2,3].
 */
ListRef tail(ListRef list) {
	if (isEmpty(list) == 1) {
		return NULL;
	}
	else {
		if (list -> next == NULL) { //the list contains only 1 element
			return NULL;
		}
		else {
			return list -> next;
		}

	}
}

/**
 * Append the given data to the end of the list and return a pointer to the sub-list containing only this data.
 * If the given data is NULL no change will be made to the list and NULL will be returned.
 * E.g. if the list holds the addresses [1,2,3] then after calling append(list, (void*)4) the list will hold [1,2,3,4]
 * and will return the sub-list [4].
 *
 * May return NULL if malloc fails.
 */

ListRef append(ListRef list, void* data) {
	if (data == NULL) {
		return NULL;
	}
	else {
		if (isEmpty(list) == 1) {
			list -> is_empty = 0; //list isn't empty anymore
			free(list->data);
			list -> data = data;
			return list;
		}
		else {
			ListRef new_item = newList(data);
			ListRef curr_item = list;
			while (curr_item -> next != NULL) { //sets curr_item to be the last item
				curr_item = curr_item -> next;
			}
			curr_item -> next = new_item;
			return new_item;
		}
	}
}



/**
 * Free all memory allocated to the list and all its sub-lists.
 * Will use the given freeData function in order to free all the data contained in the list.
 * Given list assumed to have been returned from the 'newList' function (i.e. not a sub-list) -
 * otherwise all operations on the original list may have undefined behaviour.
 */
void destroyList(ListRef list, FreeFunc freeData) {
	if (list != NULL) {
		destroyList((list->next), freeData); //destroy the list from last to first item
		freeData(list -> data);
		free(list);
	}
}


/**
 * Return zero if the list has any data or non-zero if it is empty.
 */
int isEmpty(ListRef list) {
	return list -> is_empty;
}
