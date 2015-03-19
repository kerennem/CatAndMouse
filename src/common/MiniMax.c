#include "MiniMax.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Returns the best child of the given state, resulting from the MiniMax computation up to maxDepth.
 * The getChildren function will be used to get each state's children.
 * The freeState function will be used to deallocate any lists returned by GetChildren.
 * The evaluate function will be used to evaluate the state score.
 * The player who's turn it is to play at the given state is assumed to be the MAX player if and only if isMaxPlayer is non-zero,
 * otherwise, it is assumed to be the MIN player.
 *
 * Will NOT crash in case one of the given functions fails but result will be undefined.
 */
struct MiniMaxResult getBestChild(
		void* state,
		unsigned int maxDepth,
		ListRef (*getChildren) (void* state),
		FreeFunc freeState,
		int (*evaluate) (void* state),
		int isMaxPlayer){
	struct MiniMaxResult bestChild;
	int a = 1; 
	ListRef children = getChildren(state); //creates a list of posible boards after one move
	if (children == NULL){
		bestChild.index = -1;
		bestChild.value = 0;
	}
	if ((maxDepth ==0) || (isEmpty(children))) { //base case - we've reached the defined maxDepth or we've reached the leaves of the recursion tree
		bestChild.index = -1; // irrelevant index since no children are checked or exist
		bestChild.value = evaluate(state);
		destroyList(children, freeState);
		return bestChild;
	}
	ListRef currChild = children;
	int indexOfCurrBestChild = 0;
	int valueOfCurrBestChild = ((isMaxPlayer == 0)? MAX_EVALUATION : MIN_EVALUATION); // initialized as minimal possible value for max player and vice versa 
	int currChildIndex = 0;
	
	while (currChild != NULL) {
		void* childState = headData(currChild);
		struct MiniMaxResult bestDescendant = getBestChild(childState, maxDepth-1, getChildren, freeState, evaluate, ((isMaxPlayer == 0)? 1 : 0)); // goes down the recursion tree
		if (((isMaxPlayer == 0) && (bestDescendant.value < valueOfCurrBestChild)) || ((isMaxPlayer != 0) && (bestDescendant.value > valueOfCurrBestChild))) {
			valueOfCurrBestChild = bestDescendant.value;
			indexOfCurrBestChild = currChildIndex;
		}
		currChildIndex += 1;
		currChild = tail(currChild);
		a++;
	}
	destroyList(children, freeState);
	bestChild.index = indexOfCurrBestChild;
	bestChild.value = valueOfCurrBestChild;
	return bestChild;
}