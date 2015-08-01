@@ -0,0 +1,65 @@
// Driver to handle operations in 2320 Lab 3, Summer 2015
#include <stdlib.h>
#include <stdio.h>
#include "topdownRB.h"

int main()
{
int op,key,rank;

STinit();  // Initialize red-black tree
verifyRBproperties();
extendedTraceOn();

scanf_s("%d",&op);
while (op)
{
  switch (op)
  {
    case 1:
      scanf_s("%d",&key);
      if (STsearch(key) != -9999999)
	{
          printf("Error, key already exists.\n");
	  break;
	}
	else
	{
          printf("1 %d\n",key);
          STinsert(key);
	  break;
	}
    case 2:
      scanf_s("%d",&key);
      printf("2 %d\n",key);
      rank=STinvSelect(key);
      if (rank==(-1))
        printf("Key %d is not in tree\n",key);
      else
        printf("Key %d has odd rank %d\n",key,rank);
      break;
    case 3:
      scanf_s("%d",&rank);
      printf("3 %d\n",rank);
      /*if (rank<0 || rank>SToddRankOfMax())
        printf("rank %d range error\n",rank);
      else
        printf("rank %d has firstkey %d and last key %d\n",
          rank,key(STselectSmall(rank)),key(STselectLarge(rank)));*/
      break;
    case 4:
      printf("4\n");
      verifyRBproperties();
      break;
    case 5:
      STprintTree();
      break;
    default:
      printf("Bad operation %d\n",op);
  }
  fflush(stdout);  // In case output is going to a fifo using mkfifo
  scanf_s("%d",&op);
}
printf("0\n");
}
